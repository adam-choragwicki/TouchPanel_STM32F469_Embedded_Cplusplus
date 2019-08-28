#include "utilities.h"
#include "stm32f4xx_hal.h"

#define UART_TX_WAITING 50

#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

using std::string;

extern UART_HandleTypeDef huart6;

int GetArgumentCount(std::string input)
{
  int commasCount = 0;
  int index = 0;
  
  while ((index = input.find_first_of(',')) != string::npos)
  {
    ++commasCount;
    input = input.substr(index + 1);
  }
  
  /*First comma is separating command from the first argument so number of commas is equal to number of arguments*/
  int argumentsCount = commasCount;
  
  return argumentsCount;
}

bool ExtractArguments(string& input, int requiredArgumentCount, std::vector<std::string>& extractedArguments)
{
  string argument;
  int index = 0;
  
  if (input.find_first_of(' ') != string::npos)
  {
    printf("ERROR, Spaces are not allowed, aborting\n");
    return false;
  }
  
  int argumentCount = GetArgumentCount(input);
  
  if (argumentCount != requiredArgumentCount)
  {
    printf("ERROR, Wrong number of arguments, expected %d, got %d\n",requiredArgumentCount, argumentCount);
    return false;
  }
  
  /*Skip extraction of first parameter because it is command*/
  index = input.find_first_of(',');
  input = input.substr(index + 1);
  
  for (int argumentIndex = 0; argumentIndex < requiredArgumentCount; argumentIndex++)
  {
    index = input.find_first_of(',');
    
    argument = input.substr(0, index);
    
    input = input.substr(index + 1);
    
    extractedArguments.push_back(argument);
  }
  
  return true;
}

void SendPacketViaUart(UartPacket& uartPacket)
{
  HAL_UART_Transmit(&huart6, static_cast<uint8_t*>(uartPacket), PACKET_SIZE, UART_TX_WAITING);
  
  /*Toggle green LED*/
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
}