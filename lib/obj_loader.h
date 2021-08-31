#ifndef OPENGL_KITCHEN_PROJECT_OBJ_LOADER_H
#define OPENGL_KITCHEN_PROJECT_OBJ_LOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "vertex.h"

using namespace std;

enum Polygon { TRIANG = 3, QUAD = 4 };

struct face {
    Polygon type;
    int vertex[4];
    int normal[4];
    face(Polygon type_,
         int v1, int v2, int v3, int v4,
         int n1, int n2, int n3, int n4) {
        vertex[0] = v1; vertex[1] = v2;
        vertex[2] = v3; vertex[3] = v4;
        normal[0] = n1; normal[1] = n2;
        normal[2] = n3; normal[3] = n4;
        type = type_;
    }
};

namespace ObjLoader {
    vertex3 get_vertex(std::string s);
    vertex3 get_normal(std::string s);
    face get_face(Polygon type_, string s);
    void load_object(unsigned& id, const char* file_path);
};


#endif //OPENGL_KITCHEN_PROJECT_OBJ_LOADER_H
