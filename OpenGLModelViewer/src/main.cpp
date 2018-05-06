#include "mainwindow.h"
#include <QApplication>

#include <QDebug>
#include "globals.h"

namespace OpenGlModelViewer {
QString APPLICATION_DIRECTORY;
}

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    OpenGlModelViewer::APPLICATION_DIRECTORY = a.applicationDirPath();
    MainWindow w;
    w.show();

    return a.exec();
}
