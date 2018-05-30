#ifndef MESH_H
#define MESH_H

#include <QString>
#include <QList>
#include <QOpenGLFunctions_3_3_Core>

#include "vertex.h"

class Mesh {
private:
    QOpenGLFunctions_3_3_Core *gl;
public:
    uint vbo;
    uint vao;
    QList<Vertex> vertices;

    Mesh(QOpenGLFunctions_3_3_Core *gl);
    void draw();
};

#endif // MESH_H
