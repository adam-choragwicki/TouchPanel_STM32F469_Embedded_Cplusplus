#include "table_view.h"
#include "packet_field_definitions.h"
#include <QStringList>

TableView::TableView(Ui::MainWindow* ui)
{
    m_pUi = ui;
    m_pTableWidget = m_pUi->tableWidget_PacketDisplay;

    InitPacketDisplay();
}

void TableView::InitPacketDisplay()
{
    QStringList packetFieldNames;

    packetFieldNames.insert(0, "Source");
    packetFieldNames.insert(1, "Module");
    packetFieldNames.insert(2, "Function");
    packetFieldNames.insert(3, "Parameter");
    packetFieldNames.insert(4, "Sign");
    packetFieldNames.insert(5, "Length");
    packetFieldNames.insert(6, "P1");
    packetFieldNames.insert(7, "P2");
    packetFieldNames.insert(8, "P3");
    packetFieldNames.insert(9, "P4");
    packetFieldNames.insert(10, "P5");
    packetFieldNames.insert(11, "P6");
    packetFieldNames.insert(12, "P7");
    packetFieldNames.insert(13, "P8");
    packetFieldNames.insert(14, "P9");
    packetFieldNames.insert(15, "P10");
    packetFieldNames.insert(16, "CRC1");
    packetFieldNames.insert(17, "CRC2");
    packetFieldNames.insert(18, "CRC3");
    packetFieldNames.insert(19, "CRC4");

    m_pTableWidget->setColumnCount(PACKET_SIZE);

    m_pTableWidget->horizontalHeader()->setStretchLastSection(true);

    m_pTableWidget->setHorizontalHeaderLabels(packetFieldNames);

    for(int column=0; column < PACKET_SIZE; column++)
    {
        m_pTableWidget->setColumnWidth(column, 90);
    }
}

