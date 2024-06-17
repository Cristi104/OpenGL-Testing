//
// Created by cristi on 16.06.2024.
//

#include <GL/glew.h>
#include "IndexBuffer.h"
#include "GLErrorCheck.h"

IndexBuffer::IndexBuffer(const unsigned short* data, unsigned int count)
        :m_Count(count) {
    GLErrorCheck::GLClearError();
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned short), data, GL_STATIC_DRAW);
    GLErrorCheck::GLCheckError();
}

IndexBuffer::~IndexBuffer() {
    GLErrorCheck::GLClearError();
    glDeleteBuffers(1, &m_RendererID);
    GLErrorCheck::GLCheckError();
}

void IndexBuffer::bind() const {
    GLErrorCheck::GLClearError();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    GLErrorCheck::GLCheckError();
}

void IndexBuffer::unbind() {
    GLErrorCheck::GLClearError();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    GLErrorCheck::GLCheckError();
}

unsigned int IndexBuffer::getCount() const {
    return m_Count;
}
