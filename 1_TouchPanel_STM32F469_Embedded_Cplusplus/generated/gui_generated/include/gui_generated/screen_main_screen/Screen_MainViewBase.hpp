/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN_MAINVIEWBASE_HPP
#define SCREEN_MAINVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen_main_screen/Screen_MainPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Screen_MainViewBase : public touchgfx::View<Screen_MainPresenter>
{
public:
    Screen_MainViewBase();
    virtual ~Screen_MainViewBase() {}
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void ClearLeds()
    {
        // Override and implement this function in Screen_Main
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box backgroundBox_Black;
    touchgfx::TextAreaWithOneWildcard textArea_CPU_Usage;
    touchgfx::ButtonWithLabel buttonWithLabel_Module2;
    touchgfx::ButtonWithLabel buttonWithLabel_Module1;
    touchgfx::TextArea textArea_MainMenu;
    touchgfx::TextAreaWithOneWildcard textArea_ActiveModule;
    touchgfx::ButtonWithLabel buttonWithLabel_Module3;
    touchgfx::ButtonWithLabel buttonWithLabel_ClearLeds;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA_CPU_USAGE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textArea_CPU_UsageBuffer[TEXTAREA_CPU_USAGE_SIZE];
    static const uint16_t TEXTAREA_ACTIVEMODULE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textArea_ActiveModuleBuffer[TEXTAREA_ACTIVEMODULE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen_MainViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN_MAINVIEWBASE_HPP