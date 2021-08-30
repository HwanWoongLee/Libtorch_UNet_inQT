#include "framework.h"
#include "QDrawLabel.h"
#include "QSeg.h"

QDrawLabel::QDrawLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent) {
    m_pParent = nullptr;
    m_bMouseDown[eLBUTTON] = false;
    m_bMouseDown[eRBUTTON] = false;
    m_iBrushSize = 20;
    m_iLayer = 0;

	this->setCursor(Qt::CrossCursor);
	this->setMouseTracking(true);
}
QDrawLabel::~QDrawLabel() {
}
void QDrawLabel::SetParent(QSeg* parent) {
	m_pParent = parent;
	return;
}

void QDrawLabel::SetImage(cv::Mat image) {
    m_orgImage = image.clone();
    m_maskImage = cv::Mat::zeros(m_orgImage.size(), CV_8UC3);
    m_resultImage = cv::Mat();
    m_drawImage = m_orgImage.clone();

    m_pixmapSize = this->pixmap()->size();

    return;
}

void QDrawLabel::SetLayer(int num) {
	m_iLayer = num;
}

void QDrawLabel::SetBrushSize(int size) {
	m_iBrushSize = size;
}

cv::Point QDrawLabel::ViewPtToMatPt(QPoint pt) {
	cv::Point imagePt(0, 0);
	if (!m_orgImage.empty()) {
		auto w = this->width();
		auto h = this->height();
		double dx = (double)((this->width() - m_pixmapSize.width())) / 2.;
		double dy = (double)((this->height() - m_pixmapSize.height())) / 2.;
	
		cv::Rect viewRect = cv::Rect(0, 0, m_pixmapSize.width(), m_pixmapSize.height());
		cv::Rect matRect = cv::Rect(0, 0, m_orgImage.cols, m_orgImage.rows);
	
		pt -= QPoint(dx, dy);
	
		double rw = (double)matRect.width / (double)viewRect.width;
		double rh = (double)matRect.height / (double)viewRect.height;
	
		double image_x = rw * pt.x();
		double image_y = rh * pt.y();
		imagePt = cv::Point(image_x, image_y);
	}
	return imagePt;
}

cv::Mat QDrawLabel::GetLayerImage() {
	cv::Mat temp;
	if (m_resultImage.empty())
		return temp;

	switch (m_iLayer) {
		case 0: {
			cv::Mat image = m_resultImage.clone();
			if (image.channels() == 1)
				cvtColor(image, image, COLOR_GRAY2BGR);

			for (int y = 0; y < image.rows; y++) {
				auto data = image.ptr<uchar>(y);
				for (int x = 0; x < image.cols; x++) {
					uchar b = data[x * 3 + 0];
					uchar g = data[x * 3 + 1];
					uchar r = data[x * 3 + 2];
					if (b == 0 && g == 0 && r == 0) {
						data[x * 3 + 0] = 255;
						data[x * 3 + 1] = 0;
						data[x * 3 + 2] = 0;
					}
				}
			}

			cv::addWeighted(m_orgImage, 1.0, image, 0.5, 0, temp);
			break;
		}
		case 1: {
			temp = m_resultImage.clone();
			break;
		}
	}
	return temp;
}

cv::Mat QDrawLabel::Masking() {
	if (m_maskImage.empty())
		return cv::Mat();

	cv::Mat image = m_orgImage.clone();
	cv::Mat marker = m_maskImage.clone();
	cvtColor(marker, marker, cv::COLOR_BGR2GRAY);

	cv::Mat markers;
	image.convertTo(image, CV_8UC3);
	marker.convertTo(markers, CV_32S);

	try {
		cv::watershed(image, markers);
	}
	catch (exception& e) {
		std::cout << e.what();
	}

	cv::Mat result;
	markers.convertTo(result, CV_8UC3);
	cv::normalize(result, result, 0, 255, cv::NORM_MINMAX);

	double min, max;
	cv::minMaxLoc(result, &min, &max);

	// 테두리 제거
	for (int y = 0; y < result.rows; y++) {
		auto data = result.ptr<uchar>(y);
		for (int x = 0; x < result.cols; x++) {
			if (min == data[x]) {
				result.at<uchar>(y, x) = max;
			}
		}
	}
	cv::normalize(result, result, min, 255, cv::NORM_MINMAX);
	result = ~result;
	m_resultImage = result.clone();
	
	return GetLayerImage();
}

/// mouse event
void QDrawLabel::mousePressEvent(QMouseEvent* ev) {
	const QPoint pt = ev->pos();
	auto b = ev->button();
	const QPixmap* pix = this->pixmap();
	if (pix) {
		if (b == Qt::MouseButton::LeftButton) {
			m_bMouseDown[eLBUTTON] = true;
			m_bMouseDown[eRBUTTON] = false;
		}
		else if (b == Qt::MouseButton::RightButton) {
			m_bMouseDown[eLBUTTON] = false;
			m_bMouseDown[eRBUTTON] = true;
		}
	}
	
	return;
}

void QDrawLabel::mouseMoveEvent(QMouseEvent* ev) {
	if (m_maskImage.empty() || m_drawImage.empty())
		return;

	const QPoint pos = ev->pos();
	if (m_bMouseDown[eLBUTTON]) {
		cv::circle(m_maskImage, ViewPtToMatPt(pos), m_iBrushSize, cv::Scalar(0, 0, 255), -1);
		cv::circle(m_drawImage, ViewPtToMatPt(pos), m_iBrushSize, cv::Scalar(0, 0, 255), -1);
	}
	else if (m_bMouseDown[eRBUTTON]) {
		cv::circle(m_maskImage, ViewPtToMatPt(pos), m_iBrushSize, cv::Scalar(255, 255, 255), -1);
		cv::circle(m_drawImage, ViewPtToMatPt(pos), m_iBrushSize, cv::Scalar(255, 255, 255), -1);
	}

	cv::Mat image;
	image = m_drawImage.clone();
	cv::circle(image, ViewPtToMatPt(pos), m_iBrushSize, cv::Scalar(0, 0, 255), -1);
	m_pParent->ShowImage(*this, image);

	return;
}

void QDrawLabel::mouseReleaseEvent(QMouseEvent* ev) {
	const QPoint pt = ev->pos();
	if (!m_pParent)
		return;

	if (m_bMouseDown[eLBUTTON] || m_bMouseDown[eRBUTTON]) {
		cv::addWeighted(m_orgImage, 1.0, m_maskImage, 0.5, 0, m_drawImage);
		m_pParent->ShowImage(*this, m_drawImage);
	}
	m_bMouseDown[eLBUTTON] = false;
	m_bMouseDown[eRBUTTON] = false;

	return;
}

