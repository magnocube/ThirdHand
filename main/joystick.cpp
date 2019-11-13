#include "joystick.h"


Joystick::Joystick(adc1_channel_t adcChannel){
    _adcChannel = adcChannel;
    int val = adc1_get_raw(_adcChannel);

    //setup pin as analog input. and do a test read
}
void Joystick::updatePosition(){
    
}
uint32_t Joystick::getPosition(){
    return 0;
}