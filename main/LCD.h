#pragma once
#include <stdint.h>
#include <string>
#include "smbus.h"
#include "i2c-lcd1602.h"

enum class inputDirection{
    NOTHING,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    INCREASE,
    DECREASE
};

struct MenuStruct{
    std::string topText;
    std::string bottomText; // leave empty to use variable. if string is provided it will only be text
    int* menuItemValue;     //variable to edit (in case the bottom text is not filled in)
    int menuItemMinValue;   //minimum value of variable
    int menuItemMaxValue;   //maximum value of variable
    int menuItemSteps;      //leave at 0 for variables that shouldn't be updated and only displayed.

    MenuStruct* leftMenuItem;   
    MenuStruct* rightMenuItem;
    MenuStruct* topMenuItem;
    MenuStruct* bottomMenuItem;    
};

class LCDMenu{
    public:
        LCDMenu(); 
        void init(MenuStruct *startNode, int32_t address);// set start node and store address i2c
        void update();                      //update the display wit new data
        void input(inputDirection input); //update the inner menu based on the input form the user
        void setMenuStructure(MenuStruct *m);
    private:
        MenuStruct* _currentNode;
        i2c_lcd1602_info_t * lcd_info;
};