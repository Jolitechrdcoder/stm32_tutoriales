/*
 * nema17_jorge.c
 *
 * Created on: Sep 17, 2023
 * Author: Jorge Luis Martinez Suarez
 */
#include "nema17_jorge.h"
#include "stm32f4xx_hal.h"
//#include "stm32f3xx_hal.h" si usted tiene un nucleo de la familai f3 ejemplo f302r8 descomente esta parte y comente los anteriores.
//#include "stm32l4xx_hal.h" si usted tiene un nucleo de la familai l4 ejemplo l446re descomente esta parte y comente los anteriores.
extern TIM_HandleTypeDef htim1; // Declarar la variable htim1 que se utiliza en microDelay
#define DIR_PIN GPIO_PIN_8
#define DIR_PORT GPIOA
#define STEP_PIN GPIO_PIN_9
#define STEP_PORT GPIOA
void microDelay(uint16_t delay)
{
  __HAL_TIM_SET_COUNTER(&htim1, 0);
  while (__HAL_TIM_GET_COUNTER(&htim1) < delay);
}

void step(int steps, uint8_t direction, uint16_t delay)
{
  int x;
  if (direction == 0)
    HAL_GPIO_WritePin(DIR_PORT, DIR_PIN, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(DIR_PORT, DIR_PIN, GPIO_PIN_RESET);
  for (x = 0; x < steps; x = x + 1)
  {
    HAL_GPIO_WritePin(STEP_PORT, STEP_PIN, GPIO_PIN_SET);
    microDelay(delay);
    HAL_GPIO_WritePin(STEP_PORT, STEP_PIN, GPIO_PIN_RESET);
    microDelay(delay);
  }
}

