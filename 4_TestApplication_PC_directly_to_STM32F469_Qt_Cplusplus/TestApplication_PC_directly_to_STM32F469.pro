#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T04:42:48
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestApplication_PC_directly_to_STM32F469_Qt_Cplusplus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
    src/crc32.cpp \
    src/init_parameters_xml_loader.cpp \
    src/main.cpp \
    src/main_window.cpp \
    src/module.cpp \
    src/table_view.cpp \
    src/uart_packet.cpp \
    src/serial.cpp

HEADERS += \
    inc/crc32.h \
    inc/init_parameters_xml_loader.h \
    inc/main_window.h \
    inc/module.h \
    inc/packet_field_definitions.h \
    inc/table_view.h \
    inc/uart_packet.h \
    inc/serial.h

FORMS += \
    main_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
