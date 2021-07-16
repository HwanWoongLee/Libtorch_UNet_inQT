#include "framework.h"

void SearchDirectory(QString strPath, std::vector<QString>& strPathList) {
	QStringList strFilters;

	strFilters += "*.png";
	strFilters += "*.jpg";
	strFilters += "*.bmp";

	QDirIterator iterDir(strPath, strFilters, QDir::AllEntries, QDirIterator::Subdirectories);
	strPathList.clear();

	while (iterDir.hasNext())
	{
		auto next = iterDir.next();
		auto path = iterDir.path();
		auto name = iterDir.fileName();

		strPathList.push_back(next);
	}

	return;
}

void SearchDirectory(QString strPath, std::vector<std::string>& strPathList) {
	QStringList strFilters;

	strFilters += "*.png";
	strFilters += "*.jpg";
	strFilters += "*.bmp";

	QDirIterator iterDir(strPath, strFilters, QDir::AllEntries, QDirIterator::Subdirectories);
	strPathList.clear();

	while (iterDir.hasNext())
	{
		auto next = iterDir.next();
		auto path = iterDir.path();
		auto name = iterDir.fileName();

		strPathList.push_back(next.toStdString());
	}

	return;
}

bool GetFilePath(QString strCaption, QString& strPath, bool bFile) {
	QFileDialog dlg;
	QString path;

	if (bFile) {
		path = dlg.getOpenFileName(nullptr, strCaption, "../");
	}
	else {
		path = dlg.getExistingDirectory(nullptr, strCaption, "../");
	}

	if (!path.isEmpty()) {
		strPath = path;
		return true;
	}
	else {
		return false;
	}
}



QImage MatToQImage(const cv::Mat& mat)
{
	if (mat.type() == CV_8UC1)
	{
		QVector<QRgb> colorTable;
		for (int i = 0; i < 256; i++)
			colorTable.push_back(qRgb(i, i, i));

		const uchar* qImageBuffer = (const uchar*)mat.data;
		QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
		img.setColorTable(colorTable);
		return img;
	}
	if (mat.type() == CV_8UC3)
	{
		const uchar* qImageBuffer = (const uchar*)mat.data;
		QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return img.rgbSwapped();
	}

	return QImage();
}