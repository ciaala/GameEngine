//
// Created by crypt on 12/04/17.
//

#include "DriverInfo.h"

#include <vulkan/vulkan.hpp>
#include <iostream>

using namespace vk;
#define appName "GameEngineDemo"
#define engineName "GameEngine"

DriverInfo::DriverInfo() {

    this->setupInstance();
    this->enumerate_device();
}

void DriverInfo::dump() {
    const std::vector<PhysicalDevice> &physicalDevices = instance.enumeratePhysicalDevices();
    std::cout << "Number of" << std::endl;
    std::cout << "-- Valid GPUs : " << physicalDevices.size() << std::endl;
    for(auto i = 0; i < physicalDevices.size(); i++) {
        //const std::vector<LayerProperties> &properties = physicalDevices[i].enumerateDeviceLayerProperties();
        physicalDevices[0].
        std::cout << "-" << i << "- Device Name: " << properties<< std::endl;
        std::cout << "-" << i << "- Device Type: " << info.physicalDeviceProperties.deviceType << std::endl;
    }
}

void DriverInfo::setupInstance() {

    vk::ApplicationInfo applicationInfo(
            appName, 1,
            engineName, 1,
            VK_MAKE_VERSION(1, 0, 42));

    vk::InstanceCreateInfo instanceCreateInfo(
            {}, &applicationInfo,
            0, nullptr,
            0, nullptr);


    vk::Result res = vk::createInstance(&instanceCreateInfo, nullptr, &instance);
    assert(res == vk::Result::eSuccess);
}

