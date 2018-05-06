#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLFunctions_3_3_Core>
#include <string>

class Shader
{
public:
    Shader(QOpenGLFunctions_3_3_Core *gl, std::string vertShaderPath, std::string fragShaderPath);
    bool fragmentShaderCompiled();
    bool vertexShaderCompiled();

private:
    uint shaderProgramId;

    uint fragmentShaderId;
    bool fragShaderCompiled = false;

    uint vertexShaderId;
    bool vertShaderCompiled = false;

    bool loadShaderSource(std::string filename, GLenum shaderType, QOpenGLFunctions_3_3_Core *gl);
};

#endif // SHADER_H
