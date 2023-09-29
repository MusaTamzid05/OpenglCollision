#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class Shader;




struct GameObject {

    GameObject() {}
    virtual ~GameObject() {}

    virtual void render() = 0;
    virtual void update() = 0;

    Shader* shader;


};



#endif
