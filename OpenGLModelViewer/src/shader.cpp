#include "shader.h"

#include "fileio.h"
#include "globals.h"

#include <QDebug>

Shader::Shader(QOpenGLFunctions_3_3_Core *gl, std::string vertShaderPath, std::string fragShaderPath)
{
    // Generate the shader program and shader IDs.
    shaderProgramId = gl->glCreateProgram();

    // Attach vertex shader.
    vertexShaderId = gl->glCreateShader(GL_VERTEX_SHADER);
    vertShaderCompiled = loadShaderSource(vertShaderPath, GL_VERTEX_SHADER, gl);
    gl->glAttachShader(shaderProgramId, vertexShaderId);

    // Attach fragment shader.
    fragmentShaderId = gl->glCreateShader(GL_FRAGMENT_SHADER);
    fragShaderCompiled = loadShaderSource(fragShaderPath, GL_FRAGMENT_SHADER, gl);
    gl->glAttachShader(shaderProgramId, fragmentShaderId);

    gl->glLinkProgram(shaderProgramId);
}

bool Shader::loadShaderSource(std::string filename, GLenum shaderType, QOpenGLFunctions_3_3_Core *gl)
{
    // Read shader text from file. OpenGL can't use std::string directly.
    std::string shaderText = OpenGlModelViewer::readAllText(filename);
    if (shaderText == "") {
        return false; // File wasn't read correctly or is empty.
    }
    const char *shaderSource = shaderText.c_str();

    uint shaderId;
    if (shaderType == vertexShaderId) {
        shaderId = vertexShaderId;
    } else if (shaderType == GL_FRAGMENT_SHADER) {
        shaderId = fragmentShaderId;
    } else {
        return false; // Shader type is not supported.
    }

    // Load and compile the shader source.
    gl->glShaderSource(shaderId, 1, &shaderSource, nullptr);
    gl->glCompileShader(fragmentShaderId);

    // Check if the shader compiled correctly.
    GLint compiledSuccessfully;
    gl->glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &compiledSuccessfully);
    return compiledSuccessfully > 0;
}

bool Shader::fragmentShaderCompiled()
{
    return fragShaderCompiled;
}

bool Shader::vertexShaderCompiled()
{
    return vertShaderCompiled;
}
