#pragma once

#include "packet_field_definitions.h"

//Module1

//Module1InitParameterNames
char Module1InitParameter1Name[PAYLOAD_SIZE + 1] = "fs [kHz]";
char Module1InitParameter2Name[PAYLOAD_SIZE + 1] = "Uref [V]";
char Module1InitParameter3Name[PAYLOAD_SIZE + 1] = "Iref [A]";
char Module1InitParameter4Name[PAYLOAD_SIZE + 1] = "Umax [V]";
char Module1InitParameter5Name[PAYLOAD_SIZE + 1] = "Imax [A]";

//Module1InitParameterValues
char Module1InitParameter1Value[PAYLOAD_SIZE + 1] = "100";
char Module1InitParameter2Value[PAYLOAD_SIZE + 1] = "48";
char Module1InitParameter3Value[PAYLOAD_SIZE + 1] = "16";
char Module1InitParameter4Value[PAYLOAD_SIZE + 1] = "60";
char Module1InitParameter5Value[PAYLOAD_SIZE + 1] = "25";

//Module1ParameterNames
char Module1Parameter1Name[PAYLOAD_SIZE + 1] = "Udc1 [V]";
char Module1Parameter2Name[PAYLOAD_SIZE + 1] = "Udc2 [V]";
char Module1Parameter3Name[PAYLOAD_SIZE + 1] = "Idc2 [A]";
char Module1Parameter4Name[PAYLOAD_SIZE + 1] = "Psi";

//Module1ParameterValues
char Module1Parameter1Value[PAYLOAD_SIZE + 1] = "300";
char Module1Parameter2Value[PAYLOAD_SIZE + 1] = "48";
char Module1Parameter3Value[PAYLOAD_SIZE + 1] = "6";
char Module1Parameter4Value[PAYLOAD_SIZE + 1] = "25";

//Module1SettableParameterNames
char Module1SettableParameter1Name[PAYLOAD_SIZE + 1] = "Udc1 [V]";
char Module1SettableParameter2Name[PAYLOAD_SIZE + 1] = "Udc2 [V]";
char Module1SettableParameter3Name[PAYLOAD_SIZE + 1] = "Uac1 [V]";
char Module1SettableParameter4Name[PAYLOAD_SIZE + 1] = "Uac2 [V]";
char Module1SettableParameter5Name[PAYLOAD_SIZE + 1] = "Iac1 [A]";
char Module1SettableParameter6Name[PAYLOAD_SIZE + 1] = "Iac2 [A]";
char Module1SettableParameter7Name[PAYLOAD_SIZE + 1] = "fac1 [Hz]";
char Module1SettableParameter8Name[PAYLOAD_SIZE + 1] = "fac2 [Hz]";
char Module1SettableParameter9Name[PAYLOAD_SIZE + 1] = "Pac1 [W]";
char Module1SettableParameter10Name[PAYLOAD_SIZE + 1] = "Pac2 [W]";

//Module1SettableParameterValues
char Module1SettableParameter1Value[PAYLOAD_SIZE + 1] = "30";
char Module1SettableParameter2Value[PAYLOAD_SIZE + 1] = "60";
char Module1SettableParameter3Value[PAYLOAD_SIZE + 1] = "20";
char Module1SettableParameter4Value[PAYLOAD_SIZE + 1] = "50";
char Module1SettableParameter5Value[PAYLOAD_SIZE + 1] = "10";
char Module1SettableParameter6Value[PAYLOAD_SIZE + 1] = "30";
char Module1SettableParameter7Value[PAYLOAD_SIZE + 1] = "60";
char Module1SettableParameter8Value[PAYLOAD_SIZE + 1] = "80";
char Module1SettableParameter9Value[PAYLOAD_SIZE + 1] = "120";
char Module1SettableParameter10Value[PAYLOAD_SIZE + 1] = "150";

