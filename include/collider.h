#ifndef COLLIDER_H
#define COLLIDER_H

#include "game_object.h"

struct SphereCollider {

    SphereCollider(GameObject* game_object);

    bool does_intersect(SphereCollider* other) const;

    float radius;
    GameObject* game_object;

};

#endif

