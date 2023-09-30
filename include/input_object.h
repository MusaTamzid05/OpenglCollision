#ifndef INPUT_OBJECT_H
#define INPUT_OBJECT_H

#include "game_object.h"

struct Cube;

struct InputObject: GameObject {
    InputObject(GLFWwindow* window, Cube* player);

    void render();
    void update();

    GLFWwindow* window;
    Cube* player;

    float speed;
};

#endif
