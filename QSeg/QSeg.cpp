//itemSelectionChanged

#include "framework.h"
#include "QSeg.h"
#include "qfiledialog.h"
#include "qdiriterator.h"
#include "Trainer.h"



QSeg::QSeg(QWidget* parent)
	: QMainWindow(parent)
{
	if (!m_pTrainer)
		m_pTrainer = new Trainer(this);

	ui.setupUi(this);

	connect(ui.BTN_menu_data,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_menu_label,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_menu_train,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_menu_test,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_load_dataset,		SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_path_backup,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_train_train,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_train_backuppath,	SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_Label_loaddata,		SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_label_masking,		SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_Test_loaddata,		SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_Test_modelpath,		SIGNAL(clicked()),						this, SLOT(ButtonClicked()));
	connect(ui.BTN_Test_test,			SIGNAL(clicked()),						this, SLOT(ButtonClicked()));

	connect(ui.RBTN_both,				SIGNAL(clicked()),						this, SLOT(RadioClicked()));
	connect(ui.RBTN_mask,				SIGNAL(clicked()),						this, SLOT(RadioClicked()));

	connect(ui.TABLE_DATA,				SIGNAL(itemSelectionChanged()),			this, SLOT(ChangedDataTableItem()));
	connect(ui.TABLE_LABEL,				SIGNAL(itemSelectionChanged()),			this, SLOT(ChangedLabelTableItem()));
	connect(ui.TABLE_TEST,				SIGNAL(itemSelectionChanged()),			this, SLOT(ChangedTestTableItem()));

	connect(m_pTrainer,					SIGNAL(progress(int, int)),				this, SLOT(SetProgressBar(int, int)));
	connect(m_pTrainer,					SIGNAL(ploting(int, double, double)),	this, SLOT(SetCustomPlotValue(int, double, double)));
	connect(m_pTrainer,					SIGNAL(train_stop()),					this, SLOT(TrainStop()));

	connect(ui.EDIT_Label_brushSize,	SIGNAL(editingFinished()), this, SLOT(EditFinished()));

	m_iWorkWnd = 0;
}

