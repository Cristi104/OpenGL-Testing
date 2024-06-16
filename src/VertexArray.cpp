//
// Created by cristi on 16.06.2024.
//

#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_RendererID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void VertexArray::addBuffer(const VertexBuffer &buffer, const VertexBufferLayout &layout) {
    bind();
    buffer.bind();
    const auto& elements = layout.getElements();
    unsigned int offset = 0;
    for(unsigned int i = 0; i < elements.size(); i++){
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
                              layout.getStride(), (const void*)offset);
        offset += element.count * VertexBufferElement::getSize(element.type);
    }
}

void VertexArray::bind() const {
    glBindVertexArray(m_RendererID);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}
