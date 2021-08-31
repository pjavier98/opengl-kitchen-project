#ifndef OPENGL_KITCHEN_PROJECT_KITCHEN_H
#define OPENGL_KITCHEN_PROJECT_KITCHEN_H

#include "primitive.h"
#include "colors.h"

void draw_floor(GLuint id) {
    draw_cube(id, 52, 1, 52, white_ice, dark_grey);
}

void draw_wall(GLuint id, GLfloat width = 1, GLfloat height = 11, GLfloat depth = 52) {
    draw_cube(id, width, height, depth, dark_grey, kitchen_wall);
}

void draw_roof(GLuint id) {
    draw_cube(id, 52, 1, 52, dark_grey, dark_grey);
}

void draw_door(GLuint id) {
    draw_cube(id, 10, 11, 1, brown, blue);
}

void draw_window(GLuint id) {
    draw_cube(id, 50, 4, 0.5, beige, beige);
}

void draw_island(GLuint id) {
    draw_cube(id, 10, 0.5, 10, gray, gray);
}

#endif //OPENGL_KITCHEN_PROJECT_KITCHEN_H
