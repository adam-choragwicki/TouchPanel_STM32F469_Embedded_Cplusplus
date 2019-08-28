#pragma once

#include <QSerialPort>
#include "ui_main_window.h"
#include "packet_field_definitions.h"

class Serial : public QSerialPort
{
    Q_OBJECT

public:
    Serial(Ui::MainWindow* ui);
    void InitPortList();
    bool OpenPort(QString portName);
    void ClosePort(QString portName);
    void SendPacket(uint8_t * const uartPacketTable);

private:
    Ui::MainWindow* m_pUi;

    void EnableGui();
    void DisableGui();

signals:
    void FullPacketReceived(QByteArray& receivedBytes);

private slots:
    void SerialDataReceived();
};
