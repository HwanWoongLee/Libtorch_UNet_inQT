#include <opencv2/opencv.hpp>

using namespace cv;

#pragma once
class QSeg;
class QDrawLabel : public QLabel
{
	Q_OBJECT

public:
	QDrawLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	QDrawLabel(const QString& text, QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~QDrawLabel();

	enum eMOUSE {
		eLBUTTON,
		eRBUTTON,
		eEND,
	};

	cv::Mat		Masking();
	cv::Mat		GetLayerImage();
	cv::Mat		GetMaskImage() { return m_resultImage.clone(); }
	void		SetParent(QSeg* parent);
	void		SetImage(cv::Mat image);
	void		SetLayer(int num);
	void		SetBrushSize(int size);

private:
	cv::Point	ViewPtToMatPt(QPoint pt);

private:
	QSeg*		m_pParent;
	bool		m_bMouseDown[eEND];
	int			m_iBrushSize;
	int			m_iLayer;

	cv::Mat		m_orgImage;
	cv::Mat		m_drawImage;
	cv::Mat		m_maskImage;
	cv::Mat		m_resultImage;

	QSize		m_pixmapSize;

signals:
	void mousePressed(const QPoint&);
	void mouseMovwed(const QPoint&);
	void mouseReleased(const QPoint&);

protected:
	void mousePressEvent(QMouseEvent* ev);
	void mouseMoveEvent(QMouseEvent* ev);
	void mouseReleaseEvent(QMouseEvent* ev);
};

