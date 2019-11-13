#pragma once
#include <stdint.h>
#include "joystick.h"
#include <vector> 


class Joystickcontroller{ // currently only supports adc1 by design
    public:
        Joystickcontroller();
        void updateJoysticks();
        void addJoystick(Joystick* newJoystick);
    private:
        std::vector<Joystick*> joysticks;

        
};