void QSeg::SetUIStyle() {
	// main window
	this->setStyleSheet(BACK_COLOR_3 COLOR_WHITE);
	ui.statusBar->setStyleSheet(BACK_COLOR_2);

	// form widget                  
	ui.w_Background->setStyleSheet(COLOR_SELECT_BTN);
	ui.w_Menu->setStyleSheet(		BACK_COLOR_1);
	ui.w_Work->setStyleSheet(		BACK_COLOR_3);
	ui.w_Param->setStyleSheet(		BACK_COLOR_1);
	ui.w_Info->setStyleSheet(		BACK_COLOR_1);
	ui.w_Train_pram->setStyleSheet(	BACK_COLOR_1);
	ui.w_Label_pram->setStyleSheet(	BACK_COLOR_1);
	ui.w_Test->setStyleSheet(		BACK_COLOR_1);
	
	// menu buttons                      
	ui.BTN_menu_data->setStyleSheet(		BACK_COLOR_2);
	ui.BTN_menu_label->setStyleSheet(		BACK_COLOR_2);
	ui.BTN_menu_train->setStyleSheet(		BACK_COLOR_2);
	// buttons
	ui.BTN_train_train->setStyleSheet(		BACK_COLOR_2);
	ui.BTN_train_backuppath->setStyleSheet(	BACK_COLOR_2);
	ui.BTN_Label_loaddata->setStyleSheet(	BACK_COLOR_2);
	ui.BTN_label_masking->setStyleSheet(	BACK_COLOR_2);
	ui.BTN_Test_test->setStyleSheet(		BACK_COLOR_2);
	ui.BTN_load_dataset->setStyleSheet(		BACK_COLOR_2);
	ui.BTN_path_backup->setStyleSheet(		BACK_COLOR_2);
	ui.BTN_Test_loaddata->setStyleSheet(	BACK_COLOR_2);
	ui.BTN_Test_modelpath->setStyleSheet(	BACK_COLOR_2);

	ui.SENSOR_object->setStyleSheet(	"background-color:rgb(255,0,0);border:none;");
	ui.SENSOR_background->setStyleSheet("background-color:rgb(255,255,255);border:none;");

	// table widget
	ui.TABLE_DATA->resizeColumnToContents(0);
	ui.TABLE_DATA->setColumnWidth(1, 200);
	ui.TABLE_DATA->setColumnWidth(2, 100);
	ui.TABLE_DATA->horizontalHeader()->setStretchLastSection(true);
	ui.TABLE_DATA->horizontalHeader()->setStyleSheet("::section {background-color:rgb(63,63,70);color:rgb(255,255,255);}");
	ui.TABLE_DATA->verticalHeader()->hide();												// 세로 header 숨김
	ui.TABLE_DATA->editTriggers().setFlag(QAbstractItemView::EditTrigger::NoEditTriggers);	// Read only
	ui.TABLE_DATA->setSelectionBehavior(QAbstractItemView::SelectRows);						// row 단위로 선택 가능
	ui.TABLE_DATA->setSelectionMode(QAbstractItemView::SingleSelection);					// 단일 선택만 가능

	ui.TABLE_LABEL->resizeColumnToContents(0);
	ui.TABLE_LABEL->horizontalHeader()->setStretchLastSection(true);
	ui.TABLE_LABEL->horizontalHeader()->setStyleSheet("::section {background-color:rgb(63,63,70);color:rgb(255,255,255);}");
	ui.TABLE_LABEL->verticalHeader()->hide();												// 세로 header 숨김
	ui.TABLE_LABEL->editTriggers().setFlag(QAbstractItemView::EditTrigger::NoEditTriggers);	// Read only
	ui.TABLE_LABEL->setSelectionBehavior(QAbstractItemView::SelectRows);					// row 단위로 선택 가능
	ui.TABLE_LABEL->setSelectionMode(QAbstractItemView::SingleSelection);					// 단일 선택만 가능

	ui.TABLE_TEST->resizeColumnToContents(0);
	ui.TABLE_TEST->horizontalHeader()->setStretchLastSection(true);
	ui.TABLE_TEST->horizontalHeader()->setStyleSheet("::section {background-color:rgb(63,63,70);color:rgb(255,255,255);}");
	ui.TABLE_TEST->verticalHeader()->hide();												// 세로 header 숨김
	ui.TABLE_TEST->editTriggers().setFlag(QAbstractItemView::EditTrigger::NoEditTriggers);	// Read only
	ui.TABLE_TEST->setSelectionBehavior(QAbstractItemView::SelectRows);						// row 단위로 선택 가능
	ui.TABLE_TEST->setSelectionMode(QAbstractItemView::SingleSelection);					// 단일 선택만 가능

	// progress bar
	ui.progressBar->setRange(0, 100);
	ui.progressBar->setValue(0);

	// custom plot
	SetCustomPlot(100);

	// edit
	ui.EDIT_train_batchsize->setText("8");
	ui.EDIT_train_epoch->setText("100");
	ui.EDIT_train_batchsize->setStyleSheet(BACK_COLOR_1);
	ui.EDIT_train_epoch->setStyleSheet(BACK_COLOR_1);
	ui.EDIT_Label_brushSize->setStyleSheet(BACK_COLOR_1);

	// viewer
	ui.Label_viewer->SetParent(this);
	ui.Label_viewer->setFocus();

	// tree widget
	ui.treeWidget->setStyleSheet(BACK_COLOR_1);
	ui.treeWidget->setStyleSheet("QHeaderView::section {background-color:rgb(63,63,70);color: white;};");
	ui.treeWidget->expandAll();
	ui.treeWidget->setColumnWidth(0, 180);

	// 초기 세팅
	SetWorkWindow(eDATA_WND);
	ui.RBTN_both->setChecked(true);
	ui.EDIT_Label_brushSize->setText("20");

	return;
}

