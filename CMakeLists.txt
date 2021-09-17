cmake_minimum_required(VERSION 3.20)
project(opengl_kitchen_project)

set(CMAKE_CXX_STANDARD 23)

add_executable(opengl_kitchen_project main.cpp lib/constants.h lib/colors.h lib/primitive.h lib/object.h lib/camera/Camera.cpp lib/camera/Camera.h lib/vertex.h lib/kitchen.h lib/obj_loader/obj_loader.h lib/obj_loader/obj_loader.cpp lib/stb_image/stb_image.h lib/stb_image/stb_image.cpp lib/texture/texture.cpp lib/texture/texture.h)
target_link_libraries(opengl_kitchen_project -lglut -lglfw -lGLEW -lGL -lGLU)
