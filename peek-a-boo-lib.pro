#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T18:25:35
#
#-------------------------------------------------

QT       -= gui

TARGET = peek-a-boo-lib
TEMPLATE = lib

DEFINES += PEEKABOOLIB_LIBRARY

SOURCES += peekaboolib.cpp

HEADERS += peekaboolib.h\
        peek-a-boo-lib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
