//
// Created by cristi on 17.06.2024.
//

#ifndef OPENGL_TESTING_RENDERER_H
#define OPENGL_TESTING_RENDERER_H


#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Renderer {
public:
    /// Clears the screen for the next frame to be drawn.
    void clear() const;

    /// Draws an element to the screen.
    /// @param shader, indexBuffer, vertexArray The info of the drawn element.
    void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;
};


#endif //OPENGL_TESTING_RENDERER_H
