#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLFunctions_3_3_Core>
#include <string>

class Shader
{
public:
    Shader(QOpenGLFunctions_3_3_Core *gl, std::string vertShaderPath, std::string fragShaderPath);

private:
    uint shaderProgramId;
    uint fragmentShaderId;
    uint vertexShaderId;

    bool loadShaderSource(std::string filename, GLenum shaderType, QOpenGLFunctions_3_3_Core *gl);
};

#endif // SHADER_H
