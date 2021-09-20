#ifndef OPENGL_KITCHEN_PROJECT_PRIMITIVE_H
#define OPENGL_KITCHEN_PROJECT_PRIMITIVE_H

#include <vector>
#include <cmath>
#include "constants.h"
#include "vertex.h"
#include "colors.h"
#include "texture/texture.h"

using namespace std;

void make_rectangle_face(vertex3 vertex_1, vertex3 vertex_2, vertex3 vertex_3, vertex3 vertex_4) {
    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);  glVertex3fv(&vertex_1.x);
        glTexCoord2f(1.0, 0.0);  glVertex3fv(&vertex_2.x);
        glTexCoord2f(1.0, 1.0);  glVertex3fv(&vertex_3.x);
        glTexCoord2f(0.0, 1.0);  glVertex3fv(&vertex_4.x);
    glEnd();
}

void draw_cube(GLuint id, float width, float height, float depth, texture* texture) {
    vertex3 v1(-width, height, depth);
    vertex3 v2(-width, -height, depth);
    vertex3 v3(width, -height, depth);
    vertex3 v4(width, height, depth);

    vertex3 v5(width, height, -depth);
    vertex3 v6(width, -height, -depth);
    vertex3 v7(-width, -height, -depth);
    vertex3 v8(-width, height, -depth);

    glNewList(id, GL_COMPILE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    texture->bind();
        // front face
        glNormal3f(0.f, 0.f, 1.f);
        make_rectangle_face(v1, v2, v3, v4);

        // right face
        glNormal3f(1.f, 0.f, 1.f);
        make_rectangle_face(v4, v3 ,v6, v5);

        // back face
        glNormal3f(0.f, 0.f, -1.f);
        make_rectangle_face(v5, v8, v7, v6);

        // left face
        glNormal3f(-1.f, 0.f, 0.f);
        make_rectangle_face(v1, v8, v7, v2);

        // top face
        glNormal3f(0.f, 0.f, 0.f);
        make_rectangle_face(v1, v4, v5, v8);

        // bottom face
        glNormal3f(0.f, -1.f, 0.f);
        make_rectangle_face(v2, v7, v6, v3);
    texture->unbind();
    glEndList();
}

#endif // OPENGL_KITCHEN_PROJECT_PRIMITIVE_H
