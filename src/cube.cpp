#include "cube.h"
#include "shader.h"
#include "cube_mesh_component.h"

Cube::Cube() {
    shader = new Shader("../shaders/triangle.vert", "../shaders/triangle.frag");
    mesh_component = new CubeMeshComponent();
}


void Cube::render() {
    shader->use();
    mesh_component->draw();
}


void Cube::update() {

}
