#include "joystick.h"
#include "esp_log.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

Joystick::Joystick(adc1_channel_t adcChannel,int centerValue){
    _adcChannel = adcChannel;

    centerPosition = centerValue;
    calibratedPosition = centerValue;
    ESP_LOGI("Joystick","new Joystick created on adcChannel %d with centervalue %d",adcChannel,centerPosition);

}

void Joystick::updatePosition(){
    currentPosition = adc1_get_raw(_adcChannel);
    calibratedPosition = (int)((currentPosition*2+calibratedPosition*8)/10.0);
    
    if(_adcChannel == ADC1_CHANNEL_6) //only 1 for debugging
        ESP_LOGI("Y","channel %d,value: %d",_adcChannel,calibratedPosition);
}

uint32_t Joystick::getValue(){
    return currentPosition;
}

uint32_t Joystick::getCalibratedValue(){
    return calibratedPosition;
}
uint32_t Joystick::getRelativeSpeed(){
    /*a speed that will go from -1024 to 1024 based on the position of the joystick*/
    
    int i = centerPosition - calibratedPosition;
    if(i < 0){
        return map(i, 0,4095-centerPosition,0,1024);
    }else{
        return map(i, -4095+centerPosition,0,-1014,0);
    }
    
}