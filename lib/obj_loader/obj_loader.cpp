#include<vector>
#include <iostream>
#include <GL/glu.h>
#include "obj_loader.h"

using namespace std;

vertex3 ObjLoader::get_vertex(string s)
{
    float x, y, z;
    sscanf(s.c_str(), "v %f %f %f", &x, &y, &z);
    vertex3 result(x, y, z);

    return result;
}

vertex3 ObjLoader::get_normal(string s)
{
    float x, y, z;
    sscanf(s.c_str(), "vn %f %f %f", &x, &y, &z);
    vertex3 result(x, y, z);

    return result;
}

face ObjLoader::get_face(Polygon type_, string s)
{
    int v1, v2, v3, v4, vt, n1, n2, n3, n4;

    if (type_ == Polygon::TRIANG) {
        v4 = -1; n4 = -1;
        sscanf(s.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",
                 &v1, &vt, &n1,
                 &v2, &vt, &n2,
                 &v3, &vt, &n3);
    }
    else if (type_ == Polygon::QUAD) {
        sscanf(s.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
                 &v1, &vt, &n1,
                 &v2, &vt, &n2,
                 &v3, &vt, &n3,
                 &v4, &vt, &n4);
    }

    face result(type_, v1, v2, v3, v4, n1, n2, n3, n4);
    return result;
}



void ObjLoader::load_object(unsigned & id, const char * file_path) {
    vector<vertex3> vertices;
    vector<vertex3> normals;
    vector<face> faces;

    fstream file(file_path);
    string line = "";

    if (!file.is_open()) {
        cout << "File not found " << file_path << endl;
    }

    while (getline(file, line)) {
        if (line.find("v ") != string::npos) {
            vertex3 tempVertice = ObjLoader::get_vertex(line);
            vertices.push_back(tempVertice);
        } else if (line.find("vn ") != string::npos) {
            vertex3 tempNormal = ObjLoader::get_normal(line);
            normals.push_back(tempNormal);
        } else if (line.find("f ") != string::npos) {
            short nSpace = 0;
            for (char c: line)
                if (c == ' ') nSpace++;
            Polygon tipo_ = (Polygon) nSpace;
            face tempFace = get_face(tipo_, line);
            faces.push_back(tempFace);
        }
    }

    cout << "Total Vertex: " << vertices.size() << "\n";
    cout << "Total Normals: " << normals.size() << "\n";
    cout << "Total Faces: " << faces.size() << "\n";

    id = glGenLists(1);


    glNewList(id, GL_COMPILE);
    glPolygonMode(GL_FRONT, GL_FILL);
    for (int i = 0; i < faces.size(); i++) {
        int v1 = faces[i].vertex[0] - 1;
        int v2 = faces[i].vertex[1] - 1;
        int v3 = faces[i].vertex[2] - 1;
        int v4 = faces[i].vertex[3] - 1;
        int n1 = faces[i].normal[0] - 1;
        int n2 = faces[i].normal[1] - 1;
        int n3 = faces[i].normal[2] - 1;
        int n4 = faces[i].normal[3] - 1;

        if (faces[i].type == Polygon::TRIANG) {
            glBegin(GL_TRIANGLES);
            glNormal3fv(&normals[n1].x);
            glVertex3fv(&vertices[v1].x);
            glNormal3fv(&normals[n2].x);
            glVertex3fv(&vertices[v2].x);
            glNormal3fv(&normals[n3].x);
            glVertex3fv(&vertices[v3].x);
            glEnd();
        } else if (faces[i].type == Polygon::QUAD) {
            glBegin(GL_QUADS);
                glNormal3fv(&normals[n1].x);
                glVertex3fv(&vertices[v1].x);
                glNormal3fv(&normals[n2].x);
                glVertex3fv(&vertices[v2].x);
                glNormal3fv(&normals[n3].x);
                glVertex3fv(&vertices[v3].x);
                glNormal3fv(&normals[n4].x);
                glVertex3fv(&vertices[v4].x);
            glEnd();
        }

    }

    glEndList();
}
