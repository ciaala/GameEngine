//
// Created by crypt on 02/04/17.
//

#ifndef TTT_RENDER_H
#define TTT_RENDER_H


#include "DriverInfo.h"

class Render {
    DriverInfo driverInfo;
public:
    Render();

    const DriverInfo& getDriverInfo();

    const vk::Instance & getInstance();
};


#endif //TTT_RENDER_H
