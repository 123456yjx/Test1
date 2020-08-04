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
///* #define HC165_SCLK_PORT P1 // ʹ�õ���P1�� */
///* #define HC165_SCLK_BIT BIT5 // BIT5λ */
///* BIT_OUT( HC165_SCLK ); // ����P1.5λ��� */
//unsigned char DIS_BUF[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};//��ʾ������
////����� 0 1 2 3 4 5 6 7 8 9 A b C d E F - _ ��
//const unsigned char DIS[]={0xBF,0x06,0x7C,0x5E,0xC6,0xDA,0xFA,0x0E,0xFE,0xDE,0xEE,0xF2,0xB8,0x76,0xF8,0xE8,0x40,0x10,0x00};
///*****************************************************************

//	�����ܽŷ��� CS P1.0 WR P1.1 DAT P1.2

//*****************************************************************/

//#define HT1621_CS_PORT P1 //HT1621ʹ������
//#define HT1621_CS_BIT BIT0 //HT1621ʹ������
//#define HT1621_WR_PORT P1 //HT1621ʱ������
//#define HT1621_WR_BIT BIT1 //HT1621ʱ������
//#define HT1621_DAT_PORT P1 //HT1621��������
//#define HT1621_DAT_BIT BIT2 //HT1621��������
//	����/*****************************************************************

//	����HT1622 �ײ����� Data ���� Length ���ݳ���

//	����*****************************************************************/

//	����void Write_HT1622_Byte(unsigned char Data,unsigned char Length)

//	����{

//	����unsigned char i,Temp=0x80;

//	����for (i=0;i<length;i++) </length;i++)

//	����{

//	����CLR_BIT ( HT1621_WR ); //��д��ʱ����0

//	����if (Data&Temp)

//	����SET_BIT ( HT1621_DAT );//��������1

//	����else

//	����CLR_BIT ( HT1621_DAT );//��������0

//	����Temp>>=1; //׼����һλ

//	����SET_BIT ( HT1621_WR ); //��д��ʱ����1

//	����}

//	����}

//	����/*****************************************************************

//	����HT1622д�����ݺ��� Address д���ݵ�ַ Data ����

//	����*****************************************************************/

//	����void Write_HT1622_Data(unsigned char Address,unsigned char Data)

//	����{

//	����CLR_BIT ( HT1621_CS ); //Ƭѡ��0

//	����Address <<= 2; //��ʵ�ʵ�ַŲ����λ

//	����Data <<= 4; //��ʵ������Ų����λ

//	����Write_HT1622_Byte(0xA0,3); //д��д���ݵ�ID 101 ��3λ��Ч

//	����Write_HT1622_Byte(Address,6);//д��6��λ��ʼ��ַ ��6λ��Ч

//	����Write_HT1622_Byte(Data,4); //д��4��λ���� ��4λ��Ч

//	����SET_BIT ( HT1621_CS ); //Ƭѡ��1

//	����}

//	����/*****************************************************************

//	����//HT1622д����� Command ����

//	����*****************************************************************/

//	����void Write_HT1622_Command(unsigned char Command)

//	����{

//	����CLR_BIT ( HT1621_CS ); //Ƭѡ��0

//	����Write_HT1622_Byte(0x80,3); //д�������ID:100

//	����Write_HT1622_Byte(Command,8);//д��ʵ������ĸ�8λ(CMD.):C8-C1

//	����SET_BIT ( HT1621_DAT ); //|д��һ����1�����ֲ�����ָ���޹�λ������һ������λ

//	����CLR_BIT ( HT1621_WR ); //|

//	����_NOP();_NOP();_NOP(); //|

//	����SET_BIT ( HT1621_WR ); //|

//	����SET_BIT ( HT1621_CS ); //Ƭѡ��1

//	����}

//	����/*****************************************************************

//	������ʾ���ֺ��� *Data��ʾ����ָ�� Address ��ʾ��λ�� Length���ݳ���

//	����*****************************************************************/

//	����void Display(unsigned char *Data,unsigned char Address,unsigned char Length)

//	����{

//	����unsigned char i = 0,Temp=0x0F;

//	����unsigned char ADDH,ADDL;

//	����for(;i<length;i++) </length;i++)

//	����{

//	����Temp=DIS[*Data]; //���ݽ���

//	����ADDL = Address*2; //��4λ��ַ����

//	����ADDL = ADDL*2+2-(ADDL/31)*59; //��4λ��ַ����

//	����Write_HT1622_Data(ADDL,Temp&0x0F);//д��4λ����

//	����ADDH = Address*2-1; //��4λ��ַ����

//	����ADDH = ADDH*2+2-(ADDH/31)*59; //��4λ��ַ����

//	����Temp>>=4; //��4λ���ݽ���

//	����Write_HT1622_Data(ADDH,Temp&0x0F);//д��4λ����

//	����Data ++; //��ʾ����ָ����һ

//	����Address ++; //��ʾ��ַ��һ

//	����}

//	����}

//	����/*****************************************************************

//	���������� ����������ʾ 0��E

//	����*****************************************************************/

//	����void main(void)

//	����{

//	����WDTCTL = WDTPW + WDTHOLD; //�ؿ��Ź�

//	����BIT_OUT ( HT1621_DAT ); //|IO�ڳ�ʼ��

//	����BIT_OUT ( HT1621_CS ); //|

//	����BIT_OUT ( HT1621_WR ); //|

//	����SET_BIT ( HT1621_CS ); //|

//	����SET_BIT ( HT1621_WR ); //|

//	����SET_BIT ( HT1621_DAT ); //|

//	����Write_HT1622_Command(SYSDIS);//�ر�ϵͳ������LCD����

//	����Write_HT1622_Command(SYSEN); //��ϵͳ����

//	����Write_HT1622_Command(LCDOFF);//�ر�LCD��ʾ

//	Write_HT1622_Command(LCDON); //��LCD��ʾ

//	����Display(DIS_BUF,1,15); //��ʾ0��E ��һ��

//	����Display(DIS_BUF,16,15); //��ʾ0��E �ڶ���

//	����while(1);

//	����}