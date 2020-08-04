#ifndef __BSP_KEY_H
#define __BSP_KEY_H
#include "board.h"
typedef enum {  
    None=0,
    Previous=1,
    Next=2
    
}KEY_VALUE;

#define Key_Press   0          //按键按下
#define Key_Release   1        //按键释放

#define Key_Previous_Pin    GPIO_Pin_9
#define Key_Next_Pin    GPIO_Pin_8

#define KeyPreviousState     GPIO_ReadInputDataBit(GPIOB, Key_Previous_Pin)
#define KeyNextState     GPIO_ReadInputDataBit(GPIOB, Key_Next_Pin)

extern KEY_VALUE  KeyValue; 

uint8_t Key_Scan(void);
void Key_GPIO_Config_Init(void);
#endif


