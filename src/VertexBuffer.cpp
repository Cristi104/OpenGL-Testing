//
// Created by cristi on 16.06.2024.
//

#include <GL/glew.h>
#include "VertexBuffer.h"
#include "GLErrorCheck.h"

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    GLErrorCheck::GLClearError();
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    GLErrorCheck::GLCheckError();
}

VertexBuffer::~VertexBuffer() {
    GLErrorCheck::GLClearError();
    glDeleteBuffers(1, &m_RendererID);
    GLErrorCheck::GLCheckError();
}

void VertexBuffer::Bind() {
    GLErrorCheck::GLClearError();
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    GLErrorCheck::GLCheckError();
}

void VertexBuffer::Unbind() {
    GLErrorCheck::GLClearError();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLErrorCheck::GLCheckError();
}
