QT += core
QT -= gui

CONFIG += c++11

TARGET = MDP
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mdp.cpp

HEADERS += \
    mdp.h
