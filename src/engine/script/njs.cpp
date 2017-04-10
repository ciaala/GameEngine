//
// Created by crypt on 04/04/17.
//

#include <iostream>
#include "njs.h"
#include "node.h"

void njs::say_hello_world(int argc, char **argv) {
    std::cout << "Start module" << std::endl << std::flush;
    node::Start(argc, argv);
    std::cout << "Stop module" << std::endl << std::flush;
}
