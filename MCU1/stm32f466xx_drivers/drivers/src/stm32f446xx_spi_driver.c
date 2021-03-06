/*
 * stm32f446xx__spi_driver.c
 *
 *  Created on: May 29, 2020
 *      Author: Admin
 */
#include "stm32f446xx_spi_driver.h"
#include <stdint.h>
/*********************************************************************
 * @fn      		  - SPI_PeriClkCtrl
 *
 * @brief             - This function enables or disables peripheral clock
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void SPI_PeriClkCtrl(SPI_RegDef_t *pSPIx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
		{
			if (pSPIx == SPI1)
					{
					SPI1_PCLK_EN();
					}
			else if(pSPIx == SPI2)
					{
					SPI2_PCLK_EN();
					}
			else if(pSPIx == SPI2)
					{
					SPI3_PCLK_EN();
					}
			else if(pSPIx == SPI4)
					{
					SPI4_PCLK_EN();
					}
		}

		else
		{
			//todo
		}
}

/*********************************************************************
 * @fn      		  - SPI_Init
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	uint32_t tempreg = 0;
	//1.configure the device mode
	tempreg |= pSPIHandle->SPIConfig.SPI_DeviceMode << 2;
	//2.configure the bus config
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
	{
		//bidi mode should be cleared
		tempreg &= ~(1<<15);
	}
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
	{
		//bidi mode should be set
		tempreg |= ~(1<<15);
	}else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
			{//bidi mode should be cleared and RXONLY bit must be set
		tempreg &= ~(1<<15);
		tempreg |= ~(1<<10);
			}
	//3.configure the spi serial clock speed (baud rate)
	tempreg |= pSPIHandle->SPIConfig.SPI_SclkSpeed << 3;
	//4.configure the DFF
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF << 11;
	//5.configure the CPOL
	tempreg |= pSPIHandle->SPIConfig.SPI_CPOL << 1;
	//3.configure the CPHA
	tempreg |= pSPIHandle->SPIConfig.SPI_CPHA << 0;

	pSPIHandle->pSPIx->CR1 = tempreg;

}
void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}

uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName)
{
	if(pSPIx->SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;
}
/*
 * Data transmit and receive
 * blocking type - non-interrupt based
 * non-blocking type - interrupt based
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxbuffer, uint32_t Len) //blocking API
{
	while(Len > 0)
	{
		//1.wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);
		//2.check the DFF bit in CR1
		if(pSPIx->CR1 & ( 1<< SPI_CR1_DFF))
		{
			//16bit dff
			//load the data in DR
			pSPIx->DR = *((uint16_t*)pTxbuffer);
			Len--;
			Len--;
			(uint16_t) *pTxbuffer++;
		}
		else
		{   //8 bit
			pSPIx->DR = *pTxbuffer;
			Len--;
			*pTxbuffer++;

		}
	}
}

/*
 * IRQ configuration and ISR handling
 */
void SPI_IRQITConfig(uint8_t IRQNumber,  uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);
