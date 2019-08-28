#pragma once

#include <string>

/*Functionalities*/
void CommandInitModule(std::string& command);
void CommandDeinitModule(std::string& command);
void CommandSetGraphMin(std::string& command);
void CommandSetGraphMax(std::string& command);
void CommandSetGraphTime(std::string& command);
void CommandGraphLinear(std::string& command);
void CommandGraphSine(std::string& command);
void CommandGraphSquare(std::string& command);
void CommandSendWrongCrc(std::string& command);
void CommandGetParameters(std::string& command);
void CommandAdc1(std::string& command);
void CommandAdc2(std::string& command);
void CommandSendPacket(std::string& command);