char* const initParametersModule1[INIT_PACKETS_COUNT][PAYLOAD_SIZE + 1] = 
{
  {Module1InitParameter1Name},
  {Module1InitParameter2Name},
  {Module1InitParameter3Name},
  {Module1InitParameter4Name},
  {Module1InitParameter5Name},
  
  {Module1InitParameter1Value},
  {Module1InitParameter2Value},
  {Module1InitParameter3Value},
  {Module1InitParameter4Value},
  {Module1InitParameter5Value},
  
  {Module1Parameter1Name},
  {Module1Parameter2Name},
  {Module1Parameter3Name},
  {Module1Parameter4Name},
  
  {Module1Parameter1Value},
  {Module1Parameter2Value},
  {Module1Parameter3Value},
  {Module1Parameter4Value},
  
  {Module1SettableParameter1Name},
  {Module1SettableParameter2Name},
  {Module1SettableParameter3Name},
  {Module1SettableParameter4Name},
  {Module1SettableParameter5Name},
  {Module1SettableParameter6Name},
  {Module1SettableParameter7Name},
  {Module1SettableParameter8Name},
  {Module1SettableParameter9Name},
  {Module1SettableParameter10Name},

  {Module1SettableParameter1Value},
  {Module1SettableParameter2Value},
  {Module1SettableParameter3Value},
  {Module1SettableParameter4Value},
  {Module1SettableParameter5Value},
  {Module1SettableParameter6Value},
  {Module1SettableParameter7Value},
  {Module1SettableParameter8Value},
  {Module1SettableParameter9Value},
  {Module1SettableParameter10Value}
};

//Module2

//Module2InitParameterNames
char Module2InitParameter1Name[PAYLOAD_SIZE + 1] = "fs [kHz]";
char Module2InitParameter2Name[PAYLOAD_SIZE + 1] = "Uref [V]";
char Module2InitParameter3Name[PAYLOAD_SIZE + 1] = "Iref [A]";
char Module2InitParameter4Name[PAYLOAD_SIZE + 1] = "Umax [V]";
char Module2InitParameter5Name[PAYLOAD_SIZE + 1] = "Imax [A]";

//Module2InitParameterValues
char Module2InitParameter1Value[PAYLOAD_SIZE + 1] = "100";
char Module2InitParameter2Value[PAYLOAD_SIZE + 1] = "48";
char Module2InitParameter3Value[PAYLOAD_SIZE + 1] = "16";
char Module2InitParameter4Value[PAYLOAD_SIZE + 1] = "60";
char Module2InitParameter5Value[PAYLOAD_SIZE + 1] = "25";

//Module2ParameterNames
char Module2Parameter1Name[PAYLOAD_SIZE + 1] = "Udc1 [V]";
char Module2Parameter2Name[PAYLOAD_SIZE + 1] = "Udc2 [V]";
char Module2Parameter3Name[PAYLOAD_SIZE + 1] = "Idc2 [A]";
char Module2Parameter4Name[PAYLOAD_SIZE + 1] = "Psi";

//Module2ParameterValues
char Module2Parameter1Value[PAYLOAD_SIZE + 1] = "300";
char Module2Parameter2Value[PAYLOAD_SIZE + 1] = "48";
char Module2Parameter3Value[PAYLOAD_SIZE + 1] = "6";
char Module2Parameter4Value[PAYLOAD_SIZE + 1] = "25";

//Module2SettableParameterNames
char Module2SettableParameter1Name[PAYLOAD_SIZE + 1] = "Udc1 [V]";
char Module2SettableParameter2Name[PAYLOAD_SIZE + 1] = "Udc2 [V]";
char Module2SettableParameter3Name[PAYLOAD_SIZE + 1] = "Uac1 [V]";
char Module2SettableParameter4Name[PAYLOAD_SIZE + 1] = "Uac2 [V]";
char Module2SettableParameter5Name[PAYLOAD_SIZE + 1] = "Iac1 [A]";
char Module2SettableParameter6Name[PAYLOAD_SIZE + 1] = "Iac2 [A]";
char Module2SettableParameter7Name[PAYLOAD_SIZE + 1] = "fac1 [Hz]";
char Module2SettableParameter8Name[PAYLOAD_SIZE + 1] = "fac2 [Hz]";
char Module2SettableParameter9Name[PAYLOAD_SIZE + 1] = "Pac1 [W]";
char Module2SettableParameter10Name[PAYLOAD_SIZE + 1] = "Pac2 [W]";

