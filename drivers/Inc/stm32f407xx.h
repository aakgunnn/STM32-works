/*
 * stm32f407xx.h
 *
 *  Created on: Nov 29, 2024
 *      Author: 90506
 */
#include<stdint.h>

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#define __vo volatile




/*************************************************START:Processor Specific Details*******************************************
 *
 * ARM Cortex Mx processor NVIC ISERx register Addresses
 */

#define NVIC_ISER0					((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1					((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2					((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3					((__vo uint32_t*)0xE000E10C)



/*
 * ARM Cortex Mx Processor NVIC ICERx register addresses
 */

#define NVIC_ICER0					((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1					((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2					((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3					((__vo uint32_t*)0xE000E18C)

/*
 * ARM Cortex Mx Processor Prioirty Register Addresses Calculation
 */

#define NVIC_PR_BASE_ADDR			((__vo uint32_t*)0xE000E400)


#define NO_PR_BITS_IMPLEMENTED		4








#define FLASH_BASEADDR					0X08000000U  // explain this macro briefly here
#define SRAM1_BASEADDR					0X20000000U  //112KB   //explain this macro briefly here
#define SRAM2_BASEADDR					0x20001C00U  //explain this macro briefly here
#define ROM_BASEADDR					0x1FFF0000U
#define	SRAM 							SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR						0x40000000U
#define	APB1PERIPH_BASEADDR					PERIPH_BASEADDR
#define	APB2PERIPH_BASEADDR					0x40010000U
#define	AHB1PERIPH_BASEADDR					0x40020000U
#define	AHB2PERIPH_BASEADDR					0x50000000U


/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 * TODO:Complete for all other peripherals
 */

#define GPIOA_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x0000)
#define GPIOB_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x0400)
#define GPIOC_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x0800)
#define GPIOD_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x0C00)
#define GPIOE_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x1000)
#define GPIOF_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x1400)
#define GPIOG_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x1800)
#define GPIOH_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x1C00)
#define GPIOI_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x2000)
#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR	 + 0x3800)




/*
 * Base addresses of peripherals which are hanging on APB1 bus
 * TODO : Complete for all other peripherals
 */


#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0X5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0X5800)
#define I2C3_BASEADR					(APB1PERIPH_BASEADDR + 0X5X00)

#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0X3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0X4400)
#define USART3_BASEADDR					(APB1PERIPH_BASEADDR + 0X4800)
#define UART4_BASEADDR					(APB1PERIPH_BASEADDR + 0X4C00)
#define UART5_BASEADDR					(APB1PERIPH_BASEADDR + 0X5000)





/*
 * Base addresses of peripherals which are hanging on APB2 bus
 * TODO : Complete for all other peripherals
 */


#define EXTI_BASEADDR					(APB2PERIPH_BASEADDR + 0X3C00)

#define SPI1_BASEADDR					(APB2PERIPH_BASEADDR + 0X3000)

#define USART1_BASEADDR					(APB2PERIPH_BASEADDR + 0X1000)
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0X1400)

#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0X3800)



/*************************************** PERİPHERAL REGİSTER DEFINATION STRUCTURES ******************************************************/


/*
 * Note:Registers of a peripheral are specific to MCU
 * e.g: Number of registers of SPI peripheral of STM32F4x family of MCUs may be different (more or less)
 * Compared to number of registers of SPI peripheral of STM32Lx or STMF0x Family of MCUs
 * Please check your Device Referance Manuel
 */

typedef struct{
	__vo uint32_t MODER;			/*!<GPIO port mode register,			Address offset:0x00 */
	__vo uint32_t OTYPER;			/*!TODO,								Address offset:0x04 */
	__vo uint32_t OSPEEDR;			/*										Address offset:0X0C	*/
	__vo uint32_t PUPDR;			/*										Address offset:0X10	*/
	__vo uint32_t IDR;				/*										Address offset:0X14	*/
	__vo uint32_t ODR;				/*										Address offset:0X18	*/
	__vo uint32_t BSRR;				/*										Address offset:0X1A	*/
	__vo uint32_t LCKR;				/*										Address offset:0X1C	*/
	__vo uint32_t AFR[2];			/*!<AFR[0]: GPIO alternate funciton low register, AF[1]:GPIO alternate function high register Address offset: 0X20 - 0X24*/
}GPIO_RegDef_t;



/*
 * peripheral register defination structure for RCC
 */


