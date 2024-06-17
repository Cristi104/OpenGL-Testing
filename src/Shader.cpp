//
// Created by cristi on 17.06.2024.
//

#include <fstream>
#include <GL/glew.h>
#include <iostream>
#include <sstream>
#include "Shader.h"

Shader::Shader(const std::string &path)
        :m_path(path), m_RendererID(0){
    enum ShaderType{
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::fstream stream(path);
    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    // splitting shader file into multiple shader types
    while (getline(stream, line)){
        if (line.find("#shader") != std::string::npos){
            if (line.find("vertex") != std::string::npos){
                type = ShaderType::VERTEX;
            } else if (line.find("fragment") != std::string::npos){
                type = ShaderType::FRAGMENT;
            }
        } else {
            if(type != ShaderType::NONE)
                ss[(int)type] << line << '\n';
        }
    }

    // building program from split shaders
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, ss[1].str());
    unsigned int vs = CompileShader(GL_VERTEX_SHADER,ss[0].str());

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vs);
    glAttachShader(m_RendererID, fs);
    glLinkProgram(m_RendererID);
    glValidateProgram(m_RendererID);

    // shader cleanup
    glDeleteShader(vs);
    glDeleteShader(fs);
}

unsigned int Shader::CompileShader(unsigned int type, const std::string &shader) {
    // compiling shader
    unsigned int id = glCreateShader(type);
    const char* src = shader.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    // build error handling
    int res;
    glGetShaderiv(id, GL_COMPILE_STATUS, &res);
    if (res == GL_FALSE){
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* mes = (char*)(alloca(len * sizeof(char)+1));
        glGetShaderInfoLog(id, len, &len, mes);
        std::cout << mes << '\n';
        glDeleteShader(id);
        return 0;
    }
    return id;
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::bind() const {
    glUseProgram(m_RendererID);
}

Shader::~Shader() {
    glDeleteProgram(m_RendererID);
}

void Shader::setUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
    glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

int Shader::getUniformLocation(const std::string &name) const {
    return glGetUniformLocation(m_RendererID, name.c_str());
}
