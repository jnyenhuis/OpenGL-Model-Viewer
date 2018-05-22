#include "shader.h"

#include "fileio.h"
#include "globals.h"

#include <QDebug>

Shader::Shader()
{

}

Shader::Shader(QOpenGLFunctions_3_3_Core *gl, std::string vertShaderPath, std::string fragShaderPath)
{
    // Generate the shader program.
    shaderProgramId = gl->glCreateProgram();

    // Attach vertex shader.
    vertexShaderId = gl->glCreateShader(GL_VERTEX_SHADER);
    vertShaderCompiled = loadShaderSource(vertShaderPath, gl);

    // Attach fragment shader.
    fragmentShaderId = gl->glCreateShader(GL_FRAGMENT_SHADER);
    fragShaderCompiled = loadShaderSource(fragShaderPath, gl);

    gl->glLinkProgram(shaderProgramId);
}

bool Shader::loadShaderSource(std::string filename, QOpenGLFunctions_3_3_Core *gl)
{
    // Read shader text from file. OpenGL can't use std::string directly.
    std::string shaderText = OpenGlModelViewer::readAllText(filename);
    if (shaderText == "") {
        return false; // File wasn't read correctly or is empty.
    }
    const char *shaderSource = shaderText.c_str();

    // Determine the shader type based on the file extension.
    uint shaderId;
    uint shaderType;
    if (filename.substr(filename.find_last_of(".") + 1) == "vert") {
        shaderId = vertexShaderId;
        shaderType = GL_VERTEX_SHADER;
    } else if (shaderType == GL_FRAGMENT_SHADER) {
        shaderId = fragmentShaderId;
        shaderType = GL_FRAGMENT_SHADER;
    } else {
        return false; // Shader type is not supported.
    }

    // Load and compile the shader source.
    gl->glShaderSource(shaderId, 1, &shaderSource, nullptr);
    gl->glCompileShader(shaderId);
    gl->glAttachShader(shaderProgramId, shaderId);

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