void TableView::UpdatePacketDisplay(uint8_t uartPacket[], bool isReceivedPacket, bool isCrcCorrect)
{
    int rowCount = m_pTableWidget->rowCount();

    m_pTableWidget->insertRow(rowCount);

    QTableWidgetItem* source = new QTableWidgetItem(QChar(uartPacket[0]));
    source->setTextAlignment(Qt::AlignCenter);
    source->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* module = new QTableWidgetItem(QChar(uartPacket[1]));
    module->setTextAlignment(Qt::AlignCenter);
    module->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* function = new QTableWidgetItem(QChar(uartPacket[2]));
    function->setTextAlignment(Qt::AlignCenter);
    function->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* parameter = new QTableWidgetItem(QChar(uartPacket[3]));
    parameter->setTextAlignment(Qt::AlignCenter);
    parameter->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* sign = new QTableWidgetItem(QChar(uartPacket[4]));
    sign->setTextAlignment(Qt::AlignCenter);
    sign->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* length = new QTableWidgetItem(QChar(uartPacket[5]));
    length->setTextAlignment(Qt::AlignCenter);
    length->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload1 = new QTableWidgetItem(QChar(uartPacket[6]));
    payload1->setTextAlignment(Qt::AlignCenter);
    payload1->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload2 = new QTableWidgetItem(QChar(uartPacket[7]));
    payload2->setTextAlignment(Qt::AlignCenter);
    payload2->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload3 = new QTableWidgetItem(QChar(uartPacket[8]));
    payload3->setTextAlignment(Qt::AlignCenter);
    payload3->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload4 = new QTableWidgetItem(QChar(uartPacket[9]));
    payload4->setTextAlignment(Qt::AlignCenter);
    payload4->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload5 = new QTableWidgetItem(QChar(uartPacket[10]));
    payload5->setTextAlignment(Qt::AlignCenter);
    payload5->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload6 = new QTableWidgetItem(QChar(uartPacket[11]));
    payload6->setTextAlignment(Qt::AlignCenter);
    payload6->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload7 = new QTableWidgetItem(QChar(uartPacket[12]));
    payload7->setTextAlignment(Qt::AlignCenter);
    payload7->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload8 = new QTableWidgetItem(QChar(uartPacket[13]));
    payload8->setTextAlignment(Qt::AlignCenter);
    payload8->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload9 = new QTableWidgetItem(QChar(uartPacket[14]));
    payload9->setTextAlignment(Qt::AlignCenter);
    payload9->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* payload10 = new QTableWidgetItem(QChar(uartPacket[15]));
    payload10->setTextAlignment(Qt::AlignCenter);
    payload10->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* crc1 = new QTableWidgetItem(QString::number(uartPacket[16]));
    crc1->setTextAlignment(Qt::AlignCenter);
    crc1->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* crc2 = new QTableWidgetItem(QString::number(uartPacket[17]));
    crc2->setTextAlignment(Qt::AlignCenter);
    crc2->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* crc3 = new QTableWidgetItem(QString::number(uartPacket[18]));
    crc3->setTextAlignment(Qt::AlignCenter);
    crc3->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    QTableWidgetItem* crc4 = new QTableWidgetItem(QString::number(uartPacket[19]));
    crc4->setTextAlignment(Qt::AlignCenter);
    crc4->setFlags(Qt::ItemFlag::NoItemFlags | Qt::ItemFlag::ItemIsEnabled);

    m_pTableWidget->setItem(rowCount, 0, source);
    m_pTableWidget->setItem(rowCount, 1, module);
    m_pTableWidget->setItem(rowCount, 2, function);
    m_pTableWidget->setItem(rowCount, 3, parameter);
    m_pTableWidget->setItem(rowCount, 4, sign);
    m_pTableWidget->setItem(rowCount, 5, length);
    m_pTableWidget->setItem(rowCount, 6, payload1);
    m_pTableWidget->setItem(rowCount, 7, payload2);
    m_pTableWidget->setItem(rowCount, 8, payload3);
    m_pTableWidget->setItem(rowCount, 9, payload4);
    m_pTableWidget->setItem(rowCount, 10, payload5);
    m_pTableWidget->setItem(rowCount, 11, payload6);
    m_pTableWidget->setItem(rowCount, 12, payload7);
    m_pTableWidget->setItem(rowCount, 13, payload8);
    m_pTableWidget->setItem(rowCount, 14, payload9);
    m_pTableWidget->setItem(rowCount, 15, payload10);
    m_pTableWidget->setItem(rowCount, 16, crc1);
    m_pTableWidget->setItem(rowCount, 17, crc2);
    m_pTableWidget->setItem(rowCount, 18, crc3);
    m_pTableWidget->setItem(rowCount, 19, crc4);

    /*Mark every packet's payload in yellow*/
    for(int column = 6; column < 16; column++)
    {
        m_pTableWidget->item(rowCount, column)->setBackground(QBrush(Qt::yellow));
    }

    if(isReceivedPacket == true)
    {
        if(isCrcCorrect == true)
        {
            for(int column = 0; column < PACKET_SIZE; column++)
            {
                m_pTableWidget->item(rowCount, column)->setBackground(QBrush(Qt::green));
            }

            for(int column = 6; column < 16; column++)
            {
                m_pTableWidget->item(rowCount, column)->setBackground(QBrush(Qt::yellow));
            }
        }
        else
        {
            for(int column = 0; column < PACKET_SIZE; column++)
            {
                m_pTableWidget->item(rowCount, column)->setBackground(QBrush(Qt::red));
            }
        }
    }
    /*Mark also wrong CRC outbound packets with red color*/
    else
    {
        if(isCrcCorrect == false)
        {
            for(int column = 0; column < PACKET_SIZE; column++)
            {
                m_pTableWidget->item(rowCount, column)->setBackground(QBrush(Qt::red));
            }
        }
    }

    m_pTableWidget->scrollToBottom();
}

void TableView::ClearPacketDisplay()
{
    m_pTableWidget->clearContents();
    m_pTableWidget->setRowCount(0);
}
