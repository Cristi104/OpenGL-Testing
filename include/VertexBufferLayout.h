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

    /// @return Size in bytes of a given data type.
    static unsigned int getSize(unsigned int type);
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout();

    /// @param count number of floats to be added to the layout.
    void pushFloat(unsigned int count);
    /// @param count number of unsigned ints to be added to the layout.
    void pushUInt(unsigned int count);
    /// @param count number of unsigned chars to be added to the layout.
    void pushUChr(unsigned int count);

    /// @return The amount of bytes between two vertices.
    [[nodiscard]] unsigned int getStride() const;

    /// @return The elements of the layout.
    [[nodiscard]] const std::vector<VertexBufferElement> &getElements() const;
};


#endif //OPENGL_TESTING_VERTEXBUFFERLAYOUT_H
