#ifndef __BSP_ST7565_H
#define __BSP_ST7565_H

#include "stm32f10x.h"
#include "board.h"

#define  LCD_BackLight       GPIO_Pin_15
#define  LCD_SDA             GPIO_Pin_7
#define  LCD_SCL             GPIO_Pin_6
#define  LCD_CD              GPIO_Pin_5
#define  LCD_RES             GPIO_Pin_4
#define  LCD_CS              GPIO_Pin_3

#define  LCD_CS_LOW         GPIO_ResetBits(GPIOB,LCD_CS)
#define  LCD_CS_HIGH        GPIO_SetBits(GPIOB,LCD_CS)

#define  LCD_RES_LOW        GPIO_ResetBits(GPIOB,LCD_RES)
#define  LCD_RES_HIGH       GPIO_SetBits(GPIOB,LCD_RES)

#define  LCD_CD_LOW        GPIO_ResetBits(GPIOB,LCD_CD)
#define  LCD_CD_HIGH       GPIO_SetBits(GPIOB,LCD_CD)

#define  LCD_SCL_LOW               GPIO_ResetBits(GPIOB,LCD_SCL)
#define  LCD_SCL_HIGH              GPIO_SetBits(GPIOB,LCD_SCL)

#define  LCD_SDA_LOW        GPIO_ResetBits(GPIOB,LCD_SDA)
#define  LCD_SDA_HIGH       GPIO_SetBits(GPIOB,LCD_SDA)

extern unsigned char dian[];
extern unsigned char ya[];
void Display_Dianya(unsigned char page,unsigned char column);
void LCD_GPIO_Config_Init(void);
void LCD_Init(void);
void WriteToLCD(uint8_t data, uint8_t flg);
void ClearScreen(void);
void LCDAddr(uint8_t page,uint8_t column) ;
void DisplayStr(uint8_t page,uint8_t column,char *text);
void DisplayChinese(unsigned char page,unsigned char column,unsigned char *dp,unsigned char Num) ;
void DisplayPic(unsigned char *dp);







#endif