void QSeg::SetWorkWindow(eWORK_WND eWork) {
	ui.w_Work->setCurrentIndex(eWork);
	m_iWorkWnd = eWork;
	switch (eWork) {
		case eDATA_WND: {
			ui.BTN_menu_data->setStyleSheet(COLOR_SELECT_BTN);
			ui.BTN_menu_train->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_label->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_test->setStyleSheet(BACK_COLOR_2);
			break;
		}
		case eTRAIN_WND: {
			ui.BTN_menu_data->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_train->setStyleSheet(COLOR_SELECT_BTN);
			ui.BTN_menu_label->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_test->setStyleSheet(BACK_COLOR_2);
			break;
		}
		case eLABEL_WND: {
			ui.BTN_menu_data->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_train->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_label->setStyleSheet(COLOR_SELECT_BTN);
			ui.BTN_menu_test->setStyleSheet(BACK_COLOR_2);
			break;
		}
		case eTEST_WND: {
			ui.BTN_menu_data->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_train->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_label->setStyleSheet(BACK_COLOR_2);
			ui.BTN_menu_test->setStyleSheet(COLOR_SELECT_BTN);
			break;
		}
	}
}

void QSeg::SetLineEdit(QString str, QLineEdit* edit) {
	edit->setText(str);
}

void QSeg::ShowImage(QLabel& viewer, QString strPath, cv::Mat& _image) {
	cv::Mat image = cv::imread(strPath.toStdString());
	if (image.empty())
		return;

	_image = image.clone();

	QImage qimage = MatToQImage(image);
	QPixmap pixmap = QPixmap::fromImage(qimage);

	viewer.setPixmap(pixmap.scaled(viewer.size(), Qt::KeepAspectRatio));

	QString strWidth = QString::number(image.cols);
	QString strHeight = QString::number(image.rows);
	QString strChannel = QString::number(image.channels());

	ui.EDIT_Info_width->setText(strWidth);
	ui.EDIT_Info_height->setText(strHeight);
	ui.EDIT_Info_channel->setText(strChannel);

	return;
}

void QSeg::ShowImage(QLabel& viewer, cv::Mat image) {
	if (image.type() == CV_32FC1) {
		image.convertTo(image, CV_8UC1, 255, 0);
	}
	else if (image.type() == CV_32FC3) {
		image.convertTo(image, CV_8UC3, 255, 0);
	}

	QImage qimage = MatToQImage(image);
	QPixmap pixmap = QPixmap::fromImage(qimage);

	viewer.setPixmap(pixmap.scaled(viewer.size(), Qt::KeepAspectRatio));

	QString strWidth = QString::number(image.cols);
	QString strHeight = QString::number(image.rows);
	QString strChannel = QString::number(image.channels());

	ui.EDIT_Info_width->setText(strWidth);
	ui.EDIT_Info_height->setText(strHeight);
	ui.EDIT_Info_channel->setText(strChannel);

	return;
}

