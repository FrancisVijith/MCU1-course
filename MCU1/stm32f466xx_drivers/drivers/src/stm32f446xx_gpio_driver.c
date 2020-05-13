/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: May 9, 2020
 *      Author: Admin
 */

#include "stm32f446xx_gpio_driver.h"
#include <stdint.h>



/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
				{
				GPIOA_PCLK_EN();
				}
		else if(pGPIOx == GPIOB)
				{
				GPIOB_PCLK_EN();
				}
		else if(pGPIOx == GPIOC)
				{
				GPIOC_PCLK_EN();
				}
		else if(pGPIOx == GPIOD)
				{
				GPIOD_PCLK_EN();
				}
		else if(pGPIOx == GPIOE)
				{
				GPIOE_PCLK_EN();
				}
		else if(pGPIOx == GPIOF)
				{
				GPIOF_PCLK_EN();
				}
		else if(pGPIOx == GPIOG)
				{
				GPIOG_PCLK_EN();
				}
		else if(pGPIOx == GPIOH)
				{
				GPIOH_PCLK_EN();
				}
	}

	else
	{
		//todo
	}



}

/*********************************************************************
 * @fn      		  - GPIO_Initialization
 *
 * @brief             - This function initializes the GPIO port
 *
 * @param[in]         -
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp=0;
	//1. configure the mode of the gpio pin
	if ( pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//the non interrupt mode
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << ( 2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;

	}
	else
	{
		//todo
	}
	temp = 0;
	//2. configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	//3. configure the pupd settings
	temp = 0;
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp =0;
	//4. configure the optype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	//5. configure the alt functnlty
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
		{

		}

}


/*********************************************************************
 * @fn      		  - GPIO_de-initialization
 *
 * @brief             - This function de-initialize the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}


/*********************************************************************
  * @fn      		  - GPIO_ReadFromInputPin
  *
  * @brief             - This function reads input from a pin of GPIOx input port
  *
  * @param[in]         - base address of the GPIOx peripheral
  * @param[in]         - pin number of the GPIOx port
  * @param[in]         -
  *
  * @return            -  uint8_t
  *
  * @Note              -  none

  */

 uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}


 /*********************************************************************
  * @fn      		  - GPIO_GPIO_ReadFromInputPort
  *
  * @brief             -  This function reads input from the GPIOx input port  *
  * @param[in]         - base address of the GPIOx peripheral
  * @param[in]         -
  * @param[in]         -
  *
  * @return            -  uint16_t
  *
  * @Note              -  none

  */

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{

}


/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPin
 *
 * @brief             -  This function writes output to a pin of the GPIOx input port  *
 * @param[in]         - base address of the GPIOx peripheral
 * @param[in]         - pin number
 * @param[in]         - ouput value
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

}



/*********************************************************************
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -  This function write output the to GPIOx port  *
 * @param[in]         - base address of the GPIOx peripheral
 * @param[in]         - output value
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

}
/*********************************************************************
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -  This function toggles the value of a pin  *
 * @param[in]         - base address of the GPIOx peripheral
 * @param[in]         - pin number
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

/*
 * IRQ configuration ISR handling
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

/*
 * ISR handling
 *
 */

void GPIO_IRQHandling(uint8_t PinNumber)
{

}



