#define STICK_X_ADC_CHANNEL             ADC1_CHANNEL_6
#define STICK_Y_ADC_CHANNEL             ADC1_CHANNEL_7
#define STICK_Z_ADC_CHANNEL             ADC1_CHANNEL_0
#define STICK_GRABBER_ADC_CHANNEL       ADC1_CHANNEL_3

#define STICK_X_CENTER_VALUE            1900
#define STICK_Y_CENTER_VALUE            1717
#define STICK_Z_CENTER_VALUE            1850
#define STICK_GRABBER_CENTER_VALUE      0

#define PIN_STEPPER_X                   (gpio_num_t)17
#define PIN_STEPPER_Y                   (gpio_num_t)19 
#define PIN_STEPPER_Z                   (gpio_num_t)25
#define PIN_GRABBER                     (gpio_num_t)nullptr

#define PIN_DIR_X                       (gpio_num_t)16
#define PIN_DIR_Y                       (gpio_num_t)18
#define PIN_DIR_Z                       (gpio_num_t)23

#define LIMIT_SWITCH_X                  (gpio_num_t)2
#define LIMIT_SWITCH_Y                  (gpio_num_t)4
#define LIMIT_SWITCH_Z                  (gpio_num_t)5

#define SPEED_RESOLUTION                255  //resolution at the cost of memory and responsiveness