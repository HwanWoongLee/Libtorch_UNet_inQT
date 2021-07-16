#pragma once
#include "UNet.h"


class QSeg;
class Trainer : public QThread
{
	Q_OBJECT

signals:
	void progress(int value, int iMax);
	void ploting(int epoch, double train_loss, double test_loss);
	void train_stop();

private:
	void run();			// thread start하면 호출하는 부분
	bool Train(QString train_path, QString val_path, int epoch = 100, int batchsize = 8, double train_loss = 0.001);

public:
	Trainer(QSeg* parent = nullptr);
	~Trainer();

	void		SetTrainPath(QString train_path, QString val_path, QString backup_path);
	void		SetParameter(int epoch, int batchsize);
	
	bool		LoadModel(std::string strPath);
	cv::Mat		TestModel(cv::Mat image);

public:
	bool		m_bTraining;		// 현재 Train 중인지 감별

private:
	QSeg*		m_pParent;
	UNet		m_model;

	QString		m_strTrainPath;
	QString		m_strValPath;
	QString		m_strBackupPath;

	int			m_epoch;
	int			m_batchsize;
	double		m_train_loss;
};

