//
// Created by crypt on 09/04/17.
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include "render/Render.h"
#include "script/njs.h"
#include "presenter/Presenter.h"

class engine {
private:
    Presenter *presenter;
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
