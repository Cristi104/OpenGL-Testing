//
// Created by cristi on 16.06.2024.
//

#include <GL/glew.h>
#include <iostream>
#include "GLErrorCheck.h"

void GLErrorCheck::GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

void GLErrorCheck::GLCheckError() {
    if(GLenum error = glGetError()){
        std::cout << "OpenGL Error: 0x" << std::hex << error << '\n';
        exit(1);
    }
}