void QSeg::SetDataTable(QString strPath) {
	std::vector<QString> image_paths;
	SearchDirectory(strPath, image_paths);

	if (image_paths.empty())
		return;

	// clear member path(train, val)
	m_strTrainPath.clear();
	m_strValPath.clear();

	// copy
	m_strPaths.assign(image_paths.begin(), image_paths.end());

	int iCount = image_paths.size();
	int iTrain = 0;
	int iVal = 0;

	// set rows 0 = row clear
	ui.TABLE_DATA->setRowCount(0);

	for (int i = 0; i < iCount; i++) {
		ui.TABLE_DATA->insertRow(i);

		QString path = image_paths[i];
		QStringList strList = path.split("/");

		QString strNum = QString::number(i + 1);
		QString strName = strList.last();
		QString strClass = strList[strList.size() - 3];

		if (strClass == "train" || strClass == "Train") {
			iTrain++;
			if (m_strTrainPath.isEmpty())
				m_strTrainPath = strPath + "/" + strClass;
		}
		else if (strClass == "val" || strClass == "Val") {
			iVal++;
			if (m_strValPath.isEmpty())
				m_strValPath = strPath + "/" + strClass;
		}

		QTableWidgetItem* item_num = new QTableWidgetItem(strNum);
		QTableWidgetItem* item_name = new QTableWidgetItem(strName);
		QTableWidgetItem* item_class = new QTableWidgetItem(strClass);

		ui.TABLE_DATA->setItem(i, 0, item_num);
		ui.TABLE_DATA->setItem(i, 1, item_name);
		ui.TABLE_DATA->setItem(i, 2, item_class);
	}

	// 부가적으로 Table 위에 숫자 표시
	ui.label_all->setText(QString::number(iCount));
	ui.label_train->setText(QString::number(iTrain));
	ui.label_val->setText(QString::number(iVal));

	return;
}

void QSeg::SetLabelTable(QString strPath) {
	std::vector<QString> image_paths;
	SearchDirectory(strPath, image_paths);

	if (image_paths.empty())
		return;

	// copy
	m_strLabelPaths.assign(image_paths.begin(), image_paths.end());

	// set rows 0 = row clear
	ui.TABLE_LABEL->setRowCount(0);

	int iCount = image_paths.size();
	for (int i = 0; i < iCount; i++) {
		ui.TABLE_LABEL->insertRow(i);

		QString path = image_paths[i];
		QStringList strList = path.split("/");

		QString strNum = QString::number(i + 1);
		QString strName = strList.last();

		QTableWidgetItem* item_num = new QTableWidgetItem(strNum);
		QTableWidgetItem* item_name = new QTableWidgetItem(strName);

		ui.TABLE_LABEL->setItem(i, 0, item_num);
		ui.TABLE_LABEL->setItem(i, 1, item_name);
	}

	return;
}

void QSeg::SetTestTable(QString strPath) {
	std::vector<QString> image_paths;
	SearchDirectory(strPath, image_paths);

	if (image_paths.empty())
		return;

	// copy
	m_strTestPaths.assign(image_paths.begin(), image_paths.end());

	// set rows 0 = row clear
	ui.TABLE_TEST->setRowCount(0);

	int iCount = image_paths.size();
	for (int i = 0; i < iCount; i++) {
		ui.TABLE_TEST->insertRow(i);

		QString path = image_paths[i];
		QStringList strList = path.split("/");

		QString strNum = QString::number(i + 1);
		QString strName = strList.last();

		QTableWidgetItem* item_num = new QTableWidgetItem(strNum);
		QTableWidgetItem* item_name = new QTableWidgetItem(strName);

		ui.TABLE_TEST->setItem(i, 0, item_num);
		ui.TABLE_TEST->setItem(i, 1, item_name);
	}

	return;
}

void QSeg::SetProgressBar(int iVal, int iMax) {
	double dRate = 100. / (double)iMax;
	double dVal = dRate * (double)iVal;

	ui.progressBar->setValue((int)dVal);

	return;
}

