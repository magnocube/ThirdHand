#include "joystick.h"
#include "esp_log.h"
#include "config.h"

#include "LCD.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
Joystick::Joystick(adc1_channel_t adcChannel,int centerValue,int maxSpeed){
    _adcChannel = adcChannel;
    _maxSpeed = maxSpeed;
    centerPosition = centerValue;
    calibratedPosition = centerValue;
    //ESP_LOGI("Joystick","new Joystick created on adcChannel %d with centervalue %d",adcChannel,centerPosition);

}

void Joystick::updatePosition(){
    currentPosition = (adc1_get_raw(_adcChannel)+adc1_get_raw(_adcChannel)+adc1_get_raw(_adcChannel)+adc1_get_raw(_adcChannel))/4;
    calibratedPosition = (int)((currentPosition*2+calibratedPosition*8)/10.0);

    if(currentPosition > centerPosition - 300 && currentPosition < centerPosition + 300){
        flagEdgeMin = false;
        flagEdgeMax = false;
    }
    if(currentPosition>3500){
        if(!flagEdgeMax){
            flagEdgeMax = true;
            //generate event
            handleFunction(maxDir);
        }
    } else if(currentPosition < 500){
        if(!flagEdgeMin){
            flagEdgeMin = true;
            //generate event
            handleFunction(minDir);
        }
    }
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
           double per = (double)map(calibratedPosition,centerPosition+deathZone,4096,0,_maxSpeed);
           //return per;
           return min((1+0.000007*per*per*per),_maxSpeed); //0-500 speed           
       } else{
           return 0;
       }
   }else{
       if(calibratedPosition < centerPosition - DEATHBAND){
           double per = (double)map(calibratedPosition,centerPosition-deathZone,0,0,-_maxSpeed);
           //return per;
           return max((-1 + 0.000007*per*per*per),-_maxSpeed); //0-500 speed  
       } else{
           return 0;
       }
   }
    
}



void Joystick::setEventHandler(std::function<void(inputDirection)> callback, inputDirection minEvent, inputDirection maxEvent){
    handleFunction = callback;
    minDir = minEvent;
    maxDir = maxEvent;
}


