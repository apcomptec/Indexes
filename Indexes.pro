TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

QMAKE_CXXFLAGS += -std=c++0x

OTHER_FILES += \
    doc/Indexes_UML.xmi \
    doc/Indexes_UML.pdf
