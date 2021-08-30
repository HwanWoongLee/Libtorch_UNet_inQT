#include "framework.h"
#include "UNet.h"

UNetImpl::UNetImpl() {
	down_conv_1_1	= CBR2d(1, 64);
	down_conv_1_2	= CBR2d(64, 64);
	down_conv_2_1	= CBR2d(64, 128);
	down_conv_2_2	= CBR2d(128, 128);
	down_conv_3_1	= CBR2d(128, 256);
	down_conv_3_2	= CBR2d(256, 256);
	down_conv_4_1	= CBR2d(256, 512);
	down_conv_4_2	= CBR2d(512, 512);

	bridge_1		= CBR2d(512, 1024);
	bridge_2		= CBR2d(1024, 512);

	unpooling_1		= nn::Sequential(nn::ConvTranspose2d(nn::ConvTranspose2dOptions(512, 512, 2).stride(2).padding(0)));
	up_conv_1_1		= CBR2d(512 * 2, 512);
	up_conv_1_2		= CBR2d(512, 256);

	unpooling_2		= nn::Sequential(nn::ConvTranspose2d(nn::ConvTranspose2dOptions(256, 256, 2).stride(2).padding(0)));
	up_conv_2_1		= CBR2d(256 * 2, 256);
	up_conv_2_2		= CBR2d(256, 128);

	unpooling_3		= nn::Sequential(nn::ConvTranspose2d(nn::ConvTranspose2dOptions(128, 128, 2).stride(2).padding(0)));
	up_conv_3_1		= CBR2d(128 * 2, 128);
	up_conv_3_2		= CBR2d(128, 64);

	unpooling_4		= nn::Sequential(nn::ConvTranspose2d(nn::ConvTranspose2dOptions(64, 64, 2).stride(2).padding(0)));
	up_conv_4_1		= CBR2d(64 * 2, 64);
	up_conv_4_2		= CBR2d(64, 64);

	down_conv_1_1	= register_module("down_conv_1_1",	down_conv_1_1);
	down_conv_1_2	= register_module("down_conv_1_2",	down_conv_1_2);
	pooling_1		= register_module("pool1",			pooling);
					
	down_conv_2_1	= register_module("down_conv_2_1",	down_conv_2_1);
	down_conv_2_2	= register_module("down_conv_2_2",	down_conv_2_2);
	pooling_2		= register_module("pool2",			pooling);
					
	down_conv_3_1	= register_module("down_conv_3_1",	down_conv_3_1);
	down_conv_3_2	= register_module("down_conv_3_2",	down_conv_3_2);
	pooling_3		= register_module("pool3",			pooling);
					
	down_conv_4_1	= register_module("down_conv_4_1",	down_conv_4_1);
	down_conv_4_2	= register_module("down_conv_4_2",	down_conv_4_2);
	pooling_4		= register_module("pool4",			pooling);
					
	bridge_1		= register_module("bridge_1",		bridge_1);
	bridge_2		= register_module("bridge_2",		bridge_2);
					
	unpooling_1		= register_module("unpooling_1",	unpooling_1);
	up_conv_1_1		= register_module("up_conv_1_1",	up_conv_1_1);
	up_conv_1_2		= register_module("up_conv_1_2",	up_conv_1_2);
					 
	unpooling_2		= register_module("unpooling_2",	unpooling_2);
	up_conv_2_1		= register_module("up_conv_2_1",	up_conv_2_1);
	up_conv_2_2		= register_module("up_conv_2_2",	up_conv_2_2);
					
	unpooling_3		= register_module("unpooling_3",	unpooling_3);
	up_conv_3_1		= register_module("up_conv_3_1",	up_conv_3_1);
	up_conv_3_2		= register_module("up_conv_3_2",	up_conv_3_2);
					
	unpooling_4		= register_module("unpooling_4",	unpooling_4);
	up_conv_4_1		= register_module("up_conv_4_1",	up_conv_4_1);
	up_conv_4_2		= register_module("up_conv_4_2",	up_conv_4_2);
					
	fc				= register_module("fc",				fc);
	dropout2d		= register_module("dropout2d",		dropout2d);
}
UNetImpl::~UNetImpl() {

}

// Conv->Batch->ReLU
nn::Sequential UNetImpl::CBR2d(int in_channel, int out_channel) {
	return nn::Sequential(
		nn::Conv2d(nn::Conv2dOptions(in_channel, out_channel, 3).padding(1).stride(1)),
		nn::BatchNorm2d(nn::BatchNorm2dOptions(out_channel)),
		nn::ReLU(nn::ReLUOptions(true))
	);
}

torch::Tensor UNetImpl::forward(const torch::Tensor& x) {
	auto enc_1_1	= down_conv_1_1->forward(x);
	auto enc_1_2	= down_conv_1_2->forward(enc_1_1);
	//enc_1_2			= dropout2d->forward(enc_1_2);
	auto pool1		= pooling_1->forward(enc_1_2);
	pool1			= dropout2d->forward(pool1);

	auto enc_2_1	= down_conv_2_1->forward(pool1);
	auto enc_2_2	= down_conv_2_2->forward(enc_2_1);
	//enc_2_2			= dropout2d->forward(enc_2_2);
	auto pool2		= pooling_2->forward(enc_2_2);
	pool2			= dropout2d->forward(pool2);

	auto enc_3_1	= down_conv_3_1->forward(pool2);
	auto enc_3_2	= down_conv_3_2->forward(enc_3_1);
	//enc_3_2			= dropout2d->forward(enc_3_2);
	auto pool3		= pooling_3->forward(enc_3_2);
	pool3			= dropout2d->forward(pool3);

	auto enc_4_1	= down_conv_4_1->forward(pool3);
	auto enc_4_2	= down_conv_4_2->forward(enc_4_1);
	enc_4_2			= dropout2d->forward(enc_4_2);
	auto pool4		= pooling_4->forward(enc_4_2);
	pool4			= dropout2d->forward(pool4);

	auto bridge1	= bridge_1->forward(pool4);
	auto bridge2	= bridge_2->forward(bridge1);

	auto unpool1	= unpooling_1->forward(bridge2);
	auto cat1		= torch::cat({ unpool1, enc_4_2 }, 1);
	cat1			= dropout2d->forward(cat1);
	auto dec_1_1	= up_conv_1_1->forward(cat1);
	auto dec_1_2	= up_conv_1_2->forward(dec_1_1);

	auto unpool2	= unpooling_2->forward(dec_1_2);
	auto cat2		= torch::cat({ unpool2, enc_3_2 }, 1);
	cat2			= dropout2d->forward(cat2);
	auto dec_2_1	= up_conv_2_1->forward(cat2);
	auto dec_2_2	= up_conv_2_2->forward(dec_2_1);

	auto unpool3	= unpooling_3->forward(dec_2_2);
	auto cat3		= torch::cat({ unpool3, enc_2_2 }, 1);
	cat3			= dropout2d->forward(cat3);
	auto dec_3_1	= up_conv_3_1->forward(cat3);
	auto dec_3_2	= up_conv_3_2->forward(dec_3_1);

	auto unpool4	= unpooling_4->forward(dec_3_2);
	auto cat4		= torch::cat({ unpool4, enc_1_2 }, 1);
	cat4			= dropout2d->forward(cat4);
	auto dec_4_1	= up_conv_4_1->forward(cat4);
	auto dec_4_2	= up_conv_4_2->forward(dec_4_1);

	auto output		= fc->forward(dec_4_2);

	return output;
}