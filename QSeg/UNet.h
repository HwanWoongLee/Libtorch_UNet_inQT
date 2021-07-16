#pragma once


class UNetImpl : public torch::nn::Module {
public:
	UNetImpl();
	~UNetImpl();

	torch::Tensor forward(const torch::Tensor& x);

private:
	nn::Sequential							CBR2d(int in_channel, int out_channel);

	nn::MaxPool2d							pooling		= nn::MaxPool2d(nn::MaxPool2dOptions(2).stride(2));
	nn::Conv2d								fc			= nn::Conv2d(nn::Conv2dOptions(64, 1, 1).stride(1).padding(0));
	
	nn::Dropout2d							dropout2d	= nn::Dropout2d(nn::Dropout2dOptions(0.5));


	std::shared_ptr<nn::MaxPool2dImpl>		pooling_1;
	std::shared_ptr<nn::MaxPool2dImpl>		pooling_2;
	std::shared_ptr<nn::MaxPool2dImpl>		pooling_3;
	std::shared_ptr<nn::MaxPool2dImpl>		pooling_4;

	nn::Sequential							unpooling_1;
	nn::Sequential							unpooling_2;
	nn::Sequential							unpooling_3;
	nn::Sequential							unpooling_4;

	// layers
	nn::Sequential							down_conv_1_1;
	nn::Sequential							down_conv_1_2;
	nn::Sequential							down_conv_2_1;
	nn::Sequential							down_conv_2_2;
	nn::Sequential							down_conv_3_1;
	nn::Sequential							down_conv_3_2;
	nn::Sequential							down_conv_4_1;
	nn::Sequential							down_conv_4_2;

	nn::Sequential							bridge_1;
	nn::Sequential							bridge_2;

	nn::Sequential							up_conv_1_1;
	nn::Sequential							up_conv_1_2;
	nn::Sequential							up_conv_2_1;
	nn::Sequential							up_conv_2_2;
	nn::Sequential							up_conv_3_1;
	nn::Sequential							up_conv_3_2;
	nn::Sequential							up_conv_4_1;
	nn::Sequential							up_conv_4_2;
};

TORCH_MODULE(UNet);