#include "mesh.h"

Mesh::Mesh(QOpenGLFunctions_3_3_Core *gl) {
    this->gl = gl;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    gl->glGenVertexArrays(1, &vao);
    gl->glBindVertexArray(vao);

    gl->glGenBuffers(1, &vbo);
    gl->glBindBuffer(GL_ARRAY_BUFFER, vbo);
    gl->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    gl->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    gl->glEnableVertexAttribArray(0);
}

void Mesh::draw() {
    // TODO: Draw stuff.
    gl->glBindVertexArray(vao);
    gl->glDrawArrays(GL_TRIANGLES, 0, 3);
}
