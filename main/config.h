#define STICK_Y_ADC_CHANNEL             ADC1_CHANNEL_6
#define STICK_X_ADC_CHANNEL             ADC1_CHANNEL_7
#define STICK_Z_ADC_CHANNEL             ADC1_CHANNEL_0
#define STICK_GRABBER_ADC_CHANNEL       ADC1_CHANNEL_3

#define STICK_Y_CENTER_VALUE            1900
#define STICK_X_CENTER_VALUE            1780
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

#define STALL_PIN                       (gpio_num_t)0

#define SPEED_RESOLUTION                4096  //resolution at the cost of memory and responsiveness
#define MAX_X_SPEED                     512  //WARNING. these speeds are only a indication... there will be some heavy (quadratic) mathematics that determine the real speed
#define MAX_Y_SPEED                     1024
#define MAX_Z_SPEED                     512
#define DEATHBAND                       50
#define SLOWIFIER                       75

#define PIN_LED_LIGHT                   (gpio_num_t)14