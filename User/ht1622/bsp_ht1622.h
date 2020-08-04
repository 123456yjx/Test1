#ifndef _HT1622_H_ 
#define _HT1622_H_  
#include "stm32f10x.h"
/*****************************************************************
�ܽŷ��� CS P1.0 WR P1.1 DAT P1.2

*****************************************************************/
#define HT1622_PORT_RD_SCK  GPIOB
#define HT1622_PORT_WR_SCK  GPIOA
#define HT1622_PORT_DAT     GPIOA
#define HT1622_PORT_CS      GPIOB
#define HT1622_PORT_LED     GPIOA
#define HT1622_RD_CLK       GPIO_Pin_0
#define HT1622_WR_CLK       GPIO_Pin_7
#define HT1622_DAT          GPIO_Pin_6
#define HT1622_CS           GPIO_Pin_1
#define HT1622_LED          GPIO_Pin_4
#define HT1622_RD_SCK_L		GPIO_ResetBits(HT1622_PORT_RD_SCK, HT1622_RD_CLK)//PB0
#define HT1622_RD_SCK_H		GPIO_SetBits(HT1622_PORT_RD_SCK, HT1622_RD_CLK) //PB0
#define HT1622_WR_SCK_L		GPIO_ResetBits(HT1622_PORT_WR_SCK, HT1622_WR_CLK)//PA7
#define HT1622_WR_SCK_H		GPIO_SetBits(HT1622_PORT_WR_SCK, HT1622_WR_CLK)//PA7
#define HT1622_DAT_L		  GPIO_ResetBits(HT1622_PORT_DAT, HT1622_DAT)//PA6
#define HT1622_DAT_H		  GPIO_SetBits(HT1622_PORT_DAT, HT1622_DAT)//PA6	
#define HT1622_CS_L		    GPIO_ResetBits(HT1622_PORT_CS, HT1622_CS)//PB1	
#define HT1622_CS_H		    GPIO_SetBits(HT1622_PORT_CS, HT1622_CS)//PB1
#define sbi(x, y)  (x |= (1 << y))   

/*****************************************************************
HT1622 ָ��궨��
*****************************************************************/
#define SYSDIS   0X00 // ����ϵͳ������LCDƫѹ������
#define SYSEN    0X01 // ��ϵͳ����
#define LCDOFF   0X02 // ��LCDƫѹ
#define LCDON    0X03 // ��LCDƫѹ
#define TIMEDIS  0x04 // ��ֹʱ�����
#define WDTDIS   0x05 // ��ֹWDT��ʱ��־���
#define TIMEREN  0x06 // ����ʱ�����//0x06
#define WDTEN    0x07 // ����WDT��ʱ��־���0x07
#define TONEOFF  0x08 // �ر��������0x08
#define CLRTIMER 0x0D // ���ʱ��������������
#define CLRWDT   0x0F // ���WDT������
#define RC32K    0x18 // ϵͳʱ��Դ��Ƭ��RC����
#define EXT32K   0x1C // ϵͳʱ��Դ���ⲿʱ��Դ
#define TONE4K   0x40 // �������Ƶ�ʣ�4kHz��
#define TONE2K   0x60 // �������Ƶ�ʣ�2kHz��
#define IRQDIS   0x80 // ��ֹIRQ���
#define IRQEN    0x88 // ����IRQ���
#define F1       0xA0 // ʱ��ʱ�������1Hz WDT�ĳ�ʱ��־��4s
#define F2       0xA1 // ʱ��ʱ�������2Hz WDT�ĳ�ʱ��־��2s
#define F4       0xA2 // ʱ��ʱ�������4Hz WDT�ĳ�ʱ��־��1s
#define F8       0xA3 // ʱ��ʱ�������8Hz WDT�ĳ�ʱ��־��1/2s
#define F16      0xA4 // ʱ��ʱ�������16Hz WDT�ĳ�ʱ��־��1/4s
#define F32      0xA5 // ʱ��ʱ�������32Hz WDT�ĳ�ʱ��־��1/8s
#define F64      0xA6 // ʱ��ʱ�������64Hz WDT�ĳ�ʱ��־��1/16s
#define F128     0xA7 // ʱ��ʱ�������128Hz WDT�ĳ�ʱ��־��1/32s
#define TEST     0xE0 // ����ģʽ�£��û���ʹ�á�
#define NORMAL   0xE3 // ��ͨģʽ
#define       COM0        0
#define       COM1        1
#define       COM2        2
#define       COM3        3
#define       COM4        4
#define       COM5        5
#define       COM6        6
#define       COM7        7

typedef unsigned char   uchar;

void HT1622_Init(void);//��ʼ��HT1622GPIO��
void HT1622_R(void);//������
void HT1622_W(void);//д����
void LCD_Wr_Clk(void);//дʱ������
void LCD_Rd_Clk(void);//��ʱ������
void  SendBit_HL(u8 dat,u8 cnt) ;//dat �ĸ�cnt λд��HT1622���ȷ��͸�λ
void  SendBit_LH(u8  dat,u8 cnt);//dat �ĵ�cnt λд��HT1622���ȷ��͵�λ
u8    ReceiveBit_LH(void);//��ȡcom��״̬
void  Sendcmd(u8  command);//command ����
void  W1622_q(u8 addr,u8 dat);//д����
void  W1622_byte(u8 SEG,u8 dat);//��ʾ��λ
u8   W1622_Read_byte(u8 addr);//ָ��ģʽ
void W1622_READ_MODIFY_WRITE(u8 dat,u8 SEG,u8 falg);//��дͬʱ���У���ʾ��ֵ���ϵ�ǰ����������
void W1622_Write_Seg(u8 SEG,u8 dat);//com1-com4
void W1622_success(u8 SEG,u8 cnt,u8 *p);//������ʽ���������ˢ��
void disp_renew(void);   //��ʾ����,����8x32��ȫ��ˢ��
void  dispON(u8 com,u8 SEG);//������ֵ���ϵ�λ����ʾ��Ӧcom��seg�ϵ����ݡ�
void dispOFF(u8 com,u8 SEG);
void  cleandisp(void);//ȫ����պ���
void disp_All(void);//ȫ�Ժ���
void HT1621Wr_Num(unsigned char Data,u8 addr,u8 Seg_flag,u8 Com_flag );
void HT1621Wr_Nums(unsigned char Data,u8 addr,u8 Seg_flag,u8 Com_flag );

#endif
