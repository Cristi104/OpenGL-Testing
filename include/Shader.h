//
// Created by cristi on 17.06.2024.
//

#ifndef OPENGL_TESTING_SHADER_H
#define OPENGL_TESTING_SHADER_H


#include <string>
#include <unordered_map>

class Shader {
private:
    std::string m_path;
    unsigned int m_RendererID;
    std::unordered_map<std::string, int> m_UniformCache;

    /// Compiles a shader.
    /// @param type The type of shader that should be created.
    /// @param shader Source code of the shader.
    /// @return The id of the created shader.
    static unsigned int CompileShader(unsigned int type, const std::string& shader);

    /// Searches for a uniform inside the program
    /// @param name The name of the uniform.
    /// @return The id of the uniform.
    [[nodiscard]] int getUniformLocation(const std::string& name);

public:

    /// Constructs a shader form source code.
    /// @param path Path to the source code file.
    explicit Shader(const std::string& path);

    ~Shader();

    /// Binds the Shaders to the OpenGL context.
    /// Any other currently bound Shaders will be unbound.
    void bind() const;

    /// Unbinds any currently bound Shaders.
    static void unbind();

    /// Sets the value of a uniform.
    /// @param name The name of the uniform.
    /// @param v1, v2, v3, v4 values to be written to the uniform.
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

    /// Sets the value of a uniform.
    /// @param name The name of the uniform.
    /// @param v1 values to be written to the uniform.
    void setUniform1i(const std::string& name, int v0);
};


#endif //OPENGL_TESTING_SHADER_H
