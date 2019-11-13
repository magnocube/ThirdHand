#pragma once
#include <stdint.h>
#include "joystick.h"
#include <vector> 


class Joystickcontroller{
    public:
        Joystickcontroller();
        void updateJoysticks();
        void addJoystick(Joystick* newJoystick);
    private:
        std::vector<Joystick*> joysticks;

        
};
