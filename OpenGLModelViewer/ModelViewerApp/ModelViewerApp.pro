#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T10:48:24
#
#-------------------------------------------------

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ModelViewer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        ..\src\main.cpp \
        ..\src\mainwindow.cpp \
    ..\src\openglviewportwidget.cpp \
    ..\src/fileio.cpp \
    ..\src/shader.cpp

HEADERS += \
        ..\src\mainwindow.h \
    ..\src\openglviewportwidget.h \
    ..\src/globals.h \
    ..\src/fileio.h \
    ..\src/shader.h

FORMS += \
    ..\src\mainwindow.ui

LIBS += opengl32.lib

DISTFILES += \
    ../shader/shader.frag \
    ../shader/shader.vert

# path is the destination path.
# files are the paths for the files to be copied to the destination path
# TODO: make paths work for debug, release, etc
message($$shell_path($$top_srcdir/shader/shader.vert))
shaders.path = $$shell_path($$OUT_PWD/debug/shader)
shaders.files += $$shell_path($$top_srcdir/shader/shader.frag)
shaders.files += $$shell_path($$top_srcdir/shader/shader.vert)
INSTALLS += shaders
