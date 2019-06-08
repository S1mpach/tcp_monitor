TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    tcp_monitor.cpp \
    logger.cpp \
    syslogreader.cpp

HEADERS += \
    tcp_monitor.h \
    logger.h \
    syslogreader.h
