/*
 * main.c
 *
 *  Created on: Dec 9, 2024
 *      Author: 90506
 */

#include "stm32f407xx.h"

int main(){

	return 0;
}



void EXTI0_IRQHandler(void){
	//handle the interrupt
	GPIO_IRQHandling(0);
}
