//
// Created by cristi on 16.06.2024.
//

#include "VertexArray.h"
#include "GLErrorCheck.h"

VertexArray::VertexArray() {
    GLErrorCheck::GLClearError();
    glGenVertexArrays(1, &m_RendererID);
    GLErrorCheck::GLCheckError();
}

VertexArray::~VertexArray() {
    GLErrorCheck::GLClearError();
    glDeleteVertexArrays(1, &m_RendererID);
    GLErrorCheck::GLCheckError();
}

void VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) {
    bind();
    buffer.bind();
    const auto& elements = layout.getElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++){
        const auto& element = elements[i];
        GLErrorCheck::GLClearError();
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
                              layout.getStride(), (const void*)offset);
        GLErrorCheck::GLCheckError();
        offset += element.count * VertexBufferElement::getSize(element.type);
    }
}

void VertexArray::bind() const {
    GLErrorCheck::GLClearError();
    glBindVertexArray(m_RendererID);
    GLErrorCheck::GLCheckError();
}

void VertexArray::unbind() {
    GLErrorCheck::GLClearError();
    glBindVertexArray(0);
    GLErrorCheck::GLCheckError();
}
