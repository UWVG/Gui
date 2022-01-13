
QT += gui

FORMS += \
    $$PWD/MainWindow.ui

HEADERS += \
    $$PWD/MainWindow.h

SOURCES += \
    $$PWD/MainWindow.cpp \
    $$PWD/main.cpp


INCLUDEPATH += \
    DataTransportLayer/ROSComManger/ROS/ros_lib \
    DataTransportLayer/ROSComManger
