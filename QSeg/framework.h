#pragma once
#include "torch/script.h"
#include "torch/torch.h"
#include "torch/nn/parallel/data_parallel.h"
#include "c10/cuda/CUDACachingAllocator.h"


#include <Windows.h>
#include "ui_QSeg.h"

#include "opencv2/opencv.hpp"


#ifdef _DEBUG
#pragma comment(lib, "opencv_world452d.lib")
#else
#pragma comment(lib, "opencv_world452.lib")
#endif

using namespace torch;
using namespace std;
using namespace cv;


void SearchDirectory(QString strPath, std::vector<QString>& strPathList);
void SearchDirectory(QString strPath, std::vector<string>& strPathList);
bool GetFilePath(QString strCaption, QString& strPath, bool bFile = false);		// bFile=true : file, false=folder
QImage MatToQImage(const cv::Mat& mat);