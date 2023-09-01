#include "init_parameters_xml_loader.h"
#include <QDebug>
#include <QMessageBox>

InitParametersXmlLoader::InitParametersXmlLoader(Ui::MainWindow* ui)
{
    m_pUi = ui;
}

bool InitParametersXmlLoader::InitModuleParametersList(Module& module1, Module& module2, Module& module3)
{
    std::ifstream inputFile;

    inputFile.open("parameters.xml", std::ios_base::in);

    if(inputFile.is_open())
    {
        qDebug("parameters.xml opened successfully");

        ParseXmlFileToParametersList(inputFile);

        FillWidgetsTextsFromParametersList(module1, module2, module3);

        return true;
    }
    else
    {
        qDebug("Could not open parameters.xml");
        return false;
    }
}

void InitParametersXmlLoader::ParseXmlFileToParametersList(std::ifstream & inputFile)
{
    std::string inputLine;
    QString foundString;

    size_t beginningTagStartIndex;
    size_t beginningTagEndIndex;
    size_t endingTagStartIndex;
    size_t endingTagEndIndex;
    size_t stringLength;

    while(getline(inputFile,inputLine))
    {
        if(inputLine.length() != 0)
        {
            beginningTagStartIndex = inputLine.find('<', 0);
            beginningTagEndIndex= inputLine.find('>', beginningTagStartIndex + 1);

            endingTagStartIndex = inputLine.find('<', beginningTagEndIndex + 1);
            endingTagEndIndex = inputLine.find('>', endingTagStartIndex + 1);

            /*Check if beginning and ending tag was found in the line*/
            if(beginningTagStartIndex != std::string::npos &&
                    beginningTagEndIndex != std::string::npos &&
                    endingTagStartIndex != std::string::npos &&
                    endingTagEndIndex != std::string::npos)
            {
                stringLength = endingTagStartIndex - beginningTagEndIndex;

                foundString = QString::fromStdString(inputLine.substr(beginningTagEndIndex + 1, stringLength - 1));

                m_Parameters.push_back(foundString);
            }
        }
    }
}

