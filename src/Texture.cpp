//
// Created by cristi on 18.06.2024.
//

#include <GL/glew.h>
#include "Texture.h"
#include "GLErrorCheck.h"
#include "../external/stb_image/stb_image.h"

int Texture::getMWidth() const {
    return m_Width;
}

int Texture::getMBitsPerPixel() const {
    return m_BitsPerPixel;
}

int Texture::getMHeight() const {
    return m_Height;
}

Texture::Texture(const std::string &path)
        :m_RendererID(0), m_Path(path), m_Buffer(nullptr), m_Height(0), m_Width(0), m_BitsPerPixel(0){
    stbi_set_flip_vertically_on_load(1);
    m_Buffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BitsPerPixel, 4);
    GLErrorCheck::GLClearError();
    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Buffer);

    glBindTexture(GL_TEXTURE_2D, 0);
    GLErrorCheck::GLCheckError();

    if(m_Buffer != nullptr)
        stbi_image_free(m_Buffer);
}

void Texture::unbind() {
    GLErrorCheck::GLClearError();
    glBindTexture(GL_TEXTURE_2D, 0);
    GLErrorCheck::GLCheckError();
}

void Texture::bind(unsigned int slot) const {
    GLErrorCheck::GLClearError();
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
    GLErrorCheck::GLCheckError();
}

Texture::~Texture() {
    GLErrorCheck::GLClearError();
    glDeleteTextures(1, &m_RendererID);
    GLErrorCheck::GLCheckError();
}
