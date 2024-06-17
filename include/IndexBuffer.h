//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_INDEXBUFFER_H
#define OPENGL_TESTING_INDEXBUFFER_H


class IndexBuffer {
private:
    unsigned int m_RendererID;
    unsigned int m_Count;

public:
    /// Constructs an IndexBuffer.
    /// @param data An array of unsigned short indices.
    /// @param count Number of elements in the array.
    IndexBuffer(const unsigned short* data, unsigned int count);

    ~IndexBuffer();

    /// Binds the IndexBuffer to the OpenGL context for.
    /// Any other currently bound IndexBuffers will be unbound.
    void bind() const;

    /// Unbinds any currently bound IndexBuffers.
    static void unbind();

    /// @return Number of indices stored in the IndexBuffer.
    [[nodiscard]] unsigned int getCount() const;
};


#endif //OPENGL_TESTING_INDEXBUFFER_H
