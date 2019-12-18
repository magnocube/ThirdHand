#pragma once


namespace singleController{
    
        void initPerhepirals();
        void setSpeed(int xSpeed, int ySpeed, int zSpeed); // store the speed and setup the array for the motors and the directions for the motors
        void driveMotors();     //will iterate over the function pointer array to set the speeds
    
};