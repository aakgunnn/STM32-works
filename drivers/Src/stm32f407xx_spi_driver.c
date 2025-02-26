/*
 * stm32f407xx_spi_driver.c
 *
 *  Created on: Dec 10, 2024
 *      Author: 90506
 */

#include "stm32f407xx_spi_driver.h"
#include "stm32f407xx.h"


uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t FlagName){

	if (pSPIx -> SR & FlagName){
		return FLAG_SET;
	}
	return FLAG_RESET;
}




void SPI_PeriClockControl(SPI_RegDef_t *pSPIx ,uint8_t EnorDi){


	if (EnorDi == ENABLE)
	{
			if(pSPIx == SPI1){
				SPI1_PCLK_EN();
			}
			else if(pSPIx == SPI2){
				SPI2_PCLK_EN();
			}
			else if(pSPIx == SPI3){
				SPI3_PCLK_EN();
			}

	}
	else{

	}

}

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi){

	if(EnorDi == ENABLE){
		pSPIx -> CR1 |= (1<< SPI_CR1_SPE);
	}else{
		pSPIx ->CR1 &=~(1<<SPI_CR1_SPE);
	}
}

void SPI_Init(SPI_Handle_t *pSPIHandle){

	//peripheral clock enable
	SPI_PeriClockControl(pSPIHandle->pSPIx, ENABLE);



	//first lets configure the SPI_CR1 register


	uint32_t tempreg = 0;

	//1. configure the device mode
	tempreg |= pSPIHandle -> SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;


	//2.configure the bus config
	if(pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD){
		//bidi mode should be cleared
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);

	}


	else if (pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD){
			//bidi mode should be set
			tempreg |= (1<<SPI_CR1_BIDIMODE);
	}

	else if (pSPIHandle -> SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY){
		//bidi mode should be cleared
		tempreg &= ~(1<<SPI_CR1_BIDIMODE);
		//RXONLY bit must be set
		tempreg |= (1<<SPI_CR1_RXONLY);

	}

	//3. configure the spi serial clock speed (baud rate)
	tempreg |= pSPIHandle -> SPIConfig.SPI_SclkSpeed <<3;

	//4.configure the DFF
	tempreg |= pSPIHandle->SPIConfig.SPI_DFF << 11;

	//5. configure the CPOL
	tempreg |= pSPIHandle -> SPIConfig.SPI_CPOL <<1;

	//6. configure the CPHA
	tempreg |= pSPIHandle -> SPIConfig.SPI_CPHA << 0;

	pSPIHandle -> pSPIx -> CR1 = tempreg;
}



void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len){


	while(Len>0){

		//1. wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET);

		//2.check the DFF bit CR1
		if(pSPIx -> CR1 & (1 << SPI_CR1_DFF)){
			//16. bit DFF
			//1. load the data in to the DR
			pSPIx -> DR = ((uint16_t*)pTxBuffer);
			Len--;
			Len--;
			(uint16_t*)pTxBuffer++;
		}else{
			//8 bit DFF
			pSPIx -> DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}

	}
}



void SPI_SSIConfig(SPI_RegDef_t *pSPIx,uint8_t EnorDi){
	if(EnorDi == ENABLE){
		pSPIx ->CR1 |= (1<< SPI_CR1_SSI);
	}else{
		pSPIx ->CR1 &= ~(1<< SPI_CR1_SSI);
	}

}



void SPI_ReceiveData(){

}




void SPI_DeInit(SPI_RegDef_t *pSPIx){

}


