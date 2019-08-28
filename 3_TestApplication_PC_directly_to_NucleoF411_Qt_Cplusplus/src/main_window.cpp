#include "main_window.h"
#include "ui_main_window.h"
#include "packet_field_definitions.h"
#include <QSerialPortInfo>
#include <QMessageBox>
#include <cmath> //for sin()
#include "windows.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_Serial(ui)
{
    ui->setupUi(this);

    m_Serial.InitPortList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitConnectionModule(ModuleID module)
{
    qDebug("InitConnectionModule");

    SendString("#InitModule", QString(static_cast<int>(module)));
}

void MainWindow::DeinitConnectionModule(ModuleID module)
{
    qDebug("DeinitConnectionModule");

    SendString("#DeinitModule", QString(static_cast<int>(module)));
}

void MainWindow::SetRangeMinimum()
{
    QString module = ui->comboBox_GraphModule->currentText();
    QString enteredMinimumRange = ui->lineEdit_RangeMinimum->text();

    if(!ValidateIntegerInput(enteredMinimumRange, "SetRangeMinimum"))
    {
        return;
    }

    SendString("#SetGraphMin", module, enteredMinimumRange);
}

void MainWindow::SetRangeMaximum()
{
    QString module = ui->comboBox_GraphModule->currentText();
    QString enteredMaximumRange = ui->lineEdit_RangeMaximum->text();

    if(!ValidateIntegerInput(enteredMaximumRange, "SetRangeMaximum"))
    {
        return;
    }

    SendString("#SetGraphMax", module, enteredMaximumRange);
}

void MainWindow::SetRangeTime()
{
    QString module = ui->comboBox_GraphModule->currentText();
    QString enteredTimeRangeString = ui->comboBox_TimeRange->currentText();

    if(!ValidateIntegerInput(enteredTimeRangeString, "SetRangeTime"))
    {
        return;
    }

    SendString("#SetGraphTime", module, enteredTimeRangeString);
}

void MainWindow::GraphLinear()
{
    QString strModule= ui->comboBox_GraphModule->currentText();
    QString strSignalCount = ui->comboBox_GraphSignalCount->currentText();
    QString strStartValue = ui->lineEdit_LinearStart->text();
    QString strStopValue = ui->lineEdit_LinearStop->text();
    QString strStepValue = ui->lineEdit_LinearStep->text();

    QString functionName = "GraphLinear";

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

    SendString("#GraphLinear", strModule, strSignalCount, strStartValue, strStopValue, strStepValue);
}

void MainWindow::GraphSine()
{
    QString strModule= ui->comboBox_GraphModule->currentText();
    QString strSignalCount = ui->comboBox_GraphSignalCount->currentText();
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

    if(amplitude <= 0)
    {
        QMessageBox::warning(this, "ERROR", "GenerateSineGraph: Amplitude cannot be less than or equal 0, aborting");
        return;
    }

    SendString("#GraphSine", strModule, strSignalCount, strStartDegrees, strStopDegrees, strAmplitude);
}

void MainWindow::GraphSquare()
{
    QString strModule= ui->comboBox_GraphModule->currentText();
    QString strSignalCount = ui->comboBox_GraphSignalCount->currentText();
    QString strStartValue = ui->lineEdit_SquareStart->text();
    QString strStopValue = ui->lineEdit_SquareStop->text();
    QString strAmplitude = ui->lineEdit_SquareAmplitude->text();
    QString strPeriod = ui->lineEdit_SquarePeriod->text();

    QString functionName = "GenerateSquareGraph";

    if(!ValidateIntegerInput(strStartValue, functionName) ||
            !ValidateIntegerInput(strStopValue, functionName) ||
            !ValidateFloatingPointInput(strAmplitude, functionName) ||
            !ValidateIntegerInput(strPeriod, functionName))
    {
        return;
    }

    int startValue = strStartValue.toInt();
    int stopValue = strStopValue.toInt();
    double amplitude = strAmplitude.toDouble();
    int period = strPeriod.toInt();

    if(startValue > stopValue)
    {
        QMessageBox::warning(this, "ERROR", "GenerateSquareGraph: Start values is higher than stop value, aborting");
        return;
    }

    if(amplitude <= 0)
    {
        QMessageBox::warning(this, "ERROR", "GenerateSquareGraph: Amplitude cannot be less than or equal 0, aborting");
        return;
    }

    if(period < 1)
    {
        QMessageBox::warning(this, "ERROR", "GenerateSquareGraph: Period cannot be less than 1, aborting");
        return;
    }

    SendString("#GraphSquare", strModule, strSignalCount, strStartValue, strStopValue, strAmplitude, strPeriod);
}

void MainWindow::StopGraph()
{
    SendString("#StopGraph");
}

void MainWindow::SendCustomPacket()
{    
    QString module = ui->comboBox_CustomPacketModule->currentText();
    QString parameter = ui->comboBox_CustomPacketParameter->currentText();
    QString enteredPayload = ui->lineEdit_CustomPacketPayload->text();

    if(!ValidateFloatingPointInput(enteredPayload, "SendCustomPacket"))
    {
        return;
    }

    SendString("#SendPacket",
               module,
               parameter,
               enteredPayload);
}

void MainWindow::SendWrongCrcDataPacket()
{
    QString module = ui->comboBox_CustomPacketModule->currentText();

    SendString("#SendWrongCrc", module);
}

/*Button slots*/
void MainWindow::on_pushButton_Open_clicked()
{
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
    GraphLinear();
}

void MainWindow::on_pushButton_StartSine_clicked()
{
    GraphSine();
}

void MainWindow::on_pushButton_StartSquare_clicked()
{
    GraphSquare();
}

void MainWindow::on_pushButton_Stop_clicked()
{
    StopGraph();
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
    Sleep(1000);
    SetRangeMaximum();
    Sleep(1000);
    SetRangeTime();
}

void MainWindow::on_pushButton_GetParametersModule1_clicked()
{
    qDebug() << "Get parameters module 1";

    SendString("#GetParameters", QString("1"));
}

void MainWindow::on_pushButton_GetParametersModule2_clicked()
{
    qDebug() << "Get parameters module 2";

    SendString("#GetParameters", QString("2"));
}

void MainWindow::on_pushButton_GetParametersModule3_clicked()
{
    qDebug() << "Get parameters module 3";

    SendString("#GetParameters", QString("3"));
}

void MainWindow::on_pushButton_Module1ADCToGraph_clicked()
{
    QString module = "1";
    QString packetCount = ui->lineEdit_Module1ADCPacketCount->text();

    if(!ValidateIntegerInput(packetCount, "ADC to graph module 1"))
    {
        return;
    }

    qDebug() << "ADC data to graph module 1";

    SendString("#Adc1", module, packetCount);
}

void MainWindow::on_pushButton_Module1ADCToTable_clicked()
{
    QString module = "1";
    QString packetCount = ui->lineEdit_Module1ADCPacketCount->text();

    qDebug() << "ADC data to table module 1";

    SendString("#Adc2", module, packetCount);
}

void MainWindow::on_pushButton_Module2ADCToGraph_clicked()
{
    QString module = "2";
    QString packetCount = ui->lineEdit_Module2ADCPacketCount->text();

    qDebug() << "ADC data to graph module 2";

    SendString("#Adc1", module, packetCount);
}

void MainWindow::on_pushButton_Module2ADCToTable_clicked()
{
    QString module = "2";
    QString packetCount = ui->lineEdit_Module2ADCPacketCount->text();

    qDebug() << "ADC data to table module 2";

    SendString("#Adc2", module, packetCount);
}

void MainWindow::on_pushButton_Module3ADCToGraph_clicked()
{
    QString module = "3";
    QString packetCount = ui->lineEdit_Module3ADCPacketCount->text();

    qDebug() << "ADC data to graph module 3";

    SendString("#Adc1", module, packetCount);
}

void MainWindow::on_pushButton_Module3ADCToTable_clicked()
{
    QString module = "3";
    QString packetCount = ui->lineEdit_Module3ADCPacketCount->text();

    qDebug() << "ADC data to table module 3";

    SendString("#Adc2", module, packetCount);
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

void MainWindow::SendString(QString command)
{
    SendString(command, "", "", "", "", "", "");
}

void MainWindow::SendString(QString command, QString arg1)
{
    SendString(command, arg1, "", "", "", "", "");
}

void MainWindow::SendString(QString command, QString arg1, QString arg2)
{
    SendString(command, arg1, arg2, "", "", "", "");
}

void MainWindow::SendString(QString command, QString arg1, QString arg2, QString arg3)
{
    SendString(command, arg1, arg2, arg3, "", "", "");
}

void MainWindow::SendString(QString command, QString arg1, QString arg2, QString arg3, QString arg4)
{
    SendString(command, arg1, arg2, arg3, arg4, "", "");
}

void MainWindow::SendString(QString command, QString arg1, QString arg2, QString arg3, QString arg4, QString arg5)
{
    SendString(command, arg1, arg2, arg3, arg4, arg5, "");
}

void MainWindow::SendString(QString command, QString arg1, QString arg2, QString arg3, QString arg4, QString arg5, QString arg6)
{
    QByteArray commandBuffer;

    commandBuffer.append(command);

    if(!arg1.isEmpty())
    {
        commandBuffer.append(",");
        commandBuffer.append(arg1);
    }

    if(!arg2.isEmpty())
    {
        commandBuffer.append(",");
        commandBuffer.append(arg2);
    }

    if(!arg3.isEmpty())
    {
        commandBuffer.append(",");
        commandBuffer.append(arg3);
    }

    if(!arg4.isEmpty())
    {
        commandBuffer.append(",");
        commandBuffer.append(arg4);
    }

    if(!arg5.isEmpty())
    {
        commandBuffer.append(",");
        commandBuffer.append(arg5);
    }

    if(!arg6.isEmpty())
    {
        commandBuffer.append(",");
        commandBuffer.append(arg6);
    }

    if(commandBuffer.size() > COMMAND_LENGTH)
    {
        assert(false);
    }

    while(commandBuffer.size() != COMMAND_LENGTH)
    {
        commandBuffer.append('\0');
    }

    qDebug() << "Command size: " << commandBuffer.size();
    qDebug() << "Sending command: " << commandBuffer;

    m_Serial.write(commandBuffer);

    m_Serial.waitForBytesWritten(1000);
}
