//
// Created by crypt on 09/04/17.
//

#include "engine.h"
#include "presenter/Presenter.h"


engine::engine() {
    this->render = new Render();
    this->presenter = new Presenter(this->render->getDriverInfo());
    this->script = new njs();
}

void engine::setup(int argc, char **argv) {
    //script->say_hello_world(argc, argv);
}

void engine::start() {
    if ( render->getDriverInfo().hasPresentationQueue() ) {
        render->getDriverInfo().dumpCurrentSelection();
    }
}

void engine::stop() {

}

engine::~engine() {
    if (script != nullptr) {
        delete script;
    }
    if (render != nullptr) {
        delete render;
    }
}