void QSeg::SetCustomPlot(int epoch) {
	// set color
	QLinearGradient plotGradient;
	plotGradient.setStart(0, 0);
	plotGradient.setFinalStop(0, 350);
	plotGradient.setColorAt(0, QColor(80, 80, 80));
	plotGradient.setColorAt(1, QColor(50, 50, 50));
	ui.customPlot->setBackground(plotGradient);

	ui.customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
	ui.customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
	ui.customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
	ui.customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
	ui.customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
	ui.customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
	ui.customPlot->xAxis->setTickLabelColor(Qt::white);
	ui.customPlot->yAxis->setTickLabelColor(Qt::white);
	ui.customPlot->xAxis->setLabelColor(Qt::white);
	ui.customPlot->yAxis->setLabelColor(Qt::white);
	ui.customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
	ui.customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
	ui.customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
	ui.customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
	ui.customPlot->xAxis->grid()->setSubGridVisible(true);
	ui.customPlot->yAxis->grid()->setSubGridVisible(true);
	ui.customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
	ui.customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);

	// set aixs arrow
	ui.customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
	ui.customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

	// set range
	ui.customPlot->xAxis->setRange(0, epoch);
	ui.customPlot->yAxis->setRange(0, 1);

	ui.customPlot->xAxis->setLabel("Epoch");
	ui.customPlot->yAxis->setLabel("Loss");

	ui.customPlot->clearGraphs();
	ui.customPlot->addGraph();
	ui.customPlot->addGraph();
	ui.customPlot->graph(0)->setName("train loss");
	ui.customPlot->graph(1)->setName("val loss");

	ui.customPlot->legend->setVisible(true);

	ui.customPlot->replot();

	m_loss_values.clear();
	m_loss_values_test.clear();
	return;
}

void QSeg::SetCustomPlotValue(int epoch, double train_loss, double val_loss) {
	ui.customPlot->graph(0)->setPen(QPen(Qt::GlobalColor::green));
	ui.customPlot->graph(0)->setBrush(QBrush(QColor(0, 255, 0, 20)));

	ui.customPlot->graph(1)->setPen(QPen(QColor(255, 127, 39)));
	ui.customPlot->graph(1)->setBrush(QBrush(QColor(255, 127, 39, 20)));
	
	// set value
	QVector<double> xAxis(epoch + 1);
	for (int i = 0; i <= epoch; i++) {
		xAxis[i] = i;
	}
	m_loss_values.push_back(train_loss);
	m_loss_values_test.push_back(val_loss);

	if (m_loss_values.size() == 1) {	
		m_loss_values.push_back(train_loss);
		m_loss_values_test.push_back(val_loss);
		ui.customPlot->yAxis->setRange(0, train_loss);
	}

	// draw
	ui.customPlot->graph(0)->setData(xAxis, m_loss_values);
	ui.customPlot->graph(1)->setData(xAxis, m_loss_values_test);
	ui.customPlot->replot();

	return;
}

void QSeg::TrainStart() {
	// Train parameters
	int iEpoch = ui.EDIT_train_epoch->text().toInt();
	int iBatchSized = ui.EDIT_train_batchsize->text().toInt();
	m_pTrainer->SetParameter(iEpoch, iBatchSized);

	// epoch에 맞춰서 plot
	SetCustomPlot(iEpoch);
	SetProgressBar(0, 100);

	// 실질적인 Train 부분 (Trainer::Train())
	m_pTrainer->SetTrainPath(m_strTrainPath, m_strValPath, m_strBackupPath);
	m_pTrainer->start();

	// button change
	ui.BTN_train_train->setStyleSheet("background-color:rgb(255,0,0);");
	ui.BTN_train_train->setText("Train Stop");

	return;
}

void QSeg::TrainStop() {
	m_pTrainer->m_bTraining = false;
	ui.BTN_train_train->setStyleSheet(BACK_COLOR_2);
	ui.BTN_train_train->setText("Train");

	return;
}

void QSeg::EditFinished() {
	QString strBrushSize = ui.EDIT_Label_brushSize->text();
	ui.Label_viewer->SetBrushSize(strBrushSize.toInt());
	return;
}

