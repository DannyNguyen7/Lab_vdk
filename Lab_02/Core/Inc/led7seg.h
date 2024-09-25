/*
 * led7seg.h
 *
 *  Created on: Sep 24, 2024
 *      Author: tiend
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_
#include "main.h"

extern uint16_t Led7Seg[10];
extern int led_buffer[4]; 
//const int MAX_LED = 4;

void display7SEG(int num);
void control_countdown(int countdown);
void control_countup(int countup);
void clear7SEG();
void update7SEG(int index);

#endif /* INC_LED7SEG_H_ */
