//
// Created by cristi on 17.06.2024.
//

#include "Renderer.h"
#include "GLErrorCheck.h"

void Renderer::draw(const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Shader &shader) const {
    shader.bind();
    vertexArray.bind();
    indexBuffer.bind();
    GLErrorCheck::GLClearError();
    glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_SHORT, nullptr);
    GLErrorCheck::GLCheckError();
}

void Renderer::clear() const {
    GLErrorCheck::GLClearError();
    glClear(GL_COLOR_BUFFER_BIT);
    GLErrorCheck::GLCheckError();
}
