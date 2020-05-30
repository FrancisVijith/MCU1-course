/*
 * stm32446xx.h
 *
 *  Created on: May 7, 2020
 *      Author: Francis
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>
#define __vo volatile

/*ARM Cortex Mu-procsr NVIC ISERx register addresses*/

#define NVIC_ISER0			((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1			((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2			((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3			((__vo uint32_t*)0xE000E10C)

/*#define NVIC_ISER4		((__vo uint32_t*)0xE000E100)
#define NVIC_ISER5			((__vo uint32_t*)0xE000E100)
#define NVIC_ISER6			((__vo uint32_t*)0xE000E100)*/

/*ARM Cortex Mu-procsr NVIC ICERx register addresses*/
#define NVIC_ICER0			((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1			((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2			((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3			((__vo uint32_t*)0xE000E18C)

/*ARM Cortex Mx Procsr Priority Register Address Calculation*/
#define NVIC_PR_BASE_ADDR	((__vo uint32_t*)0xE000E400)

//ARM Cortex MxPrcsr number of priority bits implemented in Priority Register

#define NO_PR_BITS_IMPLEMENTED 		4

//base addresses of FLASH and SRAM memories
#define FLASH_BASEADDR		0x08000000U //base address of the flash memory
#define SRAM1_BASEADDR  	0x20000000U //base address of SRAM1 112KB
#define SRAM2_BASEADDR		0x2001C000U //base address of SRAM2 16 KB
#define ROM					0x1FFF0000U //base address of the system memory
#define OTP_BASEADDR		0x1FFF7800U //base address of the OTP area
#define SRAM				SRAM1_BASEADDR

//base addresses of AHBx and APBx bus

#define PERIPH_BASE			0x40000000U //base address of bus peripheral
#define APB1PERIPH_BASE		0x40000000U //base address of APB1 bus domain
#define	APB2PERIPH_BASE		0x40010000U //base address of APB2 bus domain
#define	AHB1PERIPH_BASE		0x40020000U //base address of AHB1 bus domain
#define AHB2PERIPH_BASE		0x50000000U //base address of AHB2 bus domain

//base address of GPIOs hanging to AHB1 bus

#define RCC_BASEADDR		0x40023800U //base address of RCC

#define GPIOA_BASEADDR		0x40020000U //base address of GPIOA
#define GPIOB_BASEADDR		0x40020400U //base address of GPIOB
#define GPIOC_BASEADDR		0x40020800U //base address of GPIOC
#define GPIOD_BASEADDR		0x40020C00U //base address of GPIOD
#define GPIOE_BASEADDR		0x40021000U //base address of GPIOE
#define GPIOF_BASEADDR		0x40021400U //base address of GPIOF
#define GPIOG_BASEADDR		0x40021800U //base address of GPIOG
#define GPIOH_BASEADDR		0x40021C00U //base address of GPIOH

//base address of peripherals hanging to APB1 bus

#define I2C1_BASEADDR		0x40005400U //base address of I2C1
#define I2C2_BASEADDR		0x40005800U //base address of I2C2
#define I2C3_BASEADDR		0x40005C00U //base address of I2C3
#define SPI2_BASEADDR		0x40003800U //base address of SPI2
#define SPI3_BASEADDR		0x40003C00U //base address of SPI3
#define USART2_BASEADDR		0x40004400U //base address of USART2
#define USART3_BASEADDR		0x40004800U //base address of USART3
#define UART4_BASEADDR		0x40004C00U //base address of USART4
#define UART5_BASEADDR		0x40005000U //base address of USART5

//base address of peripheral hanging to APB2 bus

#define SPI1_BASEADDR		0x40013000U //base address of SPI1
#define SPI4_BASEADDR		0x40013400U //base address of SPI1
#define USART1_BASEADDR		0x40011000U //base address of USART1
#define USART6_BASEADDR		0x40011400U //base address of USAR6
#define EXTI_BASEDDR		0x40013C00U //base address of EXT1
#define SYSCFG_BASEDADDR	0x40013800U //base address of SYSCFG



