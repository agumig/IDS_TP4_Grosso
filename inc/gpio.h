#ifndef _GPIO_H__
#define _GPIO_H__

/**** includes ****/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**** definitions ****/
typedef struct gpio_s *gpio_t;

/**** Memory allocation****/
#define _STATIC__       /* Define alocación estática de los objetos en memoria */
//#define _DINAMIC__    /* Define alocación dinámica de los objetos en memoria */

/**** public function prototypes ****/
/*!
*   @brief  Inicializa un objeto gpio
*   @return gpio_t dirección de memoria de la estructura alocada
*/
gpio_t gpioCreate(uint8_t port, uint8_t pin, bool output);
/*!
*   @brief  Obtiene el estado actual de un objeto gpio
*   @return bool estado leído
*/
bool gpioGetValue(gpio_t output);
/*!
*   @brief  Setea el valor de un objeto gpio
*   @return none
*/
void gpioSetValue(gpio_t output, bool value);

#endif