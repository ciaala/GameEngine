//
// Created by crypt on 12/04/17.
//

#include "DriverInfo.h"

#include <iostream>
#include <sstream>

using namespace vk;
#define appName "GameEngineDemo"
#define engineName "GameEngine"


DriverInfo::DriverInfo() {
    this->setupInstance();
}

void dumpPhysicalDevice(const vk::PhysicalDevice &physicalDevice, const std::string &prefix) {
    const PhysicalDeviceProperties &properties = physicalDevice.getProperties();
    std::cout << prefix << "Device Id:      " << properties.deviceID << std::endl;
    std::cout << prefix << "Device Name:    " << properties.deviceName << "(" << properties.vendorID << ")"
              << std::endl;
    std::cout << prefix << "Device Type:    " << to_string(properties.deviceType) << std::endl;
    std::cout << prefix << "Driver Version: " << properties.driverVersion << std::endl;
    std::cout << prefix << "API Version:    " << VK_VERSION_MAJOR(properties.apiVersion)
              << "." << VK_VERSION_MINOR(properties.apiVersion)
              << "." << VK_VERSION_PATCH(properties.apiVersion)
              << std::endl;
}

void dumpQueueFamilyProperty(const QueueFamilyProperties &queueFamilyProperty, const std::string &prefix) {
    const vk::Extent3D &extent3D = queueFamilyProperty.minImageTransferGranularity;
    std::cout << prefix
              << "type: " << to_string(queueFamilyProperty.queueFlags)
              << ", tstamp: " << queueFamilyProperty.timestampValidBits
              << ", minImageGranularity: (" << extent3D.width << ", " << extent3D.height << ", " << extent3D.depth
              << ")" << std::endl;
}

void DriverInfo::dump() const {
    const std::vector<PhysicalDevice> &physicalDevices = instance.enumeratePhysicalDevices();
    std::cout << "Number of" << std::endl;
    std::cout << "Valid GPUs : " << physicalDevices.size() << std::endl;
    for (size_t i = 0; i < physicalDevices.size(); i++) {
        std::ostringstream prefix;
        prefix << "  d:" << i << "  ";
        dumpPhysicalDevice(physicalDevices[i], prefix.str());
        const std::vector<QueueFamilyProperties> &queueFamilyProperties = physicalDevices[0].getQueueFamilyProperties();
        for (auto &&queueFamilyProperty : queueFamilyProperties) {
            prefix.str("");
            prefix << "    q:" << (queueFamilyProperty.queueCount) << " ";
            dumpQueueFamilyProperty(queueFamilyProperty, prefix.str());
        }
    }
}

void DriverInfo::dumpCurrentSelection() const {
    std::cout << "Device & Quese selected" << std::endl;
    dumpPhysicalDevice(this->physicalDevice, "    ");
    dumpQueueFamilyProperty(*this->presentationQueue, "        ");
}

void DriverInfo::prepareQueues() {
    const std::vector<PhysicalDevice> &physicalDevices = instance.enumeratePhysicalDevices();

    for (size_t i = 0; i < physicalDevices.size(); i++) {
        const PhysicalDeviceProperties &properties = physicalDevices[i].getProperties();
        const std::vector<QueueFamilyProperties> &queueFamilyProperties = physicalDevices[i].getQueueFamilyProperties();
        for (auto &&queueFamilyProperty : queueFamilyProperties) {
            if (physicalDevices[i].getSu)
            if (queueFamilyProperty.queueFlags & QueueFlagBits::eGraphics) {
                this->presentationQueue = static_cast<vk::QueueFamilyProperties *>(malloc(
                        sizeof(vk::QueueFamilyProperties)));
                physicalDevice = physicalDevices[i];
                uint32_t queueIndex = queueFamilyProperty.queueCount;
                physicalDevices[i].getQueueFamilyProperties(&queueIndex, presentationQueue);

            }
        }
    }

    this->prepare_present_queue();
    this->create_device_queue();
}

bool DriverInfo::hasPresentationQueue() const {
    return this->presentationQueue != nullptr;
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
    this->prepareSurfaces();
    this->prepareQueues();
}

const Instance &DriverInfo::getInstance() const {
    return instance;
}

void DriverInfo::create_device_queue() {
    float queue_priorities[1] = {0.0};
    vk::DeviceQueueCreateInfo queueCreateInfo;
    queueCreateInfo.queueFamilyIndex = this->presentationQueue->queueCount;
    queueCreateInfo.pQueuePriorities = queue_priorities;
    queueCreateInfo.queueCount = 1;
    vk::DeviceCreateInfo deviceCreateInfo;

    deviceCreateInfo.queueCreateInfoCount = 1;
    deviceCreateInfo.pQueueCreateInfos = &queueCreateInfo;

    deviceCreateInfo.enabledExtensionCount = 0;
    deviceCreateInfo.ppEnabledExtensionNames = nullptr;
    deviceCreateInfo.enabledLayerCount = 0;
    deviceCreateInfo.ppEnabledLayerNames = nullptr;
    deviceCreateInfo.pEnabledFeatures = nullptr;

    vk::Device device;
            ResultValueType<Device>::type  result = physicalDevice.createDevice(deviceCreateInfo);
    device = result;


}

void DriverInfo::prepareSurfaces() {
    this->prepare_window();

    auto const createInfo = vk::XcbSurfaceCreateInfoKHR().setConnection(connection).setWindow(xcb_window);
    auto result = instance.createXcbSurfaceKHR(&createInfo, nullptr, &(this->surface);
    assert(result == vk::Result::eSuccess);
}

void DriverInfo::prepare_window() {

}