//*******peripheral register definition structures****************
/*GPIO peripheral register definition*/
typedef struct
{
	__vo uint32_t MODER;        //GPIO port mode register Address offset: 0x00
	__vo uint32_t OTYPER;		//GPIO port output type register (GPIOx_OTYPER) (x = A..H) Address offset: 0x04
	__vo uint32_t OSPEEDR;		//GPIO port output speed register (GPIOx_OSPEEDR) (x = A..H) Address offset: 0x08
	__vo uint32_t PUPDR;		//GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A..H) Address offset: 0x0C
	__vo uint32_t IDR;			//GPIO port input data register (GPIOx_IDR) (x = A..H) Address offset: 0x10
	__vo uint32_t ODR;			//GPIO port output data register (GPIOx_ODR) (x = A..H) Address offset: 0x14
	__vo uint32_t BSRR;			//GPIO port bit set/reset register (GPIOx_BSRR) (x = A..H) Address offset: 0x18
	__vo uint32_t LCKR;			//GPIO port configuration lock register (GPIOx_LCKR) (x = A..H)Address offset: 0x1C
	__vo uint32_t AFR[2];		//GPIO alternate function low register (GPIOx_AFRL) (x = A..H) 	Address offset: 0x20  GPIO alternate function high register (GPIOx_AFRH) (x = A..H) Address offset: 0x24
}GPIO_RegDef_t;

/*SPI peripheral register definition*/
typedef struct
{
	__vo uint32_t CR1;			//SPI control register 1 (SPI_CR1) Address offset: 0x00
	__vo uint32_t CR2;			//SPI control register 2 (SPI_CR2) Address offset: 0x04
	__vo uint32_t SR;			//SPI status register (SPI_SR) Address offset: 0x08
	__vo uint32_t DR;			//SPI data register (SPI_DR) Address offset: 0x0C
	__vo uint32_t CRCPR;		//SPI CRC polynomial register (SPI_CRCPR) (not used in I2S mode) Address offset: 0x10
	__vo uint32_t RXCRCR;		//SPI RX CRC register (SPI_RXCRCR) (not used in I2S mode) Address offset: 0x14
	__vo uint32_t TXCRCR;		//SPI TX CRC register (SPI_TXCRCR) (not used in I2S mode) Address offset: 0x18
	__vo uint32_t I2SCFGR;		//SPI_I2S configuration register (SPI_I2SCFGR) Address offset: 0x1C
	__vo uint32_t I2SPR;  		//SPI_I2S prescaler register (SPI_I2SPR) Address offset: 0x20
}SPI_RegDef_t;

typedef struct
{
	__vo uint32_t CR;			//RCC clock control register (RCC_CR) Address offset: 0x00
	__vo uint32_t PLLCFGR;		//RCC PLL configuration register (RCC_PLLCFGR) Address offset: 0x04
	__vo uint32_t CFGR;			//RCC clock configuration register (RCC_CFGR) Address offset: 0x08
	__vo uint32_t CIR;			//RCC clock interrupt register (RCC_CIR) Address offset: 0x0C
	__vo uint32_t AHB1RSTR;		//RCC AHB1 peripheral reset register (RCC_AHB1RSTR) Address offset: 0x10
	__vo uint32_t AHB2RSTR;		//RCC AHB2 peripheral reset register (RCC_AHB2RSTR) Address offset: 0x14
	__vo uint32_t AHB3RSTR;		//RCC AHB3 peripheral reset register (RCC_AHB3RSTR) Address offset: 0x18
	uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;		//RCC APB1 peripheral reset register (RCC_APB1RSTR) Address offset: 0x20
	__vo uint32_t APB2RSTR;		//RCC APB2 peripheral reset register (RCC_APB2RSTR) Address offset: 0x24
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;		//RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) Address offset: 0x30
	__vo uint32_t AHB2ENR;		//RCC AHB2 peripheral clock enable register (RCC_AHB2ENR) Address offset: 0x34
	__vo uint32_t AHB3ENR;		//RCC AHB3 peripheral clock enable register (RCC_AHB3ENR) Address offset: 0x38 uint32_t RESERVED2;
	__vo uint32_t APB1ENR;		//RCC APB1 peripheral clock enable register (RCC_APB1ENR) Address offset: 0x40
	__vo uint32_t APB2ENR;		//RCC APB2 peripheral clock enable register (RCC_APB2ENR) Address offset: 0x44
	uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;	//RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR) Address offset: 0x50
	__vo uint32_t	AHB2LPENR;	//RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR) Address offset: 0x54
	__vo uint32_t	AHB3LPENR;	//RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR) Address offset: 0x58
	uint32_t RESERVED4;
	__vo uint32_t	APB1LPENR;	//RCC APB1 peripheral clock enable in low power mode register(RCC_APB1LPENR) Address offset: 0x60
	__vo uint32_t	APB2LPENR;	//RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR) Address offset: 0x64
	uint32_t RESERVED5[2];
	__vo uint32_t	BDCR;		//RCC Backup domain control register (RCC_BDCR) Address offset: 0x70
	__vo uint32_t	CSR;		//RCC clock control & status register (RCC_CSR) Address offset: 0x74
	uint32_t RESERVED6[2];
	__vo uint32_t	SSCGR;		//RCC spread spectrum clock generation register (RCC_SSCGR) Address offset: 0x80
	__vo uint32_t	PLLI2SCFGR;	//RCC PLLI2S configuration register (RCC_PLLI2SCFGR) Address offset: 0x84
	__vo uint32_t	PLLSAICFGR;	//RCC PLL configuration register (RCC_PLLSAICFGR) Address offset: 0x88
	__vo uint32_t	DCKCFGR;	//RCC Dedicated Clock Configuration Register (RCC_DCKCFGR) Address offset: 0x8C
	__vo uint32_t	CKGATENR;	//RCC clocks gated enable register (CKGATENR) Address offset: 0x90
	__vo uint32_t	DCKCFGR2;	//RCC dedicated clocks configuration register 2 (DCKCFGR2) Address offset: 0x94

}RCC_RegDef_t;

