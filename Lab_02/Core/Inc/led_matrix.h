#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_
#include "main.h"

extern index_led_matrix;
extern const int MAX_LED_MATRIX;

void display_row(uint8_t row_data);
void updateLEDMatrix (int index );

#endif /* INC_LED7SEG_H_ */
