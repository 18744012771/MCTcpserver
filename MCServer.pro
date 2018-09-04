#-------------------------------------------------
#
# Project created by QtCreator 2018-09-01T10:57:49
#
#-------------------------------------------------

QT       += core gui  network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MCServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpsocket.cpp \
    tcpserver.cpp \
    threadhandle.cpp \
    connectionpool.cpp

HEADERS  += mainwindow.h \
    tcpsocket.h \
    tcpserver.h \
    threadhandle.h \
    connectionpool.h

FORMS    += mainwindow.ui


CONFIG+=c++11