//peripheral structure definition for EXTI
typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;
//peripheral structure definition for SYSCFG
typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	//EXTICR2;
	//EXTICR3;
	//EXTICR4;
	 uint32_t RESERVED[2];
	__vo uint32_t CMPCR;
	uint32_t RESERVED2[2];
	__vo uint32_t CFGR;
}SYSCFG_RegDef_t;


#define RCC			((RCC_RegDef_t*)RCC_BASEADDR)
#define GPIOA 		((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 		((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 		((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 		((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 		((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 		((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 		((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 		((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define EXTI		((EXTI_RegDef_t*)EXTI_BASEDDR)

#define SYSCFG		((SYSCFG_RegDef_t*)SYSCFG_BASEDADDR)

#define SPI1		((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2		((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3		((SPI_RegDef_t*)SPI3_BASEADDR)
#define SPI4		((SPI_RegDef_t*)SPI4_BASEADDR)
/*clock enable macros for GPIOx peripherals*/

#define GPIOA_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 0 ) )
#define GPIOB_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 1 ) )
#define GPIOC_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 2 ) )
#define GPIOD_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 3 ) )
#define GPIOE_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 4 ) )
#define GPIOF_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 5 ) )
#define GPIOG_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 6 ) )
#define GPIOH_PCLK_EN()		( RCC -> AHB1ENR |= ( 1 << 7 ) )

/*clock enable macros for I2Cx peripherals*/

#define I2C1_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 21 ) )
#define I2C2_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 22 ) )
#define I2C3_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 23 ) )

/*clock enable macros for SP1X peripherals*/
#define SPI1_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 12 ) )
#define SPI2_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 14 ) )
#define SPI3_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 15 ) )
#define SPI4_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 13 ) )
/*clock enable macros for USARTX peripherals*/
#define USART1_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 4 ) )
#define USART2_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 17 ) )
#define USART3_PCLK_EN()		( RCC -> APB1ENR |= ( 1 << 18 ) )
#define UART4_PCLK_EN()			( RCC -> APB1ENR |= ( 1 << 19 ) )
#define UART5_PCLK_EN()			( RCC -> APB1ENR |= ( 1 << 20 ) )
#define USART6_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 5 ) )

/*clock enable macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 14 ) )

/*clock enable macros for EXT1 peripherals*/
//#define SYSCFG_PCLK_EN()		( RCC -> APB2ENR |= ( 1 << 14 ) )

/*clock disable macros for GPIOx peripherals*/

#define GPIOA_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 0 ) )
#define GPIOB_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 1 ) )
#define GPIOC_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 2 ) )
#define GPIOD_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 3 ) )
#define GPIOE_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 4 ) )
#define GPIOF_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 5 ) )
#define GPIOG_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 6 ) )
#define GPIOH_PCLK_DI()		( RCC -> AHB1ENR &= ~( 1 << 7 ) )

