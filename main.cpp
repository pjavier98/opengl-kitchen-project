#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include "lib/object.h"
#include "lib/Camera.h"
#include "lib/kitchen.h"
#include "lib/obj_loader.h"

using namespace std;

static float angle = 0.0;
static float last_mouse_position = 0.0;
static bool first_mouse_movement = true;

static bool is_door_open = false;
static float door_x_position = -40.0;

static bool is_window_open = false;
static float window_y_position = 11.0;

static float debug_x = 0;
static float debug_y = 0;
static float debug_z = 0;
static float debug_scale = 3;

static float debug_value = 1.0;

vector<Object> objects;
vector<Object> blender_objects;
Camera camera(vertex3(0, 10, 0));

static unsigned blend_id;


void make_resize(int frame_buffer_width, int frame_buffer_height) {
    glViewport(0, 0, frame_buffer_width, frame_buffer_height);

    // Value of the deformation reason when make a resize
    float aspect = float(frame_buffer_width) / float(frame_buffer_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 500.0);

    glMatrixMode(GL_MODELVIEW);
}

// Model View Matriz
// Translation (third) * Rotation (second) * Scale (first) * Vertex (draw)
void make_draw(float dt) {
    float angular_velocity = dt * DEGREES_PER_SECOND;

    glLoadIdentity();
    camera.activate();

    // internal floor
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glCallList(objects[0].id);
    glPopMatrix();

    // 1 wall
    glPushMatrix();
        glTranslatef(51, 12, 0.0);
        glCallList(objects[1].id);
    glPopMatrix();

    // 2 wall
    glPushMatrix();
        glTranslatef(-51, 12, 0.0);
        glCallList(objects[2].id);
    glPopMatrix();

    // 3 wall + space to the door
    glPushMatrix();
        glTranslatef(10, 12, -51);
        glCallList(objects[3].id);
    glPopMatrix();

    // 4 wall + window
    glPushMatrix();
        glTranslatef(0, 4, 51);
        glCallList(objects[4].id);
    glPopMatrix();

    // 4 wall + window
    glPushMatrix();
        glTranslatef(0, 19, 51);
        glCallList(objects[5].id);
    glPopMatrix();

    // door
    glPushMatrix();
        glTranslatef(door_x_position, 12, -49);
        glCallList(objects[6].id);
    glPopMatrix();

    // window
    glPushMatrix();
        glTranslatef(0.0, window_y_position, 50);
        glCallList(objects[7].id);
    glPopMatrix();

    // roof
    glPushMatrix();
        glTranslatef(0.0, 24.0, 0.0);
        glCallList(objects[8].id);
    glPopMatrix();

    // island
    glPushMatrix();
        glTranslatef(4.0, 4.0, -15.0);
        glCallList(objects[9].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(4.0, 6.0, -14.0);
        glCallList(objects[10].id);
    glPopMatrix();

    // kitchen countertop
    glPushMatrix();
        glTranslatef(14.0, 4.0, -47.0);
        glCallList(objects[11].id);
    glPopMatrix();

    // stove
    glPushMatrix();
        glTranslatef(27.0, 4.0, -47.0);
        glCallList(objects[12].id);
    glPopMatrix();

    // kitchen countertop
    glPushMatrix();
        glTranslatef(41.0, 4.0, -47.0);
        glCallList(objects[13].id);
    glPopMatrix();

    // forniture
    glPushMatrix();
        glTranslatef(28, 18, -47);
        glCallList(objects[14].id);
    glPopMatrix();

    // carpet
    glPushMatrix();
        glTranslatef(-40, 1, -42);
        glCallList(objects[15].id);
    glPopMatrix();

    // picture
    glPushMatrix();
        glTranslatef(-49.9, 12, 30);
        glRotatef(90, 0.0, -1, 0.0);
        glCallList(objects[16].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-49.9, 12, 10);
        glRotatef(90, 0.0, -1, 0.0);
        glCallList(objects[17].id);
    glPopMatrix();

    // refrigerator
    glPushMatrix();
        glTranslatef(0.0, 0.0, -47);
        glRotatef(90, 0.0, -1, 0.0);
        glScalef(3, 3, 3);
        glCallList(blender_objects[0].id);
    glPopMatrix();

    // island chairs
    glPushMatrix();
        glTranslatef(0.0, 0.0, -4.0);
        glRotatef(180, 0.0, -1, 0.0);
        glScalef(11.0, 11.0, 11.0);
        glCallList(blender_objects[1].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(8.0, 0.0, -4.0);
        glRotatef(180, 0.0, -1, 0.0);
        glScalef(11.0, 11.0, 11.0);
        glCallList(blender_objects[2].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(15, 0.0, -10);
        glRotatef(90, 0.0, -1, 0.0);
        glScalef(11.0, 11.0, 11.0);
        glCallList(blender_objects[3].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(15, 0.0, -18);
        glRotatef(90, 0.0, -1, 0.0);
        glScalef(11.0, 11.0, 11.0);
        glCallList(blender_objects[4].id);
    glPopMatrix();

    // table
    glPushMatrix();
        glTranslatef(35, 5, 35);
        glScalef(0.01, 0.01, 0.01);
        glCallList(blender_objects[5].id);
    glPopMatrix();

    // chairs table
    glPushMatrix();
        glTranslatef(35, 0.0, 30);
        glScalef(7, 7, 7);
        glCallList(blender_objects[6].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(35, 0.0, 40);
        glRotatef(180, 0.0, -1, 0.0);
        glScalef(7, 7, 7);
        glCallList(blender_objects[7].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(30, 0.0, 35);
        glRotatef(270, 0.0, -1, 0.0);
        glScalef(7, 7, 7);
        glCallList(blender_objects[8].id);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(40, 0.0, 35);
        glRotatef(90, 0.0, -1, 0.0);
        glScalef(7, 7, 7);
        glCallList(blender_objects[9].id);
    glPopMatrix();

//    glPushMatrix();
//        glTranslatef(debug_x, debug_y, debug_z);
//        glScalef(debug_scale, debug_scale, debug_scale);
//        glCallList(blend_id);
//    glPopMatrix();

    if (is_door_open && door_x_position < -20) {
        door_x_position += 0.1;
    } else if (!is_door_open && door_x_position > -40) {
        door_x_position -= 0.1;
    }

    // translate door
    glPushMatrix();
        glTranslatef(door_x_position, 10, -49);
        glCallList(objects[6].id);
    glPopMatrix();

    if (is_window_open && window_y_position < 19) {
        window_y_position += 0.05;
    } else if (!is_window_open && window_y_position > 11) {
        window_y_position -= 0.05;
    }

    // translate window
    glPushMatrix();
        glTranslatef(0.0, window_y_position, 50);
        glCallList(objects[7].id);
    glPopMatrix();

    angle += angular_velocity;

    if (angle >= 360.0) angle = 0.0;
}

void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    bool movement_action = action == GLFW_PRESS || action == GLFW_REPEAT;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    } else if (key == GLFW_KEY_W && movement_action) {
        camera.move_forward();
    } else if (key == GLFW_KEY_S && movement_action) {
        camera.move_back();
    } else if (key == GLFW_KEY_A && movement_action) {
        camera.move_left();
    } else if (key == GLFW_KEY_D && movement_action) {
        camera.move_right();
    } else if (key == GLFW_KEY_X) {
        debug_x += debug_value;
    } else if (key == GLFW_KEY_Y) {
        debug_y += debug_value;
    } else if (key == GLFW_KEY_Z) {
        debug_z += debug_value;
    } else if (key == GLFW_KEY_N) {
        debug_value = -1.0;
    } else if (key == GLFW_KEY_M) {
        debug_value = 1.0;
    } else if (key == GLFW_KEY_1) {
        is_door_open = true;
    } else if (key == GLFW_KEY_2) {
        is_door_open = false;
    } else if (key == GLFW_KEY_3) {
        is_window_open = true;
    } else if (key == GLFW_KEY_4) {
        is_window_open = false;
    } else if (key == GLFW_KEY_E) {
        debug_scale += debug_value;
    }

    if (key == GLFW_KEY_X || key == GLFW_KEY_Y || key == GLFW_KEY_Z) {
        cout << "x: " << debug_x << ", y: " << debug_y << ", z: " << debug_z << endl;
    }

    if (key == GLFW_KEY_E) {
        cout << "debug_scale: " << debug_scale << endl;
    }
}

void cursor_callback(GLFWwindow* window, double x_pos, double y_pos) {
    float dx;

    if (first_mouse_movement) {
        dx = 0;
        last_mouse_position = x_pos;
        first_mouse_movement = false;
    }

    dx = x_pos - last_mouse_position;
    last_mouse_position = x_pos;
    camera.update_yaw(dx);
    camera.update_direction_vertex();
}

void init(GLFWwindow* window) {
    glfwSetCursorPosCallback(window, cursor_callback);
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetKeyCallback(window, keyboard_callback);

    // Set background color
    glClearColor(0.0, 0.0, 0.0, 0.1);
    glEnable(GL_DEPTH_TEST);

    for (int i = 0; i < TOTAL_AMOUNT_OBJECTS; i++) {
        Object new_obj;
        objects.push_back(new_obj);
    }

    for (int i = 0; i < TOTAL_AMOUNT_BLEND_OBJECTS; i++) {
        Object new_obj;
        blender_objects.push_back(new_obj);
    }

    objects[0].id = glGenLists(TOTAL_AMOUNT_OBJECTS);
    blender_objects[0].id = glGenLists(TOTAL_AMOUNT_BLEND_OBJECTS);

    for (int i = 1; i < TOTAL_AMOUNT_OBJECTS; i++) {
        objects[i].id = objects[0].id + i;
    }

    for (int i = 1; i < TOTAL_AMOUNT_OBJECTS; i++) {
        blender_objects[i].id = blender_objects[0].id + i;
    }

    // draw internal floor
    draw_floor(objects[0].id);

    // draw walls
    draw_wall(objects[1].id);
    draw_wall(objects[2].id);

    // wall + space to door
    draw_wall(objects[3].id, 40, 11, 1);

    // wall + window
    draw_wall(objects[4].id, 50, 3, 1);
    draw_wall(objects[5].id, 50, 4, 1);

    // door
    draw_door(objects[6].id);

    // window
    draw_window(objects[7].id);

    // roof
    draw_roof(objects[8].id);

    // island
    draw_cube(objects[9].id, 8, 2, 8, blue, blue);
    draw_island(objects[10].id);

    // kitchen countertop
    draw_cube(objects[11].id, 8, 3, 4, gray, gray);

    // stove
    draw_cube(objects[12].id, 4, 3, 4, red, red);

    // kitchen countertop
    draw_cube(objects[13].id, 9, 3, 4, gray, gray);

    // forniture
    draw_cube(objects[14].id, 22, 3, 4, gray, gray);

    // carpet
    draw_cube(objects[15].id, 10, 0.1, 5, red, red);

    // picture
    draw_cube(objects[16].id, 5, 5, 0.1, light_blue, light_blue);
    draw_cube(objects[17].id, 5, 5, 0.1, gray, gray);


    // refrigerator
    ObjLoader::load_object(blender_objects[0].id, "../objects/refrigerator/source/refrigerator.obj");

    // island_chair
    ObjLoader::load_object(blender_objects[1].id, "../objects/island_chair/island_chair.obj");
    ObjLoader::load_object(blender_objects[2].id, "../objects/island_chair/island_chair.obj");
    ObjLoader::load_object(blender_objects[3].id, "../objects/island_chair/island_chair.obj");
    ObjLoader::load_object(blender_objects[4].id, "../objects/island_chair/island_chair.obj");

    // table
    ObjLoader::load_object(blender_objects[5].id, "../objects/table/source/table.obj");

    // chairs table
    ObjLoader::load_object(blender_objects[6].id, "../objects/chair/source/chair.obj");
    ObjLoader::load_object(blender_objects[7].id, "../objects/chair/source/chair.obj");
    ObjLoader::load_object(blender_objects[8].id, "../objects/chair/source/chair.obj");
    ObjLoader::load_object(blender_objects[9].id, "../objects/chair/source/chair.obj");
}

int main() {
    GLFWwindow* window;

    if (!glfwInit()) return -1;

    window = glfwCreateWindow(WIDTH, HEIGHT, "Desenhando Esfera", NULL, NULL);

    if (!window){
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    init(window);

    float last_time = 0.0;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {

        float current_time = (float) glfwGetTime();
        float dt = current_time - last_time;
        last_time = current_time;

        // Poll for and process events
        glfwPollEvents();

        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        int frame_buffer_width, frame_buffer_height;

        glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);

        make_resize(frame_buffer_width, frame_buffer_height);

        make_draw(dt);

        // Swap front and back buffers
        glfwSwapBuffers(window);
    }


    glfwTerminate();
    return 0;
}