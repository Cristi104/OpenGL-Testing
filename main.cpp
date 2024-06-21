#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

    float positions[] = {-0.5f, -0.5f, 0.0f, 0.0f,
                         0.5f, -0.5f, 1.0f, 0.0f,
                         0.5f, 0.5f, 1.0f, 1.0f,
                         -0.5f, 0.5f, 0.0f, 1.0f
    };

    unsigned short indices[] = {
            0, 1, 2,
            0, 2, 3
    };

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    VertexArray vertexArray;
    VertexBuffer vertexBuffer(positions, 4 * 4 *sizeof(float));
    VertexBufferLayout vertexBufferLayout;
    vertexBufferLayout.pushFloat(2);
    vertexBufferLayout.pushFloat(2);
    vertexArray.addBuffer(vertexBuffer,vertexBufferLayout);

    IndexBuffer indexBuffer(indices, 6);

    Shader shader("../res/shaders/textureShader.glsl");
    shader.bind();

    Texture texture("../res/assets/None.png");
    texture.bind();
    shader.setUniform1i("u_Texture", 0);

    Renderer renderer;

    float r = 0.0f;
    float inc = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.clear();

        shader.setUniform4f("u_Color", r, 0.5f, 0.0f, 1.0f);

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