//
// Created by cristi on 17.06.2024.
//

#ifndef OPENGL_TESTING_SHADER_H
#define OPENGL_TESTING_SHADER_H


#include <string>

class Shader {
private:
    std::string m_path;
    unsigned int m_RendererID;

    static unsigned int CompileShader(unsigned int type, const std::string& shader);
    [[nodiscard]] int getUniformLocation(const std::string& name) const;

public:
    explicit Shader(const std::string& path);
    ~Shader();

    void bind() const;
    static void unbind();

    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
};


#endif //OPENGL_TESTING_SHADER_H
