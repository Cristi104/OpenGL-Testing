#include <iostream>
#include "GLFW/glfw3.h"
#include "../include/Window.h"

int main(){

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "test", nullptr, nullptr);
    if(window == nullptr){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glViewport(0,0,800,600);

    std::cout << "Hello, World!\n";
    return 0;
}