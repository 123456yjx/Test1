#ifndef _HT1622_H_ 
#define _HT1622_H_  
#include "stm32f10x.h"
/*****************************************************************
管脚分配 CS P1.0 WR P1.1 DAT P1.2

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
HT1622 指令宏定义
*****************************************************************/
#define SYSDIS   0X00 // 关振系统荡器和LCD偏压发生器
#define SYSEN    0X01 // 打开系统振荡器
#define LCDOFF   0X02 // 关LCD偏压
#define LCDON    0X03 // 打开LCD偏压
#define TIMEDIS  0x04 // 禁止时基输出
#define WDTDIS   0x05 // 禁止WDT超时标志输出
#define TIMEREN  0x06 // 启用时基输出//0x06
#define WDTEN    0x07 // 启用WDT超时标志输出0x07
#define TONEOFF  0x08 // 关闭声音输出0x08
#define CLRTIMER 0x0D // 清除时基发生器的内容
#define CLRWDT   0x0F // 清除WDT的内容
#define RC32K    0x18 // 系统时钟源，片上RC振荡器
#define EXT32K   0x1C // 系统时钟源，外部时钟源
#define TONE4K   0x40 // 音的输出频率：4kHz的
#define TONE2K   0x60 // 音的输出频率：2kHz的
#define IRQDIS   0x80 // 禁止IRQ输出
#define IRQEN    0x88 // 启用IRQ输出
#define F1       0xA0 // 时基时钟输出：1Hz WDT的超时标志后：4s
#define F2       0xA1 // 时基时钟输出：2Hz WDT的超时标志后：2s
#define F4       0xA2 // 时基时钟输出：4Hz WDT的超时标志后：1s
#define F8       0xA3 // 时基时钟输出：8Hz WDT的超时标志后：1/2s
#define F16      0xA4 // 时基时钟输出：16Hz WDT的超时标志后：1/4s
#define F32      0xA5 // 时基时钟输出：32Hz WDT的超时标志后：1/8s
#define F64      0xA6 // 时基时钟输出：64Hz WDT的超时标志后：1/16s
#define F128     0xA7 // 时基时钟输出：128Hz WDT的超时标志后：1/32s
#define TEST     0xE0 // 测试模式下，用户不使用。
#define NORMAL   0xE3 // 普通模式
#define       COM0        0
#define       COM1        1
#define       COM2        2
#define       COM3        3
#define       COM4        4
#define       COM5        5
#define       COM6        6
#define       COM7        7

typedef unsigned char   uchar;

void HT1622_Init(void);//初始化HT1622GPIO口
void HT1622_R(void);//读数据
void HT1622_W(void);//写数据
void LCD_Wr_Clk(void);//写时钟脉冲
void LCD_Rd_Clk(void);//读时钟脉冲
void  SendBit_HL(u8 dat,u8 cnt) ;//dat 的高cnt 位写入HT1622，先发送高位
void  SendBit_LH(u8  dat,u8 cnt);//dat 的低cnt 位写入HT1622，先发送低位
u8    ReceiveBit_LH(void);//读取com口状态
void  Sendcmd(u8  command);//command 命令
void  W1622_q(u8 addr,u8 dat);//写数据
void  W1622_byte(u8 SEG,u8 dat);//显示单位
u8   W1622_Read_byte(u8 addr);//指令模式
void W1622_READ_MODIFY_WRITE(u8 dat,u8 SEG,u8 falg);//读写同时进行，显示真值表上的前四例的数据
void W1622_Write_Seg(u8 SEG,u8 dat);//com1-com4
void W1622_success(u8 SEG,u8 cnt,u8 *p);//单个段式数码管连续刷新
void disp_renew(void);   //显示更新,所有8x32段全部刷新
void  dispON(u8 com,u8 SEG);//更具真值表上的位置显示对应com，seg上的数据。
void dispOFF(u8 com,u8 SEG);
void  cleandisp(void);//全部清空函数
void disp_All(void);//全显函数
void HT1621Wr_Num(unsigned char Data,u8 addr,u8 Seg_flag,u8 Com_flag );
void HT1621Wr_Nums(unsigned char Data,u8 addr,u8 Seg_flag,u8 Com_flag );

#endif
