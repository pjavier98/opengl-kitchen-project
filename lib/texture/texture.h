#pragma once
#include<iostream>

#ifndef OPENGL_KITCHEN_PROJECT_TEXTURE_H
#define OPENGL_KITCHEN_PROJECT_TEXTURE_H


class texture {
    private:
        unsigned int m_id;
        int m_largura, m_altura, m_canais;

public:
    texture();
    ~texture();
    void load(std::string file_path);
    void bind();
    void unbind();
};


#endif //OPENGL_KITCHEN_PROJECT_TEXTURE_H
