#-------------------------------------------------
#
# Project created by QtCreator 2017-05-28T13:33:23
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RythmMosaic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    keyboard.cpp \
    hit.cpp \
    key.cpp \
    gamewindow.cpp \
    indicator.cpp \
    score.cpp \
    game_client.cpp \
    button.cpp

HEADERS  += mainwindow.h \
    keyboard.h \
    hit.h \
    key.h \
    gamewindow.h \
    indicator.h \
    score.h \
    game_client.h \
    button.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
