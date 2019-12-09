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
#include "motorController.h"

#include "config.h"


#include "esp_log.h"
#define TAG "I2C:"

#include "LCD.h"
#include <driver/i2c.h>

extern "C" { 	
	void app_main(); 
}




static void i2c_master_init(void)
{
    i2c_port_t i2c_master_port = (i2c_port_t)0;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = (gpio_num_t)21;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE; 
    conf.scl_io_num = (gpio_num_t)22;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;  
    conf.master.clk_speed = 400000;
    i2c_param_config(i2c_master_port, &conf);
    i2c_driver_install(i2c_master_port, conf.mode,
                       64,
                       64, 0);
}


void i2cDinges(){
        // Set up I2C
    
    // ESP_LOGI(TAG, "display A at 0,0");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 0, 0);
    // i2c_lcd1602_write_char(lcd_info, 'A');

    // ESP_LOGI(TAG, "display B at 8,0");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 8, 0);
    // i2c_lcd1602_write_char(lcd_info, 'B');

    // ESP_LOGI(TAG, "display C at 15,1");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 15, 1);
    // i2c_lcd1602_write_char(lcd_info, 'C');

    // ESP_LOGI(TAG, "move to 0,1 and blink");  // cursor should still be on
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 0, 1);
    // i2c_lcd1602_set_blink(lcd_info, true);

    // ESP_LOGI(TAG, "display DE and move cursor back onto D");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_write_char(lcd_info, 'D');
    // i2c_lcd1602_set_right_to_left(lcd_info);
    // i2c_lcd1602_write_char(lcd_info, 'E');
    // i2c_lcd1602_set_left_to_right(lcd_info);

    // ESP_LOGI(TAG, "disable display");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_display(lcd_info, false);

    // ESP_LOGI(TAG, "display F at 7,1");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 7, 1);
    // i2c_lcd1602_write_char(lcd_info, 'F');

    // ESP_LOGI(TAG, "enable display");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_display(lcd_info, true);

    // ESP_LOGI(TAG, "disable blink");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_blink(lcd_info, false);  // cursor should still be on

    // ESP_LOGI(TAG, "disable cursor");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_cursor(lcd_info, false);

    // ESP_LOGI(TAG, "display alphabet at 0,0");  // should overflow to second line at "ABC..."
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_home(lcd_info);
    // i2c_lcd1602_write_string(lcd_info, "abcdefghijklmnopqrstuvwxyz0123456789.,-+ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // ESP_LOGI(TAG, "scroll left 8 places slowly");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // for (int i = 0; i < 8; ++i)
    // {
    //     i2c_lcd1602_scroll_display_left(lcd_info);
    //     vTaskDelay(200 / portTICK_RATE_MS);
    // }

    // ESP_LOGI(TAG, "scroll right 8 places quickly");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // for (int i = 0; i < 8; ++i)
    // {
    //     i2c_lcd1602_scroll_display_right(lcd_info);
    // }

    // ESP_LOGI(TAG, "move to 8,0 and show cursor");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 8, 0);
    // i2c_lcd1602_set_cursor(lcd_info, true);

    // ESP_LOGI(TAG, "move cursor 5 places to the right");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // for (int i = 0; i < 5; ++i)
    // {
    //     i2c_lcd1602_move_cursor_right(lcd_info);
    // }

    // ESP_LOGI(TAG, "move cursor 3 places to the left");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // for (int i = 0; i < 3; ++i)
    // {
    //     i2c_lcd1602_move_cursor_left(lcd_info);
    // }

    // ESP_LOGI(TAG, "enable auto-scroll and display >>>>>");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_auto_scroll(lcd_info, true);
    // for (int i = 0; i < 5; ++i)
    // {
    //     i2c_lcd1602_write_char(lcd_info, '>');
    //     vTaskDelay(200 / portTICK_RATE_MS);
    // }

    // ESP_LOGI(TAG, "change address counter to decrement (right to left) and display <<<<<");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_right_to_left(lcd_info);
    // for (int i = 0; i < 5; ++i)
    // {
    //     i2c_lcd1602_write_char(lcd_info, '<');
    //     vTaskDelay(200 / portTICK_RATE_MS);
    // }

    // ESP_LOGI(TAG, "disable auto-scroll and display +++++");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_auto_scroll(lcd_info, false);
    // for (int i = 0; i < 5; ++i)
    // {
    //     i2c_lcd1602_write_char(lcd_info, '+');
    //     vTaskDelay(200 / portTICK_RATE_MS);
    // }

    // ESP_LOGI(TAG, "set left_to_right and display >>>>>");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_set_left_to_right(lcd_info);
    // for (int i = 0; i < 5; ++i)
    // {
    //     i2c_lcd1602_write_char(lcd_info, '>');
    //     vTaskDelay(200 / portTICK_RATE_MS);
    // }

    // ESP_LOGI(TAG, "clear display and disable cursor");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_clear(lcd_info);
    // i2c_lcd1602_set_cursor(lcd_info, false);

    // ESP_LOGI(TAG, "create custom character and display");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // // https://github.com/agnunez/ESP8266-I2C-LCD1602/blob/master/examples/CustomChars/CustomChars.ino
    // uint8_t bell[8]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
    // uint8_t note[8]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
    // uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
    // uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
    // uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
    // uint8_t check[8] = {0x0, 0x1 ,0x3, 0x16, 0x1c, 0x8, 0x0};
    // uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
    // uint8_t retarrow[8] = { 0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_0, bell);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_1, note);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_2, clock);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_3, heart);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_4, duck);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_5, check);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_6, cross);
    // i2c_lcd1602_define_char(lcd_info, I2C_LCD1602_INDEX_CUSTOM_7, retarrow);

    // // after defining custom characters, DDRAM address must be set by home() or moving the cursor

    // ESP_LOGI(TAG, "display custom characters");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 0, 0);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_0);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_1);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_2);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_3);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_4);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_5);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_6);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_CUSTOM_7);

    // ESP_LOGI(TAG, "display special characters");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_move_cursor(lcd_info, 0, 1);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_ALPHA);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_BETA);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_THETA);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_PI);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_OMEGA);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_SIGMA);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_INFINITY);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_DEGREE);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_ARROW_LEFT);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_ARROW_RIGHT);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_SQUARE);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_DOT);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_DIVIDE);
    // i2c_lcd1602_write_char(lcd_info, I2C_LCD1602_CHARACTER_BLOCK);

    // ESP_LOGI(TAG, "display all characters");
    // vTaskDelay(1000 / portTICK_PERIOD_MS);
    // i2c_lcd1602_clear(lcd_info);
    // i2c_lcd1602_set_cursor(lcd_info, true);
    // uint8_t c = 0;
    // uint8_t col = 0;
    // uint8_t row = 0;
    // while (1)
    // {
    //     i2c_lcd1602_write_char(lcd_info, c);
    //     vTaskDelay(100 / portTICK_RATE_MS);
    //     ESP_LOGI(TAG, "col %d, row %d, char 0x%02x", col, row, c);
    //     ++c;
    //     ++col;
    //     if (col >= I2C_LCD1602_NUM_VISIBLE_COLUMNS)
    //     {
    //         ++row;
    //         if (row >= I2C_LCD1602_NUM_ROWS)
    //         {
    //             row = 0;
    //         }
    //         col = 0;
    //         i2c_lcd1602_move_cursor(lcd_info, col, row);
    //     }
    // }

}







