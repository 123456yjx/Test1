#include "bsp_key.h"
KEY_VALUE  KeyValue;
void Key_GPIO_Config_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);

    // GPIO_InitStructure.GPIO_Pin = ;
    // GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    // GPIO_Init(RCC_APB2Periph_GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = Key_Previous_Pin | Key_Next_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	 // GPIO_ResetBits(GPIOB,Key_Previous_Pin|Key_Next_Pin );
	  
}

uint8_t Key_Scan(void) //按键扫描
{
    
    static uint8_t  Key_Press_Flag = FlagTure;
     
    if (Key_Press_Flag && (KeyPreviousState==Key_Press || KeyNextState==Key_Press))
    {
        Key_Press_Flag = FlagFalse;
			  delay_ms(11);
        if (KeyPreviousState == Key_Press)
				{
					 
             return   KeyValue=Previous;
				}
        else if (KeyNextState == Key_Press)
				{
					   
             return   KeyValue=Next;
				}
    }
    else if (KeyPreviousState == Key_Release && KeyNextState== Key_Release)

        Key_Press_Flag = FlagTure;   return KeyValue=None; 
}
