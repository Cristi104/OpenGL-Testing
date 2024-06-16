//
// Created by cristi on 16.06.2024.
//

#ifndef OPENGL_TESTING_INDEXBUFFER_H
#define OPENGL_TESTING_INDEXBUFFER_H


class IndexBuffer {
private:
    unsigned int m_RendererID;
public:
    IndexBuffer(const void* data, unsigned int size);
    ~IndexBuffer();

    void Bind();
    void Unbind();
};



#endif //OPENGL_TESTING_INDEXBUFFER_H
