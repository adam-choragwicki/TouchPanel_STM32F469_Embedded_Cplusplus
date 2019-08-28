#include "main_window.h"
#include "ui_main_window.h"
#include "packet_field_definitions.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include "init_parameters_xml_loader.h"
#include <cmath> //for sin()
#include "windows.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_Serial(ui)
{
    ui->setupUi(this);

    m_Serial.InitPortList();

    m_pTableView = std::make_unique<TableView>(ui);

    connect(&m_Serial, &Serial::FullPacketReceived, this, &MainWindow::ProcessReceivedPacket);

    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Slot*/
void MainWindow::ProcessReceivedPacket(QByteArray& receivedBytes)
{
    qDebug() << "Processing received packet";

    UartPacket uartPacket(reinterpret_cast<const uint8_t*>(receivedBytes.constData()));

    uint8_t uartReceivedPacket[PACKET_SIZE] = {0};

    for(int i=0; i<PACKET_SIZE; i++)
    {
        uartReceivedPacket[i] = static_cast<uint8_t>(receivedBytes.at(i));
    }

    if(uartPacket.CheckCrc32() == true)
    {
        m_pTableView->UpdatePacketDisplay(uartReceivedPacket, true, true);
    }
    else
    {
        m_pTableView->UpdatePacketDisplay(uartReceivedPacket, true, false);

        qDebug("Wrong CRC, packet discarded");

        return;
    }

    QCoreApplication::processEvents();

    Module* p_CurrentModule = nullptr;

    ModuleID moduleID = uartPacket.GetModule();

    if(moduleID == ModuleID::MODULE1)
    {
        qDebug() << "Module 1";
        p_CurrentModule = &m_Module1;
    }
    else if(moduleID == ModuleID::MODULE2)
    {
        qDebug() << "Module 2";
        p_CurrentModule = &m_Module2;
    }
    else if(moduleID == ModuleID::MODULE3)
    {
        qDebug() << "Module 3";
        p_CurrentModule = &m_Module3;
    }
    else
    {
        qDebug() << "ERROR - Incorrect received packet - Wrong module field in received packet. Packet discarded";
        return;
    }

    Function function = uartPacket.GetFunction();
    Parameter parameter = uartPacket.GetParameter();

    double valueDouble = 0;

    switch(function)
    {
    case Function::DATA_PACKET:
        qDebug() << "Data transfer packet";
        break;

    case Function::ENABLE_PARAMETER_PACKET:
        qDebug() << "Enable parameter";

        p_CurrentModule->EnableParameter(parameter);

        break;

    case Function::DISABLE_PARAMETER_PACKET:
        qDebug() << "Disable parameter";

        p_CurrentModule->DisableParameter(parameter);

        break;

    case Function::SET_PARAMETER_PACKET:
        qDebug() << "Set parameter";

        try
    {
        /*Try to convert packet payload to real number*/
        valueDouble = std::stod(reinterpret_cast<const char*>(uartPacket.GetPayload()));
    }
        catch (std::invalid_argument)
        {
            QMessageBox::warning(this, "ERROR", "Packet payload could not be converted to number, aborting");
            return;
        }

        if(uartPacket.GetSign() == Sign::NEGATIVE_SIGN)
        {
            /*Make value negative if it was marked as negative in UART Packet*/
            valueDouble = valueDouble * (-1);
        }

        p_CurrentModule->SetParameter(parameter,valueDouble);

        break;

    default:
        qDebug() << "ERROR - Incorrect received packet - Wrong function type";
    }

    UpdateGUI();
}

void MainWindow::InitConnectionModule(ModuleID module)
{
    UartPacket uartPacket[INIT_PACKETS_COUNT];

    for(int i = 0; i < INIT_PACKETS_COUNT; i++)
    {
        uartPacket[i].SetSource(Source::SOURCE_TARGET1);
        uartPacket[i].SetModule(module);
        uartPacket[i].SetFunction(Function::INIT_PACKET);
        uartPacket[i].SetParameter(Parameter::NULL_PARAMETER);
        uartPacket[i].SetSign(Sign::POSITIVE_SIGN);
    }

    QString initInfoValuesModule1[INIT_PACKETS_COUNT] = {ui->label_Module1InitParameter1Name->text(),
                                                         ui->label_Module1InitParameter2Name->text(),
                                                         ui->label_Module1InitParameter3Name->text(),
                                                         ui->label_Module1InitParameter4Name->text(),
                                                         ui->label_Module1InitParameter5Name->text(),
                                                         ui->lineEdit_Module1InitParameter1Value->text(),
                                                         ui->lineEdit_Module1InitParameter2Value->text(),
                                                         ui->lineEdit_Module1InitParameter3Value->text(),
                                                         ui->lineEdit_Module1InitParameter4Value->text(),
                                                         ui->lineEdit_Module1InitParameter5Value->text(),
                                                         ui->label_Module1Parameter1Name->text(),
                                                         ui->label_Module1Parameter2Name->text(),
                                                         ui->label_Module1Parameter3Name->text(),
                                                         ui->label_Module1Parameter4Name->text(),
                                                         ui->lineEdit_Module1Parameter1Name->text(),
                                                         ui->lineEdit_Module1Parameter2Name->text(),
                                                         ui->lineEdit_Module1Parameter3Name->text(),
                                                         ui->lineEdit_Module1Parameter4Name->text(),
                                                         ui->label_Module1_SettableParameter1Name->text(),
                                                         ui->label_Module1_SettableParameter2Name->text(),
                                                         ui->label_Module1_SettableParameter3Name->text(),
                                                         ui->label_Module1_SettableParameter4Name->text(),
                                                         ui->label_Module1_SettableParameter5Name->text(),
                                                         ui->label_Module1_SettableParameter6Name->text(),
                                                         ui->label_Module1_SettableParameter7Name->text(),
                                                         ui->label_Module1_SettableParameter8Name->text(),
                                                         ui->label_Module1_SettableParameter9Name->text(),
                                                         ui->label_Module1_SettableParameter10Name->text()
                                                        };

    for(auto value : initInfoValuesModule1)
    {
        if(value.size() > PAYLOAD_SIZE)
        {
            QMessageBox::warning(this, "Warning", "Module 1 initialization parameter value is too long,"
                                                  " maximum allowed length is 10. Aborting module initialization");
            return;
        }
    }

    QString initInfoValuesModule2[INIT_PACKETS_COUNT] = {ui->label_Module2InitParameter1Name->text(),
                                                         ui->label_Module2InitParameter2Name->text(),
                                                         ui->label_Module2InitParameter3Name->text(),
                                                         ui->label_Module2InitParameter4Name->text(),
                                                         ui->label_Module2InitParameter5Name->text(),
                                                         ui->lineEdit_Module2InitParameter1Value->text(),
                                                         ui->lineEdit_Module2InitParameter2Value->text(),
                                                         ui->lineEdit_Module2InitParameter3Value->text(),
                                                         ui->lineEdit_Module2InitParameter4Value->text(),
                                                         ui->lineEdit_Module2InitParameter5Value->text(),
                                                         ui->label_Module2Parameter1Name->text(),
                                                         ui->label_Module2Parameter2Name->text(),
                                                         ui->label_Module2Parameter3Name->text(),
                                                         ui->label_Module2Parameter4Name->text(),
                                                         ui->lineEdit_Module2Parameter1Name->text(),
                                                         ui->lineEdit_Module2Parameter2Name->text(),
                                                         ui->lineEdit_Module2Parameter3Name->text(),
                                                         ui->lineEdit_Module2Parameter4Name->text(),
                                                         ui->label_Module2_SettableParameter1Name->text(),
                                                         ui->label_Module2_SettableParameter2Name->text(),
                                                         ui->label_Module2_SettableParameter3Name->text(),
                                                         ui->label_Module2_SettableParameter4Name->text(),
                                                         ui->label_Module2_SettableParameter5Name->text(),
                                                         ui->label_Module2_SettableParameter6Name->text(),
                                                         ui->label_Module2_SettableParameter7Name->text(),
                                                         ui->label_Module2_SettableParameter8Name->text(),
                                                         ui->label_Module2_SettableParameter9Name->text(),
                                                         ui->label_Module2_SettableParameter10Name->text()
                                                        };

    for(auto value : initInfoValuesModule2)
    {
        if(value.size() > PAYLOAD_SIZE)
        {
            QMessageBox::warning(this, "Warning", "Module 2 initialization parameter value is too long,"
                                                  " maximum allowed length is 10. Aborting module initialization");
            return;
        }
    }

    QString initInfoValuesModule3[INIT_PACKETS_COUNT] = {ui->label_Module3InitParameter1Name->text(),
                                                         ui->label_Module3InitParameter2Name->text(),
                                                         ui->label_Module3InitParameter3Name->text(),
                                                         ui->label_Module3InitParameter4Name->text(),
                                                         ui->label_Module3InitParameter5Name->text(),
                                                         ui->lineEdit_Module3InitParameter1Value->text(),
                                                         ui->lineEdit_Module3InitParameter2Value->text(),
                                                         ui->lineEdit_Module3InitParameter3Value->text(),
                                                         ui->lineEdit_Module3InitParameter4Value->text(),
                                                         ui->lineEdit_Module3InitParameter5Value->text(),
                                                         ui->label_Module3Parameter1Name->text(),
                                                         ui->label_Module3Parameter2Name->text(),
                                                         ui->label_Module3Parameter3Name->text(),
                                                         ui->label_Module3Parameter4Name->text(),
                                                         ui->lineEdit_Module3Parameter1Name->text(),
                                                         ui->lineEdit_Module3Parameter2Name->text(),
                                                         ui->lineEdit_Module3Parameter3Name->text(),
                                                         ui->lineEdit_Module3Parameter4Name->text(),
                                                         ui->label_Module3_SettableParameter1Name->text(),
                                                         ui->label_Module3_SettableParameter2Name->text(),
                                                         ui->label_Module3_SettableParameter3Name->text(),
                                                         ui->label_Module3_SettableParameter4Name->text(),
                                                         ui->label_Module3_SettableParameter5Name->text(),
                                                         ui->label_Module3_SettableParameter6Name->text(),
                                                         ui->label_Module3_SettableParameter7Name->text(),
                                                         ui->label_Module3_SettableParameter8Name->text(),
                                                         ui->label_Module3_SettableParameter9Name->text(),
                                                         ui->label_Module3_SettableParameter10Name->text()
                                                        };

    for(auto value : initInfoValuesModule3)
    {
        if(value.size() > PAYLOAD_SIZE)
        {
            QMessageBox::warning(this, "Warning", "Module 3 initialization parameter value is too long,"
                                                  " maximum allowed length is 10. Aborting module initialization");
            return;
        }
    }

    for(int i = 0; i < INIT_PACKETS_COUNT; i++)
    {
        if(module == ModuleID::MODULE1)
        {
            uartPacket[i].SetPayload(initInfoValuesModule1[i].toStdString().c_str());
        }
        else if(module == ModuleID::MODULE2)
        {
            uartPacket[i].SetPayload(initInfoValuesModule2[i].toStdString().c_str());
        }
        else if(module == ModuleID::MODULE3)
        {
            uartPacket[i].SetPayload(initInfoValuesModule3[i].toStdString().c_str());
        }

        uint8_t length = static_cast<uint8_t>(strlen(reinterpret_cast<char const*>(uartPacket[i].GetPayload())));

        uartPacket[i].SetLength(length);

        uartPacket[i].AppendCrcToPacket();

        qDebug("Init Packet is: %s", static_cast<uint8_t*>(uartPacket[i]));

        m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket[i]), false);

        m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket[i]));

        Sleep(uint(10));

        QCoreApplication::processEvents();
    }
}

