#include "transform_component.h"

TransformCompoent::TransformCompoent() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

void TransformCompoent::update() {
    transform = glm::mat4(1.0f);
    glm::quat quat(glm::radians(glm::vec3(rotation.x, rotation.y, rotation.z)));
    transform = glm::translate(transform, position);
    transform *= glm::toMat4(quat);
    transform = glm::scale(transform, scale);

}
