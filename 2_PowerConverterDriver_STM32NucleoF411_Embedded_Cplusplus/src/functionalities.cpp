#include "functionalities.h"
#include "uart_packet.h"
#include "utilities.h"
#include "string"
#include "init_parameters.h"
#include "stm32f4xx_hal.h"
#include "module.h"
#include <string.h>
#include <cmath>

#define DEBUG 1

extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;

Module module1;
Module module2;
Module module3;

void InitModule(int module)
{
  for(int i=0; i < INIT_PACKETS_COUNT; i++)
  {
#if DEBUG == 1
    printf("Sending init packet %d: ", i + 1);
#endif
    
    UartPacket uartPacket;
    
    uartPacket.SetSource(Source::SOURCE_TARGET1);
    uartPacket.SetModule(module);
    uartPacket.SetFunction(Function::INIT_PACKET);
    uartPacket.SetParameter(Parameter::NULL_PARAMETER);
    uartPacket.SetSign(Sign::POSITIVE_SIGN);
    
    if(module == 1)
    {
      memcpy((char*)uartPacket.GetPayload(), *(initParametersModule1[i]), PAYLOAD_SIZE);
    }
    else if(module == 2)
    {
      memcpy((char*)uartPacket.GetPayload(), *(initParametersModule2[i]), PAYLOAD_SIZE);
    }
    else if(module == 3)
    {
      memcpy((char*)uartPacket.GetPayload(), *(initParametersModule3[i]), PAYLOAD_SIZE);
    }
    else
    {
      printf("ERROR, Bad module ID in InitModule function, aborting\n");
      return;
    }
    
    uint8_t lengthInt = strlen(reinterpret_cast<const char*>(uartPacket.GetPayload()));
    
    uartPacket.SetLength(lengthInt); // convert from int to ASCII
    
    uartPacket.AppendCrcToPacket();
    
#if DEBUG == 1
    printf("Init Packet is: ");
    uartPacket.PrintPacket();
#endif
    
    SendPacketViaUart(uartPacket);
    
    HAL_Delay(20);
  }
}

void DeinitModule(int module)
{
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::DEINIT_PACKET);
  uartPacket.SetParameter(Parameter::NULL_PARAMETER);
  uartPacket.SetSign(Sign::POSITIVE_SIGN);
  uartPacket.SetLength(Length::NO_PAYLOAD);
  
  uartPacket.AppendCrcToPacket();
  
#if DEBUG == 1
  printf("Deinit Packet is: ");
  uartPacket.PrintPacket();
#endif
  
  SendPacketViaUart(uartPacket);
}

void SetGraphLowerRange(int module, long long int value)
{
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::SET_GRAPH_RANGE_MIN);
  uartPacket.SetParameter(Parameter::NULL_PARAMETER);
  
  if(value >= 0)
  {
    uartPacket.SetSign(Sign::POSITIVE_SIGN);
  }
  else
  {
    uartPacket.SetSign(Sign::NEGATIVE_SIGN);
    value = value * (-1);
  }
  
  char numericStringConversionBuffer[PAYLOAD_SIZE + 1];
  
  snprintf(numericStringConversionBuffer, PAYLOAD_SIZE + 1, "%lld", value);
  
  int lengthInt = strlen(numericStringConversionBuffer);
  
  uartPacket.SetLength(lengthInt);
  
  memcpy((char*)uartPacket.GetPayload(), numericStringConversionBuffer, lengthInt);
  
  uartPacket.AppendCrcToPacket();
  
#if DEBUG == 1
  printf("SetGraphLowerRange Packet is: ");
  uartPacket.PrintPacket();
#endif
  
  SendPacketViaUart(uartPacket);
}

void SetGraphUpperRange(int module, long long int value)
{
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::SET_GRAPH_RANGE_MAX);
  uartPacket.SetParameter(Parameter::NULL_PARAMETER);
  
  if(value >= 0)
  {
    uartPacket.SetSign(Sign::POSITIVE_SIGN);
  }
  else
  {
    uartPacket.SetSign(Sign::NEGATIVE_SIGN);
    value = value * (-1);
  }
  
  char numericStringConversionBuffer[PAYLOAD_SIZE + 1];
  
  snprintf(numericStringConversionBuffer, PAYLOAD_SIZE + 1, "%lld", value);
  
  int lengthInt = strlen(numericStringConversionBuffer);
  
  uartPacket.SetLength(lengthInt);
  
  memcpy((char*)uartPacket.GetPayload(), numericStringConversionBuffer, lengthInt);
  
  uartPacket.AppendCrcToPacket();
  
