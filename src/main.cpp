#include <iostream>
#include "vulkan/vulkan.hpp"
#include "engine/engine.h"

int main(int argc, char** argv) {


    std::cout << "Start" << std::endl;

    engine engine;
    engine.setup(argc, argv);
    engine.start();

    engine.stop();

    std::cout << "Exit" << std::endl;

    return 0;
}