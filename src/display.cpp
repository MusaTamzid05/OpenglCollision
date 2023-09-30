#include "display.h"
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>
#include "shape.h"

#include "game_object.h"
#include "cube.h"
#include "input_object.h"
#include "collider.h"

namespace Engine {


    Display::Display(const std::string& title,
            int width,
            int height):width(width), height(height) {

        if(!init(title)) {
            std::cerr << "Could not intialize display.\n";
            return;
        }

        //game_objects.push_back(new Cube());
        Cube* cube1 = new Cube();
        cube1->transform_component.position = glm::vec3(-1.0f, 0.0f, 0.0f);

        Cube* cube2= new Cube();
        cube2->transform_component.position = glm::vec3(1.0f, 0.0f, 0.0f);
        game_objects.push_back(cube1);
        game_objects.push_back(cube2);

        game_objects.push_back(new InputObject(m_window, cube1));

        std::cout << "Display initialize.\n";
        

    }

    Display::~Display() {


        glfwTerminate();
    }

    bool Display::init(const std::string& title) {

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width,
                height,
                title.c_str(),
                nullptr,
                nullptr
                );

        if(m_window == nullptr) {
            std::cerr << "could not initialize glfw.\n";
            return false;
        }

        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "could not initialize glad.\n";
            return false;
        }

        return true;
    }

    void Display::draw() {

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for(GameObject* game_object : game_objects)
            game_object->render();


    }

    void Display::update() {
        for(GameObject* game_object : game_objects)
            game_object->update();

        AABBCollider* collider1 = game_objects[0]->collider;
        AABBCollider* collider2 = game_objects[1]->collider;

        if(collider1->does_intersect(collider2))
            game_objects[0]->color = glm::vec4(1.0f, 0.0f, 0.0f, 0.0f);
        else
            game_objects[0]->color = glm::vec4(1.0f, 0.5f, 0.2f, 1.0f);





    }



    void Display::run() {


        if(m_window == nullptr) {
            std::cerr << "could not run.\n";
            return;
        }

        while(!glfwWindowShouldClose(m_window)) {
            //handle_input();
            draw();
            update();

            glfwSwapBuffers(m_window);
            glfwPollEvents();

            
        }
    }


    void Display::framebuffer_size_callback(GLFWwindow* window,
            int width,
            int height) {
        glViewport(0, 0, width, height);
    }


}
