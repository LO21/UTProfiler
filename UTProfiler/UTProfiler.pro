QT += widgets
QT += core
QT += gui
QT += sql

TARGET = SQL
CONFIG += console
CONFIG -= app

TEMPLATE = app

SOURCES += \
    main.cpp \
    InterfaceSQL.cpp \
    UTProfiler.cpp

HEADERS += \
    UTProfiler.h
