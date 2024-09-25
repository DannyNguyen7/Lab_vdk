/*
 * timer.c
 *
 *  Created on: Sep 24, 2024
 *      Author: tiend
 */

#include "timer.h"
#include "main.h"

int timer_counter[10] = {0};
int timerFLag[10] = {0};


void set_timer(int index, int counter)
{
    timer_counter[index] = counter / tick;
    timerFLag[index] = 0;
}

void timer_run()
{
    for(int i = 0; i < 2; i++){
      if(timer_counter[i] > 0){
        timer_counter[i]--;
        if(timer_counter[i] <= 0){
          timerFLag[i] = 1;
        }
      }
    }
}
