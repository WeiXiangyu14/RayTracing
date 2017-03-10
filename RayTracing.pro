#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T19:46:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayTracing
TEMPLATE = app


SOURCES += main.cpp \
    ball.cpp \
    colour.cpp \
    intersection.cpp \
    lightsource.cpp \
    pixel.cpp \
    raytracer.cpp \
    scene.cpp \
    screen.cpp \
    vec3.cpp \
    flat.cpp

HEADERS  += \
    ball.h \
    colour.h \
    const.h \
    intersection.h \
    lightsource.h \
    pixel.h \
    raytracer.h \
    scene.h \
    screen.h \
    vec3.h \
    widget.h \
    flat.h
