#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "gl_header.h"

struct TransformCompoent {

    TransformCompoent();

    void update();

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::mat4 transform;

};

#endif
