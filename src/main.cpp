#include <iostream>
#include "vulkan/vulkan.hpp"
#include "engine/render.h"
#include "script/njs.h"

int main(int argc, char** argv) {
    std::cout << "Start" << std::endl;
    render::driverInfo();
    njs::say_hello_world(argc, argv);
    std::cout << "Exit" << std::endl;
    return 0;
}