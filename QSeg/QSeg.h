#pragma once
#include <QtWidgets/QMainWindow>

#define BACK_COLOR_1        "background-color:rgb(45,45,48);"
#define BACK_COLOR_2        "background-color:rgb(63,63,70);"
#define BACK_COLOR_3        "background-color:rgb(30,30,30);"
#define COLOR_WHITE         "color:rgb(255,255,255);"
#define COLOR_SELECT_BTN    "background-color:rgb(0,122,204);"

using namespace std;
using namespace cv;


enum eWORK_WND {
    eDATA_WND,
    eTRAIN_WND,
    eLABEL_WND,
    eTEST_WND,
    eEND,
};

class Trainer;
class QSeg : public QMainWindow
{
    Q_OBJECT

private slots:
    void ButtonClicked();
    void RadioClicked();
    void ChangedDataTableItem();
    void ChangedLabelTableItem();
    void ChangedTestTableItem();
    void SetProgressBar(int iVal, int iMax);        // iVal : 현재값, iMax : process 목표값
    void SetCustomPlotValue(int epoch, double train_loss, double val_loss);
    void TrainStop();
    void TrainStart();
    void EditFinished();

protected:
    void keyPressEvent(QKeyEvent* ev);


public:
    QSeg(QWidget *parent = Q_NULLPTR);

    void SetUIStyle();
    void WriteTrainLog(QString strLog);
    void ShowImage(QLabel& viewer, QString strPath, cv::Mat& _image = cv::Mat());   // viewer에 image 출력
    void ShowImage(QLabel& viewer, cv::Mat image);


private:
    void SetWorkWindow(eWORK_WND eWork);
    void SetLineEdit(QString str, QLineEdit* edit);
    void SetCustomPlot(int epoch);

    void SetDataTable(QString strPath);             // Set Table
    void SetLabelTable(QString strPath);            // Set Table
    void SetTestTable(QString strPath);             // Set Table
    
    void Masking();
    QString GetMaskPath(QString strPath);
    

    

private:
    Ui::QtGUIClass              ui;
	Trainer*                    m_pTrainer = nullptr;

    std::vector<QString>        m_strPaths;         // 불러오기 한 전체 이미지 경로들
    std::vector<QString>        m_strLabelPaths;    // Labeling Paths
    std::vector<QString>        m_strTestPaths;     // Labeling Paths

    QVector<double>             m_loss_values;      // ploting할 loss value(train)
    QVector<double>             m_loss_values_test; // ploting할 loss value(test)

    QString                     m_strTrainPath;     // train 경로
    QString                     m_strValPath;       // val 경로
    QString                     m_strLoadPath;      // dataset 상위 경로
    QString                     m_strBackupPath;    // 모델 저장 경로
    QString                     m_strLabelPath;     // Labeling 경로
    QString                     m_strTestPath;      // test dataset 경로
    QString                     m_strModelPath;     // 불러온 model 경로

    std::string                 m_strCurMaskPath;   // 현재 선택중인 List의 Mask Path

    cv::Mat                     m_testImage;        // Predict image

    int                         m_iWorkWnd;
};
