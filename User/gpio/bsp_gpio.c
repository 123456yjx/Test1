#include "bsp_gpio.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
#if 0
void GPIO_Config_Init(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	  GPIO_InitTypeDef GPIO_InitStructure;
   
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
      GPIO_InitStructure.GPIO_Pin = LCD_BackLight;	 
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
      GPIO_Init(GPIOA, &GPIO_InitStructure);	
	  GPIO_SetBits(GPIOA,LCD_BackLight);
    
      RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
      GPIO_InitStructure.GPIO_Pin = LCD_SDA|LCD_SCL|LCD_Data_Command|LCD_RES|LCD_CS;	 
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
      GPIO_Init(GPIOB, &GPIO_InitStructure);	
	  GPIO_ResetBits(GPIOB,LCD_SDA|LCD_SCL|LCD_Data_Command|LCD_RES|LCD_CS);
		
}
#endif



/*********************************************END OF FILE**********************/




