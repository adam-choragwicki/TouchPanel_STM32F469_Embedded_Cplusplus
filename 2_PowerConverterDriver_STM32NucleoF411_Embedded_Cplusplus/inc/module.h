#pragma once

#include "packet_field_definitions.h"

class Module
{
public:
  void EnableParameter(Parameter parameter);
  void DisableParameter(Parameter parameter);
  void SetParameter(Parameter parameter, double value);
  bool GetParameterState(int index) const {return m_ParameterStates[index];}
  double GetParameterValue(int index) const {return m_ParameterValues[index];}
  
private:
  bool m_ParameterStates[PARAMETERS_COUNT] {false};
  double m_ParameterValues[PARAMETERS_COUNT] {0.0};
  
  void EnableParameterByIndex(int index) {m_ParameterStates[index] = true;}
  void DisableParameterByIndex(int index) {m_ParameterStates[index] = false;}
  void SetParameterByIndex(int index, double value) {m_ParameterValues[index] = value;}
  bool const* GetParameterStatesTable() const {return m_ParameterStates;}
  double const* GetParameterValuesTable() const {return m_ParameterValues;}
};
