/*
 * timer.h
 *
 *  Created on: Sep 24, 2024
 *      Author: tiend
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define tick 10

extern int timer_counter[10];
extern int timerFLag[10];

void timer_run();
void set_timer(int index, int counter);


#endif /* INC_TIMER_H_ */
