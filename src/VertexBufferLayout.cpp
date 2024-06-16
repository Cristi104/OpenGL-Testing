//
// Created by cristi on 17.06.2024.
//

#include "VertexBufferLayout.h"

void VertexBufferLayout::pushFloat(unsigned int count){
    m_Elements.push_back({count, GL_FLOAT, GL_FALSE});
    m_Stride += count * VertexBufferElement::getSize(GL_FLOAT);
}

void VertexBufferLayout::pushUInt(unsigned int count){
    m_Elements.push_back({count, GL_UNSIGNED_INT, GL_FALSE});
    m_Stride += count * VertexBufferElement::getSize(GL_UNSIGNED_INT);
}

void VertexBufferLayout::pushUChr(unsigned int count){
    m_Elements.push_back({count, GL_UNSIGNED_BYTE, GL_FALSE});
    m_Stride += count * VertexBufferElement::getSize(GL_UNSIGNED_BYTE);
}

unsigned int VertexBufferLayout::getStride() const {
    return m_Stride;
}

const std::vector<VertexBufferElement> &VertexBufferLayout::getElements() const {
    return m_Elements;
}

VertexBufferLayout::VertexBufferLayout()
        :m_Stride(0){}

unsigned int VertexBufferElement::getSize(unsigned int type) {
    switch (type) {
        case GL_UNSIGNED_INT:
            return sizeof(unsigned int);
        case GL_UNSIGNED_BYTE:
            return sizeof(unsigned char);
        case GL_FLOAT:
            return sizeof(float);
        default:
            return 0;
    }
}
