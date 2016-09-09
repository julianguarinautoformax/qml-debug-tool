#-------------------------------------------------
#
# Project created by QtGuarin 2016-08-26T18:25:35
#
#-------------------------------------------------

#Start Message

message ("Peek a boo Makefile Generator")
message ($$sprintf("%1 %2","Project Dir --->",$$_PRO_FILE_PWD_))


# Compilador y Toolchain

TEMPLATE = lib
TARGET = AFMXDebug
QT  += gui qml quick
CONFIG += qt plugin c++11


# Target: pregunta, para qué sirve la función qtLibraryTartget
TARGET = $$qtLibraryTarget($$TARGET)
uri = com.afmx.debug

# Fuentes 
SOURCES += peekaboolib.cpp \
    afmxdebug_plugin.cpp

HEADERS += peekaboolib.h\
    afmxdebug_plugin.h

DISTFILES += \
    qmldir \
    AMFXDebugScreenConsole.qml

!equals(_PRO_FILE_PWD_, $$OUT_PWD){
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target    
}

qmldir.files = qmldir

unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    message($$sprintf("%1 %2","Install Dir -->",$$installPath))
    INSTALLS += target qmldir
}

RESOURCES += \
    qml.qrc

