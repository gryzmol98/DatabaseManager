#-------------------------------------------------
#
# Project created by QtCreator 2018-10-29T18:02:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ranking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dodawanie.cpp \
    usuwanie.cpp \
    aktualizacja.cpp

HEADERS  += mainwindow.h \
    dodawanie.h \
    usuwanie.h \
    aktualizacja.h \
    baza.h

FORMS    += mainwindow.ui \
    dodawanie.ui \
    usuwanie.ui \
    aktualizacja.ui

RESOURCES +=
