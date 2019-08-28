#pragma once

#include <vector>
#include "uart_packet.h"

int GetArgumentCount(std::string input);
bool ExtractArguments(std::string& input, int requiredArgumentCount, std::vector<std::string>& extractedArguments);
void SendPacketViaUart(UartPacket& uartPacket);