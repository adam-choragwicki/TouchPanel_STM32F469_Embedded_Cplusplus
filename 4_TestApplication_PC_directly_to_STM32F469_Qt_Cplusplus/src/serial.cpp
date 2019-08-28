#include "serial.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

Serial::Serial(Ui::MainWindow* ui)
{
    m_pUi = ui;

    connect(this, &Serial::readyRead, this, &Serial::SerialDataReceived);
}

void Serial::InitPortList()
{
    QString myPortDescription = "Prolific USB-to-Serial Comm Port";
    quint16 myPortIdentifier = 8963;

    qDebug() << "Number of serial ports available:" << QSerialPortInfo::availablePorts().count();

    QList<QSerialPortInfo> availablePortList = QSerialPortInfo::availablePorts();

    bool myPortFound = false;

    /*Check if my port is present in system*/
    for(auto port : availablePortList)
    {
        if(port.description() == myPortDescription && port.productIdentifier() == myPortIdentifier)
        {
            myPortFound = true;
        }
    }

    if(myPortFound)
    {
        /*Add only my port name to list*/
        for(auto port : availablePortList)
        {
            if(port.description() == myPortDescription)
            {
                m_pUi->comboBox_Port->addItem(port.portName());
            }
        }
    }
    else
    {
        /*Add all present port names to list*/
        for(auto port : availablePortList)
        {
            m_pUi->comboBox_Port->addItem(port.portName());
        }
    }
}

bool Serial::OpenPort(QString portName)
{
    setPortName(portName);

    /*Check if port is already open*/
    if(isOpen())
    {
        qDebug("Port is already open");
        return false;
    }

    setBaudRate(QSerialPort::Baud115200);
    setDataBits(QSerialPort::Data8);
    setParity(QSerialPort::NoParity);
    setStopBits(QSerialPort::OneStop);
    setFlowControl(QSerialPort::NoFlowControl);

    if(open(QIODevice::ReadWrite))
    {
        qDebug("Port opened successfully");
        m_pUi->label_ShowStatus->setText("<font color='green'>Open</font>");

        EnableGui();

        return true;
    }
    else
    {
        qDebug("Could not open port");
        m_pUi->label_ShowStatus->setText("Closed");

        return false;
    }
}

void Serial::ClosePort(QString portName)
{
    setPortName(portName);

    if(isOpen() == true)
    {
        close();

        /*Ensure port was closed*/
        if(isOpen() == false)
        {
            qDebug("Port closed successfully");
            m_pUi->label_ShowStatus->setText("<font color='red'>Close</font>");

            DisableGui();
        }
        else
        {
            /*Could not close port*/
            QMessageBox::warning(nullptr, "Port error", "Port could not be closed");
        }
    }
    else
    {
        qDebug("Port is not open, cannot close");
    }
}

void Serial::SendPacket(uint8_t* const uartPacketTable)
{
    write(reinterpret_cast<const char*>(uartPacketTable), PACKET_SIZE);
    waitForBytesWritten(3000);
    flush();
}

/*Slot*/
void Serial::SerialDataReceived()
{
    static QByteArray receivedBytes;

    receivedBytes += readAll();

    if(receivedBytes.size() >= PACKET_SIZE)
    {
        qDebug("FULL PACKET RECEIVED");
        qDebug("Received Packet is: %.16s", receivedBytes.constData());
        emit(FullPacketReceived(receivedBytes));
        receivedBytes.clear();
    }
}

void Serial::EnableGui()
{
    m_pUi->comboBox_Port->setEnabled(false);
    m_pUi->groupBox_ModuleControls->setEnabled(true);
    m_pUi->groupBox_CustomPacketControls ->setEnabled(true);
    m_pUi->groupBox_GraphControls->setEnabled(true);
    m_pUi->groupBox_PacketDisplay->setEnabled(true);
    m_pUi->groupBox_Module1->setEnabled(true);
    m_pUi->groupBox_Module2->setEnabled(true);
    m_pUi->groupBox_Module3->setEnabled(true);
}

void Serial::DisableGui()
{
    m_pUi->comboBox_Port->setEnabled(true);
    m_pUi->groupBox_ModuleControls->setEnabled(false);
    m_pUi->groupBox_CustomPacketControls ->setEnabled(false);
    m_pUi->groupBox_GraphControls->setEnabled(false);
    m_pUi->groupBox_PacketDisplay->setEnabled(false);
    m_pUi->groupBox_Module1->setEnabled(false);
    m_pUi->groupBox_Module2->setEnabled(false);
}
