/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // Screen_Main
    void gotoScreen_MainScreenNoTransition();

    void gotoScreen_MainScreenSlideTransitionWest();


    // Screen_Module1
    void gotoScreen_Module1ScreenSlideTransitionEast();


    // Screen_Module2
    void gotoScreen_Module2ScreenSlideTransitionEast();


    // Screen_Module3
    void gotoScreen_Module3ScreenCoverTransitionEast();


    // Screen_UART
    void gotoScreen_UARTScreenSlideTransitionEast();


    // Template
    void gotoTemplateScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen_Main
    void gotoScreen_MainScreenNoTransitionImpl();

    void gotoScreen_MainScreenSlideTransitionWestImpl();


    // Screen_Module1
    void gotoScreen_Module1ScreenSlideTransitionEastImpl();


    // Screen_Module2
    void gotoScreen_Module2ScreenSlideTransitionEastImpl();


    // Screen_Module3
    void gotoScreen_Module3ScreenCoverTransitionEastImpl();


    // Screen_UART
    void gotoScreen_UARTScreenSlideTransitionEastImpl();


    // Template
    void gotoTemplateScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
