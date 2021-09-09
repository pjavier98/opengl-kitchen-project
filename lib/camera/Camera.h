#ifndef OPENGL_KITCHEN_PROJECT_CAMERA_H
#define OPENGL_KITCHEN_PROJECT_CAMERA_H

#include "../vertex.h"

class Camera {
    private:
        vertex3 position;
        vertex3 direction;
        vertex3 left;
        vertex3 up;
        vertex3 velocity;

        // velocity of movement
        float scale = 0.5;
        float yaw;

    public:
        Camera(vertex3 position);
        ~Camera();
        void activate();

        void move_forward();
        void move_back();
        void move_left();
        void move_right();
        void update_yaw(float d_yaw);
        void update_direction_vertex();
    private:
        float degreesToRadians(float angle);
};


#endif //OPENGL_KITCHEN_PROJECT_CAMERA_H
