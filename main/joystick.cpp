#include "joystick.h"
#include "esp_log.h"
#include "config.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

Joystick::Joystick(adc1_channel_t adcChannel,int centerValue,int maxSpeed){
    _adcChannel = adcChannel;
    _maxSpeed = maxSpeed;
    centerPosition = centerValue;
    calibratedPosition = centerValue;
    ESP_LOGI("Joystick","new Joystick created on adcChannel %d with centervalue %d",adcChannel,centerPosition);

}

void Joystick::updatePosition(){
    currentPosition = adc1_get_raw(_adcChannel);
    calibratedPosition = (int)((currentPosition*2+calibratedPosition*8)/10.0);
}

uint32_t Joystick::getValue(){
    return currentPosition;
}

uint32_t Joystick::getCalibratedValue(){
    return calibratedPosition;
}
uint32_t Joystick::getRelativeSpeed(){
    /*a speed that will go from -1024 to 1024 based on the position of the joystick*/
   if(calibratedPosition > centerPosition){
       if(calibratedPosition > centerPosition + DEATHBAND){
           return map(calibratedPosition,centerPosition+deathZone,4096,0,_maxSpeed);
       } else{
           return 0;
       }
   }else{
       if(calibratedPosition < centerPosition - DEATHBAND){
           return map(calibratedPosition,centerPosition-deathZone,0,0,-_maxSpeed);
       } else{
           return 0;
       }
   }
    
}


