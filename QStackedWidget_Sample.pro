#-------------------------------------------------
#
# Project created by QtCreator 2016-12-07T19:00:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QStackedWidget_Sample
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    page_widget/OriginalWidget.cpp

HEADERS  += Dialog.h \
    page_widget/OriginalWidget.h

FORMS    += Dialog.ui \
    page_widget/OriginalWidget.ui