//Module2SettableParameterValues
char Module2SettableParameter1Value[PAYLOAD_SIZE + 1] = "30";
char Module2SettableParameter2Value[PAYLOAD_SIZE + 1] = "60";
char Module2SettableParameter3Value[PAYLOAD_SIZE + 1] = "20";
char Module2SettableParameter4Value[PAYLOAD_SIZE + 1] = "50";
char Module2SettableParameter5Value[PAYLOAD_SIZE + 1] = "10";
char Module2SettableParameter6Value[PAYLOAD_SIZE + 1] = "30";
char Module2SettableParameter7Value[PAYLOAD_SIZE + 1] = "60";
char Module2SettableParameter8Value[PAYLOAD_SIZE + 1] = "80";
char Module2SettableParameter9Value[PAYLOAD_SIZE + 1] = "120";
char Module2SettableParameter10Value[PAYLOAD_SIZE + 1] = "150";

char* const initParametersModule2[INIT_PACKETS_COUNT][PAYLOAD_SIZE + 1] = 
{
  {Module2InitParameter1Name},
  {Module2InitParameter2Name},
  {Module2InitParameter3Name},
  {Module2InitParameter4Name},
  {Module2InitParameter5Name},
  
  {Module2InitParameter1Value},
  {Module2InitParameter2Value},
  {Module2InitParameter3Value},
  {Module2InitParameter4Value},
  {Module2InitParameter5Value},
  
  {Module2Parameter1Name},
  {Module2Parameter2Name},
  {Module2Parameter3Name},
  {Module2Parameter4Name},
  
  {Module2Parameter1Value},
  {Module2Parameter2Value},
  {Module2Parameter3Value},
  {Module2Parameter4Value},
  
  {Module2SettableParameter1Name},
  {Module2SettableParameter2Name},
  {Module2SettableParameter3Name},
  {Module2SettableParameter4Name},
  {Module2SettableParameter5Name},
  {Module2SettableParameter6Name},
  {Module2SettableParameter7Name},
  {Module2SettableParameter8Name},
  {Module2SettableParameter9Name},
  {Module2SettableParameter10Name},

  {Module2SettableParameter1Value},
  {Module2SettableParameter2Value},
  {Module2SettableParameter3Value},
  {Module2SettableParameter4Value},
  {Module2SettableParameter5Value},
  {Module2SettableParameter6Value},
  {Module2SettableParameter7Value},
  {Module2SettableParameter8Value},
  {Module2SettableParameter9Value},
  {Module2SettableParameter10Value}
};

//Module3

//Module3InitParameterNames
char Module3InitParameter1Name[PAYLOAD_SIZE + 1] = "fs [kHz]";
char Module3InitParameter2Name[PAYLOAD_SIZE + 1] = "Uref [V]";
char Module3InitParameter3Name[PAYLOAD_SIZE + 1] = "Iref [A]";
char Module3InitParameter4Name[PAYLOAD_SIZE + 1] = "Umax [V]";
char Module3InitParameter5Name[PAYLOAD_SIZE + 1] = "Imax [A]";

//Module3InitParameterValues
char Module3InitParameter1Value[PAYLOAD_SIZE + 1] = "100";
char Module3InitParameter2Value[PAYLOAD_SIZE + 1] = "48";
char Module3InitParameter3Value[PAYLOAD_SIZE + 1] = "16";
char Module3InitParameter4Value[PAYLOAD_SIZE + 1] = "60";
char Module3InitParameter5Value[PAYLOAD_SIZE + 1] = "25";

//Module3ParameterNames
char Module3Parameter1Name[PAYLOAD_SIZE + 1] = "Udc1 [V]";
char Module3Parameter2Name[PAYLOAD_SIZE + 1] = "Udc2 [V]";
char Module3Parameter3Name[PAYLOAD_SIZE + 1] = "Idc2 [A]";
char Module3Parameter4Name[PAYLOAD_SIZE + 1] = "Psi";

