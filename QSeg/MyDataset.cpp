#include "framework.h"
#include "MyDataset.h"

torch::Tensor MatToTensor(cv::Mat image) {
	torch::Tensor tensor;
	image.convertTo(image, CV_32FC1, 1.0f / 255.0f);			// 0 ~ 1

	tensor = torch::from_blob(image.data, { image.rows, image.cols, 1 }, torch::kFloat32).clone();
	tensor = tensor.permute({ 2, 0, 1 });

	//cv::Mat test = TensorToMat(tensor);
	return tensor;
}

cv::Mat TensorToMat(const torch::Tensor& tensor) {	
	torch::Tensor out_tensor = tensor.clone();
	out_tensor = out_tensor.to(torch::kCPU);

	cv::Mat image(out_tensor.size(1), out_tensor.size(2), CV_32FC1);
	std::memcpy(image.data, out_tensor.data_ptr(), sizeof(float) * out_tensor.numel());

	return image;
}

cv::Mat TensorToMat(const torch::Tensor& tensor, int iCount) {
	vector<cv::Mat> images;
	for (int i = 0; i < iCount; i++) {
		std::cout << tensor[i].dtype() << std::endl;
		std::cout << tensor[i].sizes() << std::endl;

		torch::Tensor out_tensor = tensor[i].clone();
		out_tensor = out_tensor.to(torch::kCPU);

		cv::Mat image(out_tensor.size(1), out_tensor.size(2), CV_32FC1);
		std::memcpy(image.data, out_tensor.data_ptr(), sizeof(float) * out_tensor.numel());
		images.push_back(image);
	}

	return images[0];
}


cv::Mat TransformsImage(cv::Mat image, bool bLabel) {
	cv::Mat trans = image.clone();

	// gray scale
	if (trans.channels() == 3)
		cv::cvtColor(trans, trans, cv::COLOR_BGR2GRAY);

	// resize image
	cv::resize(trans, trans, cv::Size(224, 224), 0, 0, cv::InterpolationFlags::INTER_NEAREST);
	
	if (bLabel) {
		cv::threshold(trans, trans, 100, 255, cv::THRESH_OTSU);
	}

	return trans;
}


vector<torch::Tensor> process_images(vector<string> list_images) {
	vector<torch::Tensor> tensors;

	for (int i = 0; i < list_images.size(); i++) {
		cv::Mat image = cv::imread(list_images[i]);

		image = TransformsImage(image, false);
		tensors.push_back(MatToTensor(image).clone());
	}

	return tensors;
}
vector<torch::Tensor> process_labels(vector<string> list_labels) {
	vector<torch::Tensor> tensors;

	for (int i = 0; i < list_labels.size(); i++) {
		cv::Mat image = cv::imread(list_labels[i]);
		if (image.channels() == 3)
			cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);

		image = TransformsImage(image, true);
		tensors.push_back(MatToTensor(image).clone());
	}

	return tensors;
}