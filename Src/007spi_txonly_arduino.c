
/*
 * 006spi_tx_testing.c
 *
 *  Created on: Dec 11, 2024
 *      Author: 90506
 */
#include "stm32f407xx.h"
#include "string.h"



void delay(void){
	for (uint32_t i =0 ;i<500000;i++ );
}
/*
 * PB14 --> SPI2_MISO
 * PB15 --> SPI2_MOSI
 * PB13 --> SPI2_SCLK
 * PB12 --> SPI2_NSS
 * ALT function mode :5
 */

void SPI2_GPIOInits(void)
{
	GPIO_Handle_t SPIPins;

	SPIPins.pGPIOx = GPIOB;

	SPIPins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;

	SPIPins.GPIO_PinConfig.GPIO_PinAltFunMode = 5;

	SPIPins.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;

	SPIPins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	SPIPins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;



	//SCLK

	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;

	GPIO_Init(&SPIPins);


	//MOSI
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;

	GPIO_Init(&SPIPins);

	//MISO
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIO_Init(&SPIPins);


	//NSS
	SPIPins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIO_Init(&SPIPins);


}


void SPI2_Inits(void)
{

	SPI_Handle_t SPI2Handle;

	SPI2Handle.pSPIx = SPI2;

	SPI2Handle.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;

	SPI2Handle.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;

	SPI2Handle.SPIConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8; //generates sclk of 8Mhz

	SPI2Handle.SPIConfig.SPI_DFF=SPI_DFF_8BITS;

	SPI2Handle.SPIConfig.SPI_CPOL=SPI_CPOL_LOW;

	SPI2Handle.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;

	SPI2Handle.SPIConfig.SPI_SSM = SPI_SSM_DI; //hardware slave management enabled for NSS pin

	SPI_Init(&SPI2Handle);

}






void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE){
		pSPIx ->CR2 |= (1<< SPI_CR2_SSOE);
	}else{
		pSPIx ->CR2 &= ~(1<< SPI_CR2_SSOE);
	}

}

void GPIO_ButtonInit(void){
	GPIO_Handle_t GpioBtn;
	//GPIO button configuration
	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;


	GPIO_Init(&GpioBtn);
}

int main(void){


	char user_data[] = "Hello World";



	//this function is used to initialize the GPIO pins to behave as SPI2 pins
	SPI2_GPIOInits();


	//This function is used to initialize the  SPI2 peripheral parameters
	SPI2_Inits();


	/*
	 * making ssoe 1 does nss output enable
	 * the nss pin is automatically managed by the hardware
	 * i.e. when SPE = 1, NSS will be pulled to low
	 * and NSS pin will be high when SPE =0
	 */

	SPI_SSOEConfig(SPI2,ENABLE);

	while(1){

		while(!GPIO_ReadFromInputPin(GPIOA,GPIO_PIN_NO_0));

		delay();

		//enable the SPI2 peripheral
		SPI_PeripheralControl(SPI2, ENABLE);


		//first send length information
		uint8_t dataLen = strlen(user_data);
		SPI_SendData(SPI2,&dataLen,1);


		// to send data
		SPI_SendData(SPI2,(uint8_t*)user_data,strlen(user_data));

		//lets confirm SPI is not busy
		while(SPI_GetFlagStatus(SPI2, SPI_BUSY_FLAG));


		//disable the SPI2 peripheral
		SPI_PeripheralControl(SPI2, DISABLE);

	}






	return 0;
}



