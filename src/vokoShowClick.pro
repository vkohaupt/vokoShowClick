
unix: QT += x11extras
QT += core gui widgets multimedia network testlib dbus

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    global.cpp

HEADERS += \
    global.h

RESOURCES += showclick.qrc \
             spezialCheckBox/spezialCheckBox.qrc
    
CONFIG += link_pkgconfig

unix:LIBS += -L/usr/X11/lib -lX11

include(showclick/showclick.pri)
include(licenses/licenses.pri)
include(help/help.pri)
include(spezialSlider/spezialSlider.pri)
include(spezialCheckBox/spezialCheckBox.pri)
#include(moveButton/movebutton.pri)