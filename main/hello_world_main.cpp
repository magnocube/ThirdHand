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

extern "C" { 	
	void app_main();
}

void app_main()
{
  
    Joystick *stickX =        new Joystick(ADC1_CHANNEL_6,1900);
    Joystick *stickY =        new Joystick(ADC1_CHANNEL_7,1717);
    Joystick *stickZ =        new Joystick(ADC1_CHANNEL_0,2000);
    Joystick *stickGrabber =  new Joystick(ADC1_CHANNEL_3,2000);

    Joystickcontroller j;
    j.addJoystick(stickX);
    j.addJoystick(stickY);
    j.addJoystick(stickZ);
    j.addJoystick(stickGrabber);

    while(1){
        j.updateJoysticks();
        printf("X: %d,  Y: %d\n",stickX->getRelativeSpeed(),stickY->getRelativeSpeed());
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    

    printf("Restarting now.\n");  
    esp_restart();
}
