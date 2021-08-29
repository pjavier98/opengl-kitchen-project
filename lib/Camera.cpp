#include <GL/glu.h>

#include <cmath>
#include "Camera.h"
#include "constants.h"

Camera::Camera(vertex3 initial_position) {
    position = vertex3(initial_position);
    direction = vertex3(0, 0, -1);
    left = vertex3(-1, 0, 0);
    up = vertex3(0, 1, 0);
    velocity = vertex3(0, 0, 0);
}

Camera::~Camera() noexcept = default;

void Camera::activate() {
    vertex3 look = position + direction;

    gluLookAt(position.x, position.y, position.z, look.x, look.y, look.z, up.x, up.y, up.z);
}

void Camera::move_forward() {
    velocity = direction * scale;
    position = position + velocity;
}

void Camera::move_back() {
    velocity = direction * (-scale);
    position = position + velocity;
}

void Camera::move_left() {
    velocity = left * scale;
    position = position + velocity;
}

void Camera::move_right() {
    velocity = left * (-scale);
    position = position + velocity;
}

float Camera::degreesToRadians(float angle) {
    return (angle * PI) / 180.0;
}

void Camera::update_yaw(float d_yaw) {
    yaw += d_yaw;
}

void Camera::update_direction_vertex() {
    float angle = degreesToRadians(yaw);

    direction.x = sin(angle);
    direction.z = -cos(angle);
    direction.normalize();
    left = up.vector_product(direction);
}


