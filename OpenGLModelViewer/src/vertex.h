#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>
#include <QVector2D>



class Vertex
{
public:
    QVector3D position = QVector3D(0, 0, 0);
    QVector3D normal = QVector3D(0, 0, 0);
    QVector2D uv = QVector2D(0, 0);

    Vertex();
};

#endif // VERTEX_H
