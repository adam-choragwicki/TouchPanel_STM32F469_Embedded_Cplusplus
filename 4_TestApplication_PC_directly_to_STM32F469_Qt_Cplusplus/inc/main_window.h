#pragma once

#include <QMainWindow>
#include <QDebug>
#include "QtSerialPort/QSerialPort"
#include "uart_packet.h"
#include "module.h"
#include "table_view.h"
#include "serial.h"
#include <memory>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void InitPacketDisplay();
    void InitPortList();

    void UpdateGUI();

    /*Functionalities*/
    void InitConnectionModule(ModuleID module);
    void DeinitConnectionModule(ModuleID module);
    void SetRangeMinimum();
    void SetRangeMaximum();
    void SetRangeTime();
    void SendCustomPacket();
    void SendWrongCrcDataPacket();
    void GenerateLinearGraph(int signalCount);
    void GenerateSineGraph(int signalCount);
    void GenerateSquareGraph(int signalCount);
    void SendGraphPacket(UartPacket& uartPacket);
    bool ValidateFloatingPointInput(QString input, QString functionName);
    bool ValidateIntegerInput(QString input, QString functionName);

private slots:
    void ProcessReceivedPacket(QByteArray& receivedBytes);

    void on_pushButton_Open_clicked();
    void on_pushButton_Send_pressed();
    void on_pushButton_InitConnectionModule1_clicked();
    void on_pushButton_InitConnectionModule2_clicked();
    void on_pushButton_InitConnectionModule3_clicked();
    void on_pushButton_DeinitConnectionModule1_clicked();
    void on_pushButton_DeinitConnectionModule2_clicked();
    void on_pushButton_DeinitConnectionModule3_clicked();
    void on_pushButton_StartLinear_clicked();
    void on_pushButton_StartSine_clicked();
    void on_pushButton_StartSquare_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Close_clicked();
    void on_pushButton_SendWrongCrcPacket_clicked();
    void on_pushButton_SetRanges_clicked();
    void on_pushButton_ClearTable_clicked();

private:
    Ui::MainWindow* ui;

    Serial m_Serial;
    std::unique_ptr<TableView> m_pTableView;

    Module m_Module1;
    Module m_Module2;
    Module m_Module3;

    bool m_stopPressed = false;
};
