#pragma once

#include <stdint.h>
#include <driver/adc.h>

class Joystick{
    public:
        Joystick(adc1_channel_t adcChannel);
        void updatePosition();
        uint32_t getPosition();
    private:
        adc1_channel_t _adcChannel;
        
};