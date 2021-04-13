TEMPLATE = app
RC_FILE += gui.rc
include(DisplayLayer/DisplayLayer.pri)
include(DataProcessLayer/DataProcessLayer.pri)
include(DataTransportLayer/DataTransportLayer.pri)
include(utils/utils.pri)

HEADERS += \
    gui.rc \
    version.h
