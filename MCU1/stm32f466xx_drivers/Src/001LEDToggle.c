/*
 * 001LEDToggle.c
 *
 *  Created on: May 19, 2020
 *      Author: Admin
 */
#include"stm32f446xx.h"
#include"stm32f446xx_gpio_driver.h"

int delay(int x)
{
	for(int y=0; y <= x; y++);
}
int main(void)
{
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

	GPIO_PeriClkCtrl(GPIOA,ENABLE);
	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay(50000000);
	}
	return 0;

}

