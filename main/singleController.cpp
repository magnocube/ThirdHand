#include "singleController.h"
#include <driver/gpio.h>
#include "config.h"
#include <stdlib.h>

namespace singleController{
    class Stepper{
        private:
            int _pos =0;
            int _pins = 0;
            int _pind = 0;
            int _dir = 0;
            int _speed = 0;
            int _maxSpeed = 0;
        public:
        Stepper(int pinStep,int pinDir, int maxSpeed){
            _maxSpeed = maxSpeed;
            _pins = pinStep;
            _pind = pinDir;
        }
        void doStep(){
            if(_speed == 0){
                return;
            }
            for(int i =0;i<(_maxSpeed+1-abs(_speed))*500;i++){
                gpio_set_level((gpio_num_t)_pins,1);
            }
            gpio_set_level((gpio_num_t)_pins,0);
            gpio_set_level((gpio_num_t)_pins,0);
            gpio_set_level((gpio_num_t)_pins,0);
            gpio_set_level((gpio_num_t)_pins,0);
            gpio_set_level((gpio_num_t)_pins,0);
            _pos+=_dir;
            
        }
        int pos(){
            return _pos;
        }
        void setSpeed(int s){
            _speed = s;
            if(_speed > 0){
                gpio_set_level((gpio_num_t)_pind,1);
                _dir = 0;
            } else{
                gpio_set_level((gpio_num_t)_pind,0);
                _dir = 1;
            }
        }
        int getSpeed(){
            return _speed;
        }
    };

    Stepper x(PIN_STEPPER_X,PIN_DIR_X,MAX_X_SPEED);
    Stepper y(PIN_STEPPER_Y,PIN_DIR_Y,MAX_Y_SPEED);
    Stepper z(PIN_STEPPER_Z,PIN_DIR_Z,MAX_Z_SPEED);
    Stepper* currentStepper;



    void initPerhepirals(){        
      
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
       
        currentStepper = &x;
    }

    
    void setSpeed(int xSpeed, int ySpeed, int zSpeed){
        x.setSpeed(xSpeed);
        y.setSpeed(ySpeed);
        z.setSpeed(zSpeed);
        
        if(currentStepper->getSpeed()==0){
            int max =0;
            if(x.getSpeed()>max){max = x.getSpeed(); currentStepper = &x;}
            if(y.getSpeed()>max){max = y.getSpeed(); currentStepper = &y;}
            if(z.getSpeed()>max){max = z.getSpeed(); currentStepper = &z;}
        }

    }
    void driveMotors(){
         currentStepper->doStep();
    }
}