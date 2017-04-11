//
// Created by crypt on 12/04/17.
//

#ifndef GAMEENGINE_DRIVERINFO_H
#define GAMEENGINE_DRIVERINFO_H


#include <vulkan/vulkan.hpp>

class DriverInfo {
private:
    vk::Instance instance;
public:
    DriverInfo();
    void dump();

    void setupInstance();

    void enumerate_device();
};


#endif //GAMEENGINE_DRIVERINFO_H
