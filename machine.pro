TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    machine.cpp \
    geometric.cpp \
    errorer.cpp

HEADERS += \
    machine.h \
    geometric.h \
    errorer.h
