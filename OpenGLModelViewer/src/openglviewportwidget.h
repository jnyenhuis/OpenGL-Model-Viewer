#ifndef OPENGLVIEWPORTWIDGET_H
#define OPENGLVIEWPORTWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>


class OpenGLViewportWidget : public QOpenGLWidget, public QOpenGLFunctions_3_3_Core
{
public:
    uint vertexShader;
    uint fragmentShader;
    explicit OpenGLViewportWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // OPENGLVIEWPORTWIDGET_H
