/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_Module1;
    QGridLayout *gridLayout_5;
    QLabel *label_Module1ADCPacketCount;
    QPushButton *pushButton_GetParametersModule1;
    QLineEdit *lineEdit_Module1ADCPacketCount;
    QFrame *line;
    QPushButton *pushButton_Module1ADCToGraph;
    QPushButton *pushButton_Module1ADCToTable;
    QGroupBox *groupBox_Module2;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_Module2ADCToTable;
    QPushButton *pushButton_Module2ADCToGraph;
    QLabel *label_Module2ADCPacketCount;
    QPushButton *pushButton_GetParametersModule2;
    QLineEdit *lineEdit_Module2ADCPacketCount;
    QFrame *line_5;
    QGroupBox *groupBox_Module3;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_Module3ADCPacketCount;
    QPushButton *pushButton_GetParametersModule3;
    QLabel *label_Module3ADCPacketCount;
    QPushButton *pushButton_Module3ADCToTable;
    QPushButton *pushButton_Module3ADCToGraph;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_ComPortControls;
    QGridLayout *gridLayout_3;
    QLabel *label_Status;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Close;
    QLabel *label_SerialPort;
    QLabel *label_ShowStatus;
    QComboBox *comboBox_Port;
    QGroupBox *groupBox_ModuleControls;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_InitConnectionModule1;
    QPushButton *pushButton_DeinitConnectionModule1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_InitConnectionModule2;
    QPushButton *pushButton_DeinitConnectionModule2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_InitConnectionModule3;
    QPushButton *pushButton_DeinitConnectionModule3;
    QGroupBox *groupBox_CustomPacketControls;
    QGridLayout *gridLayout_8;
    QLabel *label_CustomPacketSource;
    QComboBox *comboBox_CustomPacketSource;
    QLabel *label_CustomPacketModule;
    QComboBox *comboBox_CustomPacketModule;
    QLabel *label_CustomPacketFunction;
    QComboBox *comboBox_CustomPacketFunction;
    QLabel *label_CustomPacketParameter;
    QComboBox *comboBox_CustomPacketParameter;
    QLabel *label_CustomPacketSign;
    QLineEdit *lineEdit_CustomPacketSign;
    QLabel *label_CustomPacketLength;
    QLineEdit *lineEdit_CustomPacketLength;
    QLabel *label_CustomPacketPayload;
    QLineEdit *lineEdit_CustomPacketPayload;
    QPushButton *pushButton_Send;
    QPushButton *pushButton_SendWrongCrcPacket;
    QGroupBox *groupBox_GraphControls;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_SquareAmplitude;
    QFrame *line_1;
    QLabel *label_LinearStop;
    QLabel *label_LinearStep;
    QComboBox *comboBox_GraphModule;
    QLineEdit *lineEdit_SineStartDegrees;
    QLabel *label_Linear;
    QLineEdit *lineEdit_RangeMaximum;
    QLineEdit *lineEdit_LinearStep;
    QLineEdit *lineEdit_SineAmplitude;
    QComboBox *comboBox_TimeRange;
    QPushButton *pushButton_StartSquare;
    QLabel *label_GraphModule;
    QLabel *label_RangeMinimum;
    QLineEdit *lineEdit_SineStopDegrees;
    QPushButton *pushButton_SetRanges;
    QLabel *label_Square;
    QFrame *line_2;
    QLabel *label_Sine;
    QLabel *label_SquareStop;
    QFrame *line_3;
    QLabel *label_SineStopDegrees;
    QLabel *label_SineStartDegrees;
    QPushButton *pushButton_StartLinear;
    QLabel *label_RangeMaximum;
    QLineEdit *lineEdit_RangeMinimum;
    QPushButton *pushButton_StartSine;
    QLineEdit *lineEdit_SquarePeriod;
    QLineEdit *lineEdit_SquareStart;
    QLineEdit *lineEdit_LinearStart;
    QComboBox *comboBox_GraphSignalCount;
    QFrame *line_4;
    QLabel *label_LinearStart;
    QLabel *label_SineAmplitude;
    QLabel *label_SignalCount;
    QLineEdit *lineEdit_SquareStop;
    QLabel *label_SquareStart;
    QLineEdit *lineEdit_LinearStop;
    QLabel *label_SquareAmplitude;
    QLabel *label_TimeRange;
    QLabel *label_SquarePeriod;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1229, 1059);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_Module1 = new QGroupBox(centralWidget);
        groupBox_Module1->setObjectName(QString::fromUtf8("groupBox_Module1"));
        groupBox_Module1->setEnabled(false);
        groupBox_Module1->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_Module1->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(groupBox_Module1);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(-1, 0, -1, 0);
        label_Module1ADCPacketCount = new QLabel(groupBox_Module1);
        label_Module1ADCPacketCount->setObjectName(QString::fromUtf8("label_Module1ADCPacketCount"));
        label_Module1ADCPacketCount->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_Module1ADCPacketCount, 2, 0, 1, 1);

        pushButton_GetParametersModule1 = new QPushButton(groupBox_Module1);
        pushButton_GetParametersModule1->setObjectName(QString::fromUtf8("pushButton_GetParametersModule1"));
        pushButton_GetParametersModule1->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_5->addWidget(pushButton_GetParametersModule1, 0, 0, 1, 2);

        lineEdit_Module1ADCPacketCount = new QLineEdit(groupBox_Module1);
        lineEdit_Module1ADCPacketCount->setObjectName(QString::fromUtf8("lineEdit_Module1ADCPacketCount"));
        lineEdit_Module1ADCPacketCount->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lineEdit_Module1ADCPacketCount, 2, 1, 1, 1);

        line = new QFrame(groupBox_Module1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 1, 0, 1, 2);

        pushButton_Module1ADCToGraph = new QPushButton(groupBox_Module1);
        pushButton_Module1ADCToGraph->setObjectName(QString::fromUtf8("pushButton_Module1ADCToGraph"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Module1ADCToGraph->sizePolicy().hasHeightForWidth());
        pushButton_Module1ADCToGraph->setSizePolicy(sizePolicy);
        pushButton_Module1ADCToGraph->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_5->addWidget(pushButton_Module1ADCToGraph, 3, 0, 1, 1);

        pushButton_Module1ADCToTable = new QPushButton(groupBox_Module1);
        pushButton_Module1ADCToTable->setObjectName(QString::fromUtf8("pushButton_Module1ADCToTable"));
        sizePolicy.setHeightForWidth(pushButton_Module1ADCToTable->sizePolicy().hasHeightForWidth());
        pushButton_Module1ADCToTable->setSizePolicy(sizePolicy);
        pushButton_Module1ADCToTable->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_5->addWidget(pushButton_Module1ADCToTable, 3, 1, 1, 1);


        horizontalLayout_2->addWidget(groupBox_Module1);

        groupBox_Module2 = new QGroupBox(centralWidget);
        groupBox_Module2->setObjectName(QString::fromUtf8("groupBox_Module2"));
        groupBox_Module2->setEnabled(false);
        groupBox_Module2->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_Module2->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_Module2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setVerticalSpacing(0);
        gridLayout_6->setContentsMargins(-1, 0, -1, 0);
        pushButton_Module2ADCToTable = new QPushButton(groupBox_Module2);
        pushButton_Module2ADCToTable->setObjectName(QString::fromUtf8("pushButton_Module2ADCToTable"));
        sizePolicy.setHeightForWidth(pushButton_Module2ADCToTable->sizePolicy().hasHeightForWidth());
        pushButton_Module2ADCToTable->setSizePolicy(sizePolicy);
        pushButton_Module2ADCToTable->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_6->addWidget(pushButton_Module2ADCToTable, 3, 1, 1, 2);

        pushButton_Module2ADCToGraph = new QPushButton(groupBox_Module2);
        pushButton_Module2ADCToGraph->setObjectName(QString::fromUtf8("pushButton_Module2ADCToGraph"));
        sizePolicy.setHeightForWidth(pushButton_Module2ADCToGraph->sizePolicy().hasHeightForWidth());
        pushButton_Module2ADCToGraph->setSizePolicy(sizePolicy);
        pushButton_Module2ADCToGraph->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_6->addWidget(pushButton_Module2ADCToGraph, 3, 0, 1, 1);

        label_Module2ADCPacketCount = new QLabel(groupBox_Module2);
        label_Module2ADCPacketCount->setObjectName(QString::fromUtf8("label_Module2ADCPacketCount"));
        label_Module2ADCPacketCount->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_Module2ADCPacketCount, 2, 0, 1, 1);

        pushButton_GetParametersModule2 = new QPushButton(groupBox_Module2);
        pushButton_GetParametersModule2->setObjectName(QString::fromUtf8("pushButton_GetParametersModule2"));
        pushButton_GetParametersModule2->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_6->addWidget(pushButton_GetParametersModule2, 0, 0, 1, 3);

        lineEdit_Module2ADCPacketCount = new QLineEdit(groupBox_Module2);
        lineEdit_Module2ADCPacketCount->setObjectName(QString::fromUtf8("lineEdit_Module2ADCPacketCount"));
        lineEdit_Module2ADCPacketCount->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lineEdit_Module2ADCPacketCount, 2, 1, 1, 1);

        line_5 = new QFrame(groupBox_Module2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_5, 1, 0, 1, 2);


        horizontalLayout_2->addWidget(groupBox_Module2);

        groupBox_Module3 = new QGroupBox(centralWidget);
        groupBox_Module3->setObjectName(QString::fromUtf8("groupBox_Module3"));
        groupBox_Module3->setEnabled(false);
        groupBox_Module3->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_Module3->setAlignment(Qt::AlignCenter);
        gridLayout_7 = new QGridLayout(groupBox_Module3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(0);
        gridLayout_7->setContentsMargins(-1, 0, -1, 0);
        lineEdit_Module3ADCPacketCount = new QLineEdit(groupBox_Module3);
        lineEdit_Module3ADCPacketCount->setObjectName(QString::fromUtf8("lineEdit_Module3ADCPacketCount"));
        lineEdit_Module3ADCPacketCount->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_Module3ADCPacketCount, 2, 2, 1, 1);

        pushButton_GetParametersModule3 = new QPushButton(groupBox_Module3);
        pushButton_GetParametersModule3->setObjectName(QString::fromUtf8("pushButton_GetParametersModule3"));
        pushButton_GetParametersModule3->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_7->addWidget(pushButton_GetParametersModule3, 0, 0, 1, 3);

        label_Module3ADCPacketCount = new QLabel(groupBox_Module3);
        label_Module3ADCPacketCount->setObjectName(QString::fromUtf8("label_Module3ADCPacketCount"));
        label_Module3ADCPacketCount->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_Module3ADCPacketCount, 2, 0, 1, 1);

        pushButton_Module3ADCToTable = new QPushButton(groupBox_Module3);
        pushButton_Module3ADCToTable->setObjectName(QString::fromUtf8("pushButton_Module3ADCToTable"));
        sizePolicy.setHeightForWidth(pushButton_Module3ADCToTable->sizePolicy().hasHeightForWidth());
        pushButton_Module3ADCToTable->setSizePolicy(sizePolicy);
        pushButton_Module3ADCToTable->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_7->addWidget(pushButton_Module3ADCToTable, 3, 1, 1, 2);

        pushButton_Module3ADCToGraph = new QPushButton(groupBox_Module3);
        pushButton_Module3ADCToGraph->setObjectName(QString::fromUtf8("pushButton_Module3ADCToGraph"));
        sizePolicy.setHeightForWidth(pushButton_Module3ADCToGraph->sizePolicy().hasHeightForWidth());
        pushButton_Module3ADCToGraph->setSizePolicy(sizePolicy);
        pushButton_Module3ADCToGraph->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_7->addWidget(pushButton_Module3ADCToGraph, 3, 0, 1, 1);

        line_6 = new QFrame(groupBox_Module3);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_6, 1, 0, 1, 3);


        horizontalLayout_2->addWidget(groupBox_Module3);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_ComPortControls = new QGroupBox(centralWidget);
        groupBox_ComPortControls->setObjectName(QString::fromUtf8("groupBox_ComPortControls"));
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        groupBox_ComPortControls->setFont(font);
        groupBox_ComPortControls->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_ComPortControls->setAlignment(Qt::AlignCenter);
        groupBox_ComPortControls->setFlat(false);
        groupBox_ComPortControls->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_ComPortControls);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(0);
        gridLayout_3->setContentsMargins(-1, 0, -1, 0);
        label_Status = new QLabel(groupBox_ComPortControls);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_Status, 0, 0, 1, 1);

        pushButton_Open = new QPushButton(groupBox_ComPortControls);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));

        gridLayout_3->addWidget(pushButton_Open, 2, 0, 1, 1);

        pushButton_Close = new QPushButton(groupBox_ComPortControls);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));

        gridLayout_3->addWidget(pushButton_Close, 2, 1, 1, 1);

        label_SerialPort = new QLabel(groupBox_ComPortControls);
        label_SerialPort->setObjectName(QString::fromUtf8("label_SerialPort"));
        label_SerialPort->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_SerialPort, 1, 0, 1, 1);

        label_ShowStatus = new QLabel(groupBox_ComPortControls);
        label_ShowStatus->setObjectName(QString::fromUtf8("label_ShowStatus"));
        label_ShowStatus->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_ShowStatus->setTextFormat(Qt::RichText);
        label_ShowStatus->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_ShowStatus, 0, 1, 1, 1);

        comboBox_Port = new QComboBox(groupBox_ComPortControls);
        comboBox_Port->setObjectName(QString::fromUtf8("comboBox_Port"));
        comboBox_Port->setInsertPolicy(QComboBox::InsertAtBottom);
        comboBox_Port->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout_3->addWidget(comboBox_Port, 1, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox_ComPortControls);

        groupBox_ModuleControls = new QGroupBox(centralWidget);
        groupBox_ModuleControls->setObjectName(QString::fromUtf8("groupBox_ModuleControls"));
        groupBox_ModuleControls->setEnabled(false);
        groupBox_ModuleControls->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_ModuleControls->setAlignment(Qt::AlignCenter);
        gridLayout_9 = new QGridLayout(groupBox_ModuleControls);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(0);
        gridLayout_9->setContentsMargins(-1, 0, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_InitConnectionModule1 = new QPushButton(groupBox_ModuleControls);
        pushButton_InitConnectionModule1->setObjectName(QString::fromUtf8("pushButton_InitConnectionModule1"));
        pushButton_InitConnectionModule1->setStyleSheet(QString::fromUtf8("color: blue"));

        verticalLayout->addWidget(pushButton_InitConnectionModule1);

        pushButton_DeinitConnectionModule1 = new QPushButton(groupBox_ModuleControls);
        pushButton_DeinitConnectionModule1->setObjectName(QString::fromUtf8("pushButton_DeinitConnectionModule1"));
        pushButton_DeinitConnectionModule1->setStyleSheet(QString::fromUtf8("color: blue"));

        verticalLayout->addWidget(pushButton_DeinitConnectionModule1);


        gridLayout_9->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_InitConnectionModule2 = new QPushButton(groupBox_ModuleControls);
        pushButton_InitConnectionModule2->setObjectName(QString::fromUtf8("pushButton_InitConnectionModule2"));
        pushButton_InitConnectionModule2->setStyleSheet(QString::fromUtf8("color: blue"));

        verticalLayout_2->addWidget(pushButton_InitConnectionModule2);

        pushButton_DeinitConnectionModule2 = new QPushButton(groupBox_ModuleControls);
        pushButton_DeinitConnectionModule2->setObjectName(QString::fromUtf8("pushButton_DeinitConnectionModule2"));
        pushButton_DeinitConnectionModule2->setStyleSheet(QString::fromUtf8("color: blue"));

        verticalLayout_2->addWidget(pushButton_DeinitConnectionModule2);


        gridLayout_9->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton_InitConnectionModule3 = new QPushButton(groupBox_ModuleControls);
        pushButton_InitConnectionModule3->setObjectName(QString::fromUtf8("pushButton_InitConnectionModule3"));
        pushButton_InitConnectionModule3->setStyleSheet(QString::fromUtf8("color: blue"));

        verticalLayout_3->addWidget(pushButton_InitConnectionModule3);

        pushButton_DeinitConnectionModule3 = new QPushButton(groupBox_ModuleControls);
        pushButton_DeinitConnectionModule3->setObjectName(QString::fromUtf8("pushButton_DeinitConnectionModule3"));
        pushButton_DeinitConnectionModule3->setStyleSheet(QString::fromUtf8("color: blue"));

        verticalLayout_3->addWidget(pushButton_DeinitConnectionModule3);


        gridLayout_9->addLayout(verticalLayout_3, 0, 2, 1, 1);


        verticalLayout_4->addWidget(groupBox_ModuleControls);


        horizontalLayout->addLayout(verticalLayout_4);

        groupBox_CustomPacketControls = new QGroupBox(centralWidget);
        groupBox_CustomPacketControls->setObjectName(QString::fromUtf8("groupBox_CustomPacketControls"));
        groupBox_CustomPacketControls->setEnabled(false);
        groupBox_CustomPacketControls->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_CustomPacketControls->setAlignment(Qt::AlignCenter);
        gridLayout_8 = new QGridLayout(groupBox_CustomPacketControls);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_CustomPacketSource = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketSource->setObjectName(QString::fromUtf8("label_CustomPacketSource"));
        label_CustomPacketSource->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketSource, 0, 0, 1, 1);

        comboBox_CustomPacketSource = new QComboBox(groupBox_CustomPacketControls);
        comboBox_CustomPacketSource->addItem(QString());
        comboBox_CustomPacketSource->setObjectName(QString::fromUtf8("comboBox_CustomPacketSource"));

        gridLayout_8->addWidget(comboBox_CustomPacketSource, 0, 1, 1, 1);

        label_CustomPacketModule = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketModule->setObjectName(QString::fromUtf8("label_CustomPacketModule"));
        label_CustomPacketModule->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketModule, 1, 0, 1, 1);

        comboBox_CustomPacketModule = new QComboBox(groupBox_CustomPacketControls);
        comboBox_CustomPacketModule->addItem(QString());
        comboBox_CustomPacketModule->addItem(QString());
        comboBox_CustomPacketModule->addItem(QString());
        comboBox_CustomPacketModule->setObjectName(QString::fromUtf8("comboBox_CustomPacketModule"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_CustomPacketModule->sizePolicy().hasHeightForWidth());
        comboBox_CustomPacketModule->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(comboBox_CustomPacketModule, 1, 1, 1, 1);

        label_CustomPacketFunction = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketFunction->setObjectName(QString::fromUtf8("label_CustomPacketFunction"));
        label_CustomPacketFunction->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketFunction, 2, 0, 1, 1);

        comboBox_CustomPacketFunction = new QComboBox(groupBox_CustomPacketControls);
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->addItem(QString());
        comboBox_CustomPacketFunction->setObjectName(QString::fromUtf8("comboBox_CustomPacketFunction"));

        gridLayout_8->addWidget(comboBox_CustomPacketFunction, 2, 1, 1, 1);

        label_CustomPacketParameter = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketParameter->setObjectName(QString::fromUtf8("label_CustomPacketParameter"));
        label_CustomPacketParameter->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketParameter, 3, 0, 1, 1);

        comboBox_CustomPacketParameter = new QComboBox(groupBox_CustomPacketControls);
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->addItem(QString());
        comboBox_CustomPacketParameter->setObjectName(QString::fromUtf8("comboBox_CustomPacketParameter"));
        sizePolicy1.setHeightForWidth(comboBox_CustomPacketParameter->sizePolicy().hasHeightForWidth());
        comboBox_CustomPacketParameter->setSizePolicy(sizePolicy1);

        gridLayout_8->addWidget(comboBox_CustomPacketParameter, 3, 1, 1, 1);

        label_CustomPacketSign = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketSign->setObjectName(QString::fromUtf8("label_CustomPacketSign"));
        label_CustomPacketSign->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketSign, 4, 0, 1, 1);

        lineEdit_CustomPacketSign = new QLineEdit(groupBox_CustomPacketControls);
        lineEdit_CustomPacketSign->setObjectName(QString::fromUtf8("lineEdit_CustomPacketSign"));
        lineEdit_CustomPacketSign->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_CustomPacketSign->sizePolicy().hasHeightForWidth());
        lineEdit_CustomPacketSign->setSizePolicy(sizePolicy1);
        lineEdit_CustomPacketSign->setMaxLength(1);
        lineEdit_CustomPacketSign->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit_CustomPacketSign, 4, 1, 1, 1);

        label_CustomPacketLength = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketLength->setObjectName(QString::fromUtf8("label_CustomPacketLength"));
        label_CustomPacketLength->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketLength, 5, 0, 1, 1);

        lineEdit_CustomPacketLength = new QLineEdit(groupBox_CustomPacketControls);
        lineEdit_CustomPacketLength->setObjectName(QString::fromUtf8("lineEdit_CustomPacketLength"));
        sizePolicy1.setHeightForWidth(lineEdit_CustomPacketLength->sizePolicy().hasHeightForWidth());
        lineEdit_CustomPacketLength->setSizePolicy(sizePolicy1);
        lineEdit_CustomPacketLength->setMaxLength(2);
        lineEdit_CustomPacketLength->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit_CustomPacketLength, 5, 1, 1, 1);

        label_CustomPacketPayload = new QLabel(groupBox_CustomPacketControls);
        label_CustomPacketPayload->setObjectName(QString::fromUtf8("label_CustomPacketPayload"));
        label_CustomPacketPayload->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_CustomPacketPayload, 6, 0, 1, 1);

        lineEdit_CustomPacketPayload = new QLineEdit(groupBox_CustomPacketControls);
        lineEdit_CustomPacketPayload->setObjectName(QString::fromUtf8("lineEdit_CustomPacketPayload"));
        sizePolicy1.setHeightForWidth(lineEdit_CustomPacketPayload->sizePolicy().hasHeightForWidth());
        lineEdit_CustomPacketPayload->setSizePolicy(sizePolicy1);
        lineEdit_CustomPacketPayload->setMaxLength(15);

        gridLayout_8->addWidget(lineEdit_CustomPacketPayload, 6, 1, 1, 1);

        pushButton_Send = new QPushButton(groupBox_CustomPacketControls);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_8->addWidget(pushButton_Send, 7, 0, 1, 2);

        pushButton_SendWrongCrcPacket = new QPushButton(groupBox_CustomPacketControls);
        pushButton_SendWrongCrcPacket->setObjectName(QString::fromUtf8("pushButton_SendWrongCrcPacket"));
        pushButton_SendWrongCrcPacket->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_8->addWidget(pushButton_SendWrongCrcPacket, 8, 0, 1, 2);


        horizontalLayout->addWidget(groupBox_CustomPacketControls);

        groupBox_GraphControls = new QGroupBox(centralWidget);
        groupBox_GraphControls->setObjectName(QString::fromUtf8("groupBox_GraphControls"));
        groupBox_GraphControls->setEnabled(false);
        groupBox_GraphControls->setStyleSheet(QString::fromUtf8("font:bold"));
        groupBox_GraphControls->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox_GraphControls);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(3);
        gridLayout_4->setContentsMargins(-1, 0, -1, 0);
        lineEdit_SquareAmplitude = new QLineEdit(groupBox_GraphControls);
        lineEdit_SquareAmplitude->setObjectName(QString::fromUtf8("lineEdit_SquareAmplitude"));
        lineEdit_SquareAmplitude->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_SquareAmplitude, 38, 1, 1, 1);

        line_1 = new QFrame(groupBox_GraphControls);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        sizePolicy1.setHeightForWidth(line_1->sizePolicy().hasHeightForWidth());
        line_1->setSizePolicy(sizePolicy1);
        line_1->setFrameShape(QFrame::HLine);
        line_1->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_1, 8, 0, 1, 2);

        label_LinearStop = new QLabel(groupBox_GraphControls);
        label_LinearStop->setObjectName(QString::fromUtf8("label_LinearStop"));
        label_LinearStop->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_LinearStop, 12, 0, 1, 1);

        label_LinearStep = new QLabel(groupBox_GraphControls);
        label_LinearStep->setObjectName(QString::fromUtf8("label_LinearStep"));
        label_LinearStep->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_LinearStep, 13, 0, 1, 1);

        comboBox_GraphModule = new QComboBox(groupBox_GraphControls);
        comboBox_GraphModule->addItem(QString());
        comboBox_GraphModule->addItem(QString());
        comboBox_GraphModule->addItem(QString());
        comboBox_GraphModule->setObjectName(QString::fromUtf8("comboBox_GraphModule"));
        sizePolicy1.setHeightForWidth(comboBox_GraphModule->sizePolicy().hasHeightForWidth());
        comboBox_GraphModule->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(comboBox_GraphModule, 0, 1, 1, 1);

        lineEdit_SineStartDegrees = new QLineEdit(groupBox_GraphControls);
        lineEdit_SineStartDegrees->setObjectName(QString::fromUtf8("lineEdit_SineStartDegrees"));
        lineEdit_SineStartDegrees->setMaxLength(15);
        lineEdit_SineStartDegrees->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_SineStartDegrees, 20, 1, 1, 1);

        label_Linear = new QLabel(groupBox_GraphControls);
        label_Linear->setObjectName(QString::fromUtf8("label_Linear"));
        sizePolicy1.setHeightForWidth(label_Linear->sizePolicy().hasHeightForWidth());
        label_Linear->setSizePolicy(sizePolicy1);
        label_Linear->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Linear, 9, 0, 1, 2);

        lineEdit_RangeMaximum = new QLineEdit(groupBox_GraphControls);
        lineEdit_RangeMaximum->setObjectName(QString::fromUtf8("lineEdit_RangeMaximum"));
        sizePolicy1.setHeightForWidth(lineEdit_RangeMaximum->sizePolicy().hasHeightForWidth());
        lineEdit_RangeMaximum->setSizePolicy(sizePolicy1);
        lineEdit_RangeMaximum->setMaxLength(15);
        lineEdit_RangeMaximum->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_RangeMaximum, 6, 1, 1, 1);

        lineEdit_LinearStep = new QLineEdit(groupBox_GraphControls);
        lineEdit_LinearStep->setObjectName(QString::fromUtf8("lineEdit_LinearStep"));
        sizePolicy1.setHeightForWidth(lineEdit_LinearStep->sizePolicy().hasHeightForWidth());
        lineEdit_LinearStep->setSizePolicy(sizePolicy1);
        lineEdit_LinearStep->setMaxLength(15);
        lineEdit_LinearStep->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_LinearStep, 13, 1, 1, 1);

        lineEdit_SineAmplitude = new QLineEdit(groupBox_GraphControls);
        lineEdit_SineAmplitude->setObjectName(QString::fromUtf8("lineEdit_SineAmplitude"));
        sizePolicy1.setHeightForWidth(lineEdit_SineAmplitude->sizePolicy().hasHeightForWidth());
        lineEdit_SineAmplitude->setSizePolicy(sizePolicy1);
        lineEdit_SineAmplitude->setMaxLength(15);
        lineEdit_SineAmplitude->setAlignment(Qt::AlignCenter);
        lineEdit_SineAmplitude->setReadOnly(false);

        gridLayout_4->addWidget(lineEdit_SineAmplitude, 22, 1, 1, 1);

        comboBox_TimeRange = new QComboBox(groupBox_GraphControls);
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->addItem(QString());
        comboBox_TimeRange->setObjectName(QString::fromUtf8("comboBox_TimeRange"));
        comboBox_TimeRange->setLayoutDirection(Qt::LeftToRight);
        comboBox_TimeRange->setAutoFillBackground(false);

        gridLayout_4->addWidget(comboBox_TimeRange, 4, 0, 1, 2);

        pushButton_StartSquare = new QPushButton(groupBox_GraphControls);
        pushButton_StartSquare->setObjectName(QString::fromUtf8("pushButton_StartSquare"));
        pushButton_StartSquare->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_4->addWidget(pushButton_StartSquare, 40, 0, 1, 2);

        label_GraphModule = new QLabel(groupBox_GraphControls);
        label_GraphModule->setObjectName(QString::fromUtf8("label_GraphModule"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_GraphModule->sizePolicy().hasHeightForWidth());
        label_GraphModule->setSizePolicy(sizePolicy2);
        label_GraphModule->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_GraphModule, 0, 0, 1, 1);

        label_RangeMinimum = new QLabel(groupBox_GraphControls);
        label_RangeMinimum->setObjectName(QString::fromUtf8("label_RangeMinimum"));
        sizePolicy1.setHeightForWidth(label_RangeMinimum->sizePolicy().hasHeightForWidth());
        label_RangeMinimum->setSizePolicy(sizePolicy1);
        label_RangeMinimum->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_RangeMinimum, 5, 0, 1, 1);

        lineEdit_SineStopDegrees = new QLineEdit(groupBox_GraphControls);
        lineEdit_SineStopDegrees->setObjectName(QString::fromUtf8("lineEdit_SineStopDegrees"));
        lineEdit_SineStopDegrees->setMaxLength(15);
        lineEdit_SineStopDegrees->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_SineStopDegrees, 21, 1, 1, 1);

        pushButton_SetRanges = new QPushButton(groupBox_GraphControls);
        pushButton_SetRanges->setObjectName(QString::fromUtf8("pushButton_SetRanges"));
        sizePolicy1.setHeightForWidth(pushButton_SetRanges->sizePolicy().hasHeightForWidth());
        pushButton_SetRanges->setSizePolicy(sizePolicy1);
        pushButton_SetRanges->setStyleSheet(QString::fromUtf8("color:blue"));

        gridLayout_4->addWidget(pushButton_SetRanges, 7, 0, 1, 2);

        label_Square = new QLabel(groupBox_GraphControls);
        label_Square->setObjectName(QString::fromUtf8("label_Square"));
        sizePolicy1.setHeightForWidth(label_Square->sizePolicy().hasHeightForWidth());
        label_Square->setSizePolicy(sizePolicy1);
        label_Square->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Square, 35, 0, 1, 2);

        line_2 = new QFrame(groupBox_GraphControls);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_2, 2, 0, 1, 2);

        label_Sine = new QLabel(groupBox_GraphControls);
        label_Sine->setObjectName(QString::fromUtf8("label_Sine"));
        sizePolicy1.setHeightForWidth(label_Sine->sizePolicy().hasHeightForWidth());
        label_Sine->setSizePolicy(sizePolicy1);
        label_Sine->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_Sine, 19, 0, 1, 2);

        label_SquareStop = new QLabel(groupBox_GraphControls);
        label_SquareStop->setObjectName(QString::fromUtf8("label_SquareStop"));
        label_SquareStop->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SquareStop, 37, 0, 1, 1);

        line_3 = new QFrame(groupBox_GraphControls);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_3, 18, 0, 1, 2);

        label_SineStopDegrees = new QLabel(groupBox_GraphControls);
        label_SineStopDegrees->setObjectName(QString::fromUtf8("label_SineStopDegrees"));
        label_SineStopDegrees->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SineStopDegrees, 21, 0, 1, 1);

        label_SineStartDegrees = new QLabel(groupBox_GraphControls);
        label_SineStartDegrees->setObjectName(QString::fromUtf8("label_SineStartDegrees"));
        label_SineStartDegrees->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SineStartDegrees, 20, 0, 1, 1);

        pushButton_StartLinear = new QPushButton(groupBox_GraphControls);
        pushButton_StartLinear->setObjectName(QString::fromUtf8("pushButton_StartLinear"));
        sizePolicy1.setHeightForWidth(pushButton_StartLinear->sizePolicy().hasHeightForWidth());
        pushButton_StartLinear->setSizePolicy(sizePolicy1);
        pushButton_StartLinear->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_4->addWidget(pushButton_StartLinear, 17, 0, 1, 2);

        label_RangeMaximum = new QLabel(groupBox_GraphControls);
        label_RangeMaximum->setObjectName(QString::fromUtf8("label_RangeMaximum"));
        sizePolicy1.setHeightForWidth(label_RangeMaximum->sizePolicy().hasHeightForWidth());
        label_RangeMaximum->setSizePolicy(sizePolicy1);
        label_RangeMaximum->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_RangeMaximum, 5, 1, 1, 1);

        lineEdit_RangeMinimum = new QLineEdit(groupBox_GraphControls);
        lineEdit_RangeMinimum->setObjectName(QString::fromUtf8("lineEdit_RangeMinimum"));
        sizePolicy1.setHeightForWidth(lineEdit_RangeMinimum->sizePolicy().hasHeightForWidth());
        lineEdit_RangeMinimum->setSizePolicy(sizePolicy1);
        lineEdit_RangeMinimum->setMaxLength(15);
        lineEdit_RangeMinimum->setFrame(true);
        lineEdit_RangeMinimum->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_RangeMinimum, 6, 0, 1, 1);

        pushButton_StartSine = new QPushButton(groupBox_GraphControls);
        pushButton_StartSine->setObjectName(QString::fromUtf8("pushButton_StartSine"));
        sizePolicy1.setHeightForWidth(pushButton_StartSine->sizePolicy().hasHeightForWidth());
        pushButton_StartSine->setSizePolicy(sizePolicy1);
        pushButton_StartSine->setStyleSheet(QString::fromUtf8("color: blue"));

        gridLayout_4->addWidget(pushButton_StartSine, 32, 0, 1, 2);

        lineEdit_SquarePeriod = new QLineEdit(groupBox_GraphControls);
        lineEdit_SquarePeriod->setObjectName(QString::fromUtf8("lineEdit_SquarePeriod"));
        lineEdit_SquarePeriod->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_SquarePeriod, 39, 1, 1, 1);

        lineEdit_SquareStart = new QLineEdit(groupBox_GraphControls);
        lineEdit_SquareStart->setObjectName(QString::fromUtf8("lineEdit_SquareStart"));
        lineEdit_SquareStart->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_SquareStart, 36, 1, 1, 1);

        lineEdit_LinearStart = new QLineEdit(groupBox_GraphControls);
        lineEdit_LinearStart->setObjectName(QString::fromUtf8("lineEdit_LinearStart"));
        sizePolicy1.setHeightForWidth(lineEdit_LinearStart->sizePolicy().hasHeightForWidth());
        lineEdit_LinearStart->setSizePolicy(sizePolicy1);
        lineEdit_LinearStart->setMaxLength(15);
        lineEdit_LinearStart->setAlignment(Qt::AlignCenter);
        lineEdit_LinearStart->setReadOnly(false);

        gridLayout_4->addWidget(lineEdit_LinearStart, 10, 1, 1, 1);

        comboBox_GraphSignalCount = new QComboBox(groupBox_GraphControls);
        comboBox_GraphSignalCount->addItem(QString());
        comboBox_GraphSignalCount->addItem(QString());
        comboBox_GraphSignalCount->addItem(QString());
        comboBox_GraphSignalCount->addItem(QString());
        comboBox_GraphSignalCount->setObjectName(QString::fromUtf8("comboBox_GraphSignalCount"));

        gridLayout_4->addWidget(comboBox_GraphSignalCount, 1, 1, 1, 1);

        line_4 = new QFrame(groupBox_GraphControls);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        sizePolicy1.setHeightForWidth(line_4->sizePolicy().hasHeightForWidth());
        line_4->setSizePolicy(sizePolicy1);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_4, 34, 0, 1, 2);

        label_LinearStart = new QLabel(groupBox_GraphControls);
        label_LinearStart->setObjectName(QString::fromUtf8("label_LinearStart"));
        label_LinearStart->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_LinearStart, 10, 0, 1, 1);

        label_SineAmplitude = new QLabel(groupBox_GraphControls);
        label_SineAmplitude->setObjectName(QString::fromUtf8("label_SineAmplitude"));
        label_SineAmplitude->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SineAmplitude, 22, 0, 1, 1);

        label_SignalCount = new QLabel(groupBox_GraphControls);
        label_SignalCount->setObjectName(QString::fromUtf8("label_SignalCount"));
        sizePolicy2.setHeightForWidth(label_SignalCount->sizePolicy().hasHeightForWidth());
        label_SignalCount->setSizePolicy(sizePolicy2);
        label_SignalCount->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SignalCount, 1, 0, 1, 1);

        lineEdit_SquareStop = new QLineEdit(groupBox_GraphControls);
        lineEdit_SquareStop->setObjectName(QString::fromUtf8("lineEdit_SquareStop"));
        lineEdit_SquareStop->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(lineEdit_SquareStop, 37, 1, 1, 1);

        label_SquareStart = new QLabel(groupBox_GraphControls);
        label_SquareStart->setObjectName(QString::fromUtf8("label_SquareStart"));
        label_SquareStart->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SquareStart, 36, 0, 1, 1);

        lineEdit_LinearStop = new QLineEdit(groupBox_GraphControls);
        lineEdit_LinearStop->setObjectName(QString::fromUtf8("lineEdit_LinearStop"));
        sizePolicy1.setHeightForWidth(lineEdit_LinearStop->sizePolicy().hasHeightForWidth());
        lineEdit_LinearStop->setSizePolicy(sizePolicy1);
        lineEdit_LinearStop->setMaxLength(15);
        lineEdit_LinearStop->setAlignment(Qt::AlignCenter);
        lineEdit_LinearStop->setReadOnly(false);

        gridLayout_4->addWidget(lineEdit_LinearStop, 12, 1, 1, 1);

        label_SquareAmplitude = new QLabel(groupBox_GraphControls);
        label_SquareAmplitude->setObjectName(QString::fromUtf8("label_SquareAmplitude"));
        label_SquareAmplitude->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SquareAmplitude, 38, 0, 1, 1);

        label_TimeRange = new QLabel(groupBox_GraphControls);
        label_TimeRange->setObjectName(QString::fromUtf8("label_TimeRange"));
        label_TimeRange->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_TimeRange, 3, 0, 1, 2);

        label_SquarePeriod = new QLabel(groupBox_GraphControls);
        label_SquarePeriod->setObjectName(QString::fromUtf8("label_SquarePeriod"));
        label_SquarePeriod->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_SquarePeriod, 39, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_GraphControls);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        comboBox_Port->setCurrentIndex(-1);
        comboBox_TimeRange->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_Module1->setTitle(QCoreApplication::translate("MainWindow", "Module 1", nullptr));
        label_Module1ADCPacketCount->setText(QCoreApplication::translate("MainWindow", "ADC Packet count module 1", nullptr));
        pushButton_GetParametersModule1->setText(QCoreApplication::translate("MainWindow", "Get parameters module 1", nullptr));
        lineEdit_Module1ADCPacketCount->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton_Module1ADCToGraph->setText(QCoreApplication::translate("MainWindow", "ADC data to GRAPH module 1", nullptr));
        pushButton_Module1ADCToTable->setText(QCoreApplication::translate("MainWindow", "ADC data to TABLE module 1", nullptr));
        groupBox_Module2->setTitle(QCoreApplication::translate("MainWindow", "Module 2", nullptr));
        pushButton_Module2ADCToTable->setText(QCoreApplication::translate("MainWindow", "ADC data to TABLE module 2", nullptr));
        pushButton_Module2ADCToGraph->setText(QCoreApplication::translate("MainWindow", "ADC data to GRAPH module 2", nullptr));
        label_Module2ADCPacketCount->setText(QCoreApplication::translate("MainWindow", "ADC Packet count module 2", nullptr));
        pushButton_GetParametersModule2->setText(QCoreApplication::translate("MainWindow", "Get parameters module 2", nullptr));
        lineEdit_Module2ADCPacketCount->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        groupBox_Module3->setTitle(QCoreApplication::translate("MainWindow", "Module 3", nullptr));
        lineEdit_Module3ADCPacketCount->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        pushButton_GetParametersModule3->setText(QCoreApplication::translate("MainWindow", "Get parameters module 3", nullptr));
        label_Module3ADCPacketCount->setText(QCoreApplication::translate("MainWindow", "ADC Packet count module 3", nullptr));
        pushButton_Module3ADCToTable->setText(QCoreApplication::translate("MainWindow", "ADC data to TABLE module 3", nullptr));
        pushButton_Module3ADCToGraph->setText(QCoreApplication::translate("MainWindow", "ADC data to GRAPH module 3", nullptr));
        groupBox_ComPortControls->setTitle(QCoreApplication::translate("MainWindow", "COM Port Settings", nullptr));
        label_Status->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        pushButton_Open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_SerialPort->setText(QCoreApplication::translate("MainWindow", "Serial port", nullptr));
        label_ShowStatus->setText(QCoreApplication::translate("MainWindow", "<color:red>Closed</>", nullptr));
        groupBox_ModuleControls->setTitle(QCoreApplication::translate("MainWindow", "Module Control", nullptr));
        pushButton_InitConnectionModule1->setText(QCoreApplication::translate("MainWindow", "Init Connection Module 1", nullptr));
        pushButton_DeinitConnectionModule1->setText(QCoreApplication::translate("MainWindow", "Deinit Connection Module 1", nullptr));
        pushButton_InitConnectionModule2->setText(QCoreApplication::translate("MainWindow", "Init Connection Module 2", nullptr));
        pushButton_DeinitConnectionModule2->setText(QCoreApplication::translate("MainWindow", "Deinit Connection Module 2", nullptr));
        pushButton_InitConnectionModule3->setText(QCoreApplication::translate("MainWindow", "Init Connection Module 3", nullptr));
        pushButton_DeinitConnectionModule3->setText(QCoreApplication::translate("MainWindow", "Deinit Connection Module 3", nullptr));
        groupBox_CustomPacketControls->setTitle(QCoreApplication::translate("MainWindow", "Custom Packet", nullptr));
        label_CustomPacketSource->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        comboBox_CustomPacketSource->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));

        label_CustomPacketModule->setText(QCoreApplication::translate("MainWindow", "Module", nullptr));
        comboBox_CustomPacketModule->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_CustomPacketModule->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_CustomPacketModule->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        label_CustomPacketFunction->setText(QCoreApplication::translate("MainWindow", "Function", nullptr));
        comboBox_CustomPacketFunction->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_CustomPacketFunction->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_CustomPacketFunction->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_CustomPacketFunction->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_CustomPacketFunction->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_CustomPacketFunction->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_CustomPacketFunction->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_CustomPacketFunction->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_CustomPacketFunction->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));

        label_CustomPacketParameter->setText(QCoreApplication::translate("MainWindow", "Parameter", nullptr));
        comboBox_CustomPacketParameter->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_CustomPacketParameter->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_CustomPacketParameter->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_CustomPacketParameter->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_CustomPacketParameter->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_CustomPacketParameter->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_CustomPacketParameter->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_CustomPacketParameter->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_CustomPacketParameter->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_CustomPacketParameter->setItemText(9, QCoreApplication::translate("MainWindow", "a", nullptr));
        comboBox_CustomPacketParameter->setItemText(10, QCoreApplication::translate("MainWindow", "b", nullptr));
        comboBox_CustomPacketParameter->setItemText(11, QCoreApplication::translate("MainWindow", "c", nullptr));
        comboBox_CustomPacketParameter->setItemText(12, QCoreApplication::translate("MainWindow", "d", nullptr));
        comboBox_CustomPacketParameter->setItemText(13, QCoreApplication::translate("MainWindow", "e", nullptr));

        label_CustomPacketSign->setText(QCoreApplication::translate("MainWindow", "Sign", nullptr));
        lineEdit_CustomPacketSign->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_CustomPacketLength->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        lineEdit_CustomPacketLength->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        label_CustomPacketPayload->setText(QCoreApplication::translate("MainWindow", "Payload", nullptr));
        lineEdit_CustomPacketPayload->setText(QCoreApplication::translate("MainWindow", "123.456", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_SendWrongCrcPacket->setText(QCoreApplication::translate("MainWindow", "Send wrong CRC packet", nullptr));
        groupBox_GraphControls->setTitle(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        lineEdit_SquareAmplitude->setText(QCoreApplication::translate("MainWindow", "5000", nullptr));
        label_LinearStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_LinearStep->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        comboBox_GraphModule->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_GraphModule->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_GraphModule->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        lineEdit_SineStartDegrees->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_Linear->setText(QCoreApplication::translate("MainWindow", "Linear", nullptr));
        lineEdit_RangeMaximum->setText(QCoreApplication::translate("MainWindow", "+10000", nullptr));
        lineEdit_LinearStep->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineEdit_SineAmplitude->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        comboBox_TimeRange->setItemText(0, QCoreApplication::translate("MainWindow", "360", nullptr));
        comboBox_TimeRange->setItemText(1, QCoreApplication::translate("MainWindow", "720", nullptr));
        comboBox_TimeRange->setItemText(2, QCoreApplication::translate("MainWindow", "1080", nullptr));
        comboBox_TimeRange->setItemText(3, QCoreApplication::translate("MainWindow", "1440", nullptr));
        comboBox_TimeRange->setItemText(4, QCoreApplication::translate("MainWindow", "1800", nullptr));
        comboBox_TimeRange->setItemText(5, QCoreApplication::translate("MainWindow", "2160", nullptr));
        comboBox_TimeRange->setItemText(6, QCoreApplication::translate("MainWindow", "2520", nullptr));
        comboBox_TimeRange->setItemText(7, QCoreApplication::translate("MainWindow", "2880", nullptr));
        comboBox_TimeRange->setItemText(8, QCoreApplication::translate("MainWindow", "3240", nullptr));
        comboBox_TimeRange->setItemText(9, QCoreApplication::translate("MainWindow", "3600", nullptr));

        pushButton_StartSquare->setText(QCoreApplication::translate("MainWindow", "Start Square", nullptr));
        label_GraphModule->setText(QCoreApplication::translate("MainWindow", "Module", nullptr));
        label_RangeMinimum->setText(QCoreApplication::translate("MainWindow", "Range minimum", nullptr));
        lineEdit_SineStopDegrees->setText(QCoreApplication::translate("MainWindow", "720", nullptr));
        pushButton_SetRanges->setText(QCoreApplication::translate("MainWindow", "Set Ranges", nullptr));
        label_Square->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        label_Sine->setText(QCoreApplication::translate("MainWindow", "Sine", nullptr));
        label_SquareStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_SineStopDegrees->setText(QCoreApplication::translate("MainWindow", "Stop degrees", nullptr));
        label_SineStartDegrees->setText(QCoreApplication::translate("MainWindow", "Start degrees", nullptr));
        pushButton_StartLinear->setText(QCoreApplication::translate("MainWindow", "Start Linear", nullptr));
        label_RangeMaximum->setText(QCoreApplication::translate("MainWindow", "Range maximum", nullptr));
        lineEdit_RangeMinimum->setText(QCoreApplication::translate("MainWindow", "-10000", nullptr));
        pushButton_StartSine->setText(QCoreApplication::translate("MainWindow", "Start Sine", nullptr));
        lineEdit_SquarePeriod->setText(QCoreApplication::translate("MainWindow", "180", nullptr));
        lineEdit_SquareStart->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_LinearStart->setText(QCoreApplication::translate("MainWindow", "-10000", nullptr));
        comboBox_GraphSignalCount->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_GraphSignalCount->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_GraphSignalCount->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_GraphSignalCount->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));

        label_LinearStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_SineAmplitude->setText(QCoreApplication::translate("MainWindow", "Amplitude", nullptr));
        label_SignalCount->setText(QCoreApplication::translate("MainWindow", "Signal count", nullptr));
        lineEdit_SquareStop->setText(QCoreApplication::translate("MainWindow", "720", nullptr));
        label_SquareStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        lineEdit_LinearStop->setText(QCoreApplication::translate("MainWindow", "10000", nullptr));
        label_SquareAmplitude->setText(QCoreApplication::translate("MainWindow", "Amplitude", nullptr));
        label_TimeRange->setText(QCoreApplication::translate("MainWindow", "Time range", nullptr));
        label_SquarePeriod->setText(QCoreApplication::translate("MainWindow", "Period", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
