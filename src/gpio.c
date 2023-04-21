/**** includes ****/
#include "gpio.h"

/**** definitions ****/

#ifdef _DINAMIC__
struct gpio_s{
    uint8_t port;
    uint8_t pint;
    bool output;
};
#endif

#ifndef GPIO_COUNT
#define GPIO_COUNT 6
#endif

#ifdef _STATIC__
struct gpio_s{
    uint8_t port;
    uint8_t pin;
    bool output;
    bool alocated;
};
#endif

/**** private functions ****/
static gpio_t gpioAlocate(void);

/**** private functions ****/
static gpio_t gpioAlocate(void)
{
    uint8_t i = 0;
    static struct gpio_s instances[GPIO_COUNT] = {0};
    gpio_t result = NULL;

    /* Busco cuál tiene alocated == false y lo devuelvo*/
    for(i=0; i < GPIO_COUNT; i++)
    {
        if(instances[i].alocated == false)
        {
            result = &instances[i];
            result ->alocated = true;
            break;
        }
    }
    return result;
}

/**** public functions ****/
gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output)
{
    #ifdef _DINAMIC__
    gpio_t result = malloc(sizeof(struct gpio_s));
    #endif
    #ifdef _STATIC__
    gpio_t result = gpioAlocate();
    #endif

    if(result != NULL)
    {
        result->port = port;
        result->pin = pin;
        result->output = output;
    }

    /* Acá se debería, también, configurar el funcionamiento del objeto (comunicación, etc) */

    return result;
}

bool gpioGetValue(gpio_t output)
{
    /* Leo valor del objeto*/
}

void gpioSetValue(gpio_t output, bool value)
{
    if(output->output)
    {
        /* Cambio el estado de la salida */

    }
}