//Module3ParameterValues
char Module3Parameter1Value[PAYLOAD_SIZE + 1] = "300";
char Module3Parameter2Value[PAYLOAD_SIZE + 1] = "48";
char Module3Parameter3Value[PAYLOAD_SIZE + 1] = "6";
char Module3Parameter4Value[PAYLOAD_SIZE + 1] = "25";

//Module3SettableParameterNames
char Module3SettableParameter1Name[PAYLOAD_SIZE + 1] = "Udc1 [V]";
char Module3SettableParameter2Name[PAYLOAD_SIZE + 1] = "Udc2 [V]";
char Module3SettableParameter3Name[PAYLOAD_SIZE + 1] = "Uac1 [V]";
char Module3SettableParameter4Name[PAYLOAD_SIZE + 1] = "Uac2 [V]";
char Module3SettableParameter5Name[PAYLOAD_SIZE + 1] = "Iac1 [A]";
char Module3SettableParameter6Name[PAYLOAD_SIZE + 1] = "Iac2 [A]";
char Module3SettableParameter7Name[PAYLOAD_SIZE + 1] = "fac1 [Hz]";
char Module3SettableParameter8Name[PAYLOAD_SIZE + 1] = "fac2 [Hz]";
char Module3SettableParameter9Name[PAYLOAD_SIZE + 1] = "Pac1 [W]";
char Module3SettableParameter10Name[PAYLOAD_SIZE + 1] = "Pac2 [W]";

//Module3SettableParameterValues
char Module3SettableParameter1Value[PAYLOAD_SIZE + 1] = "30";
char Module3SettableParameter2Value[PAYLOAD_SIZE + 1] = "60";
char Module3SettableParameter3Value[PAYLOAD_SIZE + 1] = "20";
char Module3SettableParameter4Value[PAYLOAD_SIZE + 1] = "50";
char Module3SettableParameter5Value[PAYLOAD_SIZE + 1] = "10";
char Module3SettableParameter6Value[PAYLOAD_SIZE + 1] = "30";
char Module3SettableParameter7Value[PAYLOAD_SIZE + 1] = "60";
char Module3SettableParameter8Value[PAYLOAD_SIZE + 1] = "80";
char Module3SettableParameter9Value[PAYLOAD_SIZE + 1] = "120";
char Module3SettableParameter10Value[PAYLOAD_SIZE + 1] = "150";

char* const initParametersModule3[INIT_PACKETS_COUNT][PAYLOAD_SIZE + 1] = 
{
  {Module3InitParameter1Name},
  {Module3InitParameter2Name},
  {Module3InitParameter3Name},
  {Module3InitParameter4Name},
  {Module3InitParameter5Name},
  
  {Module3InitParameter1Value},
  {Module3InitParameter2Value},
  {Module3InitParameter3Value},
  {Module3InitParameter4Value},
  {Module3InitParameter5Value},
  
  {Module3Parameter1Name},
  {Module3Parameter2Name},
  {Module3Parameter3Name},
  {Module3Parameter4Name},
  
  {Module3Parameter1Value},
  {Module3Parameter2Value},
  {Module3Parameter3Value},
  {Module3Parameter4Value},
  
  {Module3SettableParameter1Name},
  {Module3SettableParameter2Name},
  {Module3SettableParameter3Name},
  {Module3SettableParameter4Name},
  {Module3SettableParameter5Name},
  {Module3SettableParameter6Name},
  {Module3SettableParameter7Name},
  {Module3SettableParameter8Name},
  {Module3SettableParameter9Name},
  {Module3SettableParameter10Name},

  {Module3SettableParameter1Value},
  {Module3SettableParameter2Value},
  {Module3SettableParameter3Value},
  {Module3SettableParameter4Value},
  {Module3SettableParameter5Value},
  {Module3SettableParameter6Value},
  {Module3SettableParameter7Value},
  {Module3SettableParameter8Value},
  {Module3SettableParameter9Value},
  {Module3SettableParameter10Value}
};