#if DEBUG == 1
  printf("SetGraphUpperRange Packet is: ");
  uartPacket.PrintPacket();
#endif
  
  SendPacketViaUart(uartPacket);
}

void SetGraphTimeRange(int module, int value)
{
  if(value > 3600 || value < 360 || (value % 360 != 0))
  {
    printf("ERROR, Time range value is too high, too low or not multiplier of 360, aborting\n");
    return;
  }
  
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::SET_GRAPH_TIME_RANGE);
  uartPacket.SetParameter(Parameter::NULL_PARAMETER);
  uartPacket.SetSign(Sign::POSITIVE_SIGN);
  
  char numericStringConversionBuffer[PAYLOAD_SIZE + 1];
  
  snprintf(numericStringConversionBuffer, PAYLOAD_SIZE + 1, "%d", value);
  
  int lengthInt = strlen(numericStringConversionBuffer);
  
  uartPacket.SetLength(lengthInt);
  
  memcpy((char*)uartPacket.GetPayload(), numericStringConversionBuffer, lengthInt);
  
  uartPacket.AppendCrcToPacket();
  
#if DEBUG == 1
  printf("SetGraphTimeRange Packet is: ");
  uartPacket.PrintPacket();
#endif
  
  SendPacketViaUart(uartPacket);
}

void GenerateLinearGraph(int module, int signalCount, double startValue, double stopValue, double stepValue)
{
  UartPacket uartPacket;
  
  if(startValue >= stopValue)
  {
    printf("ERROR, GenerateLinearGraph: Start values is higher than or equal to stop value, aborting");
    return;
  }
  
  if(stepValue < 0)
  {
    printf("ERROR, GenerateLinearGraph: Negative step value not supported, aborting");
    return;
  }
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  
  uartPacket.SetModule(module);
  
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
      
      uartPacket.SetPayload(reinterpret_cast<uint8_t*>(tempBuffer));
      
      uartPacket.SetLength(length);
      
      uartPacket.AppendCrcToPacket();
      
      SendPacketViaUart(uartPacket);
      
      HAL_Delay(20);
    }
  }
}

void GenerateSineGraph(int module, int signalCount, int startDegrees, int stopDegrees, double amplitude)
{
  UartPacket uartPacket;
  
  if(startDegrees > stopDegrees)
  {
    printf("ERROR, GenerateSineGraph: Start values is higher than stop value, aborting");
    return;
  }
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
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
      
      uartPacket.SetPayload(reinterpret_cast<uint8_t*>(tempBuffer));
      
      uartPacket.SetLength(length);
      
      uartPacket.AppendCrcToPacket();
      
      SendPacketViaUart(uartPacket);
      
      HAL_Delay(20);
    }
  }
}

void GenerateSquareGraph(int module, int signalCount, int startValue, int stopValue, double amplitude, int period)
{
  UartPacket uartPacket;
  
  if(startValue > stopValue)
  {
    printf("ERROR, GenerateSquareGraph: Start values is higher than stop value, aborting");
    return;
  }
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::DATA_PACKET);
  
  uint8_t length;
  double value;
  
  const int halfPeriod = period / 2;
  
  int multiplierSignal1 = +1;
  int multiplierSignal2 = -1;
  
  int counterSignal1 = halfPeriod;
  int counterSignal2 = halfPeriod;
  
  for(int x = startValue; x < stopValue; x++)
  {
    if(signalCount >= 1)
    {      
      if(counterSignal1 == 0)
      {
        counterSignal1 = halfPeriod;
        multiplierSignal1 = multiplierSignal1 * (-1);
      }
      else
      {
        --counterSignal1;
      }
      
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
      
      uartPacket.SetPayload(reinterpret_cast<uint8_t*>(tempBuffer));
      
      uartPacket.SetLength(length);
      
      uartPacket.AppendCrcToPacket();
      
      SendPacketViaUart(uartPacket);
      
      HAL_Delay(20);
    }
    
    if(signalCount >= 2)
    {      
      if(counterSignal2 == 0)
      {
        counterSignal2 = halfPeriod;
        multiplierSignal2 = multiplierSignal2 * (-1);
      }
      else
      {
        --counterSignal2;
      }
      
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
      
      uartPacket.SetPayload(reinterpret_cast<uint8_t*>(tempBuffer));
      
      uartPacket.SetLength(length);
      
      uartPacket.AppendCrcToPacket();
      
      SendPacketViaUart(uartPacket);
      
      HAL_Delay(20);
    }
  }
}

