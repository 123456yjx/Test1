#ifndef __BSP_APPLICATION_H
#define __BSP_APPLICATION_H
#include "board.h"

typedef struct
{
  uint8_t NUM_1;
  uint8_t NUM_2;
  uint8_t NUM_3;
	  uint8_t NUM_4;
	  uint8_t NUM_5;
	  uint8_t NUM_6;
	  uint8_t NUM_7;
		  uint8_t NUM_8;

}PAGE_NUM;

extern PAGE_NUM  PageNum;
void KeyDeal(void);
void Menu_Display(void);


extern u8 flag_sand1;
extern u8 flag_sand2;
extern u8 flag_sand3;
extern u8 flag_sand4;
extern u8 flag_sand5;
extern u8 flag_sand6;
extern u8 flag_sand7;
extern u8 flag_sand8;
extern u8 flag_sand9;
#endif



