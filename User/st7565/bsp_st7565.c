
#include "bsp_st7565.h"

void LCD_GPIO_Config_Init(void)
{
    /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
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
** ��������: LCD_Init
** ��������: ��ʼ��LCDģ��
** ��  ����: ��
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
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

    WriteToLCD(0x2c, 1);		/*��ѹ����1*/

    WriteToLCD(0x2e, 1);		/*��ѹ����2*/

    WriteToLCD(0x2f, 1);		/*��ѹ����3*/

    WriteToLCD(0x26, 1);		/*�ֵ��Աȶȣ������÷�Χ20��27*/
    WriteToLCD(0x81, 1);		/*΢���Աȶ�*/
    WriteToLCD(0x45, 1);		/*΢���Աȶȵ�ֵ�������÷�Χ0��63  1f*/
    WriteToLCD(0xa3, 1);		/*1/9ƫѹ�ȣ�bias��*/
    WriteToLCD(0xc8, 1);		/*��ɨ��˳�򣺴��ϵ���*/
    WriteToLCD(0xa0, 1);		/*��ɨ��˳�򣺴�����*/
    WriteToLCD(0x40, 1);		/*��ʼ�У��ӵ�һ�п�ʼ*/
    ClearScreen();
    WriteToLCD(0xaf, 1);		/*����ʾ*/
#endif

}

/*********************************************************************************************************
** ��������: WriteToLCD
** ��������: д���ݽ�LCD
** ��  ����: data:д����
**					 flg:��ʶ��(0,����)(1,����)
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
********************************************************************************************************/
void WriteToLCD(uint8_t data, uint8_t flg)
{
    uint8_t i;
    LCD_CS_LOW;
    if(flg)
    {
        LCD_CD_LOW;//д����
    }
    else
    {
        LCD_CD_HIGH;//д����
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
** ��������: ClearScreen
** ��������: �����Ļ
** ��  ����: ��
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
********************************************************************************************************/
void ClearScreen(void)
{
    unsigned char i,j;
    LCD_CS_LOW;
    for(i=0; i<9; i++)
    {
        LCDAddr(1+i,1);
        WriteToLCD(0xb0+i,1);//д����
        WriteToLCD(0x10,1);
        WriteToLCD(0x00,1);

        for(j=0; j<132; j++)
        {
            WriteToLCD(0x00,0);//д����
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
** ��������: LCDAddr
** ��������: LCD��ַƫ��,�ڲ�ʹ��
** ��  ����: page:ҳ,column:��
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
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
** ��������: DisplayStr
** ��������: ��ʾ�ַ���
** ��  ����: page:ҳ,column:��,text:�ı�ָ��
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
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
** ��������: DisplayStr
** ��������: ��ʾ16*16����
** ��  ����: page:ҳ,column:��,dp:�ı�ָ��,Num:������Ŀ
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
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
                WriteToLCD(*dp,0);    //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
                dp++;
            }
        }
    }
    LCD_CS_HIGH;
}
/*********************************************************************************************************
** ��������: DisplayPic
** ��������: ��ʾ����
** ��  ����: dp:ͼƬָ��
** ��  ����: ��
** ȫ�ֱ���: ��
** ����ģ��: ��
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
                WriteToLCD(*dp,0);    //д���ݵ� LCD,ÿд��һ�� 8 λ�����ݺ��е�ַ�Զ��� 1
                dp++;
            }
        }
    }
    LCD_CS_HIGH;
}





