//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_VERTEXBUFFER_H
#define OPENGL_TESTING_VERTEXBUFFER_H


class VertexBuffer {
private:
    unsigned int m_RendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind();
    void Unbind();
};


#endif //OPENGL_TESTING_VERTEXBUFFER_H
