#ifndef COLLIDER_H
#define COLLIDER_H

#include "game_object.h"

struct SphereCollider {

    SphereCollider(GameObject* game_object);

    bool does_intersect(SphereCollider* other) const;

    float radius;
    GameObject* game_object;

};


struct AABBCollider {

    AABBCollider(GameObject* game_object);

    bool does_intersect(AABBCollider* other) const;

    glm::vec3 min;
    glm::vec3 max;


};




#endif

