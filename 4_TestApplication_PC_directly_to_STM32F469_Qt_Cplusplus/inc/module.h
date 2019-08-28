#pragma once

#include "packet_field_definitions.h"

class Module
{
public:
    void EnableParameter(Parameter parameter);
    void DisableParameter(Parameter parameter);
    void SetParameter(Parameter parameter, double value);
    bool GetParameterState(int index);
    double GetParameterValue(int index);
    bool* GetParameterStatesTable();
    double* GetParameterValuesTable();

private:
    void SetParameterByIndex(int index, double value);
    void EnableParameterByIndex(int index);
    void DisableParameterByIndex(int index);

    bool m_ParameterStates[PARAMETERS_COUNT] {false};
    double m_ParameterValues[PARAMETERS_COUNT] {0.0};
};
