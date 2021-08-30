#include "framework.h"
#include "Trainer.h"
#include "MyDataset.h"
#include "QSeg.h"

Trainer::Trainer(QSeg* parent) {
	m_pParent		= parent;
	m_bTraining		= false;
	m_epoch			= 100;
	m_batchsize		= 8;
	m_train_loss	= 0.001;

	// Load torch CUDA, GPU 사용하려면 필요한 구문
	LoadLibraryA("torch_cuda.dll");
}
Trainer::~Trainer() {

}

void GetFileListFromPath() {

}

void Trainer::SetTrainPath(QString train_path, QString val_path, QString backup_path) {
	m_strTrainPath	= train_path;
	m_strValPath	= val_path;

	QDate curDate = QDate::currentDate();
	QTime curTime = QTime::currentTime();

	QString strCurDate = QString::number(curDate.year()) +
		QString::number(curDate.month()) +
		QString::number(curDate.day()) +
		QString::number(curTime.hour()) +
		QString::number(curTime.minute());

	m_strBackupPath = backup_path + "/newModel_" + strCurDate + ".pt";

	return;
}

bool Trainer::LoadModel(std::string strPath) {
	try {
		torch::load(m_model, strPath);
	}
	catch (exception& err) {
		return false;
	}
	return true;
}

cv::Mat Trainer::TestModel(cv::Mat image) {
	m_model->eval();

	cv::Mat test_image = image.clone();
	test_image = TransformsImage(test_image, false);
	auto data = MatToTensor(test_image);
	data = data.unsqueeze(0);
	data = data.to(torch::kCUDA).toType(torch::kFloat);

	auto test_out = m_model->forward(data);
	cv::Mat out_image = TensorToMat(test_out, test_out.size(0));
	cv::resize(out_image, out_image, cv::Size(image.cols, image.rows));

	return out_image;
}

void Trainer::SetParameter(int epoch, int batchsize) {
	m_epoch = epoch;
	m_batchsize = batchsize;
}

void Trainer::run() {
	if (Train(m_strTrainPath, m_strValPath, m_epoch, m_batchsize)) {
		torch::save(m_model, m_strBackupPath.toStdString());

	}
	emit train_stop();
	return;
}

bool Trainer::Train(QString train_path, QString val_path, int epoch, int batchsize, double train_loss) {
	m_pParent->WriteTrainLog("..........Train start");
	auto sTime = GetTickCount64();
	m_bTraining = true;
	
	// train parameters
	m_pParent->WriteTrainLog("Epoch \t" + QString::number(epoch));
	m_pParent->WriteTrainLog("Batch size \t" + QString::number(batchsize));
	m_pParent->WriteTrainLog("Train loss \t" + QString::number(train_loss));

	// get image, mask list
	QString train_image_path = train_path + "/image";
	QString train_mask_path = train_path + "/mask";

	QString image_path_val = val_path + "/image";
	QString mask_path_val = val_path + "/mask";

	vector<std::string> image_list, mask_list;
	vector<std::string> image_list_val, mask_list_val;

	SearchDirectory(train_image_path, image_list);
	SearchDirectory(train_mask_path, mask_list);
	SearchDirectory(image_path_val, image_list_val);
	SearchDirectory(mask_path_val, mask_list_val);

	if (image_list.size() <= 0 || mask_list.size() <= 0) {
		return false;
	}
	if (image_list_val.size() <= 0 || mask_list_val.size() <= 0) {
		return false;
	}

	// get dataset(train)
	auto dataset = MyDataset(image_list, mask_list).map(torch::data::transforms::Stack<>());
	auto data_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
		std::move(dataset),
		batchsize);

	// test dataset
	auto dataset_val = MyDataset(image_list_val, mask_list_val).map(torch::data::transforms::Stack<>());
	auto data_loader_val = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
		std::move(dataset_val),
		batchsize);

	auto optim = torch::optim::Adam(m_model->parameters(), torch::optim::AdamOptions(train_loss));
	m_pParent->WriteTrainLog("..........Set dataset");

	// train
	auto device = torch::cuda::is_available() ? torch::kCUDA : torch::kCPU;
	m_model->to(device);

	QString strlog;
	for (int i = 1; i <= epoch; i++) {
		m_model->train();

		std::vector<float> loss_arr, loss_arr_val;
		int batch_index = 0;

		for (auto& batch : *data_loader) {
			if (!m_bTraining) {
				m_pParent->WriteTrainLog("..........Train stop !");
				return false;
			}

			auto data = batch.data.to(device).toType(torch::kFloat);
			auto label = batch.target.to(device).toType(torch::kFloat);

			auto output = m_model->forward(data);

			optim.zero_grad();
			auto loss = torch::binary_cross_entropy_with_logits(output, label);
			loss.backward();
			optim.step();

			auto loss_value = loss.item<float>();
			loss_arr.push_back(loss_value);

			strlog = "Batch : " + QString::number(++batch_index) + " | Train Loss : " + QString::number(loss_value);
			m_pParent->WriteTrainLog(strlog);
		}

		// set progressbar
		emit progress(i, epoch);

		// set plot (train set)
		double loss_mean = accumulate(loss_arr.begin(), loss_arr.end(), 0.0f) / loss_arr.size();
		//emit ploting(epoch, loss_mean);
		strlog = "Epoch[" + QString::number(i) + "/" + QString::number(epoch) + "] | Train Mean Loss : " + QString::number(loss_mean);
		m_pParent->WriteTrainLog(strlog);

		// test set
		m_model->eval();
		loss_arr_val.clear(); 

        for (auto& batch : *data_loader_val) {
            //torch::NoGradGuard no_grad;
            if (!m_bTraining) {
                m_pParent->WriteTrainLog("..........Train stop !");
                return false;
            }

            auto data = batch.data.to(device).toType(torch::kFloat);
            auto label = batch.target.to(device).toType(torch::kFloat);

            auto output = m_model->forward(data);

            optim.zero_grad();
            auto loss = torch::binary_cross_entropy_with_logits(output, label);
            loss.backward();
            optim.step();

            auto loss_value = loss.item<float>();
            loss_arr_val.push_back(loss_value);
        }
		
		double loss_mean_val = accumulate(loss_arr_val.begin(), loss_arr_val.end(), 0.0f) / loss_arr_val.size();
		emit ploting(epoch, loss_mean, loss_mean_val);
		strlog = "Epoch[" + QString::number(i) + "/" + QString::number(epoch) + "] | Test Mean Loss : " + QString::number(loss_mean_val);
		m_pParent->WriteTrainLog(strlog);
	}

	// gpu memory release
	c10::cuda::CUDACachingAllocator::emptyCache();

	m_bTraining = false;
	m_pParent->WriteTrainLog("..........Train complete !!!");
	return true;
}
