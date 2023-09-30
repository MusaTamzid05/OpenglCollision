#ifndef INPUT_OBJECT_H
#define INPUT_OBJECT_H

#include "game_object.h"

struct InputObject: GameObject {
    InputObject(GLFWwindow* window);

    void render();
    void update();

    GLFWwindow* window;
};

#endif
