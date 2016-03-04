TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    observer.h \
    subject.h \
    windobserver.h \
    weatherstation.h \
    pressureobserver.h \
    temperatureobserver.h