void SendWrongCrc(int module)
{
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::DATA_PACKET);
  uartPacket.SetParameter(Parameter::NULL_PARAMETER);
  
  uartPacket.SetWrongCrc();
  
#if DEBUG == 1
  printf("SendWrongCrc packet is:");
  uartPacket.PrintPacket();
#endif
  
  SendPacketViaUart(uartPacket);
}

void GetParameters(int module)
{
  printf("\nModule %d parameters:\n\n", module);
  
  Module* pCurrentModule = nullptr;
  
  if(module == 1)
  {
    pCurrentModule = &module1;
  }
  else if(module == 2)
  {
    pCurrentModule = &module2;
  }
  else if(module == 3)
  {
    pCurrentModule = &module3;
  }
  else
  {
    printf("ERROR, Wrong module field in received packet, aborting\n");
    return;
  }
  
  for(int i = 0; i < PARAMETERS_COUNT; i++)
  {
    printf("Parameter %3d state: %10d\n", i+1, pCurrentModule->GetParameterState(i));
  }
  
  printf("\n");
  
  for(int i = 0; i < PARAMETERS_COUNT; i++)
  {
    printf("Parameter %3d value: %10lf\n", i+1, pCurrentModule->GetParameterValue(i));
  } 
}

void SendAdcToGraphScreen(int module, int packetCount)
{  
#if DEBUG == 1
  printf("\nModule %d, generating and sending %d ADC packets per each of 4 signals\n\n", module, packetCount);
#endif
  
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::DATA_PACKET);
  
  int rawAdcValue = 0;
  double value = 0;
  
  Parameter parameters[4] = {Parameter::GRAPH_PARAMETER1, Parameter::GRAPH_PARAMETER2, Parameter::GRAPH_PARAMETER3, Parameter::GRAPH_PARAMETER4};
  
  for(int i = 0; i < packetCount; i++)
  {    
    for(int signalNumber = 0; signalNumber < 4; signalNumber++)
    {
      HAL_ADC_Start(&hadc1);
      
      rawAdcValue = HAL_ADC_GetValue(&hadc1);
      
      uartPacket.SetParameter(parameters[signalNumber]);
      
#if DEBUG == 1
      printf("ADC raw value is %d out of 4096 = %.3fV\n", rawAdcValue, rawAdcValue * 3.3f / 4096.0f);
#endif
      
      /*Scale ADC value to reference voltage and 12-bit size*/
      value = rawAdcValue * 3.3f / 4096.0f;// * 3.3f / 4096.0f; //adcValue;
      
      if(value >= 0)
      {
        uartPacket.SetSign(Sign::POSITIVE_SIGN);
      }
      else
      {
        uartPacket.SetSign(Sign::NEGATIVE_SIGN);
        value = value * (-1);
      }
      
      char numericStringConversionBuffer[PAYLOAD_SIZE + 1];
      
      snprintf(numericStringConversionBuffer, PAYLOAD_SIZE + 1, "%lf", value);
      
      int lengthInt = strlen(numericStringConversionBuffer);
      
      uartPacket.SetLength(lengthInt);
      
      memcpy((char*)uartPacket.GetPayload(), numericStringConversionBuffer, lengthInt);
      
      uartPacket.AppendCrcToPacket();
      
#if DEBUG == 1
      printf("Sending packet: ");
      uartPacket.PrintPacket();
#endif
      SendPacketViaUart(uartPacket);
      
      HAL_Delay(20);
    }
  }
}

