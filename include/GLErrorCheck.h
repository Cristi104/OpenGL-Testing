//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_GLERRORCHECK_H
#define OPENGL_TESTING_GLERRORCHECK_H


class GLErrorCheck {
public:
    GLErrorCheck() = delete;

    static void GLClearError();
    static void GLCheckError();
};


#endif //OPENGL_TESTING_GLERRORCHECK_H
