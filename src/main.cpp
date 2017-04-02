#include <iostream>
#include "vulkan/vulkan.hpp"
#include "engine/render.h"
#include "script/js.h"

int main() {
    render::driverInfo();
    js::say_hello_world();
    return 0;
}