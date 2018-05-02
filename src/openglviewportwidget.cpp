#include "openglviewportwidget.h"

#include <fstream>
#include <string>
#include <QDebug>
#include <QString>

#include "fileio.h"
#include "globals.h"

OpenGLViewportWidget::OpenGLViewportWidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

void OpenGLViewportWidget::initializeGL()
{
    glFunctions = new QOpenGLFunctions_3_3_Core;
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    std::string shaderDir = OpenGlModelViewer::APPLICATION_DIRECTORY.toStdString() + "\\shader";
    std::string vertShaderText = OpenGlModelViewer::readAllText(shaderDir + "\\shader.vert");
    std::string fragShaderText = OpenGlModelViewer::readAllText(shaderDir + "\\shader.frag");
    qDebug() << QString::fromStdString(vertShaderText) << "\n";
    qDebug() << QString::fromStdString(fragShaderText) << "\n";
}

void OpenGLViewportWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, -0.5, 0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f( 0.5, -0.5, 0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( 0.0,  0.5, 0);
    glEnd();
}

void OpenGLViewportWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //gluLookAt(0,0,5,0,0,0,0,1,0);
}
