#pragma once

#include <QWidget>
#include "ui_main_window.h"

class TableView
{
public:
    TableView() = delete;
    TableView(const TableView&) = delete;
    TableView& operator=(TableView&) = delete;
    TableView(const TableView&&) = delete;
    TableView& operator=(TableView&&) = delete;

    TableView(Ui::MainWindow* pUiHandle);
    void InitPacketDisplay();
    void UpdatePacketDisplay(uint8_t UART_MessageToTransmit[], bool isReceivedPacket, bool isCrcCorrect=true);
    void ClearPacketDisplay();

private:
    Ui::MainWindow* m_pUi = nullptr;
    QTableWidget* m_pTableWidget = nullptr;
};
