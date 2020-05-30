/*
 * 001LEDToggle.c
 *
 *  Created on: May 19, 2020
 *      Author: Admin
 */
#include"stm32f446xx.h"
#include"stm32f446xx_gpio_driver.h"

void delay(int x)
{
	for(int i = 0; i < x ; i++);
}
int main(void)
{
	GPIO_Handle_t GpioLed,GpioBtn;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

	GPIO_PeriClkCtrl(GPIOA,ENABLE);
	GPIO_Init(&GpioLed);
	//gpio button
		GpioBtn.pGPIOx = GPIOC;
		GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
		GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
		GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
		GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

		GPIO_PeriClkCtrl(GPIOC,ENABLE);
		GPIO_Init(&GpioBtn);


	while(1)
	{if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13)==0)
		{delay(500000);
		//GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_5, 1);
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		}
	}

	return 0;

}

