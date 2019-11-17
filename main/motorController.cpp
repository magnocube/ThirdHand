#include "motorController.h"

#include <esp_log.h>
#include <driver/gpio.h>
#include "config.h"


namespace motorContoller{
    /*function prototypes and (private) variables*/
        void stepX();
        void stepY();
        void stepZ();
        void doNothing();
        void resetStep();//the steps will only set the pin high, this will reset all pins to low
        void (*arr[SPEED_RESOLUTION*4])() = {};
        void (*functptrs[3])() = {stepX,stepY,stepZ};
        stepperData X, Y, Z;



    void initPerhepirals(){        
        for(auto &a:arr){
            a = doNothing;
        }
        for(int i =0; i < SPEED_RESOLUTION*4; i++){
            if(i%4 == 0){
                arr[i] = resetStep;
            } else{
                //x y or z
            }
        }
        gpio_pad_select_gpio(PIN_DIR_X);
        gpio_pad_select_gpio(PIN_DIR_Y);
        gpio_pad_select_gpio(PIN_DIR_Z);
        gpio_pad_select_gpio(PIN_STEPPER_X);
        gpio_pad_select_gpio(PIN_STEPPER_Y);
        gpio_pad_select_gpio(PIN_STEPPER_Z);

        gpio_set_direction(PIN_DIR_Y,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_DIR_Z,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_DIR_X,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_STEPPER_X,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_STEPPER_Y,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_STEPPER_Z,GPIO_MODE_OUTPUT);

       
        
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
        gpio_set_level(PIN_STEPPER_X,1);
    }
    void stepY(){
        //ESP_LOGI("M","Y");
        Y.currentPosition++;
        gpio_set_level(PIN_STEPPER_Y,1);
    }
    void stepZ(){
        //ESP_LOGI("M","Z");
        Z.currentPosition++;
        gpio_set_level(PIN_STEPPER_Z,1);
    }
    void doNothing(){

    }
    void resetStep(){
        gpio_set_level(PIN_STEPPER_X,0);
        gpio_set_level(PIN_STEPPER_Y,0);
        gpio_set_level(PIN_STEPPER_Z,0);
    }


}

