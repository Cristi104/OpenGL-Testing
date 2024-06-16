//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_GLERRORCHECK_H
#define OPENGL_TESTING_GLERRORCHECK_H


class GLErrorCheck {
public:
    static void GLClearError();
    static void GLCheckError();
    GLErrorCheck() = delete;
};


#endif //OPENGL_TESTING_GLERRORCHECK_H
