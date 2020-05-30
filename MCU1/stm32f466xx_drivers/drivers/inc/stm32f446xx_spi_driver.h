/*
 * stm32f446xx_spi_driver.h
 *
 *  Created on: May 29, 2020
 *      Author: Admin
 */

#ifndef INC_STM32F446XX_SPI_DRIVER_H_
#define INC_STM32F446XX_SPI_DRIVER_H_

#include "stm32f446xx.h"
#include <stdint.h>

//this is a configuration structure for a SPIx peripheral

typedef struct
{
	uint8_t SPI_DeviceMode;			//possible values from @GPIO_PIN_NUMBER
	uint8_t SPI_BusConfig;			//possible values from @GPIO_PIN_MODES
	uint8_t SPI_SclkSpeed;			//possible values from @GPIO_PIN_SPEED
	uint8_t SPI_DFF;				//possible values from @GPIO_PIN_PUPD
	uint8_t SPI_CPOL;				//possible values from @GPIO_PIN_OP_TYPE
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

typedef struct
{

	SPI_RegDef_t *pSPIx; 				//this holds the base address of the SPI port to which the pin belongs
	SPI_Config_t SPIConfig;			 	//this holds SPI pin configuration settings
}SPI_Handle_t;

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0
/*
 * @SPI_BusConfif
 */
#define SPI_BUS_CONFIG_FD				1
#define SPI_BUS_CONFIG_HD				2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY	3
/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2					0
#define SPI_SCLK_SPEED_DIV4					1
#define SPI_SCLK_SPEED_DIV8					2
#define SPI_SCLK_SPEED_DIV16				3
#define SPI_SCLK_SPEED_DIV32				4
#define SPI_SCLK_SPEED_DIV64				5
#define SPI_SCLK_SPEED_DIV128				6
#define SPI_SCLK_SPEED_DIV256				7
/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS					0
#define SPI_DFF_16BITS					1
/*
 * @SPI_CPOL
 */
#define SPI_CPOL_LOW 					0
#define SPI_CPOL_HIGH					1
/*
 * @SPI_CPHA
 */
#define SPI_CPHA_LOW					0
#define SPI_CPHA_HIGH					1
/*
 * @SPI_SSM
 */
#define SPI_SSM_EN						1
#define SPI_SSM_DI						0

#define SPI_TXE_FLAG					(1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG					(1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG					(1 << SPI_SR_BUSY)
/*APIs supported by this driver*/

/*
 * peripheral clock setup
 */
void SPI_PeriClkCtrl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi);
/*
 * Initialization and De-initialization
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data transmit and receive
 * blocking type - non-interrupt based
 * non-blocking type - interrupt based
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxbuffer, uint32_t Len);
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pRxbuffer, uint32_t Len);

/*
 * IRQ configuration and ISR handling
 */
void SPI_IRQITConfig(uint8_t IRQNumber,  uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

#endif /* INC_STM32F446XX_SPI_DRIVER_H_ */
