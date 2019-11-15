/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"


#include "joystick.h"
#include "joystickcontroller.h"

#include "config.h"

extern "C" { 	
	void app_main(); 
}

void app_main()
{
  
    Joystick *stickX =        new Joystick(STICK_X_ADC_CHANNEL,STICK_X_CENTER_VALUE);
    Joystick *stickY =        new Joystick(STICK_Y_ADC_CHANNEL,STICK_Y_CENTER_VALUE);
    Joystick *stickZ =        new Joystick(STICK_Z_ADC_CHANNEL,STICK_Z_CENTER_VALUE);
    Joystick *stickGrabber =  new Joystick(STICK_GRABBER_ADC_CHANNEL,STICK_GRABBER_CENTER_VALUE);

    Joystickcontroller j;
    j.addJoystick(stickX);
    j.addJoystick(stickY);
    j.addJoystick(stickZ);
    j.addJoystick(stickGrabber);

    while(1){
        j.updateJoysticks();
        printf("X: %d,  Y: %d,  Z: %d,  G: %d\n",stickX->getRelativeSpeed(),stickY->getRelativeSpeed(),stickZ->getRelativeSpeed(),stickGrabber->getRelativeSpeed());
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    

    printf("Restarting now.\n");  
    esp_restart();
}
