//
// Created by crypt on 09/04/17.
//

#include "engine.h"


engine::engine() {
    this->render = new Render();
    this->script = new njs();
}

void engine::setup(int argc, char **argv) {
    script->say_hello_world(argc, argv);
}

void engine::start() {
    render->driverInfo();
}

void engine::stop() {

}
