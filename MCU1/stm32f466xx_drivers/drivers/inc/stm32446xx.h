/*
 * stm32446xx.h
 *
 *  Created on: May 7, 2020
 *      Author: Francis
 */

#ifndef INC_STM32446XX_H_
#define INC_STM32446XX_H_

//base addresses of FLASH and SRAM memories
#define FLASH_BASEADDR		0x0800 0000U //base address of the flash memory
#define SRAM1_BASEADDR  	0x2000 0000U //base address of SRAM1 112KB
#define SRAM2_BASEADDR		0x2001 C000U //base address of SRAM2 16 KB
#define ROM					0x1FFF 0000U //base address of the system memory
#define OTP_BASEADDR		0x1FFF 7800U //base address of the OTP area
#define SRAM				SRAM1_BASEADDR

//base addresses of AHBx and APBx bus

#define PERIPH_BASE			0x4000 0000U //base address of bus peripheral
#define APB1PERIPH_BASE		0x4000 0000U //base address of APB1 bus domain
#define	APB2PERIPH_BASE		0x4001 0000U //base address of APB2 bus domain
#define	AHB1PERIPH_BASE		0x4002 0000U //base address of AHB1 bus domain
#define AHB2PERIPH_BASE		0x5000 0000U //base address of AHB2 bus domain

//base address of GPIOs hanging to AHB1 bus

#define GPIOA_BASEADDR		0x4002 0000U
#define GPIOB_BASEADDR		0x4002 0400U
#define GPIOC_BASEADDR		0x4002 0800U
#define GPIOD_BASEADDR		0x4002 0C00U
#define GPIOE_BASEADDR		0x4002 1000U
#define GPIOF_BASEADDR		0x4002 1400U
#define GPIOG_BASEADDR		0x4002 1800U
#define GPIOH_BASEADDR		0x4002 1C00U

//base address of peripherals hanging to APB1 bus

#define I2C1_BASEADDR		0x4000 5400U
#define I2C2_BASEADDR		0x4000 5800U
#define I2C3_BASEADDR		0x4000 5C00U
#define SPI2_BASEADDR		0x4000 3800U
#define SPI3_BASEADDR		0x4000 3C00U
#define USART2_BASEADDR		0x4000 4400U
#define USART3_BASEADDR		0x4000 4800U
#define USART4_BASEADDR		0x4000 4C00U
#define USART5_BASEADDR		0x4000 5000U

//base address of peripheral hanging to APB2 bus

#define SPI1_BASEADDR		0x4001 3000U
#define USART1_BASEADDR		0x4001 1000U
#define USART6_BASEADDR		0x4001 1400U
#define EXT1_BASEDDR		0x4001 3C00U
#define SYSCFG_BASEDADDR	0x4001 3800U
#endif /* INC_STM32446XX_H_ */
