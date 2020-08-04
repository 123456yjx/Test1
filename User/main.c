/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  */

#include "board.h"


int main(void)
{
	 unsigned char Send_InitData[7]={0xAA,0x01,0x00,0X01,0xC0,0x70,0x55};
	 
   board_init(); 
	IWDG_Init(4,1935);
   Usart_SendArray(USART2,Send_InitData,7);
   HT1621Wr_Nums(8,0,12,0);
	 disp_All();
	 delay_ms(100);
	 cleandisp();
   while(1) 
	 {	
		    Menu_Display(); //包类型为0x00页数为第一页		
		    Parameter_ReceiveData();
		    IWDG_Feed();
	 }
}
		
//    spTaskScheduler();  
//		  

/*********************************************END OF FILE**********************/

	 
