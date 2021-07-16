/********************************************************************************
** Form generated from reading UI file 'QSeg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSEG_H
#define UI_QSEG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QDrawLabel.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_QtGUIClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *w_Menu;
    QVBoxLayout *verticalLayout;
    QPushButton *BTN_menu_data;
    QPushButton *BTN_menu_train;
    QPushButton *BTN_menu_label;
    QPushButton *BTN_menu_test;
    QSpacerItem *verticalSpacer;
    QWidget *w_Background;
    QGridLayout *gridLayout_6;
    QStackedWidget *w_Work;
    QWidget *page_data;
    QHBoxLayout *horizontalLayout_2;
    QWidget *w_Temp;
    QVBoxLayout *verticalLayout_2;
    QWidget *w_Param;
    QGridLayout *gridLayout_2;
    QPushButton *BTN_load_dataset;
    QLineEdit *EDIT_load_dataset;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *EDIT_path_backup;
    QPushButton *BTN_path_backup;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *w_DataInfo;
    QGridLayout *gridLayout_3;
    QLabel *label_all;
    QLabel *label_train;
    QLabel *label_val;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTableWidget *TABLE_DATA;
    QLabel *image_viwer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QWidget *w_Info;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *EDIT_Info_width;
    QLabel *label_2;
    QLineEdit *EDIT_Info_height;
    QLabel *label_3;
    QLineEdit *EDIT_Info_channel;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_train;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QWidget *w_Train_pram;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_7;
    QLineEdit *EDIT_train_backuppath;
    QPushButton *BTN_train_backuppath;
    QLineEdit *EDIT_train_batchsize;
    QLineEdit *EDIT_train_epoch;
    QWidget *widget_3;
    QFormLayout *formLayout_2;
    QSpacerItem *verticalSpacer_9;
    QPushButton *BTN_train_train;
    QWidget *widget_train_work;
    QGridLayout *gridLayout_4;
    QProgressBar *progressBar;
    QCustomPlot *customPlot;
    QListWidget *train_log;
    QWidget *page_label;
    QGridLayout *gridLayout_11;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_6;
    QWidget *w_Label_pram;
    QGridLayout *gridLayout_10;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_15;
    QPushButton *BTN_Label_loaddata;
    QLineEdit *EDIT_Label_imagepath;
    QLabel *label_16;
    QLineEdit *EDIT_Label_brushSize;
    QPushButton *BTN_label_masking;
    QTableWidget *TABLE_LABEL;
    QWidget *w_Label_work;
    QGridLayout *gridLayout_7;
    QDrawLabel *Label_viewer2;
    QWidget *widget_7;
    QGridLayout *gridLayout_13;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *SENSOR_background;
    QLabel *label_11;
    QPushButton *SENSOR_object;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer;
    QRadioButton *RBTN_both;
    QRadioButton *RBTN_mask;
    QDrawLabel *Label_viewer;
    QTreeWidget *treeWidget;
    QWidget *page_test;
    QGridLayout *gridLayout_8;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_7;
    QWidget *w_Test;
    QGridLayout *gridLayout_12;
    QLabel *label_17;
    QLineEdit *EDIT_Test_modelpath;
    QPushButton *BTN_Test_modelpath;
    QPushButton *BTN_Test_loaddata;
    QLabel *label_18;
    QLineEdit *EDIT_Test_loaddata;
    QSpacerItem *verticalSpacer_7;
    QPushButton *BTN_Test_test;
    QTableWidget *TABLE_TEST;
    QWidget *w_Test_work;
    QGridLayout *gridLayout_9;
    QLabel *Test_viewer2;
    QLabel *Test_viewer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGUIClass)
    {
        if (QtGUIClass->objectName().isEmpty())
            QtGUIClass->setObjectName(QString::fromUtf8("QtGUIClass"));
        QtGUIClass->resize(1610, 972);
        QtGUIClass->setMinimumSize(QSize(1000, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QtGUIClass->setWindowIcon(icon);
        centralWidget = new QWidget(QtGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(6, 0, 6, 0);
        w_Menu = new QWidget(centralWidget);
        w_Menu->setObjectName(QString::fromUtf8("w_Menu"));
        w_Menu->setMinimumSize(QSize(90, 0));
        w_Menu->setMaximumSize(QSize(90, 16777215));
        verticalLayout = new QVBoxLayout(w_Menu);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        BTN_menu_data = new QPushButton(w_Menu);
        BTN_menu_data->setObjectName(QString::fromUtf8("BTN_menu_data"));
        BTN_menu_data->setMinimumSize(QSize(0, 90));
        BTN_menu_data->setMaximumSize(QSize(16777215, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        BTN_menu_data->setFont(font);
        BTN_menu_data->setFocusPolicy(Qt::NoFocus);
        BTN_menu_data->setAutoDefault(false);
        BTN_menu_data->setFlat(false);

        verticalLayout->addWidget(BTN_menu_data);

        BTN_menu_train = new QPushButton(w_Menu);
        BTN_menu_train->setObjectName(QString::fromUtf8("BTN_menu_train"));
        BTN_menu_train->setMinimumSize(QSize(0, 90));
        BTN_menu_train->setMaximumSize(QSize(16777215, 80));
        BTN_menu_train->setFont(font);
        BTN_menu_train->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(BTN_menu_train);

        BTN_menu_label = new QPushButton(w_Menu);
        BTN_menu_label->setObjectName(QString::fromUtf8("BTN_menu_label"));
        BTN_menu_label->setMinimumSize(QSize(0, 90));
        BTN_menu_label->setMaximumSize(QSize(16777215, 80));
        BTN_menu_label->setFont(font);
        BTN_menu_label->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(BTN_menu_label);

        BTN_menu_test = new QPushButton(w_Menu);
        BTN_menu_test->setObjectName(QString::fromUtf8("BTN_menu_test"));
        BTN_menu_test->setMinimumSize(QSize(0, 90));
        BTN_menu_test->setMaximumSize(QSize(16777215, 80));
        BTN_menu_test->setFont(font);
        BTN_menu_test->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(BTN_menu_test);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(w_Menu, 1, 0, 1, 1);

        w_Background = new QWidget(centralWidget);
        w_Background->setObjectName(QString::fromUtf8("w_Background"));
        gridLayout_6 = new QGridLayout(w_Background);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(3, 0, 0, 0);
        w_Work = new QStackedWidget(w_Background);
        w_Work->setObjectName(QString::fromUtf8("w_Work"));
        w_Work->setFrameShape(QFrame::NoFrame);
        w_Work->setFrameShadow(QFrame::Plain);
        w_Work->setLineWidth(10);
        w_Work->setMidLineWidth(10);
        page_data = new QWidget();
        page_data->setObjectName(QString::fromUtf8("page_data"));
        horizontalLayout_2 = new QHBoxLayout(page_data);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 6, 0, 6);
        w_Temp = new QWidget(page_data);
        w_Temp->setObjectName(QString::fromUtf8("w_Temp"));
        w_Temp->setMinimumSize(QSize(350, 0));
        w_Temp->setMaximumSize(QSize(300, 10000));
        verticalLayout_2 = new QVBoxLayout(w_Temp);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        w_Param = new QWidget(w_Temp);
        w_Param->setObjectName(QString::fromUtf8("w_Param"));
        w_Param->setMinimumSize(QSize(0, 50));
        w_Param->setMaximumSize(QSize(16777215, 100));
        gridLayout_2 = new QGridLayout(w_Param);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        BTN_load_dataset = new QPushButton(w_Param);
        BTN_load_dataset->setObjectName(QString::fromUtf8("BTN_load_dataset"));
        BTN_load_dataset->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(BTN_load_dataset, 0, 2, 1, 1);

        EDIT_load_dataset = new QLineEdit(w_Param);
        EDIT_load_dataset->setObjectName(QString::fromUtf8("EDIT_load_dataset"));
        EDIT_load_dataset->setMinimumSize(QSize(0, 0));
        EDIT_load_dataset->setReadOnly(true);

        gridLayout_2->addWidget(EDIT_load_dataset, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        EDIT_path_backup = new QLineEdit(w_Param);
        EDIT_path_backup->setObjectName(QString::fromUtf8("EDIT_path_backup"));
        EDIT_path_backup->setMinimumSize(QSize(0, 0));
        EDIT_path_backup->setContextMenuPolicy(Qt::DefaultContextMenu);
        EDIT_path_backup->setReadOnly(true);

        gridLayout_2->addWidget(EDIT_path_backup, 1, 1, 1, 1);

        BTN_path_backup = new QPushButton(w_Param);
        BTN_path_backup->setObjectName(QString::fromUtf8("BTN_path_backup"));
        BTN_path_backup->setMaximumSize(QSize(30, 16777215));

        gridLayout_2->addWidget(BTN_path_backup, 1, 2, 1, 1);

        label_13 = new QLabel(w_Param);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        label_14 = new QLabel(w_Param);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 1, 0, 1, 1);


        verticalLayout_2->addWidget(w_Param);

        w_DataInfo = new QWidget(w_Temp);
        w_DataInfo->setObjectName(QString::fromUtf8("w_DataInfo"));
        w_DataInfo->setMinimumSize(QSize(0, 60));
        gridLayout_3 = new QGridLayout(w_DataInfo);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_all = new QLabel(w_DataInfo);
        label_all->setObjectName(QString::fromUtf8("label_all"));
        label_all->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_all, 0, 0, 1, 1);

        label_train = new QLabel(w_DataInfo);
        label_train->setObjectName(QString::fromUtf8("label_train"));
        label_train->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_train, 0, 1, 1, 1);

        label_val = new QLabel(w_DataInfo);
        label_val->setObjectName(QString::fromUtf8("label_val"));
        label_val->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_val, 0, 2, 1, 1);

        label_4 = new QLabel(w_DataInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(w_DataInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 1, 1, 1, 1);

        label_6 = new QLabel(w_DataInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_6, 1, 2, 1, 1);


        verticalLayout_2->addWidget(w_DataInfo);

        TABLE_DATA = new QTableWidget(w_Temp);
        if (TABLE_DATA->columnCount() < 3)
            TABLE_DATA->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TABLE_DATA->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TABLE_DATA->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TABLE_DATA->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        TABLE_DATA->setObjectName(QString::fromUtf8("TABLE_DATA"));
        TABLE_DATA->setMaximumSize(QSize(16777215, 10000));
        TABLE_DATA->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TABLE_DATA->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(TABLE_DATA);


        horizontalLayout_2->addWidget(w_Temp);

        image_viwer = new QLabel(page_data);
        image_viwer->setObjectName(QString::fromUtf8("image_viwer"));
        image_viwer->setMinimumSize(QSize(300, 0));
        image_viwer->setFrameShape(QFrame::Panel);
        image_viwer->setFrameShadow(QFrame::Plain);
        image_viwer->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(image_viwer);

        widget = new QWidget(page_data);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(300, 0));
        widget->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        w_Info = new QWidget(widget);
        w_Info->setObjectName(QString::fromUtf8("w_Info"));
        w_Info->setMinimumSize(QSize(0, 200));
        w_Info->setMaximumSize(QSize(10000, 320));
        formLayout = new QFormLayout(w_Info);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(w_Info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        EDIT_Info_width = new QLineEdit(w_Info);
        EDIT_Info_width->setObjectName(QString::fromUtf8("EDIT_Info_width"));
        EDIT_Info_width->setMinimumSize(QSize(0, 0));
        EDIT_Info_width->setMaximumSize(QSize(10000, 16777215));
        EDIT_Info_width->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_Info_width->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, EDIT_Info_width);

        label_2 = new QLabel(w_Info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));
        label_2->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        EDIT_Info_height = new QLineEdit(w_Info);
        EDIT_Info_height->setObjectName(QString::fromUtf8("EDIT_Info_height"));
        EDIT_Info_height->setMinimumSize(QSize(0, 0));
        EDIT_Info_height->setMaximumSize(QSize(10000, 16777215));
        EDIT_Info_height->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_Info_height->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, EDIT_Info_height);

        label_3 = new QLabel(w_Info);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(100, 0));
        label_3->setMaximumSize(QSize(100, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        EDIT_Info_channel = new QLineEdit(w_Info);
        EDIT_Info_channel->setObjectName(QString::fromUtf8("EDIT_Info_channel"));
        EDIT_Info_channel->setMinimumSize(QSize(0, 0));
        EDIT_Info_channel->setMaximumSize(QSize(10000, 16777215));
        EDIT_Info_channel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_Info_channel->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, EDIT_Info_channel);


        verticalLayout_3->addWidget(w_Info);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_2->addWidget(widget);

        w_Work->addWidget(page_data);
        page_train = new QWidget();
        page_train->setObjectName(QString::fromUtf8("page_train"));
        horizontalLayout = new QHBoxLayout(page_train);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 6, 0, 6);
        widget_2 = new QWidget(page_train);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(350, 16777215));
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        w_Train_pram = new QWidget(widget_2);
        w_Train_pram->setObjectName(QString::fromUtf8("w_Train_pram"));
        w_Train_pram->setMinimumSize(QSize(350, 150));
        w_Train_pram->setMaximumSize(QSize(350, 150));
        gridLayout_5 = new QGridLayout(w_Train_pram);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_9 = new QLabel(w_Train_pram);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        label_8 = new QLabel(w_Train_pram);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_8, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 3, 1, 1, 1);

        label_7 = new QLabel(w_Train_pram);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));

        gridLayout_5->addWidget(label_7, 0, 0, 1, 1);

        EDIT_train_backuppath = new QLineEdit(w_Train_pram);
        EDIT_train_backuppath->setObjectName(QString::fromUtf8("EDIT_train_backuppath"));
        EDIT_train_backuppath->setFrame(true);
        EDIT_train_backuppath->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        EDIT_train_backuppath->setReadOnly(true);

        gridLayout_5->addWidget(EDIT_train_backuppath, 2, 1, 1, 1);

        BTN_train_backuppath = new QPushButton(w_Train_pram);
        BTN_train_backuppath->setObjectName(QString::fromUtf8("BTN_train_backuppath"));
        BTN_train_backuppath->setMaximumSize(QSize(40, 16777215));

        gridLayout_5->addWidget(BTN_train_backuppath, 2, 2, 1, 1);

        EDIT_train_batchsize = new QLineEdit(w_Train_pram);
        EDIT_train_batchsize->setObjectName(QString::fromUtf8("EDIT_train_batchsize"));
        EDIT_train_batchsize->setMinimumSize(QSize(0, 0));
        EDIT_train_batchsize->setFrame(true);
        EDIT_train_batchsize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_train_batchsize->setReadOnly(false);

        gridLayout_5->addWidget(EDIT_train_batchsize, 1, 1, 1, 2);

        EDIT_train_epoch = new QLineEdit(w_Train_pram);
        EDIT_train_epoch->setObjectName(QString::fromUtf8("EDIT_train_epoch"));
        EDIT_train_epoch->setFrame(true);
        EDIT_train_epoch->setEchoMode(QLineEdit::Normal);
        EDIT_train_epoch->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_train_epoch->setReadOnly(false);

        gridLayout_5->addWidget(EDIT_train_epoch, 0, 1, 1, 2);


        verticalLayout_4->addWidget(w_Train_pram);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        formLayout_2 = new QFormLayout(widget_3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::LabelRole, verticalSpacer_9);

        BTN_train_train = new QPushButton(widget_3);
        BTN_train_train->setObjectName(QString::fromUtf8("BTN_train_train"));
        BTN_train_train->setMinimumSize(QSize(0, 50));
        BTN_train_train->setMaximumSize(QSize(16777215, 16777215));

        formLayout_2->setWidget(0, QFormLayout::SpanningRole, BTN_train_train);


        verticalLayout_4->addWidget(widget_3);


        horizontalLayout->addWidget(widget_2);

        widget_train_work = new QWidget(page_train);
        widget_train_work->setObjectName(QString::fromUtf8("widget_train_work"));
        gridLayout_4 = new QGridLayout(widget_train_work);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(widget_train_work);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_4->addWidget(progressBar, 0, 0, 1, 1);

        customPlot = new QCustomPlot(widget_train_work);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setMinimumSize(QSize(0, 400));

        gridLayout_4->addWidget(customPlot, 1, 0, 1, 2);

        train_log = new QListWidget(widget_train_work);
        train_log->setObjectName(QString::fromUtf8("train_log"));
        train_log->setMaximumSize(QSize(16777215, 300));

        gridLayout_4->addWidget(train_log, 2, 0, 1, 2);


        horizontalLayout->addWidget(widget_train_work);

        w_Work->addWidget(page_train);
        page_label = new QWidget();
        page_label->setObjectName(QString::fromUtf8("page_label"));
        gridLayout_11 = new QGridLayout(page_label);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(3, 6, 0, 6);
        widget_4 = new QWidget(page_label);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 0));
        widget_4->setMaximumSize(QSize(350, 16777215));
        verticalLayout_6 = new QVBoxLayout(widget_4);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        w_Label_pram = new QWidget(widget_4);
        w_Label_pram->setObjectName(QString::fromUtf8("w_Label_pram"));
        w_Label_pram->setMinimumSize(QSize(350, 150));
        w_Label_pram->setMaximumSize(QSize(350, 150));
        gridLayout_10 = new QGridLayout(w_Label_pram);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(9, 9, 9, 9);
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_6, 2, 0, 1, 1);

        label_15 = new QLabel(w_Label_pram);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(100, 0));

        gridLayout_10->addWidget(label_15, 0, 0, 1, 1);

        BTN_Label_loaddata = new QPushButton(w_Label_pram);
        BTN_Label_loaddata->setObjectName(QString::fromUtf8("BTN_Label_loaddata"));
        BTN_Label_loaddata->setMaximumSize(QSize(30, 16777215));
        BTN_Label_loaddata->setFocusPolicy(Qt::NoFocus);

        gridLayout_10->addWidget(BTN_Label_loaddata, 0, 3, 1, 1);

        EDIT_Label_imagepath = new QLineEdit(w_Label_pram);
        EDIT_Label_imagepath->setObjectName(QString::fromUtf8("EDIT_Label_imagepath"));
        EDIT_Label_imagepath->setFrame(true);
        EDIT_Label_imagepath->setEchoMode(QLineEdit::Normal);
        EDIT_Label_imagepath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_Label_imagepath->setReadOnly(true);

        gridLayout_10->addWidget(EDIT_Label_imagepath, 0, 1, 1, 2);

        label_16 = new QLabel(w_Label_pram);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(100, 0));

        gridLayout_10->addWidget(label_16, 1, 0, 1, 1);

        EDIT_Label_brushSize = new QLineEdit(w_Label_pram);
        EDIT_Label_brushSize->setObjectName(QString::fromUtf8("EDIT_Label_brushSize"));
        EDIT_Label_brushSize->setFrame(true);
        EDIT_Label_brushSize->setEchoMode(QLineEdit::Normal);
        EDIT_Label_brushSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        EDIT_Label_brushSize->setReadOnly(false);

        gridLayout_10->addWidget(EDIT_Label_brushSize, 1, 1, 1, 3);


        verticalLayout_6->addWidget(w_Label_pram);

        BTN_label_masking = new QPushButton(widget_4);
        BTN_label_masking->setObjectName(QString::fromUtf8("BTN_label_masking"));
        BTN_label_masking->setMinimumSize(QSize(0, 50));
        BTN_label_masking->setFocusPolicy(Qt::NoFocus);

        verticalLayout_6->addWidget(BTN_label_masking);

        TABLE_LABEL = new QTableWidget(widget_4);
        if (TABLE_LABEL->columnCount() < 2)
            TABLE_LABEL->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TABLE_LABEL->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TABLE_LABEL->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        TABLE_LABEL->setObjectName(QString::fromUtf8("TABLE_LABEL"));
        TABLE_LABEL->setFocusPolicy(Qt::NoFocus);
        TABLE_LABEL->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_6->addWidget(TABLE_LABEL);


        gridLayout_11->addWidget(widget_4, 1, 0, 1, 1);

        w_Label_work = new QWidget(page_label);
        w_Label_work->setObjectName(QString::fromUtf8("w_Label_work"));
        gridLayout_7 = new QGridLayout(w_Label_work);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        Label_viewer2 = new QDrawLabel(w_Label_work);
        Label_viewer2->setObjectName(QString::fromUtf8("Label_viewer2"));
        Label_viewer2->setMinimumSize(QSize(500, 500));
        Label_viewer2->setMaximumSize(QSize(500, 500));
        Label_viewer2->setFrameShape(QFrame::Panel);
        Label_viewer2->setFrameShadow(QFrame::Plain);
        Label_viewer2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Label_viewer2, 1, 1, 1, 1);

        widget_7 = new QWidget(w_Label_work);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setMinimumSize(QSize(0, 30));
        widget_7->setMaximumSize(QSize(500, 16777215));
        gridLayout_13 = new QGridLayout(widget_7);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setHorizontalSpacing(6);
        gridLayout_13->setContentsMargins(-1, 0, 9, 0);
        label_12 = new QLabel(widget_7);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(100, 0));
        label_12->setMaximumSize(QSize(100, 16777215));

        gridLayout_13->addWidget(label_12, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        SENSOR_background = new QPushButton(widget_7);
        SENSOR_background->setObjectName(QString::fromUtf8("SENSOR_background"));
        SENSOR_background->setEnabled(false);
        SENSOR_background->setMinimumSize(QSize(20, 20));
        SENSOR_background->setMaximumSize(QSize(20, 20));
        QFont font1;
        font1.setStrikeOut(false);
        SENSOR_background->setFont(font1);
        SENSOR_background->setFocusPolicy(Qt::NoFocus);
        SENSOR_background->setContextMenuPolicy(Qt::NoContextMenu);
        SENSOR_background->setCheckable(false);
        SENSOR_background->setAutoDefault(false);

        gridLayout_13->addWidget(SENSOR_background, 2, 0, 1, 1);

        label_11 = new QLabel(widget_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(100, 0));
        label_11->setMaximumSize(QSize(100, 16777215));

        gridLayout_13->addWidget(label_11, 2, 1, 1, 1);

        SENSOR_object = new QPushButton(widget_7);
        SENSOR_object->setObjectName(QString::fromUtf8("SENSOR_object"));
        SENSOR_object->setEnabled(false);
        SENSOR_object->setMinimumSize(QSize(20, 20));
        SENSOR_object->setMaximumSize(QSize(20, 20));
        SENSOR_object->setFont(font1);
        SENSOR_object->setFocusPolicy(Qt::NoFocus);
        SENSOR_object->setContextMenuPolicy(Qt::NoContextMenu);
        SENSOR_object->setCheckable(false);
        SENSOR_object->setAutoDefault(false);
        SENSOR_object->setFlat(false);

        gridLayout_13->addWidget(SENSOR_object, 1, 0, 1, 1);


        gridLayout_7->addWidget(widget_7, 2, 1, 2, 1);

        widget_5 = new QWidget(w_Label_work);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMaximumSize(QSize(500, 30));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_10 = new QLabel(widget_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_10->setFont(font2);

        horizontalLayout_3->addWidget(label_10);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        RBTN_both = new QRadioButton(widget_5);
        RBTN_both->setObjectName(QString::fromUtf8("RBTN_both"));
        RBTN_both->setMaximumSize(QSize(80, 16777215));
        RBTN_both->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(RBTN_both);

        RBTN_mask = new QRadioButton(widget_5);
        RBTN_mask->setObjectName(QString::fromUtf8("RBTN_mask"));
        RBTN_mask->setMaximumSize(QSize(80, 16777215));
        RBTN_mask->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(RBTN_mask);


        gridLayout_7->addWidget(widget_5, 0, 1, 1, 1);

        Label_viewer = new QDrawLabel(w_Label_work);
        Label_viewer->setObjectName(QString::fromUtf8("Label_viewer"));
        Label_viewer->setMinimumSize(QSize(500, 500));
        Label_viewer->setMaximumSize(QSize(16777215, 16777215));
        Label_viewer->setFrameShape(QFrame::Panel);
        Label_viewer->setFrameShadow(QFrame::Plain);
        Label_viewer->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(Label_viewer, 0, 0, 10, 1);

        treeWidget = new QTreeWidget(w_Label_work);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(500, 200));
        treeWidget->setFocusPolicy(Qt::NoFocus);
        treeWidget->setStyleSheet(QString::fromUtf8(""));
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setCascadingSectionResizes(false);
        treeWidget->header()->setDefaultSectionSize(150);
        treeWidget->header()->setHighlightSections(false);

        gridLayout_7->addWidget(treeWidget, 9, 1, 1, 1);


        gridLayout_11->addWidget(w_Label_work, 1, 1, 1, 1);

        w_Work->addWidget(page_label);
        page_test = new QWidget();
        page_test->setObjectName(QString::fromUtf8("page_test"));
        gridLayout_8 = new QGridLayout(page_test);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 6, 0, 6);
        widget_6 = new QWidget(page_test);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setMinimumSize(QSize(0, 0));
        widget_6->setMaximumSize(QSize(350, 16777215));
        verticalLayout_7 = new QVBoxLayout(widget_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        w_Test = new QWidget(widget_6);
        w_Test->setObjectName(QString::fromUtf8("w_Test"));
        w_Test->setMinimumSize(QSize(350, 150));
        w_Test->setMaximumSize(QSize(350, 150));
        gridLayout_12 = new QGridLayout(w_Test);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(9, 9, 9, 9);
        label_17 = new QLabel(w_Test);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(100, 0));

        gridLayout_12->addWidget(label_17, 0, 0, 1, 1);

        EDIT_Test_modelpath = new QLineEdit(w_Test);
        EDIT_Test_modelpath->setObjectName(QString::fromUtf8("EDIT_Test_modelpath"));
        EDIT_Test_modelpath->setFrame(true);
        EDIT_Test_modelpath->setEchoMode(QLineEdit::Normal);
        EDIT_Test_modelpath->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        EDIT_Test_modelpath->setReadOnly(true);

        gridLayout_12->addWidget(EDIT_Test_modelpath, 2, 1, 1, 2);

        BTN_Test_modelpath = new QPushButton(w_Test);
        BTN_Test_modelpath->setObjectName(QString::fromUtf8("BTN_Test_modelpath"));
        BTN_Test_modelpath->setMaximumSize(QSize(30, 16777215));

        gridLayout_12->addWidget(BTN_Test_modelpath, 2, 3, 1, 1);

        BTN_Test_loaddata = new QPushButton(w_Test);
        BTN_Test_loaddata->setObjectName(QString::fromUtf8("BTN_Test_loaddata"));
        BTN_Test_loaddata->setMaximumSize(QSize(30, 16777215));

        gridLayout_12->addWidget(BTN_Test_loaddata, 0, 3, 1, 1);

        label_18 = new QLabel(w_Test);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(100, 0));

        gridLayout_12->addWidget(label_18, 2, 0, 1, 1);

        EDIT_Test_loaddata = new QLineEdit(w_Test);
        EDIT_Test_loaddata->setObjectName(QString::fromUtf8("EDIT_Test_loaddata"));
        EDIT_Test_loaddata->setFrame(true);
        EDIT_Test_loaddata->setEchoMode(QLineEdit::Normal);
        EDIT_Test_loaddata->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        EDIT_Test_loaddata->setReadOnly(true);

        gridLayout_12->addWidget(EDIT_Test_loaddata, 0, 1, 1, 2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_7, 3, 1, 1, 1);


        verticalLayout_7->addWidget(w_Test);

        BTN_Test_test = new QPushButton(widget_6);
        BTN_Test_test->setObjectName(QString::fromUtf8("BTN_Test_test"));
        BTN_Test_test->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(BTN_Test_test);

        TABLE_TEST = new QTableWidget(widget_6);
        if (TABLE_TEST->columnCount() < 2)
            TABLE_TEST->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TABLE_TEST->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TABLE_TEST->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        TABLE_TEST->setObjectName(QString::fromUtf8("TABLE_TEST"));
        TABLE_TEST->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_7->addWidget(TABLE_TEST);


        gridLayout_8->addWidget(widget_6, 0, 0, 1, 1);

        w_Test_work = new QWidget(page_test);
        w_Test_work->setObjectName(QString::fromUtf8("w_Test_work"));
        gridLayout_9 = new QGridLayout(w_Test_work);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        Test_viewer2 = new QLabel(w_Test_work);
        Test_viewer2->setObjectName(QString::fromUtf8("Test_viewer2"));
        Test_viewer2->setMinimumSize(QSize(0, 0));
        Test_viewer2->setMaximumSize(QSize(10000, 10000));
        Test_viewer2->setFrameShape(QFrame::Panel);
        Test_viewer2->setFrameShadow(QFrame::Plain);
        Test_viewer2->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(Test_viewer2, 1, 1, 1, 1);

        Test_viewer = new QLabel(w_Test_work);
        Test_viewer->setObjectName(QString::fromUtf8("Test_viewer"));
        Test_viewer->setMinimumSize(QSize(0, 0));
        Test_viewer->setMaximumSize(QSize(10000, 10000));
        Test_viewer->setFrameShape(QFrame::Panel);
        Test_viewer->setFrameShadow(QFrame::Plain);
        Test_viewer->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(Test_viewer, 1, 0, 1, 1);


        gridLayout_8->addWidget(w_Test_work, 0, 1, 1, 1);

        w_Work->addWidget(page_test);

        gridLayout_6->addWidget(w_Work, 0, 0, 1, 1);


        gridLayout->addWidget(w_Background, 1, 1, 1, 1);

        QtGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGUIClass->setStatusBar(statusBar);

        retranslateUi(QtGUIClass);

        BTN_menu_data->setDefault(false);
        w_Work->setCurrentIndex(2);
        SENSOR_background->setDefault(false);
        SENSOR_object->setDefault(false);


        QMetaObject::connectSlotsByName(QtGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGUIClass)
    {
        QtGUIClass->setWindowTitle(QCoreApplication::translate("QtGUIClass", "QtGUI", nullptr));
        BTN_menu_data->setText(QCoreApplication::translate("QtGUIClass", "Data", nullptr));
        BTN_menu_train->setText(QCoreApplication::translate("QtGUIClass", "Train", nullptr));
        BTN_menu_label->setText(QCoreApplication::translate("QtGUIClass", "Label", nullptr));
        BTN_menu_test->setText(QCoreApplication::translate("QtGUIClass", "Test", nullptr));
        BTN_load_dataset->setText(QCoreApplication::translate("QtGUIClass", "...", nullptr));
        BTN_path_backup->setText(QCoreApplication::translate("QtGUIClass", "...", nullptr));
        label_13->setText(QCoreApplication::translate("QtGUIClass", "Load Data", nullptr));
        label_14->setText(QCoreApplication::translate("QtGUIClass", "Backup Path", nullptr));
        label_all->setText(QCoreApplication::translate("QtGUIClass", "0", nullptr));
        label_train->setText(QCoreApplication::translate("QtGUIClass", "0", nullptr));
        label_val->setText(QCoreApplication::translate("QtGUIClass", "0", nullptr));
        label_4->setText(QCoreApplication::translate("QtGUIClass", "All", nullptr));
        label_5->setText(QCoreApplication::translate("QtGUIClass", "Train", nullptr));
        label_6->setText(QCoreApplication::translate("QtGUIClass", "Validation", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TABLE_DATA->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("QtGUIClass", "No", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TABLE_DATA->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("QtGUIClass", "FileName", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TABLE_DATA->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("QtGUIClass", "Class", nullptr));
        image_viwer->setText(QString());
        label->setText(QCoreApplication::translate("QtGUIClass", "Width", nullptr));
        label_2->setText(QCoreApplication::translate("QtGUIClass", "Height", nullptr));
        label_3->setText(QCoreApplication::translate("QtGUIClass", "Channel", nullptr));
        label_9->setText(QCoreApplication::translate("QtGUIClass", "Backup path", nullptr));
        label_8->setText(QCoreApplication::translate("QtGUIClass", "Batch size", nullptr));
        label_7->setText(QCoreApplication::translate("QtGUIClass", "Epoch", nullptr));
        BTN_train_backuppath->setText(QCoreApplication::translate("QtGUIClass", "open", nullptr));
        BTN_train_train->setText(QCoreApplication::translate("QtGUIClass", "TRAIN", nullptr));
        label_15->setText(QCoreApplication::translate("QtGUIClass", "Data Path", nullptr));
        BTN_Label_loaddata->setText(QCoreApplication::translate("QtGUIClass", "...", nullptr));
        label_16->setText(QCoreApplication::translate("QtGUIClass", "Brush Size", nullptr));
        BTN_label_masking->setText(QCoreApplication::translate("QtGUIClass", "MASKING(spacebar)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TABLE_LABEL->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("QtGUIClass", "No", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TABLE_LABEL->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("QtGUIClass", "Name", nullptr));
        Label_viewer2->setText(QString());
        label_12->setText(QCoreApplication::translate("QtGUIClass", "Object", nullptr));
        SENSOR_background->setText(QString());
        label_11->setText(QCoreApplication::translate("QtGUIClass", "Background", nullptr));
        SENSOR_object->setText(QString());
        label_10->setText(QCoreApplication::translate("QtGUIClass", "Masking Image", nullptr));
        RBTN_both->setText(QCoreApplication::translate("QtGUIClass", "Both", nullptr));
        RBTN_mask->setText(QCoreApplication::translate("QtGUIClass", "Mask", nullptr));
        Label_viewer->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("QtGUIClass", "..", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("QtGUIClass", "Shortcut", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("QtGUIClass", "Mouse", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(1, QCoreApplication::translate("QtGUIClass", "Object", nullptr));
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("QtGUIClass", "Left", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(1, QCoreApplication::translate("QtGUIClass", "Background", nullptr));
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("QtGUIClass", "Right", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("QtGUIClass", "Keyboard", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(1, QCoreApplication::translate("QtGUIClass", "Previous", nullptr));
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("QtGUIClass", "Up/Left", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem4->child(1);
        ___qtreewidgetitem6->setText(1, QCoreApplication::translate("QtGUIClass", "Next", nullptr));
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("QtGUIClass", "Down/Right", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem4->child(2);
        ___qtreewidgetitem7->setText(1, QCoreApplication::translate("QtGUIClass", "Masking", nullptr));
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("QtGUIClass", "Spacebar", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label_17->setText(QCoreApplication::translate("QtGUIClass", "Data Path", nullptr));
        BTN_Test_modelpath->setText(QCoreApplication::translate("QtGUIClass", "...", nullptr));
        BTN_Test_loaddata->setText(QCoreApplication::translate("QtGUIClass", "...", nullptr));
        label_18->setText(QCoreApplication::translate("QtGUIClass", "Load Model", nullptr));
        BTN_Test_test->setText(QCoreApplication::translate("QtGUIClass", "TEST", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TABLE_TEST->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("QtGUIClass", "No", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TABLE_TEST->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("QtGUIClass", "Name", nullptr));
        Test_viewer2->setText(QString());
        Test_viewer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtGUIClass: public Ui_QtGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSEG_H
