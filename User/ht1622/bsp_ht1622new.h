//#include "bsp_ht1622.h"
//#define SET 1
//#define RESET 0
//#define _ADD_STR(a, b) a##b
//#define ADD_STR(a, b) _ADD_STR(a, b)
///* PxIN */
//#define _IO_PORT_IN(PORT) (PORT##IN)
//#define GPIO_READ_BITS(PORT, BIT) ( (_IO_PORT_IN(PORT) & BIT) ? (SET):(RESET))
//#define GOIO_READ_PORTS(PORT) ( _IO_PORT_IN(PORT) )
///* PxOUT */
//#define _IO_PORT_OUT(PORT) (PORT##OUT)
//#define GPIO_SET_BITS(PORT, BIT) ( ( _IO_PORT_OUT(PORT) ) |= (BIT) )
//#define GPIO_RESET_BITS(PORT, BIT) ( ( _IO_PORT_OUT(PORT) ) &= ~(BIT) )
///* PxDIR */
//#define _IO_PORT_DIR(PORT) (PORT##DIR)
//#define GPIO_OUTPUT_DIR(PORT, BIT) ( ( _IO_PORT_DIR(PORT) ) |= (BIT) )
//#define GPIO_INPUT_DIR(PORT, BIT) ( ( _IO_PORT_DIR(PORT) ) &= ~(BIT) )
///* PxIE */
//#define _IO_PORT_IE(PORT) (PORT##IE)
//#define GPIO_ENABLE_IRQ(PORT, BIT) ( ( _IO_PORT_IE(PORT) ) |= (BIT) )
//#define GPIO_DISABLE_IRQ(PORT, BIT) ( ( _IO_PORT_IE(PORT) ) &= ~(BIT) )
///* PxSEL */
//#define _IO_PORT_SEL(PORT) (PORT##SEL)
//#define GPIO_PORT_FUNC(PORT, BIT) ( ( _IO_PORT_SEL(PORT) ) |= (BIT) )
//#define GPIO_MULTI_FUNC(PORT, BIT) ( ( _IO_PORT_SEL(PORT) ) &= ~(BIT) )
///* ------------------ High layer function ----------------------------------- */
//#define TEST_BIT(x) ( GPIO_READ_BITS( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
////#define SET_BIT(x) ( GPIO_SET_BITS( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
//#define CLR_BIT(x) ( GPIO_RESET_BITS( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
//#define BIT_OUT(x) ( GPIO_OUTPUT_DIR( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
//#define BIT_IN(x) ( GPIO_INPUT_DIR( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
//#define EINT_BIT(x) ( GPIO_ENABLE_IRQ( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
//#define DINT_BIT(x) ( GPIO_DISABLE_IRQ( ADD_STR(x, _PORT), ADD_STR(x, _BIT) ) )
///* eg. */
///* #define HC165_SCLK_PORT P1 // 使用的是P1口 */
///* #define HC165_SCLK_BIT BIT5 // BIT5位 */
///* BIT_OUT( HC165_SCLK ); // 设置P1.5位输出 */
//unsigned char DIS_BUF[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};//显示缓冲区
////段码表 0 1 2 3 4 5 6 7 8 9 A b C d E F - _ 空
//const unsigned char DIS[]={0xBF,0x06,0x7C,0x5E,0xC6,0xDA,0xFA,0x0E,0xFE,0xDE,0xEE,0xF2,0xB8,0x76,0xF8,0xE8,0x40,0x10,0x00};
///*****************************************************************

//	　　管脚分配 CS P1.0 WR P1.1 DAT P1.2

//*****************************************************************/

//#define HT1621_CS_PORT P1 //HT1621使能引脚
//#define HT1621_CS_BIT BIT0 //HT1621使能引脚
//#define HT1621_WR_PORT P1 //HT1621时钟引脚
//#define HT1621_WR_BIT BIT1 //HT1621时钟引脚
//#define HT1621_DAT_PORT P1 //HT1621数据引脚
//#define HT1621_DAT_BIT BIT2 //HT1621数据引脚
//	　　/*****************************************************************

//	　　HT1622 底层驱动 Data 数据 Length 数据长度

//	　　*****************************************************************/

//	　　void Write_HT1622_Byte(unsigned char Data,unsigned char Length)

//	　　{

//	　　unsigned char i,Temp=0x80;

//	　　for (i=0;i<length;i++) </length;i++)

//	　　{

