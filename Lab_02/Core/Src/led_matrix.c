#include "led_matrix.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0b00000000, 0b11111100, 0b00010010, 0b00010001, 0b00010001, 0b00010010, 0b11111100, 0b00000000};

void updateLEDMatrix (int index ) {
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin | ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin, SET);
    switch(index){
        case 0:
            HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
            break;        
        case 2:
            HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
            break; 
        case 3:
            HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
            break; 
        case 4:
            HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
            break; 
        case 5:
            HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
            break; 
        case 6:
            HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
            break; 
        case 7:
            HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
            break;         
        default:
            break;
    }
    display_row(matrix_buffer[index]);

}

void display_row(uint8_t value) {
    uint16_t row_pin[] = {ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin, ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin};

    for(int i = 0; i < MAX_LED_MATRIX; i++){
        if(value & (1 << i)){
            HAL_GPIO_WritePin(GPIOB, row_pin[i], RESET);
        }
        else
            HAL_GPIO_WritePin(GPIOB, row_pin[i], SET);
    }
}