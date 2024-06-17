//
// Created by cristi on 17.06.2024.
//

#ifndef OPENGL_TESTING_VERTEXBUFFERLAYOUT_H
#define OPENGL_TESTING_VERTEXBUFFERLAYOUT_H


#include <vector>
#include <GL/glew.h>

struct VertexBufferElement {
    unsigned int count;
    unsigned int type;
    unsigned char normalized;

    static unsigned int getSize(unsigned int type);
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout();

    void pushFloat(unsigned int count);
    void pushUInt(unsigned int count);
    void pushUChr(unsigned int count);

    [[nodiscard]] unsigned int getStride() const;
    [[nodiscard]] const std::vector<VertexBufferElement> &getElements() const;
};


#endif //OPENGL_TESTING_VERTEXBUFFERLAYOUT_H
