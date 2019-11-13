#pragma once

#include <stdint.h>
class Joystick{
    public:
        Joystick(uint8_t inputPin);
        void updatePosition();
        uint32_t getPosition();
    private:
        uint8_t _inputPin = -1;
};