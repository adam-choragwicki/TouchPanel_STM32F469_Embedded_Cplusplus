#include "commands.h"
#include "functionalities.h"
#include "utilities.h"

using std::vector;
using std::string;

#define UART_TX_WAITING 50

void CommandInitModule(std::string& command)
{
  int requiredArgumentsCount = 1;
  
  int initModuleNumberArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      initModuleNumberArgument = std::stoi(extractedArguments.at(0));
      
      printf("Invoking InitModule\n");
      InitModule(initModuleNumberArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandDeinitModule(std::string& command)
{
  int requiredArgumentsCount = 1;
  
  int deinitModuleNumberArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      deinitModuleNumberArgument = std::stoi(extractedArguments.at(0));
      
      printf("Invoking DeinitModule\n");
      DeinitModule(deinitModuleNumberArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandSetGraphMin(std::string& command)
{
  int requiredArgumentsCount = 2;
  
  int setGraphLowerRangeModuleNumberArgument = 0;
  long long int setGraphLowerRangeValueArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      setGraphLowerRangeModuleNumberArgument = std::stoi(extractedArguments.at(0));
      setGraphLowerRangeValueArgument = std::stoll(extractedArguments.at(1));
      
      printf("Invoking SetGraphLowerRange\n");
      SetGraphLowerRange(setGraphLowerRangeModuleNumberArgument, setGraphLowerRangeValueArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandSetGraphMax(std::string& command)
{
  int requiredArgumentsCount = 2;
  
  int setGraphUpperRangeModuleNumberArgument = 0;
  long long int setGraphUpperRangeValueArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {    
    try
    {
      setGraphUpperRangeModuleNumberArgument = std::stoi(extractedArguments.at(0));
      setGraphUpperRangeValueArgument = std::stoll(extractedArguments.at(1));
      
      printf("Invoking SetGraphUpperRange\n");
      SetGraphUpperRange(setGraphUpperRangeModuleNumberArgument, setGraphUpperRangeValueArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandSetGraphTime(std::string& command)
{
  int requiredArgumentsCount = 2;
  
  int setGraphTimeRangeModuleNumberArgument = 0;
  int setGraphTimeRangeValueArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {    
    try
    {
      setGraphTimeRangeModuleNumberArgument = std::stoi(extractedArguments.at(0));
      setGraphTimeRangeValueArgument = std::stoi(extractedArguments.at(1));
      
      printf("Invoking SetGraphTimeRange\n");
      SetGraphTimeRange(setGraphTimeRangeModuleNumberArgument, setGraphTimeRangeValueArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandGraphLinear(std::string& command)
{
  int requiredArgumentsCount = 5;
  
  int moduleNumberArgument = 0;
  int signalCount = 0;
  double startValue = 0;
  double endValue = 0;
  double stepValue = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      moduleNumberArgument = std::stoi(extractedArguments.at(0));
      signalCount = std::stoi(extractedArguments.at(1));
      startValue = std::stod(extractedArguments.at(2));
      endValue = std::stod(extractedArguments.at(3));
      stepValue = std::stod(extractedArguments.at(4));
      
      printf("Invoking GenerateLinearGraph\n");
      GenerateLinearGraph(moduleNumberArgument, signalCount, startValue, endValue, stepValue);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandGraphSine(std::string& command)
{
  int requiredArgumentsCount = 5;
  
  int moduleNumberArgument = 0;
  int signalCount = 0;
  int startDegrees = 0;
  int stopDegrees = 0;
  double amplitude = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      moduleNumberArgument = std::stoi(extractedArguments.at(0));
      signalCount = std::stoi(extractedArguments.at(1));
      startDegrees = std::stoi(extractedArguments.at(2));
      stopDegrees = std::stoi(extractedArguments.at(3));
      amplitude = std::stod(extractedArguments.at(4));
      
      printf("Invoking GenerateSineGraph\n");
      GenerateSineGraph(moduleNumberArgument, signalCount, startDegrees, stopDegrees, amplitude);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandGraphSquare(std::string& command)
{
  int requiredArgumentsCount = 6;
  
  int moduleNumberArgument = 0;
  int signalCount = 0;
  int startValue = 0;
  int stopValue = 0;
  double amplitude = 0;
  int period = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      moduleNumberArgument = std::stoi(extractedArguments.at(0));
      signalCount = std::stoi(extractedArguments.at(1));
      startValue = std::stoi(extractedArguments.at(2));
      stopValue = std::stoi(extractedArguments.at(3));
      amplitude = std::stod(extractedArguments.at(4));
      period = std::stoi(extractedArguments.at(5));
      
      printf("Invoking GenerateSquareGraph\n");
      GenerateSquareGraph(moduleNumberArgument, signalCount, startValue, stopValue, amplitude, period);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandSendWrongCrc(std::string& command)
{
  int requiredArgumentsCount = 1;
  
  int moduleNumberArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      moduleNumberArgument = std::stoi(extractedArguments.at(0));
      
      printf("Invoking SendWrongCrc\n");
      SendWrongCrc(moduleNumberArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandGetParameters(std::string& command)
{
  int requiredArgumentsCount = 1;
  
  int getParametersModuleNumberArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {    
    try
    {
      getParametersModuleNumberArgument = std::stoi(extractedArguments.at(0));
      
      printf("Invoking GetParameters\n");
      GetParameters(getParametersModuleNumberArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandAdc1(std::string& command)
{
  int requiredArgumentsCount = 2;
  
  int adcModuleNumberArgument = 0;
  int adcPacketCountNumberArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {    
    try
    {
      adcModuleNumberArgument = std::stoi(extractedArguments.at(0));
      adcPacketCountNumberArgument = std::stoi(extractedArguments.at(1));
      
      printf("Invoking SendAdcToGraphScreen\n");
      SendAdcToGraphScreen(adcModuleNumberArgument, adcPacketCountNumberArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandAdc2(std::string& command)
{
  int requiredArgumentsCount = 2;
  
  int adcModuleNumberArgument = 0;
  int adcPacketCountNumberArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {    
    try
    {
      adcModuleNumberArgument = std::stoi(extractedArguments.at(0));
      adcPacketCountNumberArgument = std::stoi(extractedArguments.at(1));
      
      printf("Invoking SendAdcToDataScreen\n");
      SendAdcToDataScreen(adcModuleNumberArgument, adcPacketCountNumberArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}

void CommandSendPacket(std::string& command)
{
  int requiredArgumentsCount = 3;
  
  int sendPacketModuleNumberArgument = 0;
  char sendPacketParameterNumberArgument = 0;
  double sendPacketValueArgument = 0;
  
  vector<string> extractedArguments;
  
  if(ExtractArguments(command, requiredArgumentsCount, extractedArguments))
  {
    try
    {
      sendPacketModuleNumberArgument = std::stoi(extractedArguments.at(0));
      sendPacketParameterNumberArgument = extractedArguments.at(1).at(0);
      sendPacketValueArgument = std::stod(extractedArguments.at(2));
      
      printf("Invoking SendCustomPacket\n");
      SendCustomPacket(sendPacketModuleNumberArgument, sendPacketParameterNumberArgument, sendPacketValueArgument);
    }
    catch(std::invalid_argument)
    {
      printf("ERROR, Invalid argument, aborting\n");
    }
  }
}