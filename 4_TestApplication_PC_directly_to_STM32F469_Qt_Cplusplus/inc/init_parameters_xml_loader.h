#pragma once

#include "ui_main_window.h"
#include <string>
#include <vector>
#include <fstream>
#include "module.h"

class InitParametersXmlLoader
{
public:
    InitParametersXmlLoader(Ui::MainWindow* ui);
    bool InitModuleParametersList(Module& module1, Module& module2, Module& module3);

private:
    void ParseXmlFileToParametersList(std::ifstream & inputFile);
    void FillWidgetsTextsFromParametersList(Module& module1, Module& module2, Module& module3);
    void SetModuleSettableParametersInitialValues(Module& module, std::vector<QString>& settableParametersInitialValues);

    Ui::MainWindow* m_pUi;
    std::vector<QString> m_Parameters;
};
