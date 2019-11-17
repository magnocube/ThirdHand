#pragma once
#include <stdint.h>
#include "config.h"
struct stepperData{
    int32_t currentPosition;
    int8_t lastSpeed;
};

namespace motorContoller{
    
        void initPerhepirals();
        void setSpeed(int xSpeed, int ySpeed, int zSpeed); // store the speed and setup the array for the motors and the directions for the motors
        void driveMotors();     //will iterate over the function pointer array to set the speeds
        void calibrateToHome(); //blocking
  
       
};