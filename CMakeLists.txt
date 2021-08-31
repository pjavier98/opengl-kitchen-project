cmake_minimum_required(VERSION 3.20)
project(opengl_kitchen_project)

set(CMAKE_CXX_STANDARD 23)

add_executable(opengl_kitchen_project main.cpp lib/constants.h lib/colors.h lib/primitive.h lib/object.h lib/Camera.cpp lib/Camera.h lib/vertex.h lib/kitchen.h lib/obj_loader.h lib/obj_loader.cpp)
target_link_libraries(opengl_kitchen_project -lglut -lglfw -lGLEW -lGL -lGLU)
