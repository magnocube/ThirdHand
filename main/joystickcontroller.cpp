#include "joystickcontroller.h"
Joystickcontroller::Joystickcontroller(){
    adc1_config_width(ADC_WIDTH_BIT_12);
}
void Joystickcontroller::updateJoysticks(){
    for(auto joystick : joysticks){
        joystick->updatePosition();
    }
}
void Joystickcontroller::addJoystick(Joystick* newJoystick){
    joysticks.push_back(newJoystick);
}
