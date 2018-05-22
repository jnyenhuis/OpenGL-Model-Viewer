#ifndef MESH_H
#define MESH_H

#include <QString>
#include <QList>

#include "vertex.h"

class Mesh
{
public:
    uint vbo;
    uint vao;
    QList<Vertex> vertices;

    Mesh();
};

#endif // MESH_H
