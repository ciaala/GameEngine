//
// Created by crypt on 12/04/17.
//

#ifndef GAMEENGINE_PRESENTER_H
#define GAMEENGINE_PRESENTER_H

#include <vulkan/vulkan.hpp>
#include "../render/DriverInfo.h"

class Presenter {
private:
    const DriverInfo &driverInfo;
    void init_window_size();
    void init_connection();
public:
    Presenter(const DriverInfo &driverInfo);
    void start();


};


#endif //GAMEENGINE_PRESENTER_H
