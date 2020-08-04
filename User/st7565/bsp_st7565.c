
#include "bsp_st7565.h"

void LCD_GPIO_Config_Init(void)
{
    /*定义一个GPIO_InitTypeDef类型的结构体*/
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    GPIO_InitStructure.GPIO_Pin = LCD_BackLight;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA,LCD_BackLight);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LCD_SDA|LCD_SCL|LCD_CD|LCD_RES|LCD_CS;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_ResetBits(GPIOB,LCD_SDA|LCD_SCL|LCD_CD|LCD_RES|LCD_CS);
}




void Delay(uint8_t tick)
{
    u8 j,k;
    for(j=0; j<tick; j++)
        for(k=0; k<110; k++);
}

/*********************************************************************************************************
** 函数名称: LCD_Init
** 功能描述: 初始化LCD模块
** 输  　入: 无
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/
void LCD_Init(void)
{
    LCD_GPIO_Config_Init();
//  LCD_RES_HIGH;
    // Delay(20);
    LCD_RES_LOW;

    LCD_RES_HIGH;
#if 1
    WriteToLCD(0xE2, 1);

    WriteToLCD(0x2c, 1);		/*升压步聚1*/

    WriteToLCD(0x2e, 1);		/*升压步聚2*/

    WriteToLCD(0x2f, 1);		/*升压步聚3*/

    WriteToLCD(0x26, 1);		/*粗调对比度，可设置范围20～27*/
    WriteToLCD(0x81, 1);		/*微调对比度*/
    WriteToLCD(0x45, 1);		/*微调对比度的值，可设置范围0～63  1f*/
    WriteToLCD(0xa3, 1);		/*1/9偏压比（bias）*/
    WriteToLCD(0xc8, 1);		/*行扫描顺序：从上到下*/
    WriteToLCD(0xa0, 1);		/*列扫描顺序：从左到右*/
    WriteToLCD(0x40, 1);		/*起始行：从第一行开始*/
    ClearScreen();
    WriteToLCD(0xaf, 1);		/*开显示*/
#endif

}

/*********************************************************************************************************
** 函数名称: WriteToLCD
** 功能描述: 写数据进LCD
** 输  　入: data:写数据
**					 flg:标识。(0,数据)(1,命令)
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/
void WriteToLCD(uint8_t data, uint8_t flg)
{
    uint8_t i;
    LCD_CS_LOW;
    if(flg)
    {
        LCD_CD_LOW;//写命令
    }
    else
    {
        LCD_CD_HIGH;//写数据
    }

    for(i=0; i<8; i++)
    {
        LCD_SCL_LOW;
        if(flg)Delay(2);
        if(data&0x80)
        {
            LCD_SDA_HIGH;
        }
        else
        {
            LCD_SDA_LOW;
        }
        LCD_SCL_HIGH;
        // delay_ms(1);
        data <<= 1;
    }
//   LCD_CS_HIGH;
}

/*********************************************************************************************************
** 函数名称: ClearScreen
** 功能描述: 清除屏幕
** 输  　入: 无
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/
void ClearScreen(void)
{
    unsigned char i,j;
    LCD_CS_LOW;
    for(i=0; i<9; i++)
    {
        LCDAddr(1+i,1);
        WriteToLCD(0xb0+i,1);//写命令
        WriteToLCD(0x10,1);
        WriteToLCD(0x00,1);

        for(j=0; j<132; j++)
        {
            WriteToLCD(0x00,0);//写数据
        }
    }

}
void full_display()
{
    int i,j;
    for(i=0; i<8; i++)
    {
        LCD_CD_LOW;
        LCDAddr(i+1,0);
        for(j=0; j<128; j++)
        {
            WriteToLCD(0xff,0);
        }
    }
}
/*********************************************************************************************************
** 函数名称: LCDAddr
** 功能描述: LCD地址偏移,内部使用
** 输  　入: page:页,column:列
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/
void LCDAddr(uint8_t page,uint8_t column)
{
    LCD_CS_LOW;
    column--;

    page--;

    WriteToLCD(0xb0+page,1);
    WriteToLCD(((column>>4)&0x0f)+0x10,1);
    WriteToLCD(column&0x0f,1);
}



/*********************************************************************************************************
** 函数名称: DisplayStr
** 功能描述: 显示字符串
** 输  　入: page:页,column:列,text:文本指针
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/
void DisplayStr(uint8_t page,uint8_t column,char *text)
{
    uint8_t i=0,j,k,n;

    while(text[i]>0x00)
    {
        if((text[i]>=0x20)&&(text[i]<=0x7e))
        {
            j=text[i]-0x20;
            for(n=0; n<2; n++)
            {
                LCDAddr(page+n,column);
                for(k=0; k<8; k++)
                {
                    WriteToLCD(ascii_table_8x16[j][k+8*n],0);
                }
            }
            i++;
            column+=8;
        }
        else
        {
            i++;
        }
    }
    LCD_CS_HIGH;
}

/*********************************************************************************************************
** 函数名称: DisplayStr
** 功能描述: 显示16*16汉字
** 输  　入: page:页,column:列,dp:文本指针,Num:汉字数目
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/
void DisplayChinese(unsigned char page,unsigned char column,unsigned char *dp,unsigned char Num)
{
    unsigned char i,j,k;

    LCD_CS_LOW;
    for(k=0; k<Num; k++)
    {
        for(j=0; j<2; j++)
        {
            LCDAddr(page+j,column+(k*12));
            for (i=0; i<12; i++)
            {
                WriteToLCD(*dp,0);    //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
                dp++;
            }
        }
    }
    LCD_CS_HIGH;
}
/*********************************************************************************************************
** 函数名称: DisplayPic
** 功能描述: 显示汉字
** 输  　入: dp:图片指针
** 输  　出: 无
** 全局变量: 无
** 调用模块: 无
********************************************************************************************************/

void DisplayPic(unsigned char *dp)
{
    unsigned char i,j;

    LCD_CS_LOW;
    for(i=0; i<8; i++)
    {
        for(j=0; j<2; j++)
        {
            LCDAddr(i,0);
            for (j=0; j<128; j++)
            {
                WriteToLCD(*dp,0);    //写数据到 LCD,每写完一个 8 位的数据后列地址自动加 1
                dp++;
            }
        }
    }
    LCD_CS_HIGH;
}





