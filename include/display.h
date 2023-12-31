#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>


struct GLFWwindow;
struct GameObject;
struct Cube;

namespace Engine {



    class Display {

        public:
            Display(const std::string& title = "Window",
                    int width = 640,
                    int height = 480
                    );

            virtual ~Display();
            void run();

            static void framebuffer_size_callback(GLFWwindow* window,
                    int width,
                    int height);


        private:


            Display(const Display&);
            Display &operator=(const Display&);

            bool init(const std::string& title);


            void draw();
            void update();

            int width;
            int height;

            GLFWwindow* m_window;
            std::vector<GameObject*> game_objects;
    };

};

#endif
