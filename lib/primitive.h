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
        make_rectangle_face(v1, v2, v3, v4);

        // right face
        make_rectangle_face(v4, v3 ,v6, v5);

        // back face
        make_rectangle_face(v5, v8, v7, v6);

        // left face
        make_rectangle_face(v1, v8, v7, v2);

        // top face
        make_rectangle_face(v1, v4, v5, v8);

        // bottom face
        make_rectangle_face(v2, v7, v6, v3);
    texture->unbind();
    glEndList();
}

void draw_sphere(GLuint id, color color, GLfloat radius, GLuint n_stacks, GLuint n_sectors) {
    vector<vector<GLuint>> indexes;
    vector<vertex3> points;

    GLfloat delta_phi = PI / float(n_stacks);
    GLfloat delta_theta = 2 * PI / n_sectors;

    for (GLuint i = 0; i <= n_stacks; i++) {
        GLfloat phi = -PI / 2.0 + i * delta_phi;
        GLfloat temp = radius * cos(phi);
        GLfloat y = radius * sin(phi);

        vector<GLuint> pointsSize;

        for (GLuint j = 0; j < n_sectors; j++) {
            GLfloat theta = j * delta_theta;
            GLfloat x = temp * sin(theta);
            GLfloat z = temp * cos(theta);

            points.push_back(vertex3(x, y, z));

            GLuint index = points.size() - 1;
            pointsSize.push_back(index);
        }

        indexes.push_back(pointsSize);
    }


    glNewList(id, GL_COMPILE);
        glColor3fv(color);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);

        for (GLuint i = 0; i < n_stacks; i++) {

            glBegin(GL_TRIANGLE_STRIP);

            for (GLuint j = 0; j < n_sectors; j++) {
                GLuint index = indexes[i][j];

                glVertex3fv(&points[index].x);
                index = indexes[i + 1][j];
                glVertex3fv(&points[index].x);

                if (j == n_sectors - 1) {
                    index = indexes[i][0];
                    glVertex3fv(&points[index].x);
                    index = indexes[i + 1][0];
                    glVertex3fv(&points[index].x);
                }
            }

            glEnd();
        }
    glDisable(GL_CULL_FACE);
    glEndList();
}

#endif // OPENGL_KITCHEN_PROJECT_PRIMITIVE_H
