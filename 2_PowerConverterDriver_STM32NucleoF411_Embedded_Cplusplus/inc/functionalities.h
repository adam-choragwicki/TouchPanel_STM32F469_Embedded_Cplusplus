#pragma once

#include <string>
#include <vector>
#include "uart_packet.h"

void InitModule(int module);
void DeinitModule(int module);
void SetGraphLowerRange(int module, long long int value);
void SetGraphUpperRange(int module, long long int value);
void SetGraphTimeRange(int module, int value);
void GenerateLinearGraph(int module, int signalCount, double startValue, double stopValue, double stepValue);
void GenerateSineGraph(int module, int signalCount, int startDegrees, int stopDegrees, double amplitude);
void GenerateSquareGraph(int module, int signalCount, int start, int stop, double amplitude, int period);
void SendWrongCrc(int module);
void GetParameters(int module);
void SendAdcToGraphScreen(int module, int packetCount);
void SendAdcToDataScreen(int module, int packetCount);
void SendCustomPacket(int module, char rawParameter, double value);
void ProcessReceivedData(UartPacket& uartPacket);