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
    IndexBuffer(const unsigned short* data, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    static void unbind();

    [[nodiscard]] unsigned int getMCount() const;
};


#endif //OPENGL_TESTING_INDEXBUFFER_H
