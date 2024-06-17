//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_VERTEXBUFFER_H
#define OPENGL_TESTING_VERTEXBUFFER_H


class VertexBuffer {
private:
    unsigned int m_RendererID;

public:
    /// Constructs an VertexBuffer.
    /// @param data An array of Vertex data.
    /// @param size Size of the array in bytes.
    VertexBuffer(const void* data, unsigned int size);

    ~VertexBuffer();

    /// Binds the VertexBuffer to the OpenGL context for.
    /// Any other currently bound VertexBuffers will be unbound.
    void bind() const;

    /// Unbinds any currently bound VertexBuffers.
    static void unbind();
};


#endif //OPENGL_TESTING_VERTEXBUFFER_H
