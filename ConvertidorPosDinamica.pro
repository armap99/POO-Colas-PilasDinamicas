TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    pila.cpp \
    node.cpp \
    cola.cpp

HEADERS += \
    error.h \
    pila.h \
    node.h \
    cola.h
