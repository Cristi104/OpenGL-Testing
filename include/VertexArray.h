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

    /// Binds the VertexArray to the OpenGL context.
    /// Any other currently bound VertexArrays will be unbound.
    void bind() const;

    /// Unbinds any currently bound VertexArrays.
    static void unbind();

    /// Adds a VertexBuffer with a specific layout.
    /// @param buffer VertexBuffer to be added.
    /// @param layout The layout of the buffer.
    void addBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout);
};


#endif //OPENGL_TESTING_VERTEXARRAY_H