void QSeg::ButtonClicked() {
	QObject* button = QObject::sender();        // SIGNAL 발생 시킨 QObject를 받아옴.
	if (!button)
		return;

	if (button == ui.BTN_menu_data)				SetWorkWindow(eDATA_WND);
	else if (button == ui.BTN_menu_train)		SetWorkWindow(eTRAIN_WND);
	else if (button == ui.BTN_menu_label)		SetWorkWindow(eLABEL_WND);
	else if (button == ui.BTN_menu_test)		SetWorkWindow(eTEST_WND);
	else if (button == ui.BTN_load_dataset) {
		if (GetFilePath("Load Data", m_strLoadPath)) {
			SetLineEdit(m_strLoadPath, ui.EDIT_load_dataset);
			SetDataTable(m_strLoadPath);
		}
	}
	else if (button == ui.BTN_Label_loaddata) {
		if (GetFilePath("Label Data", m_strLabelPath)) {
			SetLineEdit(m_strLabelPath, ui.EDIT_Label_imagepath);
			SetLabelTable(m_strLabelPath);
		}
	}
	else if (button == ui.BTN_path_backup) {
		if (GetFilePath("Backup Path", m_strBackupPath)) {
			SetLineEdit(m_strBackupPath, ui.EDIT_path_backup);
			SetLineEdit(m_strBackupPath, ui.EDIT_train_backuppath);
		}
	}
	else if (button == ui.BTN_Test_loaddata) {
		if (GetFilePath("Test Data", m_strTestPath)) {
			SetLineEdit(m_strTestPath, ui.EDIT_Test_loaddata);
			SetTestTable(m_strTestPath);
		}
	}
	else if (button == ui.BTN_Test_modelpath) {
		if (GetFilePath("Load Model", m_strModelPath, true)) {
			SetLineEdit(m_strModelPath, ui.EDIT_Test_modelpath);
			// load model
			QMessageBox msgBox;
			if (m_pTrainer->LoadModel(m_strModelPath.toStdString())) {
				msgBox.setText("Load Complete");
			}
			else {
				msgBox.setText("Load Complete");
			}
			msgBox.exec();
		}
	}
	else if (button == ui.BTN_train_backuppath) {
		if (!m_strBackupPath.isEmpty())
			QDesktopServices::openUrl(QUrl::fromLocalFile(m_strBackupPath + "/"));
	}
	else if (button == ui.BTN_train_train) {
		if (m_strTrainPath.isEmpty() || m_strValPath.isEmpty() || m_strBackupPath.isEmpty()) {
			QMessageBox msgBox;
			msgBox.setText("Data path error.");
			msgBox.exec();
			return;
		}

		if (!m_pTrainer->m_bTraining) {
			TrainStart();
		}
		else {
			TrainStop();
		}
	}
	else if (button == ui.BTN_label_masking) {
		Masking();
	}
	else if (button == ui.BTN_Test_test) {
		if (m_pTrainer && !m_testImage.empty()) {
			if (!m_strModelPath.isEmpty()) {
				cv::Mat testImage = m_pTrainer->TestModel(m_testImage);
				ShowImage(*ui.Test_viewer2, testImage.clone());
			}
		}
	}

	return;
}

void QSeg::Masking() {
	cv::Mat image = ui.Label_viewer->Masking();
	if (image.empty())
		return;

	ShowImage(*ui.Label_viewer2, image);
	if (!m_strCurMaskPath.empty()) {
		image = ui.Label_viewer->GetMaskImage();
		if (!cv::imwrite(m_strCurMaskPath, image)) {
			// 폴더가 존재하지 않으면 생성
			QDir dir;
			QString strPath = QString::fromStdString(m_strCurMaskPath);
			int iIndex = strPath.lastIndexOf('/');
			strPath = strPath.left(iIndex);
			dir.mkpath(strPath);
			cv::imwrite(m_strCurMaskPath, image);
		}
	}
}

void QSeg::RadioClicked() {
	QObject* button = QObject::sender();        // SIGNAL 발생 시킨 QObject를 받아옴.
	if (!button)
		return;

	if (button == ui.RBTN_both) {
		ui.Label_viewer->SetLayer(0);
		ShowImage(*ui.Label_viewer2, ui.Label_viewer->GetLayerImage());
		 
	}
	else if (button == ui.RBTN_mask) {
		ui.Label_viewer->SetLayer(1);
		ShowImage(*ui.Label_viewer2, ui.Label_viewer->GetLayerImage());
		cv::Mat maskImage = ui.Label_viewer->GetMaskImage();
		if (!maskImage.empty()) {
			imwrite(m_strCurMaskPath, maskImage);
		}
	}

	return;
}