Joystick *stickX =        new Joystick(STICK_X_ADC_CHANNEL,STICK_X_CENTER_VALUE,MAX_X_SPEED);
Joystick *stickY =        new Joystick(STICK_Y_ADC_CHANNEL,STICK_Y_CENTER_VALUE,MAX_Y_SPEED);
Joystick *stickZ =        new Joystick(STICK_Z_ADC_CHANNEL,STICK_Z_CENTER_VALUE,MAX_Z_SPEED);
Joystick *stickGrabber =  new Joystick(STICK_GRABBER_ADC_CHANNEL,STICK_GRABBER_CENTER_VALUE,0);

Joystickcontroller j;



void task1( void * pvParameters ){
    while(1){
      motorContoller::driveMotors();
    }
}
void task2( void * pvParameters ){
    
     while(1){
        // std::string a = "x";
        // a.
   
        j.updateJoysticks();
        //printf("X: %d,  Y: %d,  Z: %d,  G: %d\n",stickX->getRelativeSpeed(),stickY->getRelativeSpeed(),stickZ->getRelativeSpeed(),stickGrabber->getRelativeSpeed());
        motorContoller::setSpeed(stickX->getRelativeSpeed(),stickY->getRelativeSpeed(),stickZ->getRelativeSpeed());
        vTaskDelay(25 / portTICK_PERIOD_MS);
    }

}
void task3( void * pvParameters ){ // handles the display   
    int address = 0x27;
    
    //make the menus
    MenuStruct mainMenu =   {std::string("Top Level Menu"),std::string("bottom Menu"),&address,0,255,1,nullptr,nullptr,nullptr,nullptr};
    MenuStruct speedMenu =  {std::string("select speeds"),std::string("navigate down"),&address,0,255,1,nullptr,nullptr,nullptr,nullptr};
    MenuStruct speedX =     {std::string("speed x"),std::string("value: 34"),&address,0,255,1,nullptr,nullptr,nullptr,nullptr};
    MenuStruct speedY =     {std::string("speed y"),std::string("value: 234"),&address,0,255,1,nullptr,nullptr,nullptr,nullptr};
    MenuStruct speedZ =     {std::string("speed z"),std::string("value: 233"),&address,0,255,1,nullptr,nullptr,nullptr,nullptr};

    //link the menus
    mainMenu.rightMenuItem =  &speedMenu;
    speedMenu.rightMenuItem = &speedX;
    speedX.rightMenuItem =    &speedY;
    speedY.rightMenuItem =    &speedZ;
    speedZ.rightMenuItem =    &mainMenu;

    //instantiate and set the default menu. (and i2c address)
    LCDMenu menu(&mainMenu, address); 
    
    while(1){  
        menu.input(inputDirection::RIGHT);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
  
    // Allocates storage
    // char *firstLine = (char*)malloc(17 * sizeof(char));

    // while(1){
    //     // std::string a = "x";
    //     // a.
    //     i2c_lcd1602_clear(lcd_info);
   
    //     sprintf(firstLine, "X:%d", motorContoller::getX());
    //     i2c_lcd1602_move_cursor(lcd_info, 0, 0);        
    //     i2c_lcd1602_write_string(lcd_info,firstLine);
    //     sprintf(firstLine, "Y:%d", motorContoller::getY());
    //     i2c_lcd1602_move_cursor(lcd_info, 0, 1);        
    //     i2c_lcd1602_write_string(lcd_info,firstLine);
    
    //     vTaskDelay(100 / portTICK_PERIOD_MS);
    // }
    
}





void app_main()
{

    gpio_pad_select_gpio(PIN_LED_LIGHT);
    gpio_set_direction(PIN_LED_LIGHT,GPIO_MODE_OUTPUT);
    gpio_set_level(PIN_LED_LIGHT,1);

    i2c_master_init();

    motorContoller::initPerhepirals();   
    j.addJoystick(stickX);
    j.addJoystick(stickY);
    j.addJoystick(stickZ);
    j.addJoystick(stickGrabber);

    xTaskCreatePinnedToCore(task1, "motorTask", SPEED_RESOLUTION*5, NULL, 100, NULL,1 );
    xTaskCreatePinnedToCore(task2, "stickTask", 2048, NULL, 1, NULL,0 );
    xTaskCreatePinnedToCore(task3, "screenTask", 4096, NULL, 2, NULL,0 );
    

    while(1){
        
        //vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    

    printf("Restarting now.\n");  
    esp_restart();
}
