#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Shader;

#include "transform_component.h"



struct GameObject {

    GameObject() {}
    virtual ~GameObject() {}

    virtual void render();
    virtual void update();

    Shader* shader;
    TransformCompoent transform_component;


};



#endif
