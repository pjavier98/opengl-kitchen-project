#include "texture.h"
#include<GL/gl.h>
#include "../stb_image/stb_image.h"


texture::texture() :
        m_id(0), m_largura(0),
        m_altura(0), m_canais(0) {}


texture::~texture() {
    glDeleteTextures(1, &m_id);
}

void texture::load(std::basic_string<char> file_path) {
    unsigned char* img_data;

    stbi_set_flip_vertically_on_load(true);
    img_data = stbi_load(file_path.c_str(), &m_largura, &m_altura, &m_canais, 4);

    if (img_data) {
        glGenTextures(1, &m_id);
        glBindTexture(GL_TEXTURE_2D, m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_largura, m_altura, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, img_data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(img_data);
    } else {
        std::cout << "it was not possible to load the texture!" << file_path.c_str() << std::endl;
    }
}

void texture::bind() {
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}