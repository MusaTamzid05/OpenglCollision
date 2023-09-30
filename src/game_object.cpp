#include "game_object.h"
#include "shader.h"
#include "camera.h"


void GameObject::render() {

    shader->use();

    glm::mat4 view = Camera::get_instance()->view;
    glm::mat4 projection = Camera::get_instance()->projection;

    shader->setMat4("projection", projection);
    shader->setMat4("view", view);
}

void GameObject::update() {
    transform_component.update();
}