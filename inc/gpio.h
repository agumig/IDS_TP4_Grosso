#ifndef _GPIO_H__
#define _GPIO_H__

/**** includes ****/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**** definitions ****/
typedef struct gpio_s *gpio_t;

/**** Memory allocation****/
#define _STATIC__   
//#define _DINAMIC__

/**** public function prototypes ****/
gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output);
bool gpioGetValue(gpio_t output);
void gpioSetValue(gpio_t output, bool value);

#endif