QString QSeg::GetMaskPath(QString strPath) {
	// file 이름 분리
	auto strList = strPath.split('/');
	QString strFileName = strList.last();
	int iIndex = strFileName.indexOf('.');
	strFileName = strFileName.left(iIndex);
	strFileName.append("_mask.png");

	// 상위폴더 검색
	iIndex = strPath.indexOf('.');
	QString strTemp = strPath.left(iIndex);
	iIndex = strTemp.lastIndexOf('/');
	strTemp = strTemp.left(iIndex);
	iIndex = strTemp.lastIndexOf('/');
	strTemp = strTemp.left(iIndex);

	strTemp.append("/mask/");
	strTemp.append(strFileName);

	return strTemp;
}

// QTableWidget
void QSeg::ChangedDataTableItem() {
	auto selection = ui.TABLE_DATA->selectionModel()->selectedRows();
	if (selection.size() < 1)
		return;

	int iIndex = selection[0].row();

	QString item = m_strPaths[iIndex];
	ShowImage(*ui.image_viwer, item);

	return;
}

void QSeg::ChangedLabelTableItem() {
	auto selection = ui.TABLE_LABEL->selectionModel()->selectedRows();
	if (selection.size() < 1)
		return;

	int iIndex = selection[0].row();

	QString item = m_strLabelPaths[iIndex];
	cv::Mat image;
	ShowImage(*ui.Label_viewer, item, image);
	ui.Label_viewer->SetImage(image);
	
	m_strCurMaskPath = GetMaskPath(item).toStdString();
	cv::Mat maskImage = cv::imread(m_strCurMaskPath);
	if (!maskImage.empty()) {
		ShowImage(*ui.Label_viewer2, maskImage);
	}
	else {	
		ShowImage(*ui.Label_viewer2, cv::Mat::zeros(10, 10, CV_8UC1));
	}

	return;
}

void QSeg::ChangedTestTableItem() {
	auto selection = ui.TABLE_TEST->selectionModel()->selectedRows();
	if (selection.size() < 1)
		return;

	int iIndex = selection[0].row();

	QString item = m_strTestPaths[iIndex];
	cv::Mat image;
	ShowImage(*ui.Test_viewer, item, image);
	if (!image.empty()) {
		m_testImage = image.clone();
	}
	return;
}

void QSeg::WriteTrainLog(QString strLog) {
	ui.train_log->insertItem(0, strLog);

	return;
}

// keyboard event
void QSeg::keyPressEvent(QKeyEvent* ev) {
	switch (ev->key()) {
		case Qt::Key_Space: {
			if (m_iWorkWnd == eLABEL_WND) {
				Masking();
			}
			break;
		}
		case Qt::Key_Left: 
		case Qt::Key_Up:{
			if (m_iWorkWnd == eLABEL_WND) {
				int index = ui.TABLE_LABEL->currentRow();
				if (index > 0)
					index--;

				QModelIndex newIndex = ui.TABLE_LABEL->model()->index(index, 1);
				ui.TABLE_LABEL->setCurrentIndex(newIndex);
			}
			break;
		}
		case Qt::Key_Right:
		case Qt::Key_Down: {
			if (m_iWorkWnd == eLABEL_WND) {
				int index = ui.TABLE_LABEL->currentRow();
				int maxIndex = ui.TABLE_LABEL->rowCount();
				if (index < maxIndex - 1)
					index++;

				QModelIndex newIndex = ui.TABLE_LABEL->model()->index(index, 1);
				ui.TABLE_LABEL->setCurrentIndex(newIndex);
			}
			break;
		}
	}
	return;
}