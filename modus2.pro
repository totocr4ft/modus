#-------------------------------------------------
#
# Project created by QtCreator 2016-10-01T15:31:31
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = modus2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    common_helper.cpp \
    db_common.cpp \
    mo_user.cpp \
    mo_queries.cpp \
    mo_core.cpp \
    mo_module.cpp \
    common_file_downloader.cpp

HEADERS  += mainwindow.h \
    common_helper.h \
    db_common.h \
    mo_core.h \
    mo_user.h \
    mo_module.h \
    mo_include.h \
    mo_queries.h \
    common_file_downloader.h

FORMS    += mainwindow.ui
LIBS += -lVersion
