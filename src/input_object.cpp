#include "input_object.h"
#include "cube.h"
#include <iostream>



InputObject::InputObject(GLFWwindow* window, Cube* player):window(window), player(player) {
    speed = 0.05f;

}


void InputObject::render() {

}


void InputObject::update() {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);


        if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            glm::vec3 position = player->transform_component.position;
            position.x += speed;
            player->transform_component.position = position;


        }


        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            glm::vec3 position = player->transform_component.position;
            position.x -= speed;
            player->transform_component.position = position;
        }


        if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            glm::vec3 position = player->transform_component.position;
            position.y -= speed;
            player->transform_component.position = position;
        }


        if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            glm::vec3 position = player->transform_component.position;
            position.y += speed;
            player->transform_component.position = position;
        }

}
