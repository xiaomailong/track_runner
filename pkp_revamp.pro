#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T08:38:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(api_connectors/api_connectors.pri)
include(widgets/widgets.pri)
include(core_components/core_components.pri)

TARGET = pkp_revamp
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \

HEADERS  += MainWindow.hpp \

FORMS    += MainWindow.ui \
    TrainListWidget.ui
