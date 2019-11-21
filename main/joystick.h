#pragma once

#include <stdint.h>
#include <driver/adc.h>

class Joystick{
    public:
        Joystick(adc1_channel_t adcChannel, int centerValue, int maxSpeed);
        void updatePosition();
        uint32_t getValue();
        uint32_t getCalibratedValue();
        uint32_t getRelativeSpeed(); // -1024 to 1024
    private:
        adc1_channel_t _adcChannel;
        int32_t currentPosition;
        int32_t _maxSpeed;
        int32_t centerPosition;
        int32_t calibratedPosition;
        const int deathZone = 20;
};