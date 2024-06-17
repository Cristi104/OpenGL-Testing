//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_GLERRORCHECK_H
#define OPENGL_TESTING_GLERRORCHECK_H


class GLErrorCheck {
public:
    GLErrorCheck() = delete;

    /// Clears all OpenGL errors.
    static void GLClearError();

    /// Searches for OpenGL errors and prints out all of them before terminating the program.
    static void GLCheckError();
};


#endif //OPENGL_TESTING_GLERRORCHECK_H
