#ifndef OPENGL_KITCHEN_PROJECT_KITCHEN_H
#define OPENGL_KITCHEN_PROJECT_KITCHEN_H

#include "primitive.h"
#include "colors.h"

void draw_floor(GLuint id, texture* texture) {
    draw_cube(id, 52, 1, 52, texture);
}

void draw_wall(GLuint id, texture* texture, GLfloat width = 1, GLfloat height = 11, GLfloat depth = 52) {
    draw_cube(id, width, height, depth, texture);
}

void draw_roof(GLuint id, texture* texture) {
    draw_cube(id, 52, 1, 52, texture);
}

void draw_door(GLuint id, texture* texture) {
    draw_cube(id, 10, 11, 1, texture);
}

void draw_window(GLuint id, texture* texture) {
    draw_cube(id, 50, 4, 0.5, texture);
}

void draw_island(GLuint id, texture* texture) {
    draw_cube(id, 10, 0.5, 10, texture);
}

#endif //OPENGL_KITCHEN_PROJECT_KITCHEN_H
