#include "collider.h"


SphereCollider::SphereCollider(GameObject* game_object):
    game_object(game_object) {
        radius = 1.0f;

}

bool SphereCollider::does_intersect(SphereCollider * other) const {
    float radius = radius + other->radius;
    glm::vec3 distance_vec = other->game_object->transform_component.position - game_object->transform_component.position;
    float distance = glm::length(distance_vec);

    if(distance < radius)
        return true;

    return false;
}