//	　　CLR_BIT ( HT1621_WR ); //“写”时钟置0

//	　　if (Data&Temp)

//	　　SET_BIT ( HT1621_DAT );//数据线置1

//	　　else

//	　　CLR_BIT ( HT1621_DAT );//数据线置0

//	　　Temp>>=1; //准备下一位

//	　　SET_BIT ( HT1621_WR ); //“写”时钟置1

//	　　}

//	　　}

//	　　/*****************************************************************

//	　　HT1622写入数据函数 Address 写数据地址 Data 数据

//	　　*****************************************************************/

//	　　void Write_HT1622_Data(unsigned char Address,unsigned char Data)

//	　　{

//	　　CLR_BIT ( HT1621_CS ); //片选置0

//	　　Address <<= 2; //将实际地址挪到高位

//	　　Data <<= 4; //将实际数据挪到高位

//	　　Write_HT1622_Byte(0xA0,3); //写入写数据的ID 101 高3位有效

//	　　Write_HT1622_Byte(Address,6);//写入6个位初始地址 高6位有效

//	　　Write_HT1622_Byte(Data,4); //写入4个位数据 高4位有效

//	　　SET_BIT ( HT1621_CS ); //片选置1

//	　　}

//	　　/*****************************************************************

//	　　//HT1622写命令函数 Command 命令

//	　　*****************************************************************/

//	　　void Write_HT1622_Command(unsigned char Command)

//	　　{

//	　　CLR_BIT ( HT1621_CS ); //片选置0

//	　　Write_HT1622_Byte(0x80,3); //写入命令的ID:100

//	　　Write_HT1622_Byte(Command,8);//写入实际命令的高8位(CMD.):C8-C1

//	　　SET_BIT ( HT1621_DAT ); //|写入一个“1”即手册上所指“无关位”的那一个数据位

//	　　CLR_BIT ( HT1621_WR ); //|

//	　　_NOP();_NOP();_NOP(); //|

//	　　SET_BIT ( HT1621_WR ); //|

//	　　SET_BIT ( HT1621_CS ); //片选置1

//	　　}

//	　　/*****************************************************************

//	　　显示数字函数 *Data显示内容指针 Address 显示首位置 Length内容长度

//	　　*****************************************************************/

//	　　void Display(unsigned char *Data,unsigned char Address,unsigned char Length)

//	　　{

//	　　unsigned char i = 0,Temp=0x0F;

//	　　unsigned char ADDH,ADDL;

//	　　for(;i<length;i++) </length;i++)

//	　　{

//	　　Temp=DIS[*Data]; //数据解析

//	　　ADDL = Address*2; //低4位地址解析

//	　　ADDL = ADDL*2+2-(ADDL/31)*59; //低4位地址解析

//	　　Write_HT1622_Data(ADDL,Temp&0x0F);//写低4位数据

//	　　ADDH = Address*2-1; //高4位地址解析

//	　　ADDH = ADDH*2+2-(ADDH/31)*59; //高4位地址解析

//	　　Temp>>=4; //高4位数据解析

//	　　Write_HT1622_Data(ADDH,Temp&0x0F);//写高4位数据

//	　　Data ++; //显示数据指针增一

//	　　Address ++; //显示地址增一

//	　　}

//	　　}

//	　　/*****************************************************************

//	　　主函数 上下两排显示 0到E

//	　　*****************************************************************/

//	　　void main(void)

//	　　{

//	　　WDTCTL = WDTPW + WDTHOLD; //关看门狗

//	　　BIT_OUT ( HT1621_DAT ); //|IO口初始化

//	　　BIT_OUT ( HT1621_CS ); //|

//	　　BIT_OUT ( HT1621_WR ); //|

//	　　SET_BIT ( HT1621_CS ); //|

//	　　SET_BIT ( HT1621_WR ); //|

//	　　SET_BIT ( HT1621_DAT ); //|

//	　　Write_HT1622_Command(SYSDIS);//关闭系统振荡器和LCD驱动

//	　　Write_HT1622_Command(SYSEN); //打开系统振荡器

//	　　Write_HT1622_Command(LCDOFF);//关闭LCD显示

//	Write_HT1622_Command(LCDON); //打开LCD显示

//	　　Display(DIS_BUF,1,15); //显示0到E 第一排

//	　　Display(DIS_BUF,16,15); //显示0到E 第二排

//	　　while(1);

//	　　}