void InitParametersXmlLoader::FillWidgetsTextsFromParametersList(Module& module1, Module& module2, Module& module3)
{
    std::vector<QString> module1InfoParametersNames = {m_Parameters.at(0),
                                                       m_Parameters.at(1),
                                                       m_Parameters.at(2),
                                                       m_Parameters.at(3),
                                                       m_Parameters.at(4)};

    /*Initialize module info parameter names*/
    m_pUi->label_Module1InitParameter1Name->setText(module1InfoParametersNames.at(0));
    m_pUi->label_Module1InitParameter2Name->setText(module1InfoParametersNames.at(1));
    m_pUi->label_Module1InitParameter3Name->setText(module1InfoParametersNames.at(2));
    m_pUi->label_Module1InitParameter4Name->setText(module1InfoParametersNames.at(3));
    m_pUi->label_Module1InitParameter5Name->setText(module1InfoParametersNames.at(4));

    std::vector<QString> module1InfoParametersValues = {m_Parameters.at(5),
                                                        m_Parameters.at(6),
                                                        m_Parameters.at(7),
                                                        m_Parameters.at(8),
                                                        m_Parameters.at(9)};

    /*Initialize module info parameter values*/
    m_pUi->lineEdit_Module1InitParameter1Value->setText(module1InfoParametersValues.at(0));
    m_pUi->lineEdit_Module1InitParameter2Value->setText(module1InfoParametersValues.at(1));
    m_pUi->lineEdit_Module1InitParameter3Value->setText(module1InfoParametersValues.at(2));
    m_pUi->lineEdit_Module1InitParameter4Value->setText(module1InfoParametersValues.at(3));
    m_pUi->lineEdit_Module1InitParameter5Value->setText(module1InfoParametersValues.at(4));

    std::vector<QString> module1ParameterNames = {m_Parameters.at(10),
                                                  m_Parameters.at(11),
                                                  m_Parameters.at(12),
                                                  m_Parameters.at(13)};

    /*Initialize module parameter names*/
    m_pUi->label_Module1Parameter1Name->setText(module1ParameterNames.at(0));
    m_pUi->label_Module1Parameter2Name->setText(module1ParameterNames.at(1));
    m_pUi->label_Module1Parameter3Name->setText(module1ParameterNames.at(2));
    m_pUi->label_Module1Parameter4Name->setText(module1ParameterNames.at(3));

    std::vector<QString> module1ParameterValues = {m_Parameters.at(14),
                                                   m_Parameters.at(15),
                                                   m_Parameters.at(16),
                                                   m_Parameters.at(17)};

    /*Initialize module parameter values*/
    m_pUi->lineEdit_Module1Parameter1Name->setText(module1ParameterValues.at(0));
    m_pUi->lineEdit_Module1Parameter2Name->setText(module1ParameterValues.at(1));
    m_pUi->lineEdit_Module1Parameter3Name->setText(module1ParameterValues.at(2));
    m_pUi->lineEdit_Module1Parameter4Name->setText(module1ParameterValues.at(3));

    std::vector<QString> module1SettableParametersNames = {m_Parameters.at(18),
                                                           m_Parameters.at(19),
                                                           m_Parameters.at(20),
                                                           m_Parameters.at(21),
                                                           m_Parameters.at(22),
                                                           m_Parameters.at(23),
                                                           m_Parameters.at(24),
                                                           m_Parameters.at(25),
                                                           m_Parameters.at(26),
                                                           m_Parameters.at(27)};

    /*Initialize settable parameter names*/
    m_pUi->label_Module1_SettableParameter1Name->setText(module1SettableParametersNames.at(0));
    m_pUi->label_Module1_SettableParameter2Name->setText(module1SettableParametersNames.at(1));
    m_pUi->label_Module1_SettableParameter3Name->setText(module1SettableParametersNames.at(2));
    m_pUi->label_Module1_SettableParameter4Name->setText(module1SettableParametersNames.at(3));
    m_pUi->label_Module1_SettableParameter5Name->setText(module1SettableParametersNames.at(4));
    m_pUi->label_Module1_SettableParameter6Name->setText(module1SettableParametersNames.at(5));
    m_pUi->label_Module1_SettableParameter7Name->setText(module1SettableParametersNames.at(6));
    m_pUi->label_Module1_SettableParameter8Name->setText(module1SettableParametersNames.at(7));
    m_pUi->label_Module1_SettableParameter9Name->setText(module1SettableParametersNames.at(8));
    m_pUi->label_Module1_SettableParameter10Name->setText(module1SettableParametersNames.at(9));

    std::vector<QString> module1SettableParametersValues = {m_Parameters.at(28),
                                                            m_Parameters.at(29),
                                                            m_Parameters.at(30),
                                                            m_Parameters.at(31),
                                                            m_Parameters.at(32),
                                                            m_Parameters.at(33),
                                                            m_Parameters.at(34),
                                                            m_Parameters.at(35),
                                                            m_Parameters.at(36),
                                                            m_Parameters.at(37)};

    /*Initialize settable parameter values*/
    m_pUi->lcdNumber_Value_Module1_SettableParameter1->display(module1SettableParametersValues.at(0));
    m_pUi->lcdNumber_Value_Module1_SettableParameter2->display(module1SettableParametersValues.at(1));
    m_pUi->lcdNumber_Value_Module1_SettableParameter3->display(module1SettableParametersValues.at(2));
    m_pUi->lcdNumber_Value_Module1_SettableParameter4->display(module1SettableParametersValues.at(3));
    m_pUi->lcdNumber_Value_Module1_SettableParameter5->display(module1SettableParametersValues.at(4));
    m_pUi->lcdNumber_Value_Module1_SettableParameter6->display(module1SettableParametersValues.at(5));
    m_pUi->lcdNumber_Value_Module1_SettableParameter7->display(module1SettableParametersValues.at(6));
    m_pUi->lcdNumber_Value_Module1_SettableParameter8->display(module1SettableParametersValues.at(7));
    m_pUi->lcdNumber_Value_Module1_SettableParameter9->display(module1SettableParametersValues.at(8));
    m_pUi->lcdNumber_Value_Module1_SettableParameter10->display(module1SettableParametersValues.at(9));

    SetModuleSettableParametersInitialValues(module1, module1SettableParametersValues);

    //////////////////////////////////////////////////////////////////////////////////////////

    std::vector<QString> module2InfoParametersNames = {m_Parameters.at(38),
                                                       m_Parameters.at(39),
                                                       m_Parameters.at(40),
                                                       m_Parameters.at(41),
                                                       m_Parameters.at(42)};

    /*Initialize module info parameter names*/
    m_pUi->label_Module2InitParameter1Name->setText(module2InfoParametersNames.at(0));
    m_pUi->label_Module2InitParameter2Name->setText(module2InfoParametersNames.at(1));
    m_pUi->label_Module2InitParameter3Name->setText(module2InfoParametersNames.at(2));
    m_pUi->label_Module2InitParameter4Name->setText(module2InfoParametersNames.at(3));
    m_pUi->label_Module2InitParameter5Name->setText(module2InfoParametersNames.at(4));

    std::vector<QString> module2InfoParametersValues = {m_Parameters.at(43),
                                                       m_Parameters.at(44),
                                                       m_Parameters.at(45),
                                                       m_Parameters.at(46),
                                                       m_Parameters.at(47)};

    /*Initialize module info parameter values*/
    m_pUi->lineEdit_Module2InitParameter1Value->setText(module2InfoParametersValues.at(0));
    m_pUi->lineEdit_Module2InitParameter2Value->setText(module2InfoParametersValues.at(1));
    m_pUi->lineEdit_Module2InitParameter3Value->setText(module2InfoParametersValues.at(2));
    m_pUi->lineEdit_Module2InitParameter4Value->setText(module2InfoParametersValues.at(3));
    m_pUi->lineEdit_Module2InitParameter5Value->setText(module2InfoParametersValues.at(4));

    std::vector<QString> module2ParameterNames = {m_Parameters.at(48),
                                                  m_Parameters.at(49),
                                                  m_Parameters.at(50),
                                                  m_Parameters.at(51)};

    /*Initialize module parameter names*/
    m_pUi->label_Module2Parameter1Name->setText(module2ParameterNames.at(0));
    m_pUi->label_Module2Parameter2Name->setText(module2ParameterNames.at(1));
    m_pUi->label_Module2Parameter3Name->setText(module2ParameterNames.at(2));
    m_pUi->label_Module2Parameter4Name->setText(module2ParameterNames.at(3));

    std::vector<QString> module2ParameterValues = {m_Parameters.at(52),
                                                   m_Parameters.at(53),
                                                   m_Parameters.at(54),
                                                   m_Parameters.at(55)};

    /*Initialize module parameter values*/
    m_pUi->lineEdit_Module2Parameter1Name->setText(module2ParameterValues.at(0));
    m_pUi->lineEdit_Module2Parameter2Name->setText(module2ParameterValues.at(1));
    m_pUi->lineEdit_Module2Parameter3Name->setText(module2ParameterValues.at(2));
    m_pUi->lineEdit_Module2Parameter4Name->setText(module2ParameterValues.at(3));

    std::vector<QString> module2SettableParametersNames = {m_Parameters.at(56),
                                                           m_Parameters.at(57),
                                                           m_Parameters.at(58),
                                                           m_Parameters.at(59),
                                                           m_Parameters.at(60),
                                                           m_Parameters.at(61),
                                                           m_Parameters.at(62),
                                                           m_Parameters.at(63),
                                                           m_Parameters.at(64),
                                                           m_Parameters.at(65)};

    /*Initialize settable parameter names*/
    m_pUi->label_Module2_SettableParameter1Name->setText(module2SettableParametersNames.at(0));
    m_pUi->label_Module2_SettableParameter2Name->setText(module2SettableParametersNames.at(1));
    m_pUi->label_Module2_SettableParameter3Name->setText(module2SettableParametersNames.at(2));
    m_pUi->label_Module2_SettableParameter4Name->setText(module2SettableParametersNames.at(3));
    m_pUi->label_Module2_SettableParameter5Name->setText(module2SettableParametersNames.at(4));
    m_pUi->label_Module2_SettableParameter6Name->setText(module2SettableParametersNames.at(5));
    m_pUi->label_Module2_SettableParameter7Name->setText(module2SettableParametersNames.at(6));
    m_pUi->label_Module2_SettableParameter8Name->setText(module2SettableParametersNames.at(7));
    m_pUi->label_Module2_SettableParameter9Name->setText(module2SettableParametersNames.at(8));
    m_pUi->label_Module2_SettableParameter10Name->setText(module2SettableParametersNames.at(9));

    std::vector<QString> module2SettableParametersValues = {m_Parameters.at(66),
                                                           m_Parameters.at(67),
                                                           m_Parameters.at(68),
                                                           m_Parameters.at(69),
                                                           m_Parameters.at(70),
                                                           m_Parameters.at(71),
                                                           m_Parameters.at(72),
                                                           m_Parameters.at(73),
                                                           m_Parameters.at(74),
                                                           m_Parameters.at(75)};

    /*Initialize settable parameter values*/
    m_pUi->lcdNumber_Value_Module2_SettableParameter1->display(module2SettableParametersValues.at(0));
    m_pUi->lcdNumber_Value_Module2_SettableParameter2->display(module2SettableParametersValues.at(1));
    m_pUi->lcdNumber_Value_Module2_SettableParameter3->display(module2SettableParametersValues.at(2));
    m_pUi->lcdNumber_Value_Module2_SettableParameter4->display(module2SettableParametersValues.at(3));
    m_pUi->lcdNumber_Value_Module2_SettableParameter5->display(module2SettableParametersValues.at(4));
    m_pUi->lcdNumber_Value_Module2_SettableParameter6->display(module2SettableParametersValues.at(5));
    m_pUi->lcdNumber_Value_Module2_SettableParameter7->display(module2SettableParametersValues.at(6));
    m_pUi->lcdNumber_Value_Module2_SettableParameter8->display(module2SettableParametersValues.at(7));
    m_pUi->lcdNumber_Value_Module2_SettableParameter9->display(module2SettableParametersValues.at(8));
    m_pUi->lcdNumber_Value_Module2_SettableParameter10->display(module2SettableParametersValues.at(9));

    SetModuleSettableParametersInitialValues(module2, module2SettableParametersValues);

    //////////////////////////////////////////////////////////////////////////////////////////

    std::vector<QString> module3InfoParametersNames = {m_Parameters.at(76),
                                                       m_Parameters.at(77),
                                                       m_Parameters.at(78),
                                                       m_Parameters.at(79),
                                                       m_Parameters.at(80)};

    /*Initialize module info parameter names*/
    m_pUi->label_Module3InitParameter1Name->setText(module3InfoParametersNames.at(0));
    m_pUi->label_Module3InitParameter2Name->setText(module3InfoParametersNames.at(1));
    m_pUi->label_Module3InitParameter3Name->setText(module3InfoParametersNames.at(2));
    m_pUi->label_Module3InitParameter4Name->setText(module3InfoParametersNames.at(3));
    m_pUi->label_Module3InitParameter5Name->setText(module3InfoParametersNames.at(4));

    std::vector<QString> module3InfoParametersValues = {m_Parameters.at(81),
                                                       m_Parameters.at(82),
                                                       m_Parameters.at(83),
                                                       m_Parameters.at(84),
                                                       m_Parameters.at(85)};

    /*Initialize module info parameter values*/
    m_pUi->lineEdit_Module3InitParameter1Value->setText(module3InfoParametersValues.at(0));
    m_pUi->lineEdit_Module3InitParameter2Value->setText(module3InfoParametersValues.at(1));
    m_pUi->lineEdit_Module3InitParameter3Value->setText(module3InfoParametersValues.at(2));
    m_pUi->lineEdit_Module3InitParameter4Value->setText(module3InfoParametersValues.at(3));
    m_pUi->lineEdit_Module3InitParameter5Value->setText(module3InfoParametersValues.at(4));

    std::vector<QString> module3ParameterNames = {m_Parameters.at(86),
                                                  m_Parameters.at(87),
                                                  m_Parameters.at(88),
                                                  m_Parameters.at(89)};

    /*Initialize module parameter names*/
    m_pUi->label_Module3Parameter1Name->setText(module3ParameterNames.at(0));
    m_pUi->label_Module3Parameter2Name->setText(module3ParameterNames.at(1));
    m_pUi->label_Module3Parameter3Name->setText(module3ParameterNames.at(2));
    m_pUi->label_Module3Parameter4Name->setText(module3ParameterNames.at(3));

    std::vector<QString> module3ParameterValues = {m_Parameters.at(90),
                                                  m_Parameters.at(91),
                                                  m_Parameters.at(92),
                                                  m_Parameters.at(93)};

    /*Initialize module parameter values*/
    m_pUi->lineEdit_Module3Parameter1Name->setText(module3ParameterValues.at(0));
    m_pUi->lineEdit_Module3Parameter2Name->setText(module3ParameterValues.at(1));
    m_pUi->lineEdit_Module3Parameter3Name->setText(module3ParameterValues.at(2));
    m_pUi->lineEdit_Module3Parameter4Name->setText(module3ParameterValues.at(3));

    std::vector<QString> module3SettableParametersNames = {m_Parameters.at(94),
                                                           m_Parameters.at(95),
                                                           m_Parameters.at(96),
                                                           m_Parameters.at(97),
                                                           m_Parameters.at(98),
                                                           m_Parameters.at(99),
                                                           m_Parameters.at(100),
                                                           m_Parameters.at(101),
                                                           m_Parameters.at(102),
                                                           m_Parameters.at(103)};

    /*Initialize settable parameter names*/
    m_pUi->label_Module3_SettableParameter1Name->setText(module3SettableParametersNames.at(0));
    m_pUi->label_Module3_SettableParameter2Name->setText(module3SettableParametersNames.at(1));
    m_pUi->label_Module3_SettableParameter3Name->setText(module3SettableParametersNames.at(2));
    m_pUi->label_Module3_SettableParameter4Name->setText(module3SettableParametersNames.at(3));
    m_pUi->label_Module3_SettableParameter5Name->setText(module3SettableParametersNames.at(4));
    m_pUi->label_Module3_SettableParameter6Name->setText(module3SettableParametersNames.at(5));
    m_pUi->label_Module3_SettableParameter7Name->setText(module3SettableParametersNames.at(6));
    m_pUi->label_Module3_SettableParameter8Name->setText(module3SettableParametersNames.at(7));
    m_pUi->label_Module3_SettableParameter9Name->setText(module3SettableParametersNames.at(8));
    m_pUi->label_Module3_SettableParameter10Name->setText(module3SettableParametersNames.at(9));

    std::vector<QString> module3SettableParametersValues = {m_Parameters.at(104),
                                                           m_Parameters.at(105),
                                                           m_Parameters.at(106),
                                                           m_Parameters.at(107),
                                                           m_Parameters.at(108),
                                                           m_Parameters.at(109),
                                                           m_Parameters.at(110),
                                                           m_Parameters.at(111),
                                                           m_Parameters.at(112),
                                                           m_Parameters.at(113)};

    /*Initialize settable parameter values*/
    m_pUi->lcdNumber_Value_Module3_SettableParameter1->display(module3SettableParametersValues.at(0));
    m_pUi->lcdNumber_Value_Module3_SettableParameter2->display(module3SettableParametersValues.at(1));
    m_pUi->lcdNumber_Value_Module3_SettableParameter3->display(module3SettableParametersValues.at(2));
    m_pUi->lcdNumber_Value_Module3_SettableParameter4->display(module3SettableParametersValues.at(3));
    m_pUi->lcdNumber_Value_Module3_SettableParameter5->display(module3SettableParametersValues.at(4));
    m_pUi->lcdNumber_Value_Module3_SettableParameter6->display(module3SettableParametersValues.at(5));
    m_pUi->lcdNumber_Value_Module3_SettableParameter7->display(module3SettableParametersValues.at(6));
    m_pUi->lcdNumber_Value_Module3_SettableParameter8->display(module3SettableParametersValues.at(7));
    m_pUi->lcdNumber_Value_Module3_SettableParameter9->display(module3SettableParametersValues.at(8));
    m_pUi->lcdNumber_Value_Module3_SettableParameter10->display(module3SettableParametersValues.at(9));

    SetModuleSettableParametersInitialValues(module3, module3SettableParametersValues);
}

void InitParametersXmlLoader::SetModuleSettableParametersInitialValues(Module& module, std::vector<QString>& settableParametersInitialValues)
{
    module.SetParameter(Parameter::PARAMETER1, settableParametersInitialValues.at(0).toDouble());
    module.SetParameter(Parameter::PARAMETER2, settableParametersInitialValues.at(1).toDouble());
    module.SetParameter(Parameter::PARAMETER3, settableParametersInitialValues.at(2).toDouble());
    module.SetParameter(Parameter::PARAMETER4, settableParametersInitialValues.at(3).toDouble());
    module.SetParameter(Parameter::PARAMETER5, settableParametersInitialValues.at(4).toDouble());
    module.SetParameter(Parameter::PARAMETER6, settableParametersInitialValues.at(5).toDouble());
    module.SetParameter(Parameter::PARAMETER7, settableParametersInitialValues.at(6).toDouble());
    module.SetParameter(Parameter::PARAMETER8, settableParametersInitialValues.at(7).toDouble());
    module.SetParameter(Parameter::PARAMETER9, settableParametersInitialValues.at(8).toDouble());
    module.SetParameter(Parameter::PARAMETER10, settableParametersInitialValues.at(9).toDouble());
}


