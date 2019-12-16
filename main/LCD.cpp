#include "LCD.h"



#define TAG "LCD"
#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

LCDMenu::LCDMenu(){
//empty    
}
void LCDMenu::init(MenuStruct *startNode, int32_t address){
    _currentNode = startNode;

     // Set up the SMBus
    smbus_info_t * smbus_info = smbus_malloc();
    smbus_init(smbus_info, (i2c_port_t)0, address);
    smbus_set_timeout(smbus_info, 1000 / portTICK_RATE_MS);

    // Set up the LCD1602 device with backlight off
    lcd_info = i2c_lcd1602_malloc();
    i2c_lcd1602_init(lcd_info, smbus_info, true);


    // turn on backlight
    ESP_LOGI(TAG, "backlight on");
    i2c_lcd1602_set_backlight(lcd_info, true);
    ESP_LOGI(TAG, "cursor off");
   
    i2c_lcd1602_set_cursor(lcd_info, false);
}
void LCDMenu::setMenuStructure(MenuStruct *m){

}
void LCDMenu::update(){ // refresh the screen. (to accompensate for updated variables)
    i2c_lcd1602_move_cursor(lcd_info, 0, 0);
    i2c_lcd1602_write_string(lcd_info,_currentNode->topText.c_str());
    i2c_lcd1602_move_cursor(lcd_info, 0, 1);
    i2c_lcd1602_write_string(lcd_info,_currentNode->bottomText.c_str());
    
}
void LCDMenu::input(inputDirection input){ // navigate through the structure and then update.
    if(input == inputDirection::RIGHT){
        if(_currentNode->rightMenuItem != nullptr){
            i2c_lcd1602_clear(lcd_info);
            _currentNode = _currentNode->rightMenuItem;
        }
    } else if(input == inputDirection::LEFT){
        if(_currentNode->leftMenuItem != nullptr){
            i2c_lcd1602_clear(lcd_info);
            _currentNode = _currentNode->leftMenuItem;
        }
    } else if(input == inputDirection::UP){
        if(_currentNode->topMenuItem != nullptr){
            i2c_lcd1602_clear(lcd_info);
            _currentNode = _currentNode->topMenuItem;
        }
    } else if(input == inputDirection::DOWN){
        if(_currentNode->bottomMenuItem != nullptr){
            i2c_lcd1602_clear(lcd_info);
            _currentNode = _currentNode->bottomMenuItem;
        }
    } 
    update();
}