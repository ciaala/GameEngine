//
// Created by crypt on 12/04/17.
//

#ifndef GAMEENGINE_DRIVERINFO_H
#define GAMEENGINE_DRIVERINFO_H

#define VK_USE_PLATFORM_XCB_KHR
#include <vulkan/vulkan.hpp>

class DriverInfo {

private:
    vk::PhysicalDevice physicalDevice;
    vk::Instance instance;
    void prepareQueues();
    vk::QueueFamilyProperties *presentationQueue;

public:
    DriverInfo();
    void dump() const;

    void setupInstance();

    const vk::Instance & getInstance() const;

    bool hasPresentationQueue() const;

    void dumpCurrentSelection() const;

    void create_device_queue();

    void prepareSurfaces();

    void prepare_window();
};


#endif //GAMEENGINE_DRIVERINFO_H
