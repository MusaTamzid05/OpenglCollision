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

AABBCollider::AABBCollider(GameObject* game_object) {
    glm::vec3 position = game_object->transform_component.position;
    glm::vec3 scale = game_object->transform_component.scale;

    min = position - glm::vec3(0.5f, 0.5f, 0.5f);
    max = position + glm::vec3(0.5f, 0.5f, 0.5f);

}


bool AABBCollider::does_intersect(AABBCollider* other) const {
    for(int i = 0; i < 3; i += 1) {

        if(min[i] > other->max[i])
            return false;

        if(max[i] < other->min[i])
            return false;


    }

    return true;

}
