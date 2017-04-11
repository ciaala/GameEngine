//
// Created by crypt on 09/04/17.
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include "render/Render.h"
#include "script/njs.h"

class engine {
private:
    Render *render;
    njs *script;
public:
    engine();
    ~engine();
    void setup(int argc, char **argv);

    void start();

    void stop();
};


#endif //GAMEENGINE_ENGINE_H