void MainWindow::DeinitConnectionModule(ModuleID module)
{
    UartPacket uartPacket;

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(module);
    uartPacket.SetFunction(Function::DEINIT_PACKET);
    uartPacket.SetSign(Sign::POSITIVE_SIGN);
    uartPacket.SetParameter(Parameter::NULL_PARAMETER);
    uartPacket.SetLength(Length::NO_PAYLOAD);

    uartPacket.AppendCrcToPacket();

    qDebug("Deinit Packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));
}

void MainWindow::SetRangeMinimum()
{
    UartPacket uartPacket;

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(ui->comboBox_GraphModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(Function::SET_GRAPH_RANGE_MIN);
    uartPacket.SetParameter(Parameter::NULL_PARAMETER);

    QString enteredMinimumRange = ui->lineEdit_RangeMinimum->text();

    if(!ValidateIntegerInput(enteredMinimumRange, "SetRangeMinimum"))
    {
        return;
    }

    if(enteredMinimumRange.at(0).toLatin1() == '-')
    {
        uartPacket.SetSign(Sign::NEGATIVE_SIGN);

        /*Remove minus sign*/
        enteredMinimumRange.remove(0,1);
    }
    else if(enteredMinimumRange.at(0).toLatin1() == '+')
    {
        uartPacket.SetSign(Sign::POSITIVE_SIGN);

        /*Remove plus sign*/
        enteredMinimumRange.remove(0,1);
    }

    int length = enteredMinimumRange.length();

    uartPacket.SetLength(length);

    uartPacket.SetPayload(enteredMinimumRange.toLatin1());

    uartPacket.AppendCrcToPacket();

    qDebug("Set range minimum packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));
}

void MainWindow::SetRangeMaximum()
{
    UartPacket uartPacket;

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(ui->comboBox_GraphModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(Function::SET_GRAPH_RANGE_MAX);
    uartPacket.SetParameter(Parameter::NULL_PARAMETER);

    QString enteredMaximumRange = ui->lineEdit_RangeMaximum->text();

    if(!ValidateIntegerInput(enteredMaximumRange, "SetRangeMaximum"))
    {
        return;
    }

    if(enteredMaximumRange.at(0).toLatin1() == '-')
    {
        uartPacket.SetSign(Sign::NEGATIVE_SIGN);

        /*Remove minus sign*/
        enteredMaximumRange.remove(0,1);
    }
    else if(enteredMaximumRange.at(0).toLatin1() == '+')
    {
        uartPacket.SetSign(Sign::POSITIVE_SIGN);

        /*Remove plus sign*/
        enteredMaximumRange.remove(0,1);
    }

    int length = enteredMaximumRange.length();

    uartPacket.SetLength(length);

    uartPacket.SetPayload(enteredMaximumRange.toLatin1());

    uartPacket.AppendCrcToPacket();

    qDebug("Set range maximum packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));
}

void MainWindow::SetRangeTime()
{
    UartPacket uartPacket;

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(ui->comboBox_GraphModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(Function::SET_GRAPH_TIME_RANGE);
    uartPacket.SetParameter(Parameter::NULL_PARAMETER);
    uartPacket.SetSign(Sign::POSITIVE_SIGN);

    QString enteredTimeRangeString = ui->comboBox_TimeRange->currentText();

    if(!ValidateIntegerInput(enteredTimeRangeString, "SetRangeTime"))
    {
        return;
    }

    int enteredTimeRangeInteger = enteredTimeRangeString.toInt();

    if((enteredTimeRangeString.at(0).toLatin1() == '-') || enteredTimeRangeInteger < 360 || enteredTimeRangeInteger > 3600 || enteredTimeRangeInteger % 360 != 0)
    {
        qDebug() << "Wrong time range entered";
        return;
    }

    int length = enteredTimeRangeString.length();

    uartPacket.SetLength(length);

    uartPacket.SetPayload(enteredTimeRangeString.toLatin1());

    uartPacket.AppendCrcToPacket();

    qDebug("Set range time packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));
}

void MainWindow::SendCustomPacket()
{
    UartPacket uartPacket;

    uartPacket.SetSource(ui->comboBox_CustomPacketSource->currentText().at(0).toLatin1());
    uartPacket.SetModule(ui->comboBox_CustomPacketModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(ui->comboBox_CustomPacketFunction->currentText().at(0).toLatin1());
    uartPacket.SetParameter(ui->comboBox_CustomPacketParameter->currentText().at(0).toLatin1());

    QString enteredPayload = ui->lineEdit_CustomPacketPayload->text();

    if(!ValidateFloatingPointInput(enteredPayload, "SendCustomPacket"))
    {
        return;
    }

    if(enteredPayload.at(0).toLatin1() == '-')
    {
        ui->lineEdit_CustomPacketSign->setText("2");
        uartPacket.SetSign(Sign::NEGATIVE_SIGN);

        /*Remove minus sign*/
        enteredPayload.remove(0,1);
    }
    else if(enteredPayload.at(0).toLatin1() == '+')
    {
        ui->lineEdit_CustomPacketSign->setText("1");
        uartPacket.SetSign(Sign::POSITIVE_SIGN);

        /*Remove plus sign*/
        enteredPayload.remove(0,1);
    }
    else
    {
        ui->lineEdit_CustomPacketSign->setText("1");
        uartPacket.SetSign(Sign::POSITIVE_SIGN);
    }

    int length = enteredPayload.length();

    uartPacket.SetLength(length);

    uartPacket.SetPayload(enteredPayload.toLatin1());

    ui->lineEdit_CustomPacketLength->setText(QString::number(length));

    uartPacket.AppendCrcToPacket();

    qDebug("Custom Packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));
}

void MainWindow::SendWrongCrcDataPacket()
{
    UartPacket uartPacket;

    uartPacket.SetSource(ui->comboBox_CustomPacketSource->currentText().at(0).toLatin1());
    uartPacket.SetModule(ui->comboBox_CustomPacketModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(ui->comboBox_CustomPacketFunction->currentText().at(0).toLatin1());
    uartPacket.SetParameter(ui->comboBox_CustomPacketParameter->currentText().at(0).toLatin1());
    uartPacket.SetLength(Length::NO_PAYLOAD);
    uartPacket.SetSign(Sign::POSITIVE_SIGN);

    /*Set wrong all zeros CRC*/
    uartPacket.SetWrongCrc();

    qDebug("Wrong crc packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false, false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));
}

void MainWindow::GenerateLinearGraph(int signalCount)
{
    UartPacket uartPacket;

    QString strStartValue = ui->lineEdit_LinearStart->text();
    QString strStopValue = ui->lineEdit_LinearStop->text();
    QString strStepValue = ui->lineEdit_LinearStep->text();

    QString functionName = "GenerateLinearGraph";

    if(!ValidateFloatingPointInput(strStartValue, functionName) ||
            !ValidateFloatingPointInput(strStopValue, functionName) ||
            !ValidateFloatingPointInput(strStepValue, functionName))
    {
        return;
    }

    double startValue = strStartValue.toDouble();
    double stopValue = strStopValue.toDouble();
    double stepValue = strStepValue.toDouble();

    if(startValue >= stopValue)
    {
        QMessageBox::warning(this, "ERROR", "GenerateLinearGraph: Start values is higher than or equal to stop value, aborting");
        return;
    }

    if(stepValue < 0)
    {
        QMessageBox::warning(this, "ERROR", "GenerateLinearGraph: Negative step value not supported, aborting");
        return;
    }

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(ui->comboBox_GraphModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(Function::DATA_PACKET);

    uint8_t length;

    double value;

    Parameter parameters[4] = {Parameter::GRAPH_PARAMETER1, Parameter::GRAPH_PARAMETER2, Parameter::GRAPH_PARAMETER3, Parameter::GRAPH_PARAMETER4};

    for(double x = startValue; x < stopValue; x = x + stepValue)
    {
        for(int signalNumber = 0; signalNumber < signalCount; signalNumber++)
        {
            uartPacket.SetParameter(parameters[signalNumber]);

            value = x;

            if(value < 0)
            {
                /*Change value sign back to positive and mark it as negative in UART packet*/
                value = value * (-1);
                uartPacket.SetSign(Sign::NEGATIVE_SIGN);
            }
            else
            {
                uartPacket.SetSign(Sign::POSITIVE_SIGN);
            }

            /*Change parameter values so that graph lines do not overlap each other*/
            switch(signalNumber)
            {
            case 1:
                value = value * 0.75;
                break;
            case 2:
                value = value * 0.5;
                break;
            case 3:
                value = value * 0.25;
                break;
            }

            /*Temporary buffer for number-string conversion with additional space for null character*/
            char tempBuffer[PAYLOAD_SIZE + 1] = {0};

            /*Convert double number to string and write it to temporary buffer*/
            snprintf(tempBuffer , PAYLOAD_SIZE + 1, "%lf", value);

            length = static_cast<uint8_t>(strlen(tempBuffer));

            uartPacket.SetPayload(tempBuffer);

            uartPacket.SetLength(length);

            SendGraphPacket(uartPacket);
        }

        if (m_stopPressed)
        {
            qDebug("STOP PRESSED");
            m_stopPressed = false;
            return;
        }

        QCoreApplication::processEvents();
    }
}

void MainWindow::GenerateSineGraph(int signalCount)
{
    UartPacket uartPacket;

    QString strStartDegrees = ui->lineEdit_SineStartDegrees->text();
    QString strStopDegrees = ui->lineEdit_SineStopDegrees->text();
    QString strAmplitude = ui->lineEdit_SineAmplitude->text();

    QString functionName = "GenerateSineGraph";

    if(!ValidateIntegerInput(strStartDegrees, functionName) ||
            !ValidateIntegerInput(strStopDegrees, functionName) ||
            !ValidateFloatingPointInput(strAmplitude, functionName))
    {
        return;
    }

    int startDegrees = strStartDegrees.toInt();
    int stopDegrees = strStopDegrees.toInt();
    double amplitude = strAmplitude.toDouble();

    if(startDegrees > stopDegrees)
    {
        QMessageBox::warning(this, "ERROR", "GenerateSineGraph: Start values is higher than stop value, aborting");
        return;
    }

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(ui->comboBox_GraphModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(Function::DATA_PACKET);

    uint8_t length;
    double value;

    Parameter parameters[4] = {Parameter::GRAPH_PARAMETER1, Parameter::GRAPH_PARAMETER2, Parameter::GRAPH_PARAMETER3, Parameter::GRAPH_PARAMETER4};

    constexpr double radianInverse = 3.14159/180;

    double phaseShift[4] = {0.0, 120.0, 240.0, 360.0};

    for(int x = startDegrees; x < stopDegrees; x++)
    {
        for(int signalNumber = 0; signalNumber < signalCount; signalNumber++)
        {
            uartPacket.SetParameter(parameters[signalNumber]);

            /*Multiply by radian inverse to get rid of radian unit and calculate sine of x measured in degrees*/
            value = amplitude * (sin(static_cast<double>(x) * radianInverse + phaseShift[signalNumber]));

            if(value < 0)
            {
                /*Change value sign back to positive and mark it as negative in UART packet*/
                value = value * (-1);
                uartPacket.SetSign(Sign::NEGATIVE_SIGN);
            }
            else
            {
                uartPacket.SetSign(Sign::POSITIVE_SIGN);
            }

            /*Temporary buffer for number-string conversion with additional space for null character*/
            char tempBuffer[PAYLOAD_SIZE + 1] = {0};

            /*Convert double number to string and write it to temporary buffer*/
            snprintf(tempBuffer , PAYLOAD_SIZE + 1, "%lf", value);

            length = static_cast<uint8_t>(strlen(tempBuffer));

            uartPacket.SetPayload(tempBuffer);

            uartPacket.SetLength(length);

            SendGraphPacket(uartPacket);
        }

        if (m_stopPressed)
        {
            qDebug("STOP PRESSED");
            m_stopPressed = false;
            return;
        }

        QCoreApplication::processEvents();
    }
}

void MainWindow::GenerateSquareGraph(int signalCount)
{
    UartPacket uartPacket;

    QString strStartDegrees = ui->lineEdit_SquareStart->text();
    QString strStopDegrees = ui->lineEdit_SquareStop->text();
    QString strAmplitude = ui->lineEdit_SquareAmplitude->text();
    QString strPeriod = ui->lineEdit_SquarePeriod->text();

    QString functionName = "GenerateSquareGraph";

    if(!ValidateIntegerInput(strStartDegrees, functionName) ||
            !ValidateIntegerInput(strStopDegrees, functionName) ||
            !ValidateFloatingPointInput(strAmplitude, functionName))
    {
        return;
    }

    int startDegrees = strStartDegrees.toInt();
    int stopDegrees = strStopDegrees.toInt();
    double amplitude = strAmplitude.toDouble();
    int period = strPeriod.toInt();

    if(startDegrees > stopDegrees)
    {
        QMessageBox::warning(this, "ERROR", "GenerateSquareGraph: Start values is higher than stop value, aborting");
        return;
    }

    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(ui->comboBox_GraphModule->currentText().at(0).toLatin1());
    uartPacket.SetFunction(Function::DATA_PACKET);

    uint8_t length;
    double value;

    const int periodShift = period / 2;

    int multiplierSignal1 = +1;
    int multiplierSignal2 = +1;

    for(int x = startDegrees; x < stopDegrees; x++)
    {
        if(signalCount >= 1)
        {
            uartPacket.SetParameter(Parameter::GRAPH_PARAMETER1);

            value = amplitude * multiplierSignal1;

            if(value < 0)
            {
                /*Change value sign back to positive and mark it as negative in UART packet*/
                value = value * (-1);
                uartPacket.SetSign(Sign::NEGATIVE_SIGN);
            }
            else
            {
                uartPacket.SetSign(Sign::POSITIVE_SIGN);
            }

            /*Temporary buffer for number-string conversion with additional space for null character*/
            char tempBuffer[PAYLOAD_SIZE + 1] = {0};

            /*Convert double number to string and write it to temporary buffer*/
            snprintf(tempBuffer , PAYLOAD_SIZE + 1, "%lf", value);

            length = static_cast<uint8_t>(strlen(tempBuffer));

            uartPacket.SetPayload(tempBuffer);

            uartPacket.SetLength(length);

            SendGraphPacket(uartPacket);

            if(x % period == 0)
            {
                multiplierSignal1 = multiplierSignal1 * (-1);
            }

            QCoreApplication::processEvents();
        }

        if(signalCount >= 2)
        {
            uartPacket.SetParameter(Parameter::GRAPH_PARAMETER2);

            value = amplitude * multiplierSignal2;

            if(value < 0)
            {
                /*Change value sign back to positive and mark it as negative in UART packet*/
                value = value * (-1);
                uartPacket.SetSign(Sign::NEGATIVE_SIGN);
            }
            else
            {
                uartPacket.SetSign(Sign::POSITIVE_SIGN);
            }

            /*Temporary buffer for number-string conversion with additional space for null character*/
            char tempBuffer[PAYLOAD_SIZE + 1] = {0};

            /*Convert double number to string and write it to temporary buffer*/
            snprintf(tempBuffer , PAYLOAD_SIZE + 1, "%lf", value);

            length = static_cast<uint8_t>(strlen(tempBuffer));

            uartPacket.SetPayload(tempBuffer);

            uartPacket.SetLength(length);

            SendGraphPacket(uartPacket);

            if(((x + periodShift ) % period) == 0)
            {
                multiplierSignal2 = multiplierSignal2 * (-1);
            }

            QCoreApplication::processEvents();
        }

        if (m_stopPressed)
        {
            qDebug("STOP PRESSED");
            m_stopPressed = false;
            return;
        }
    }
}

void MainWindow::SendGraphPacket(UartPacket& uartPacket)
{
    uartPacket.AppendCrcToPacket();

    //qDebug("Graph packet is: %s", static_cast<uint8_t*>(uartPacket));

    m_pTableView->UpdatePacketDisplay(static_cast<uint8_t*>(uartPacket), false);

    m_Serial.SendPacket(static_cast<uint8_t*>(uartPacket));

    Sleep(uint(10));
}

void MainWindow::UpdateGUI()
{
    QWidget* module1ParameterStateLabelsTable[PAYLOAD_SIZE];
    QWidget* module2ParameterStateLabelsTable[PAYLOAD_SIZE];
    QWidget* module3ParameterStateLabelsTable[PAYLOAD_SIZE];
    QWidget* module1ParameterValueLabelsTable[PAYLOAD_SIZE];
    QWidget* module2ParameterValueLabelsTable[PAYLOAD_SIZE];
    QWidget* module3ParameterValueLabelsTable[PAYLOAD_SIZE];

    for(int i = 0; i<PAYLOAD_SIZE; i++)
    {
        module1ParameterStateLabelsTable[i] = ui->Module1ParameterStates->itemAt(i)->widget();
        module2ParameterStateLabelsTable[i] = ui->Module2ParameterStates->itemAt(i)->widget();
        module3ParameterStateLabelsTable[i] = ui->Module3ParameterStates->itemAt(i)->widget();
        module1ParameterValueLabelsTable[i] = ui->ValuesModule1Parameters->itemAt(i)->widget();
        module2ParameterValueLabelsTable[i] = ui->ValuesModule2Parameters->itemAt(i)->widget();
        module3ParameterValueLabelsTable[i] = ui->ValuesModule3Parameters->itemAt(i)->widget();
    }

    for(int i = 0; i<PAYLOAD_SIZE; i++)
    {
        if((m_Module1.GetParameterStatesTable())[i] == true)
        {
            dynamic_cast<QLabel*>(*(module1ParameterStateLabelsTable + i))->setText("<font color='green'>Enabled</font>");
        }
        else
        {
            dynamic_cast<QLabel*>(*(module1ParameterStateLabelsTable + i))->setText("<font color='red'>Disabled</font>");
        }

        if((m_Module2.GetParameterStatesTable())[i] == true)
        {
            dynamic_cast<QLabel*>(*(module2ParameterStateLabelsTable + i))->setText("<font color='green'>Enabled</font>");
        }
        else
        {
            dynamic_cast<QLabel*>(*(module2ParameterStateLabelsTable + i))->setText("<font color='red'>Disabled</font>");
        }

        if((m_Module3.GetParameterStatesTable())[i] == true)
        {
            dynamic_cast<QLabel*>(*(module3ParameterStateLabelsTable + i))->setText("<font color='green'>Enabled</font>");
        }
        else
        {
            dynamic_cast<QLabel*>(*(module3ParameterStateLabelsTable + i))->setText("<font color='red'>Disabled</font>");
        }

        dynamic_cast<QLCDNumber*>(*(module1ParameterValueLabelsTable + i))->display((m_Module1.GetParameterValuesTable())[i]);
        dynamic_cast<QLCDNumber*>(*(module2ParameterValueLabelsTable + i))->display((m_Module2.GetParameterValuesTable())[i]);
        dynamic_cast<QLCDNumber*>(*(module3ParameterValueLabelsTable + i))->display((m_Module3.GetParameterValuesTable())[i]);
    }
}

/*Button slots*/
void MainWindow::on_pushButton_Open_clicked()
{
    InitParametersXmlLoader initParametersXmlLoader(ui);

    if(initParametersXmlLoader.InitModuleParametersList(m_Module1, m_Module2, m_Module3) == false)
    {
        QMessageBox::warning(this, ".xml load error", "Error, parameters list could not be read from XML");
        return;
    }

    m_Serial.OpenPort(ui->comboBox_Port->currentText());
}

void MainWindow::on_pushButton_Close_clicked()
{
    m_Serial.ClosePort(ui->comboBox_Port->currentText());
}

void MainWindow::on_pushButton_Send_pressed()
{
    SendCustomPacket();
}

void MainWindow::on_pushButton_InitConnectionModule1_clicked()
{
    InitConnectionModule(ModuleID::MODULE1);
}

void MainWindow::on_pushButton_InitConnectionModule2_clicked()
{
    InitConnectionModule(ModuleID::MODULE2);
}

void MainWindow::on_pushButton_InitConnectionModule3_clicked()
{
    InitConnectionModule(ModuleID::MODULE3);
}

void MainWindow::on_pushButton_DeinitConnectionModule1_clicked()
{
    DeinitConnectionModule(ModuleID::MODULE1);
}

void MainWindow::on_pushButton_DeinitConnectionModule2_clicked()
{
    DeinitConnectionModule(ModuleID::MODULE2);
}

void MainWindow::on_pushButton_DeinitConnectionModule3_clicked()
{
    DeinitConnectionModule(ModuleID::MODULE3);
}

void MainWindow::on_pushButton_StartLinear_clicked()
{
    char signalCount = ui->comboBox_GraphSignalCount->currentText().at(0).toLatin1();

    switch(signalCount)
    {
    case '1':
        GenerateLinearGraph(1);
        break;
    case '2':
        GenerateLinearGraph(2);
        break;
    case '3':
        GenerateLinearGraph(3);
        break;
    case '4':
        GenerateLinearGraph(4);
        break;
    default:
        qDebug("Unsupported ammount of linear signals");
    }
}

void MainWindow::on_pushButton_StartSine_clicked()
{
    char signalCount = ui->comboBox_GraphSignalCount->currentText().at(0).toLatin1();

    switch(signalCount)
    {
    case '1':
        GenerateSineGraph(1);
        break;
    case '2':
        GenerateSineGraph(2);
        break;
    case '3':
        GenerateSineGraph(3);
        break;
    case '4':
        GenerateSineGraph(4);
        break;
    default:
        qDebug("Unsupported ammount of sine signals");
    }
}

void MainWindow::on_pushButton_StartSquare_clicked()
{
    char signalCount = ui->comboBox_GraphSignalCount->currentText().at(0).toLatin1();

    switch(signalCount)
    {
    case '1':
        GenerateSquareGraph(1);
        break;
    case '2':
        GenerateSquareGraph(2);
        break;
    case '3':
        GenerateSquareGraph(3);
        break;
    case '4':
        GenerateSquareGraph(4);
        break;
    default:
        qDebug("Unsupported ammount of square signals");
    }
}

void MainWindow::on_pushButton_Stop_clicked()
{
    m_stopPressed = true;
}

void MainWindow::on_pushButton_SendWrongCrcPacket_clicked()
{
    SendWrongCrcDataPacket();
}

void MainWindow::on_pushButton_SetRanges_clicked()
{
    QString rangeMinimumStr = ui->lineEdit_RangeMinimum->text();
    QString rangeMaximumStr = ui->lineEdit_RangeMaximum->text();

    QString functionName = "SetRanges";

    if(!ValidateIntegerInput(rangeMinimumStr, functionName) ||
            !ValidateIntegerInput(rangeMaximumStr, functionName))
    {
        return;
    }

    long long int rangeMinimumInt = rangeMinimumStr.toLongLong();
    long long int rangeMaximumInt = rangeMaximumStr.toLongLong();

    if(rangeMinimumInt >= rangeMaximumInt)
    {
        QMessageBox::warning(this, "Warning", "Minimum range value is higher than or equal to maximum range value, aborting");
        return;
    }

    SetRangeMinimum();
    Sleep(100);
    SetRangeMaximum();
    Sleep(100);
    SetRangeTime();
}

void MainWindow::on_pushButton_ClearTable_clicked()
{
    m_pTableView->ClearPacketDisplay();
}

bool MainWindow::ValidateFloatingPointInput(QString input, QString functionName)
{
    /*Remove sign*/
    if(input.at(0).toLatin1() == '-' || input.at(0).toLatin1() == '+')
    {
        input.remove(0,1);
    }

    if(input.size() > PAYLOAD_SIZE)
    {
        QString errorMessage = "Payload too long";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    if(input.isEmpty())
    {
        QString errorMessage = "Payload is empty";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    QString floatingPointPattern = "^(?!0\\d)(\\d{1,10})(\\.\\d{1,8})?$";
    QRegularExpression regExp(floatingPointPattern);

    if(!regExp.match(input).hasMatch())
    {
        QString errorMessage = "Regex does not match";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    bool conversionSuccessFlag = true;

    double numericValue = input.toDouble(&conversionSuccessFlag);

    //qDebug() << "Numeric value after conversion: " << numericValue;

    if(!conversionSuccessFlag)
    {
        QString errorMessage = "Input floating point numeric value is not convertable to numeric value";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    return true;
}

bool MainWindow::ValidateIntegerInput(QString input, QString functionName)
{
    /*Remove sign*/
    if(input.at(0).toLatin1() == '-' || input.at(0).toLatin1() == '+')
    {
        input.remove(0,1);
    }

    if(input.size() > PAYLOAD_SIZE)
    {
        QString errorMessage = "Payload too long";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    if(input.isEmpty())
    {
        QString errorMessage = "Payload is empty";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    QString integerPattern = "^(0|[1-9][0-9]{0,9})$";
    QRegularExpression regExp(integerPattern);

    if(!regExp.match(input).hasMatch())
    {
        QString errorMessage = "Regex does not match";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    bool conversionSuccessFlag = true;

    int numericValue = input.toLongLong(&conversionSuccessFlag);

    //qDebug() << "Numeric value after conversion: " << numericValue;

    if(!conversionSuccessFlag)
    {
        QString errorMessage = "Input numeric value is not convertable to numeric value";
        QMessageBox::warning(this, "VALIDATION ERROR", functionName + ": " + errorMessage);
        return false;
    }

    return true;
}
