//
// Created by crypt on 02/04/17.
//

#include "vulkan/vulkan.h"
#include <iostream>
#include "Render.h"
#include <vector>
#include <cassert>

typedef struct {
    VkApplicationInfo appInfo;
    VkInstanceCreateInfo instInfo;
    VkInstance instance;
    std::vector<VkPhysicalDevice> gpus;
    uint32_t queue_family_count;
    std::vector<VkQueueFamilyProperties> queue_props;
    VkDevice device;
    VkPhysicalDeviceProperties physicalDeviceProperties;
} RenderInfo;

void init_global_layer_properties(RenderInfo &info) {
    info.appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    info.appInfo.pNext = nullptr;
    info.appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 3);
    info.appInfo.engineVersion = 0;
    info.appInfo.pApplicationName = "TTT";
    info.appInfo.applicationVersion = 0;
}

void init_instance(RenderInfo &info) {

    info.instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    info.instInfo.pNext = nullptr;
    info.instInfo.flags = 0;
    info.instInfo.pApplicationInfo = &(info.appInfo);
    info.instInfo.enabledExtensionCount = 0;
    info.instInfo.ppEnabledExtensionNames = nullptr;
    info.instInfo.enabledLayerCount = 0;
    info.instInfo.ppEnabledLayerNames = nullptr;

    VkResult res = vkCreateInstance(&(info.instInfo), nullptr, &(info.instance));
    assert(res == VK_SUCCESS);
}

void init_enumerate_device(RenderInfo &info) {
    uint32_t gpu_count;
    VkResult res = vkEnumeratePhysicalDevices(info.instance, &gpu_count, NULL);
    info.gpus.resize(gpu_count);
    res = vkEnumeratePhysicalDevices(info.instance, &gpu_count, info.gpus.data());
    assert(res == VK_SUCCESS);
    vkGetPhysicalDeviceProperties(info.gpus[0], &(info.physicalDeviceProperties));

}

void destroy_instance(RenderInfo &info) {
    vkDestroyDevice(info.device, NULL);
    vkDestroyInstance(info.instance, NULL);
}

void print_info(RenderInfo &info) {
    std::cout << "Number of Valid GPUs: " << info.gpus.size() << std::endl;
    std::cout << "         Device Name: " << info.physicalDeviceProperties.deviceName << std::endl;
    std::cout << "         Device Type: " << info.physicalDeviceProperties.deviceType << std::endl;
}

void dumpDriverInfo() {
    RenderInfo info;
    init_global_layer_properties(info);
    init_instance(info);

    init_enumerate_device(info);

    /* VULKAN_KEY_START */

    VkDeviceQueueCreateInfo queue_info = {};

    vkGetPhysicalDeviceQueueFamilyProperties(info.gpus[0], &info.queue_family_count, NULL);
    assert(info.queue_family_count >= 1);

    info.queue_props.resize(info.queue_family_count);
    vkGetPhysicalDeviceQueueFamilyProperties(info.gpus[0], &info.queue_family_count, info.queue_props.data());

    assert(info.queue_family_count >= 1);

    bool found = false;
    for (unsigned int i = 0; i < info.queue_family_count; i++) {
        if (info.queue_props[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            queue_info.queueFamilyIndex = i;
            found = true;
            break;
        }
    }
    assert(found);
    assert(info.queue_family_count >= 1);

    float queue_priorities[1] = {0.0};
    queue_info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queue_info.pNext = nullptr;
    queue_info.queueCount = 1;
    queue_info.pQueuePriorities = queue_priorities;

    VkDeviceCreateInfo device_info = {};
    device_info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    device_info.pNext = nullptr;
    device_info.queueCreateInfoCount = 1;
    device_info.pQueueCreateInfos = &queue_info;
    device_info.enabledExtensionCount = 0;
    device_info.ppEnabledExtensionNames = nullptr;
    device_info.enabledLayerCount = 0;
    device_info.ppEnabledLayerNames = nullptr;
    device_info.pEnabledFeatures = nullptr;

    VkResult res = vkCreateDevice(info.gpus[0], &device_info, nullptr, &info.device);
    assert(res == VK_SUCCESS);
    print_info(info);



    /* VULKAN_KEY_END */

    destroy_instance(info);

}

void Render::driverInfo() {
    dumpDriverInfo();
}

Render::Render() {

}