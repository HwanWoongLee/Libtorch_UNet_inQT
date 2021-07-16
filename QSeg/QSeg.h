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
    void SetProgressBar(int iVal, int iMax);        // iVal : ���簪, iMax : process ��ǥ��
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
    void ShowImage(QLabel& viewer, QString strPath, cv::Mat& _image = cv::Mat());   // viewer�� image ���
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

    std::vector<QString>        m_strPaths;         // �ҷ����� �� ��ü �̹��� ��ε�
    std::vector<QString>        m_strLabelPaths;    // Labeling Paths
    std::vector<QString>        m_strTestPaths;     // Labeling Paths

    QVector<double>             m_loss_values;      // ploting�� loss value(train)
    QVector<double>             m_loss_values_test; // ploting�� loss value(test)

    QString                     m_strTrainPath;     // train ���
    QString                     m_strValPath;       // val ���
    QString                     m_strLoadPath;      // dataset ���� ���
    QString                     m_strBackupPath;    // �� ���� ���
    QString                     m_strLabelPath;     // Labeling ���
    QString                     m_strTestPath;      // test dataset ���
    QString                     m_strModelPath;     // �ҷ��� model ���

    std::string                 m_strCurMaskPath;   // ���� �������� List�� Mask Path

    cv::Mat                     m_testImage;        // Predict image

    int                         m_iWorkWnd;
};