/*clock disable macros for I2Cx peripherals*/

#define I2C1_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 21 ) )
#define I2C2_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 22 ) )
#define I2C3_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 23 ) )

/*clock disable macros for SP1X peripherals*/
#define SPI1_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 12 ) )
#define SPI2_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 14 ) )
#define SPI3_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 15 ) )

/*clock disable macros for USARTX peripherals*/
#define USART1_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 4 ) )
#define USART2_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 17 ) )
#define USART3_PCLK_DI()		( RCC -> APB1ENR &= ~( 1 << 18 ) )
#define UART4_PCLK_DI()			( RCC -> APB1ENR &= ~( 1 << 19 ) )
#define UART5_PCLK_DI()			( RCC -> APB1ENR &= ~( 1 << 20 ) )
#define USART6_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 5 ) )

/*clock disable macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_DI()		( RCC -> APB2ENR &= ~( 1 << 14 ) )

/*macros to reset GPIO peripheral*/
#define GPIOA_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 0 )); (RCC -> AHB1RSTR &= ~( 1 << 0 ));}while(0);
#define GPIOB_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 1 )); (RCC -> AHB1RSTR &= ~( 1 << 1 ));}while(0)
#define GPIOC_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 2 )); (RCC -> AHB1RSTR &= ~( 1 << 2 ));}while(0)
#define GPIOD_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 3 )); (RCC -> AHB1RSTR &= ~( 1 << 3 ));}while(0)
#define GPIOE_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 4 )); (RCC -> AHB1RSTR &= ~( 1 << 4 ));}while(0)
#define GPIOF_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 5 )); (RCC -> AHB1RSTR &= ~( 1 << 5 ));}while(0)
#define GPIOG_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 6 )); (RCC -> AHB1RSTR &= ~( 1 << 6 ));}while(0)
#define GPIOH_REG_RESET()		do{(RCC -> AHB1RSTR |= ( 1 << 7 )); (RCC -> AHB1RSTR &= ~( 1 << 7 ));}while(0)

//returns port code for given GPIObase address
#define GPIO_BASEADDR_TO_CODE(x)	(	(x == GPIOA) ? 0 :\
										(x == GPIOB) ? 1 :\
										(x == GPIOC) ? 2 :\
										(x == GPIOD) ? 3 :\
										(x == GPIOE) ? 4 :\
										(x == GPIOF) ? 5 :\
										(x == GPIOG) ? 6 :\
										(x == GPIOH) ? 7 :0		)
/*
		* some generic macros
 */
#define ENABLE 		1
#define DISABLE		0
#define SET			ENABLE
#define RESET		DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET
#define FLAG_RESET		RESET
#define FLAG_SET		SET

/*
 * bit position definition of SPI peripheral
 */
#define SPI_CR1_CPHA			0
#define SPI_CR1_CPOL			1
#define SPI_CR1_MSTR			2
#define SPI_CR1_BR				3
#define SPI_CR1_SPE				6
#define SPI_CR1_LSBFIRST		7
#define SPI_CR1_SSI				8
#define SPI_CR1_SSM				9
#define SPI_CR1_RXONLY			10
#define SPI_CR1_DFF				11
#define SPI_CR1_CRCNEXT			12
#define SPI_CR1_CRCEN			13
#define SPI_CR1_BIDIOE			14
#define SPI_CR1_BIDIMODE		15

#define SPI_CR2_RXDMAEN			0
#define SPI_CR2_TXDMAEN			1
#define SPI_CR2_SSOE			2
#define SPI_CR2_FRF				4
#define SPI_CR2_ERRIE			5
#define SPI_CR2_RXNEIE			6
#define SPI_CR2_TXEIE			7

#define SPI_SR_RXNE				0
#define SPI_SR_TXE				1
#define SPI_SR_CHSIDE			2
#define SPI_SR_UDR				3
#define SPI_SR_CRCERR			4
#define SPI_SR_MODF				5
#define SPI_SR_OVR				6
#define SPI_SR_BSY				7
#define SPI_SR_FRE				8
#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_spi_driver.h"
#endif /* INC_STM32F446XX_H_ */
