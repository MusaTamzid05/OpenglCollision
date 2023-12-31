#include "cube.h"
#include "shader.h"
#include "cube_mesh_component.h"
#include "camera.h"

Cube::Cube() {
    shader = new Shader("../shaders/cube.vert", "../shaders/cube.frag");
    mesh_component = new CubeMeshComponent();
    color = glm::vec4(1.0f, 0.5f, 0.2f, 1.0f);
}


void Cube::render() {
    GameObject::render();
    shader->use();
    shader->setMat4("transform", transform_component.transform);


    mesh_component->draw();
}


void Cube::update() {
    GameObject::update();
}
