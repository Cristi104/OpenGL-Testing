//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_VERTEXARRAY_H
#define OPENGL_TESTING_VERTEXARRAY_H


#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
private:
    unsigned int m_RendererID;
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
    void bind() const;
    static void unbind();
};


#endif //OPENGL_TESTING_VERTEXARRAY_H
