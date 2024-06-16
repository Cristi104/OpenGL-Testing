//
// Created by cristi on 16.06.2024.
//

#include <GL/glew.h>
#include "IndexBuffer.h"
#include "GLErrorCheck.h"

IndexBuffer::IndexBuffer(const void *data, unsigned int size) {
    GLErrorCheck::GLClearError();
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    GLErrorCheck::GLCheckError();
}

IndexBuffer::~IndexBuffer() {
    GLErrorCheck::GLClearError();
    glDeleteBuffers(1, &m_RendererID);
    GLErrorCheck::GLCheckError();
}

void IndexBuffer::Bind() {
    GLErrorCheck::GLClearError();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    GLErrorCheck::GLCheckError();
}

void IndexBuffer::Unbind() {
    GLErrorCheck::GLClearError();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    GLErrorCheck::GLCheckError();
}
