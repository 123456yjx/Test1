#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H
#include "board.h"

  void Timer2_Config_Init(void);
	void Timer3_Config_Init(void);
  void TIM2_IRQHandler(void) ;
	void TIM3_IRQHandler(void) ;//��ʱ��3����Ϊ1���ж϶�
	
extern	u8 Time1s_flag;//�жϱ�־λ

#endif