void SendAdcToDataScreen(int module, int packetCount)
{
  if(module != 1 && module != 2 && module != 3)
  {
    printf("Error, wrong module field in received packet, aborting\n");
    return;
  }
  
#if DEBUG == 1
  printf("\nModule %d, generating and sending %d ADC packets per each of 4 signals\n\n", module, packetCount);
#endif
  
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::DATA_PACKET);
  
  int rawAdcValue = 0;
  double value = 0;
  
  Parameter parameters[4] = {Parameter::PARAMETER1, Parameter::PARAMETER2, Parameter::PARAMETER3, Parameter::PARAMETER4};
  
  for(int i = 0; i < packetCount; i++)
  {    
    for(int signalNumber = 0; signalNumber < 4; signalNumber++)
    {
      HAL_ADC_Start(&hadc1);
      
      rawAdcValue = HAL_ADC_GetValue(&hadc1);
      
      uartPacket.SetParameter(parameters[signalNumber]);
      
#if DEBUG == 1
      printf("ADC raw value is %d out of 4096 = %.3fV\n", rawAdcValue, rawAdcValue * 3.3f / 4096.0f);
#endif
      /*Scale ADC value to reference voltage and 12-bit size*/
      value = rawAdcValue * 3.3f / 4096.0f;
      
      if(value >= 0)
      {
        uartPacket.SetSign(Sign::POSITIVE_SIGN);
      }
      else
      {
        uartPacket.SetSign(Sign::NEGATIVE_SIGN);
        value = value * (-1);
      }
      
      char numericStringConversionBuffer[PAYLOAD_SIZE + 1];
      
      snprintf(numericStringConversionBuffer, PAYLOAD_SIZE + 1, "%lf", value);
      
      int lengthInt = strlen(numericStringConversionBuffer);
      
      uartPacket.SetLength(lengthInt);
      
      memcpy((char*)uartPacket.GetPayload(), numericStringConversionBuffer, lengthInt);
      
      uartPacket.AppendCrcToPacket();
      
#if DEBUG == 1
      printf("Sending packet: ");
      uartPacket.PrintPacket();
#endif
      
      SendPacketViaUart(uartPacket);
      
      HAL_Delay(20);
    }
  }
}

void SendCustomPacket(int module, char rawParameter, double value)
{
  UartPacket uartPacket;
  
  uartPacket.SetSource(Source::SOURCE_TARGET1);
  uartPacket.SetModule(module);
  uartPacket.SetFunction(Function::DATA_PACKET);
  uartPacket.SetParameter(rawParameter);
  
  if(value >= 0)
  {
    uartPacket.SetSign(Sign::POSITIVE_SIGN);
  }
  else
  {
    uartPacket.SetSign(Sign::NEGATIVE_SIGN);
    value = value * (-1);
  }
  
  char numericStringConversionBuffer[PAYLOAD_SIZE + 1];
  
  snprintf(numericStringConversionBuffer, PAYLOAD_SIZE + 1, "%lf", value);
  
  int lengthInt = strlen(numericStringConversionBuffer);
  
  uartPacket.SetLength(lengthInt);
  
  memcpy((char*)uartPacket.GetPayload(), numericStringConversionBuffer, lengthInt);
  
  uartPacket.AppendCrcToPacket();
  
#if DEBUG == 1
  printf("SendCustomPacket packet is:");
  uartPacket.PrintPacket();
#endif
  
  SendPacketViaUart(uartPacket);
}

void ProcessReceivedData(UartPacket& uartPacket)
{   
#if DEBUG == 1
  uartPacket.PrintPacket();
#endif
  
  if(uartPacket.CheckCrc32())
  {
    Module* pCurrentModule = nullptr;
    
    ModuleID moduleID = uartPacket.GetModule();
    
    if(moduleID == ModuleID::MODULE1)
    {
      pCurrentModule = &module1;
    }
    else if(moduleID == ModuleID::MODULE2)
    {
      pCurrentModule = &module2;
    }
    else if(moduleID == ModuleID::MODULE3)
    {
      pCurrentModule = &module3;
    }
    else
    {
      printf("ERROR, Wrong module field in received packet, aborting\n");
      return;
    }
    
    Function function = uartPacket.GetFunction();
    Parameter parameter = uartPacket.GetParameter();
    
    double valueDouble = 0;
    
    switch(function)
    {
    case Function::ENABLE_PARAMETER_PACKET:
      printf("Enable parameter packet received\n");
      pCurrentModule->EnableParameter(parameter);
      break;
      
    case Function::DISABLE_PARAMETER_PACKET: 
      printf("Disable parameter packet received\n");
      pCurrentModule->DisableParameter(parameter);
      break;
      
    case Function::SET_PARAMETER_PACKET:
      printf("Set parameter packet received\n");
      valueDouble = double(atof((char*)(uartPacket.GetPayload())));
      
      if(uartPacket.GetSign() == Sign::NEGATIVE_SIGN)
      {
        /*Make value negative if it was marked as negative in UART Packet*/
        valueDouble = valueDouble * (-1);
      }
      
      pCurrentModule->SetParameter(parameter, valueDouble);
      break;
      
    default:
      printf("ERROR, Wrong function type, aborting\n");
      return;
    }
  }
  else
  {
    printf("ERROR, WRONG CRC IN DATA RECEIVED FROM STM32F469\n");
  }
}
