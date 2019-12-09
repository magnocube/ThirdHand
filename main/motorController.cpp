#include "motorController.h"

#include <esp_log.h>
#include <driver/gpio.h>
#include "config.h"
#include <stdlib.h>

namespace motorContoller{
    /*function prototypes and (private) variables*/
        void stepX();
        void stepY();
        void stepZ();
        void doNothing();
        void resetStep();//the steps will only set the pin high, this will reset all pins to low
        void (*arr[SPEED_RESOLUTION*4])() = {};
        void (*functptrs[3])() = {stepX,stepY,stepZ};
        stepperData X, Y, Z,N,R;
        int dirX, dirY, dirZ = 0;



    void initPerhepirals(){        
        for(auto &a:arr){
            a = doNothing;
        }
        for(int i =0; i < SPEED_RESOLUTION*4; i++){
            if(i%4 == 0){
                arr[i] = resetStep;
            } else{
                //x y or z
                arr[i] = doNothing;
            }
        }
        gpio_pad_select_gpio(STALL_PIN);
        gpio_pad_select_gpio(PIN_DIR_X);
        gpio_pad_select_gpio(PIN_DIR_Y);
        gpio_pad_select_gpio(PIN_DIR_Z);
        gpio_pad_select_gpio(PIN_STEPPER_X);
        gpio_pad_select_gpio(PIN_STEPPER_Y);
        gpio_pad_select_gpio(PIN_STEPPER_Z);
        gpio_pad_select_gpio(LIMIT_SWITCH_X);
        gpio_pad_select_gpio(LIMIT_SWITCH_Y);
        gpio_pad_select_gpio(LIMIT_SWITCH_Z);

        gpio_set_direction(STALL_PIN,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_DIR_Y,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_DIR_Z,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_DIR_X,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_STEPPER_X,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_STEPPER_Y,GPIO_MODE_OUTPUT);
        gpio_set_direction(PIN_STEPPER_Z,GPIO_MODE_OUTPUT);
        gpio_set_direction(LIMIT_SWITCH_X,GPIO_MODE_INPUT);
        gpio_set_direction(LIMIT_SWITCH_Y,GPIO_MODE_INPUT);
        gpio_set_direction(LIMIT_SWITCH_Z,GPIO_MODE_INPUT);
       
        
    }
    int getX(){
        return X.currentPosition;
    }
    int getY(){
        return Y.currentPosition;
    }
    int getZ(){
        return Z.currentPosition;
    }
    void setSpeed(int xSpeed, int ySpeed, int zSpeed){
        X.currentSpeed = abs(xSpeed);
        Y.currentSpeed = abs(ySpeed);
        Z.currentSpeed = abs(zSpeed);

        if(xSpeed >0){
            dirX = 1;
            gpio_set_level(PIN_DIR_X,1);
        } else{
            dirX = -1;
            gpio_set_level(PIN_DIR_X,0);
        }
        if(ySpeed >0){
            dirY = 1;
            gpio_set_level(PIN_DIR_Y,0);
        } else{
            dirY = -1;
            gpio_set_level(PIN_DIR_Y,1);
        }
        if(zSpeed >0){
            dirZ = 1;
            gpio_set_level(PIN_DIR_Z,0);
        } else{
            dirZ = -1;
            gpio_set_level(PIN_DIR_Z,1);
        }

        //reset the array  ... motors should not be moving, or it can result in either errors or not the right position
        for(int i = 0; i<SPEED_RESOLUTION*4; i+=4){ // reset all
            arr[i+0] = doNothing;
            arr[i+1] = doNothing;
            arr[i+2] = doNothing;
            arr[i+3] = resetStep; 
        }

        
        
       


        //0+4n = x
        //1+4n = y
        //2+4n = z
        //3+4n = reset
        if(X.currentSpeed != 0){
            float xStep = SPEED_RESOLUTION/X.currentSpeed;
            for(int i = 0; i<X.currentSpeed; i++){
                arr[((int)(i*xStep)*4)+0] = stepX;
            }
        }
        if(Y.currentSpeed != 0){
            float yStep = SPEED_RESOLUTION/Y.currentSpeed;
            for(int i = 0; i<Y.currentSpeed; i++){
                arr[((int)(i*yStep)*4)+1] = stepY;
            }
        }
        if(Z.currentSpeed != 0){
            float zStep = SPEED_RESOLUTION/Z.currentSpeed;
            for(int i = 0; i<Z.currentSpeed; i++){
                arr[((int)(i*zStep)*4)+2] = stepZ;
            }
        }


    }
    void driveMotors(){
         for(auto &a:arr){
            a();
        }
        //ESP_LOGI("motorController","data: X: %d,   Y: %d,   Z: %d   n%d   r%d",X.currentPosition,Y.currentPosition,Z.currentPosition,N.currentPosition,R.currentPosition);
    }
    void calibrateToHome(){
        
    }

    void stepX(){
    //ESP_LOGI("M","X");
        X.currentPosition+=dirX;
        gpio_set_level(PIN_STEPPER_X,1);
    }
    void stepY(){
        //ESP_LOGI("M","Y");
        Y.currentPosition+=dirY;
        gpio_set_level(PIN_STEPPER_Y,1);
    }
    void stepZ(){
        //ESP_LOGI("M","Z");
        Z.currentPosition+=dirZ;
        gpio_set_level(PIN_STEPPER_Z,1);
    }
    void doNothing(){
        N.currentPosition++;
        gpio_set_level(STALL_PIN,1);
    }
    void resetStep(){
        R.currentPosition++;
        gpio_set_level(PIN_STEPPER_X,0);
        gpio_set_level(PIN_STEPPER_Y,0);
        gpio_set_level(PIN_STEPPER_Z,0);
        for(int i = 0; i < SLOWIFIER ; i++){
            gpio_set_level(STALL_PIN,0);
        }
        
    }


}

