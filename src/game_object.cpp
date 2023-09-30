#include "game_object.h"
#include "shader.h"
#include "camera.h"

GameObject::GameObject() {
    color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
}


void GameObject::render() {

    shader->use();

    glm::mat4 view = Camera::get_instance()->view;
    glm::mat4 projection = Camera::get_instance()->projection;

    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
    shader->setVec4("color", color);
}

void GameObject::update() {
    transform_component.update();
}
