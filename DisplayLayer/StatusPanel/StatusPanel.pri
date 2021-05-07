QT       += core gui

INCLUDEPATH += 3rdparty/spider

SOURCES += \
    $$PWD/radiosignalstrength.cpp \
    $$PWD/statuspanel.cpp

HEADERS += \
    $$PWD/radiosignalstrength.h \
    $$PWD/statuspanel.h

FORMS += \
    $$PWD/statuspanel.ui

LIBS += 3rdparty/spider/spider.lib
