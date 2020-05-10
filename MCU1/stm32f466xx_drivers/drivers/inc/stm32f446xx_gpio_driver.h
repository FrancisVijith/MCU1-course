/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: May 9, 2020
 *      Author: Admin
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"
#include <stdint.h>

//this is a configuration structure for a GPIO pin

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFinMode;
}GPIO_PinConfig_t;

//this is a handle for a GPIO pin

typedef struct
{

	GPIO_RegDef_t *pGPIOx; 			//this holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig; //this holds GPIO pin configuration settings
}GPIO_Handle_t;

/*
 * peripheral clock setup
 */
void GPIO_PeriClkCtrl(void);
/*
 * Initialization and De-initialization
 */
void GPIO_Init(void);
void GPIO_DeInit(void);
/*
 * read and write from GPIO
 */
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_ToggleOutputPin(void);
/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);


#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
