#include "gpio.h"
#include "main.h"

int main (void)
{
    //gpio_t led_rojo = {.port = 1, .pin =6};
    //gpio_t tecla = {.port = 1, .pin =7};

    gpio_t led_rojo = gpioCreate(1,6,true);
    gpio_t tecla = gpioCreate(1,7,false);

    while (true)
    {
        if(gpioGetValue(tecla))
        gpioSetValue(led_rojo, true);
        else
        gpioSetValue(led_rojo, false);
    }
    
    return 0;
}