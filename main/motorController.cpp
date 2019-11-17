#include "motorController.h"

#include <esp_log.h>


namespace motorContoller{
    /*function prototypes and (private) variables*/
        void stepX();
        void stepY();
        void stepZ();
        void doNothing();
        void resetStep();//the steps will only set the pin high, this will reset all pins to low
        void (*arr[SPEED_RESOLUTION*3])() = {};
        void (*functptrs[3])() = {stepX,stepY,stepZ};
        stepperData X, Y, Z;



    void initPerhepirals(){        
        for(auto &a:arr){
            a = doNothing;
        }
        gpio


       
        
    }
    void setSpeed(int xSpeed, int ySpeed, int zSpeed){
        
    }
    void driveMotors(){
         for(auto &a:arr){
            a();
        }
        ESP_LOGI("motorController","data: X: %d,   Y: %d,   Z: %d",X.currentPosition,Y.currentPosition,Z.currentPosition);
    }
    void calibrateToHome(){
        
    }

    void stepX(){
    //ESP_LOGI("M","X");
        X.currentPosition++;
    }
    void stepY(){
        //ESP_LOGI("M","Y");
        Y.currentPosition++;
    }
    void stepZ(){
        //ESP_LOGI("M","Z");
        Z.currentPosition++;
    }
    void doNothing(){

    }
    void resetStep(){
        
    }


}

