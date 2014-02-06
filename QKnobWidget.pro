CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(qknobwidgetplugin)
TEMPLATE    = lib

HEADERS     = src/qknobwidgetplugin.h
SOURCES     = src/qknobwidgetplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(src/qknobwidget.pri)