typedef struct
{
	__vo uint32_t CR;								/*!<TODO,						Address offset: 0x00*/
	__vo uint32_t PLLCFGR;							/*!<TODO,						Address offset: 0x04*/
	__vo uint32_t CLFGR;							/*!<TODO,						Address offset: 0x08*/
	__vo uint32_t CIR;								/*!<TODO,						Address offset: 0x0C*/
	__vo uint32_t AHB1RSTR;							/*!<TODO,						Address offset: 0x10*/
	__vo uint32_t AHB2RSTR;							/*!<TODO,						Address offset: 0x14*/
	__vo uint32_t AHB3RSTR;							/*!<TODO,						Address offset: 0x18*/
		 uint32_t RESERVED0;						/*!<Reserved, 0x1C									*/
	__vo uint32_t APB1RSTR;							/*!<TODO,						Address offset: 0x20*/
	__vo uint32_t APB2RSTR;							/*!<TODO,						Address offset: 0x24*/
	 	 uint32_t RESERVED1[2];						/*!<Reserved, 0x28,0x2C											*/
	__vo uint32_t AHB1ENR;							/*!<TODO,						Address offset: 0x30*/
	__vo uint32_t AHB2ENR;							/*!<TODO,						Address offset: 0x34*/
	__vo uint32_t AHB3ENR;							/*!<TODO,						Address offset: 0x38*/
		 uint32_t RESERVED2;						/*!<Reserved, 0x3C									*/
	__vo uint32_t APB1ENR;							/*!<TODO,						Address offset: 0x40*/
	__vo uint32_t APB2ENR;							/*!<TODO,						Address offset: 0x44*/
	__vo uint32_t RESERVERD3[2];					/*!<Reserved, 0x48-0x4C								*/
	__vo uint32_t AHB1LPENR;						/*!<TODO,						Address offset: 0x50*/
	__vo uint32_t AHB2LPENR;						/*!<TODO,						Address offset: 0x54*/
	__vo uint32_t AHB3LPENR;						/*!<TODO,						Address offset: 0x58*/
		 uint32_t RESERVED4;						/*!<Reserved, 0x5C									*/
	__vo uint32_t APB1LPENR;						/*!<TODO,						Address offset: 0x60*/
	__vo uint32_t APB2LPENR;						/*!<TODO,						Address offset: 0x64*/
		 uint32_t RESERVED5[2];						/*!<Reserved, 0x68,0x6C								*/
	__vo uint32_t BDCR;								/*!<TODO,						Address offset: 0x70*/
	__vo uint32_t CSR;								/*!<TODO,						Address offset: 0x74*/
		 uint32_t RESERVED6[2];						/*!<Reserved,0x78-0x7C								*/
	__vo uint32_t SSCGR;							/*!<TODO,						Address offset: 0x80*/
	__vo uint32_t PLLI2SCFGR;						/*!<TODO,						Address offset: 0x84*/
	__vo uint32_t PLLSAICFGR;						/*!<TODO,						Address offset: 0x88*/
	__vo uint32_t DCKCFGR;							/*!<TODO,						Address offset: 0x8C*/
	__vo uint32_t CKGATENR;							/*!<TODO,						Address offset: 0x90*/
	__vo uint32_t DCKCFGR2;							/*!<TODO,						Address offset: 0x94*/

}RCC_RegDef_t;





/*
 * peripheral register defination structure for EXTI
 */

typedef struct{
	__vo uint32_t IMR;			/*!<GPIO port mode register,			Address offset:0x00 */
	__vo uint32_t EMR;			/*!TODO,								Address offset:0x04 */
	__vo uint32_t RTSR;			/*										Address offset:0X0C	*/
	__vo uint32_t FTSR;			/*										Address offset:0X10	*/
	__vo uint32_t SWIER;				/*										Address offset:0X14	*/
	__vo uint32_t PR;				/*										Address offset:0X18	*/

}EXTI_RegDef_t;


/*
 *peripheral register defination structure for SYSCFG
 */
typedef struct{
	__vo uint32_t MEMRMP;			/*!<GPIO port mode register,			Address offset:0x00 */
	__vo uint32_t PMC;			/*!TODO,								Address offset:0x04 */
	__vo uint32_t EXTICR[4];			/*										Address offset:0X0C	*/
	__vo uint32_t RESERVED1[2];			/*										Address offset:0X10	*/
	__vo uint32_t CMPCR;				/*										Address offset:0X14	*/
	__vo uint32_t RESERVED2[2];				/*										Address offset:0X18	*/
	__vo uint32_t CFGR;				/*										Address offset:0X14	*/

}SYSCFG_RegDef_t;




/*
 * peripheral register definition structure for SPI
 */

typedef struct{
	__vo uint32_t					CR1;
	__vo uint32_t					CR2;
	__vo uint32_t					SR;
	__vo uint32_t					DR;
	__vo uint32_t					CRCPR;
	__vo uint32_t					RXCRCR;
	__vo uint32_t					TXCRCR;
	__vo uint32_t					I2SCFGR;
	__vo uint32_t					I2SPR;

}SPI_RegDef_t;




/*
 * Peripheral definations (Peripheral base addresses typecasted to xxx_RegDef_t)
 */

#define GPIOA							((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB							((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC							((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD							((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE							((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF							((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG							((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH							((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI							((GPIO_RegDef_t*)GPIOI_BASEADDR)
#define RCC 							((RCC_RegDef_t*)0x40023800)

#define EXTI							((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG							((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)




#define SPI1							((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2							((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3							((SPI_RegDef_t*)SPI3_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()					(RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()					(RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()					(RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()					(RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()					(RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()					(RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()					(RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()					(RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN()					(RCC->AHB1ENR |= (1<<8))



