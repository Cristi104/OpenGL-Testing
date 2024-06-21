#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../external/glm/glm.hpp"
#include "../external/glm/gtc/matrix_transform.hpp"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"

int main() {
    GLFWwindow *window;
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window = glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        return -1;

    std::cout << glGetString(GL_VERSION) << '\n';

//    float positions[] = {-0.5f, -0.5f, 0.0f, 0.0f,
//                         0.5f, -0.5f, 1.0f, 0.0f,
//                         0.5f, 0.5f, 1.0f, 1.0f,
//                         -0.5f, 0.5f, 0.0f, 1.0f
//    };

    float positions[] = {-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
                         0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
                         0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
                         -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
                         -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
                         0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 1.0f,
                         0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
                         -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f
    };
    unsigned short indices[] = {
            0, 1, 2,
            0, 2, 3,
            2, 3, 7,
            7, 2, 6,
            1, 2, 6,
            6, 1, 5,
            5, 1, 0,
            5, 0, 4,
            4, 0,3,
            4, 3, 7,
            4, 5, 6,
            4, 6, 7
    };

//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthRange(-1.0f,1.0f);
    VertexArray vertexArray;
    VertexBuffer vertexBuffer(positions, 8 * 6 *sizeof(float));
    VertexBufferLayout vertexBufferLayout;
    vertexBufferLayout.pushFloat(3);
    vertexBufferLayout.pushFloat(3);
    vertexArray.addBuffer(vertexBuffer,vertexBufferLayout);

    IndexBuffer indexBuffer(indices, 36);

    glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

//    glm::mat4 rotx = glm::mat4(sqrt(2)/2.0f,0, sqrt(2)/2.0f,0,0,1,0,0,-sqrt(2)/2.0f,0,sqrt(2)/2.0f,0,0,0,0,1);
//    proj *= rotx;
    glm::mat4 rotx = glm::mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
    glm::mat4 roty = rotx;
    glm::mat4 rotz = rotx;

    Shader shader("../res/shaders/shader.glsl");
    shader.bind();

    Texture texture("../res/assets/None.png");
    texture.bind();
//    shader.setUniform1i("u_Texture", 0);
    shader.setUniformMat4f("u_Proj", proj);

    Renderer renderer;

    float theta = 0;
    float r = 0.0f;
    float inc = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.clear();

        theta -= 0.01;

        rotx[1][1] = std::cos(theta);
        rotx[2][1] = -std::sin(theta);
        rotx[1][2] = std::sin(theta);
        rotx[2][2] = std::cos(theta);

        roty[0][0] = std::cos(theta);
        roty[2][0] = std::sin(theta);
        roty[0][2] = -std::sin(theta);
        roty[2][2] = std::cos(theta);

        rotz[0][0] = std::cos(theta);
        rotz[1][0] = -std::sin(theta);
        rotz[0][1] = std::sin(theta);
        rotz[1][1] = std::cos(theta);

        shader.setUniform4f("u_Color", r, 0.5f, 0.0f, 1.0f);
        shader.setUniformMat4f("u_Rotx", rotx);
        shader.setUniformMat4f("u_Roty", roty);
        shader.setUniformMat4f("u_Rotz", rotz);

        renderer.draw(vertexArray, indexBuffer, shader);

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

    glfwTerminate();
    return 0;
}