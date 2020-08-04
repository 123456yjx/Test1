#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H
#include "board.h"

  void Timer2_Config_Init(void);
	void Timer3_Config_Init(void);
  void TIM2_IRQHandler(void) ;
	void TIM3_IRQHandler(void) ;//定时器3设置为1秒中断定
	
extern	u8 Time1s_flag;//中断标志位

#endif
