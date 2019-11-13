#include "joystickcontroller.h"
Joystickcontroller::Joystickcontroller(){

}
void Joystickcontroller::updateJoysticks(){
    for(auto joystick : joysticks){
        joystick->updatePosition();
    }
}
void Joystickcontroller::addJoystick(Joystick* newJoystick){
    joysticks.push_back(newJoystick);
}
