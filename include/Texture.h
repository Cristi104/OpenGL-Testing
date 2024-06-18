//
// Created by cristi on 18.06.2024.
//

#ifndef OPENGL_TESTING_TEXTURE_H
#define OPENGL_TESTING_TEXTURE_H


#include <string>

class Texture {
private:
    unsigned int m_RendererID;
    std::string m_Path;
    unsigned char* m_Buffer;
    int m_Width, m_Height, m_BitsPerPixel;

public:
    /// Loads a texture.
    /// @param path Path to the texture file (.png).
    explicit Texture(const std::string& path);

    ~Texture();

    /// Binds the Texture to the OpenGL context.
    /// @param slot the slot of the texture (max value 32 platform dependent)
    void bind(unsigned int slot = 0) const;

    /// Unbinds any currently bound Textures.
    static void unbind();

    [[nodiscard]] int getMWidth() const;

    [[nodiscard]] int getMBitsPerPixel() const;

    [[nodiscard]] int getMHeight() const;
};


#endif //OPENGL_TESTING_TEXTURE_H
