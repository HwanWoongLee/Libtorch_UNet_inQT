#pragma once

torch::Tensor				MatToTensor(cv::Mat image);
cv::Mat						TensorToMat(const torch::Tensor& tensor);
cv::Mat						TensorToMat(const torch::Tensor& tensor, int iCount);

std::vector<torch::Tensor>	process_images(vector<string> list_images);
std::vector<torch::Tensor>	process_labels(vector<string> list_labels);

cv::Mat						TransformsImage(cv::Mat image, bool bLabel);


class MyDataset : public torch::data::Dataset<MyDataset> {
private:
	vector<torch::Tensor> images, labels;
public:
	// Constructor
	MyDataset(vector<string> list_images, vector<string> list_labels) {
		images = process_images(list_images);
		labels = process_labels(list_labels);
	};

	// Override get() function to return tensor at location index
	torch::data::Example<> get(size_t index) override {
		torch::Tensor sample_img = images.at(index);
		torch::Tensor sample_label = labels.at(index);
		return { sample_img.clone(), sample_label.clone() };
	};

	// Return the length of data
	torch::optional<size_t> size() const override {
		return labels.size();
	};
};