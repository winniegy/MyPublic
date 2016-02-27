TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    contextBase.cpp \
    stateBase.cpp \
    stateFactory.cpp \
    stateTest.cpp

DISTFILES += \
    stateTest.pro.user

HEADERS += \
    contextBase.h \
    eventBase.h \
    events.h \
    myContext.h \
    stateBase.h \
    stateFactory.h \
    states.h \
    stateTest.h
