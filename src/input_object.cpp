#include "input_object.h"


InputObject::InputObject(GLFWwindow* window):window(window) {

}


void InputObject::render() {

}


void InputObject::update() {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

}
