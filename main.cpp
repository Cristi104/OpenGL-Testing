#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>
#include "GLErrorCheck.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
struct ShaderSource{
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderSource ParseShader(const std::string& path){
    std::fstream stream(path);

    enum ShaderType{
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
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
    return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const std::string& shader){
    unsigned int id = glCreateShader(type);
    const char* src = shader.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

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

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER,vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

int main() {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        return -1;

    std::cout << glGetString(GL_VERSION) << '\n';

    float positions[] = {-0.5f, -0.5f,
                         0.5f, -0.5f,
                         0.5f, 0.5f,
                         -0.5f, 0.5f
    };

    unsigned short indices[] = {
            0, 1, 2,
            0, 2, 3
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    VertexBuffer vertexBuffer(positions, 4 * 2 *sizeof(float));

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, nullptr);
    glEnableVertexAttribArray(0);

    IndexBuffer indexBuffer(indices, 6);

    ShaderSource source = ParseShader("../res/shaders/shader.glsl");

//    std::cout << source.VertexSource << source.FragmentSource;

    unsigned int program = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(program);

    int uid = glGetUniformLocation(program,"u_Color");

    glBindVertexArray(0);
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    float r = 0.0f;
    float inc = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        GLErrorCheck::GLClearError();
//        glDrawArrays(GL_TRIANGLES, 0, 6);
        glUseProgram(program);
        glUniform4f(uid, r, 0.0f, 0.0f, 1.0f);

        glBindVertexArray(vao);
        indexBuffer.bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);
        GLErrorCheck::GLCheckError();
        if(r > 1.0f)
            inc *= -1;
        if(r < 0.0f)
            inc *= -1;
        r += inc;
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(program);
    glfwTerminate();
    return 0;
}