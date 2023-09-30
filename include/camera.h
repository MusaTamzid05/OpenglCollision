#ifndef CAMERA_H
#define CAMERA_H

#include "gl_header.h"

class Camera {

    public:
        static Camera* get_instance();

        glm::mat4 view;
        glm::mat4 projection;

    private:
        Camera(int width, int height);

        static Camera* instance;

        int width;
        int height;



};


#endif
