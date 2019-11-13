#include "joystick.h"


Joystick::Joystick(uint8_t inputPin){
    _inputPin = inputPin;


    //setup pin as analog input. and do a test read
}
void Joystick::updatePosition(){
    
}
uint32_t Joystick::getPosition(){
    return 0;
}