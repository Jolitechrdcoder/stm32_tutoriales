/*
 * nema17_jorge.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Jorge Luis Martinez Suarez
 */

#ifndef NEMA17_JORGE_H
#define NEMA17_JORGE_H

#include "stm32f4xx_hal.h"
//#include "stm32f3xx_hal.h" si usted tiene un nucleo de la familai f3 ejemplo f302r8 descomente esta parte y comente los anteriores.
//#include "stm32l4xx_hal.h" si usted tiene un nucleo de la familai l4 ejemplo l446re descomente esta parte y comente los anteriores.
void microDelay(uint16_t delay);
void step(int steps, uint8_t direction, uint16_t delay);

#endif /* NEMA17_JORGE_H */