#ifndef CUBE_H
#define CUBE_H

#include "game_object.h"

struct CubeMeshComponent;


struct Cube : GameObject {
    Cube();

    void render();
    void update();

    CubeMeshComponent* mesh_component;
};


#endif
