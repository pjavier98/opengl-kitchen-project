#ifndef OPENGL_KITCHEN_PROJECT_OBJECT_H
#define OPENGL_KITCHEN_PROJECT_OBJECT_H

#include <GL/glu.h>
#include "primitive.h"

struct Object {
    GLuint id;
    vertex3 position;
    Object(): id(0), position(vertex3(0.0, 0.0, 0.0)) {}
};

#endif //OPENGL_KITCHEN_PROJECT_OBJECT_H