/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()					(RCC -> APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()					(RCC -> APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()					(RCC -> APB1ENR |= (1<<23))







/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()					(RCC -> APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()					(RCC -> APB2ENR |= (1<<14))
#define SPI3_PCLK_EN()					(RCC -> APB2ENR |= (1<<15))
#define SPI4_PCLK_EN()					(RCC -> APB2ENR |= (1<<13))




/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCCK_EN()				(RCC -> APB2ENR |= (1<<4))
#define USART2_PCCK_EN()				(RCC -> APB1ENR |= (1<<17))
#define USART3_PCCK_EN()				(RCC -> APB1ENR |= (1<<18))
#define USART4_PCCK_EN()				(RCC -> APB1ENR |= (1<<19))
#define USART5_PCCK_EN()				(RCC -> APB1ENR |= (1<<20))
#define USART6_PCCK_EN()				(RCC -> APB1ENR |= (1<<5))







/*
 * Clock Enable Macros for SYSCFGx peripherals
 */
#define SYSCFG_PCLK_EN()				(RCC->APB2ENR |= (1<<14))




/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI()					(RCC ->AHB1ENR &= ~(1<<8))







/*
 * Clock Disable Macros for I2Cx peripherals
 */


/*
 * Clock Disable Macros for SPIx peripherals
 */



/*
 * Clock Disable Macros for USARTx peripherals
 */



/*
 * Clock Disable Macros for SYSCFGx peripherals
 */

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<0));	(RCC->AHB1RSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<1));	(RCC->AHB1RSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<2));	(RCC->AHB1RSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<3));	(RCC->AHB1RSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<4));	(RCC->AHB1RSTR &= ~(1<<4));}while(0)
#define GPIOF_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<5));	(RCC->AHB1RSTR &= ~(1<<5));}while(0)
#define GPIOG_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<6));	(RCC->AHB1RSTR &= ~(1<<6));}while(0)
#define GPIOH_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<7));	(RCC->AHB1RSTR &= ~(1<<7));}while(0)
#define GPIOI_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1<<8));	(RCC->AHB1RSTR &= ~(1<<8));}while(0)


#define GPIO_BASEADDR_TO_CODE(x)			((x == GPIOA) ? 0 :\
											(x == GPIOB) ? 1 :\
											(x == GPIOC) ? 2 :\
											(x == GPIOD) ? 3 :\
											(x == GPIOE) ? 4 :\
											(x == GPIOF) ? 5 :\
											(x == GPIOG) ? 6 :\
											(x == GPIOH) ? 7 :0)






/*
 * IRQ(Interrupt Request) Numbers of STM32F407x MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list fot ohter peripherals
 */

#define IRQ_NO_EXTI0				6
#define IRQ_NO_EXTI1				7
#define IRQ_NO_EXTI2				8
#define IRQ_NO_EXTI3				9
#define IRQ_NO_EXTI4				10
#define IRQ_NO_EXTI9_5				23
#define IRQ_NO_EXTI15_10			40




/*
 * macros for all the possible priority levels
 */


#define NVIC_IRQ_PRI0				0
#define NVIC_IRQ_PRI15				15

//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET				 	ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET
#define FLAG_RESET			RESET
#define FLAG_SET			SET




/*
 * **************************************************************************
 * Bit position definitions of SPI peripheral
 * ***************************************************************************
 */

#define SPI_CR1_CPHA						0
#define SPI_CR1_CPOL						1
#define SPI_CR1_MSTR						2
#define SPI_CR1_BR							3
#define SPI_CR1_SPE							6
#define SPI_CR1_LSBFIRST					7
#define SPI_CR1_SSI							8
#define SPI_CR1_SSM							9
#define SPI_CR1_RXONLY						10
#define SPI_CR1_DFF							11
#define SPI_CR1_CRCNEXT						12
#define SPI_CR1_CRCEN						13
#define SPI_CR1_BIDIOE						14
#define SPI_CR1_BIDIMODE					15




/*
 * Bit position definitions SPI_CR2
 */

#define SPI_CR2_RXDMAEN						0
#define SPI_CR2_TXDMAEN						1
#define SPI_CR2_SSOE						2
#define SPI_CR2_FRF							4
#define SPI_CR2_ERRIE						5
#define SPI_CR2_RXNEIE						6
#define SPI_CR2_TXEIE						7




/*
 *Bit position definitions SPI_SR
 */

#define SPI_SR_RXNE							0
#define SPI_SR_TXE							1
#define SPI_SR_CHSIDE						2
#define SPI_SR_UDR							3
#define SPI_SR_CRCERR						4
#define SPI_SR_MODF							5
#define SPI_SR_OVR							6
#define SPI_SR_BSY							7
#define SPI_SR_FRE							8



#include "stm32f407xx_gpio_driver.h"

#include "stm32f407xx_spi_driver.h"




#endif /* INC_STM32F407XX_H_ */
