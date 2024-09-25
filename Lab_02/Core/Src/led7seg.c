/*
 * led7seg.c
 *
 *  Created on: Sep 24, 2024
 *      Author: tiend
 */
#include <led7seg.h>
#include <main.h>


uint16_t Led7Seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void display7SEG(int num){
	if (num < 0 || num > 9) return;
	GPIOB->ODR = (GPIOB -> ODR & 0xff80) | Led7Seg[num];
}


void control_countdown(int countdown){
	 for(int i = countdown; i > 0; i--){
		  display7SEG(i);
		  HAL_Delay(1000);
	 }
}

void control_countup(int countup){
	 for(int i = countup; i >= 0; i--){
		  display7SEG(i);
		  HAL_Delay(1000);
	 }
}

void clear7SEG(){
	GPIOB->ODR = (GPIOB -> ODR & 0xff80);
}


void update7SEG(int index){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_RESET);
	switch (index)
	{
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		default:
			break;
	}
	display7SEG(led_buffer[index]);

}

