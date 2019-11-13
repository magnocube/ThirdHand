#pragma once
#include <stdint.h>



class Joystick{
    public:
        struct AxleResults{ // simple struct for returning all the new axle values
            int32_t x,y,z,grabber=0;
        };

    
        Joystick(int axleX,int axleY, int axleZ, int axleGrabber);
        void UpdateAxles();
        AxleResults& getResults();

    private:
        uint8_t pinAxleX, pinAxleY, pinAxleZ, pinAxleGrabber = 0;
        AxleResults localAxleResult;
};
