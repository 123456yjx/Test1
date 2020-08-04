
#include "bsp_ht1622.h"
#include "bsp_delay.h"
#include "bsp_printf.h"


unsigned char DIS_BUF1[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};//��ʾ������
const unsigned char  Num1_8[10]={0xFA,0x60,0xD6,0xF4,0x6C,0xBC,0xBE,0xE0,0xFE,0xFC};
const unsigned char  Num9_16[10]={0xF5,0x60,0xB6,0xF2,0x63,0xD3,0xD7,0x70,0xF7,0xF3};   //0~~~~9; 
const unsigned char  Num17_18[10]={0x5F,0x50,0x3D,0x79,0x72,0x6B,0x6F,0x51,0x7F,0x7B};
const unsigned char  Num19_20[10]={0xFA,0x0A,0xBC,0x9E,0x4E,0xD6,0xF6,0x8A,0xFE,0xDE};//0~~~~~9;
/******************************����С�������ʾ***********************************/
const unsigned char  Nums1_8[10]={0xFB,0x61,0xD7,0xF5,0x6D,0xBD,0xBF,0xE1,0xFF,0xFD};
const unsigned char  Nums9_16[10]={0xFD,0x68,0xBE,0xFA,0x6B,0xDB,0xDF,0x78,0xFF,0xFB};   //0~~~~9; 
const unsigned char  Nums17_18[10]={0xDF,0xD0,0xBD,0xF9,0xF2,0xEB,0xEF,0xD1,0xFF,0xFB};
const unsigned char  Nums19_20[10]={0xFB,0x0B,0xBD,0x9F,0x4F,0xD7,0xF7,0x8B,0xFF,0xDF};//0~~~~~9;
unsigned char   dispram[32];    //8x32   
 

void HT1622_Init(void)
{
	u8  j = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // IO��ʱ��ʹ��
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_7;  //��ʼ������IO��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO ������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //IO ����ģʽ �������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_SetBits(GPIOA,GPIO_Pin_4);

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  //��ʼ������IO��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO ������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //IO ����ģʽ �������
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	for(j=0; j<32; j++)
	{
			DIS_BUF1[j] = 0;
	}
	Sendcmd(RC32K);  //RC32kϵͳʱ��Դ��Ƭ��RC����
	Sendcmd(SYSEN);//��ϵͳ����
	Sendcmd(LCDON);  //�� LCDƫѹ������
	
	Sendcmd(RC32K);  //RC32kϵͳʱ��Դ��Ƭ��RC����
	Sendcmd(SYSEN);//��ϵͳ����
	Sendcmd(LCDON);  //�� LCDƫѹ������
}

void HT1622_R(void)//������
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // IO��ʱ��ʹ��
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;  //��ʼ������IO��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   //IO ����ģʽ ��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void HT1622_W(void)//д����
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // IO��ʱ��ʹ��
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;  //��ʼ������IO��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO ������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //IO ����ģʽ �������
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/**********************************************************
 * ������ : LCD_Wr_Clk
 * ����   ��none
 * ���   ��none 
 * ����   ��дʱ������
 **********************************************************/
void LCD_Wr_Clk(void) 
{ 
	HT1622_WR_SCK_L;
	delay_us(2);
	HT1622_WR_SCK_H;
	delay_us(2);
} 

/**********************************************************
 * ������ : LCD_Rd_Clk
 * ����   ��none
 * ���   ��none 
 * ����   ����ʱ������
 **********************************************************/
void LCD_Rd_Clk(void) 
{ 
	HT1622_RD_SCK_L;
	delay_us(2);
	HT1622_RD_SCK_H;
	delay_us(2);
} 

/**********************************************************
 * ������ : SendBit_HL//д��ַ
 * ����   ��dat ����/���� cnt ����λ
 * ���   ��none 
 * ����   ��dat �ĸ�cnt λд��HT1622���ȷ��͸�λ
 **********************************************************/
void SendBit_HL(u8 dat,u8 cnt) //
{
    u8 i;
    for(i=0; i<cnt;i++)
    {
			if(dat&0x80)
			{
					HT1622_DAT_H;
			}
			else
			{
					HT1622_DAT_L;
			}
			LCD_Wr_Clk();
			dat <<= 1;//��������1λ
    }
}
/**********************************************************
 * ������ : SendBit_LHд����
 * ����   ��dat ����/���� cnt ����λ
 * ���   ��none 
 * ����   ��dat �ĵ�cnt λд��HT1622���ȷ��͵�λ
 **********************************************************/
void  SendBit_LH(u8  dat,u8 cnt)
{
	u8 i;
	for(i=0; i<cnt;i++)
	{
			if(dat&0x01)
			{
					HT1622_DAT_H;
			}
			else
			{
					HT1622_DAT_L;
			}
			LCD_Wr_Clk();
			dat >>= 1;//��������1λ
	}
}

/**********************************************************
 * ������ : ReceiveBit_LH
 * ����   ��
 * ���   ��none 
 * ����   ����ȡcom��״̬//
 **********************************************************/
u8  ReceiveBit_LH(void)
{
	u8 i;
	u8 j=0x01;
	u8 dat=0x00;
	HT1622_R();//���ó�����ģʽ��ȡcom��״̬
	for(i=0;i<4;i++)
	{   
		  LCD_Rd_Clk();
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==1)
			{
					dat|=j;
			}
			else
			{
				dat&=~j;
			}
			j<<=1;
	}
return dat;
}

/**********************************************************
 * ������ : Sendcmd
 * ����   ��command ����
 * ���   ��none 
 * ����   ��ָ��ģʽ
 **********************************************************/
void  Sendcmd(u8  command)
{
    HT1622_CS_L;
    SendBit_HL(0x80,3);     //д���־��"100"
    SendBit_HL(command,9);  //д�� 9 λ����,����ǰ 8 λΪ command ����,��� 1 λ����
    HT1622_CS_H;
}
/**********************************************************
 * ������ : W1622_q
 * ����   ��addr ��ַ dat ����//д����
 * ���   ��none 
 * ����   ��ָ��ģʽ
 **********************************************************/
void W1622_q(u8 addr,u8 dat)
{  
    HT1622_CS_L;
	 // dat<<=4;//��ַ������λ��
    SendBit_HL(0xa0,3); //д���־��"101"����λ��Ч
    SendBit_HL(addr<<2,6); //���Ƚ�ʵ�ʵ�ַŲ����λ��д�� 6 λ addr,��6λ��Ч��
	
    SendBit_LH(dat,4); //д���4λ����
    HT1622_CS_H;
}

	
/**********************************************************
 * ������ : W1622_byte
 * ����   ��SEG ��ַ dat ����
 * ���   ��none 
 * ����   ��дSEG�������е�λ��SEG( 0~31 )
 **********************************************************/
void  W1622_byte(u8 SEG,u8 dat)//��ʾ��λ
{
    u8 i,addr;
    addr = SEG * 2;
	
    for(i=0;i<2;i++)
    {
			W1622_q(addr,dat);
			addr += 1;
			dat >>= 4;
    }
}

/**********************************************************
 * ������ : W1622_q
 * ����   ��addr ��ַ dat ����
 * ���   ��none 
 * ����   ��ָ��ģʽ//
 **********************************************************/
u8 W1622_Read_byte(u8 addr)
{
	 u8 i=0;
	 u8 dat=0;
	 for(i=0;i<2;i++)
		{
			HT1622_CS_L;
			SendBit_HL(0xc0,3);    //д���־��"110"
			SendBit_HL(addr<<2,6); //д�� 6 λ addr
			dat|=ReceiveBit_LH();  //������4λ����
			HT1622_CS_H;
			dat<<=4;
		}
	 return dat;
}
/**********************************************************
 * ������ : W1622_READ_MODIFY_WRITE 
* ����   �� dat����Ҫд�������;  SEG��λѡ��(0~32)�� flag��com�ı�־λ��0: Com0~com3,1:com4~com7:
 * ���   ��none 
 * ����   ����дͬʱ���У���ʾ��ֵ���ϵ�����;
 **********************************************************/

void W1622_READ_MODIFY_WRITE(u8 dat,u8 SEG,u8 flag)//��ʾcom1-com4������
{
   u8 addr,temp;
   u8 addr_1;	
   addr = SEG * 2;//��ȳ���2
	 if(flag==0)
	 {
			addr_1=addr;
			temp=dat;
			temp&=ReceiveBit_LH();
			W1622_q(addr_1,dat);//������
			addr +=2;//��ַ��1
			temp=dat>>4;//��ȡд�����ݸ�4λ	
			temp&=ReceiveBit_LH();//��ȡCOM8��״̬
			HT1622_W();//�������ݶ˿�Ϊ���ģʽ
			W1622_q(addr,temp);//д������
	 }
	 else  // ��ʾcom5-com8������
	 {
			 addr_1=addr+1;
			 temp=dat;
			 temp&=ReceiveBit_LH();
			 W1622_q(addr_1,dat);//������
			 addr +=3;//��ַ��1
			 temp=dat>>4;//��ȡд�����ݸ�4λ	
			 temp&=ReceiveBit_LH();//��ȡCOM8��״̬
			 HT1622_W();//�������ݶ˿�Ϊ���ģʽ
			 W1622_q(addr,temp);//д������
	 }
}

/**********************************************************
 * ������ : W1622_Write_Seg (com1-com4)
 **********************************************************/
void W1622_Write_Seg(u8 SEG,u8 dat)
{
  u8 addr;
	u8 data=0x0f;
	u8 dat_1=dat;
  addr = SEG * 2;
	SendBit_HL(0xa0,3);    //д���־��"101"
  SendBit_HL((addr+1)<<2,6);//д�� 6 λ addr
	dat_1&=0x01;//��ȡд�����ݵ�λ
	data&=ReceiveBit_LH();//��ȡCOM�ڸ�4λ״̬
	HT1622_W();       //�������ݶ˿�Ϊ���ģʽ
	W1622_q(addr,dat);//д������
}

/**********************************************************
 * ������ : W1622_success
 * ����   ��
 * ���   ��none 
 * ����   ������д��Ԫ SEG(0~31)//������ʽ���������ˢ��
 **********************************************************/
void W1622_success(u8 SEG,u8 cnt,u8 *p)
{
    u8 i,addr;
    addr = SEG * 2;
    HT1622_CS_L;
    SendBit_HL(0xa0,3);    //д���־��"101"
    SendBit_HL(addr<<2,6); //д�� 6 λ addr
    for(i =0; i<cnt;i++)
    {
			SendBit_LH(*p,4);
			SendBit_LH(*p>>4,4);
		  p++;
    }
    HT1622_CS_H;
}



void disp_renew(void)   //��ʾ����,����8x32��ȫ��ˢ��
{
    W1622_success(0,32,(u8*)DIS_BUF1);
}

/*************************************************************************************
//������ֵ���ϵ�λ����ʾ��Ӧcom��seg�ϵ����ݡ�
//com(0-7)  SEG(0-31)
***************************************************************************************/
void  dispON(u8 com,u8 SEG)
{
	  dispram[SEG] |= (1<<com);
    W1622_byte(SEG,dispram[SEG]);     //ȥ��ע�ͺ�д���������ʾ
}
void dispOFF(u8 com,u8 SEG)
{
		dispram[SEG]&=~(1<<com);
	  W1622_byte(SEG,dispram[SEG]);//ȥ��ע�ͺ�д����������
}

/****************************************************************************************
ȫ����պ���
******************************************************************************************/
void  cleandisp(void)
{
    u8  i;
    HT1622_CS_L;           //����Ļ
    SendBit_HL(0xa0,3);    //д���־��"101"
    SendBit_HL(0,6);       //д�� 6 λ addr
    for(i =0; i <32; i++)  //����д������
    {
        SendBit_LH(0,4);
        SendBit_LH(0,4);
    }
    HT1622_CS_H;
    for(i=0; i<32; i++)
    {
       DIS_BUF1[i] = 0x00;    //����Դ�
    }
}


/****************************************************************************************
ȫ����ʾ����
******************************************************************************************/
void  disp_All(void)
{
    u8  i;
    HT1622_CS_L;           //ȫ��ʾ��Ļ
    SendBit_HL(0xa0,3);    //д���־��"101"
    SendBit_HL(0,6);       //д�� 6 λ addr
    for(i =0; i <32; i++)  //����д������
    {
        SendBit_LH(0xFF,4);
        SendBit_LH(0xFF,4);
    }
    HT1622_CS_H;
    for(i=0; i<32; i++)
    {
       DIS_BUF1[i] = 0xFF;    //����Դ�
    }    
  
}


/****************************************************************************************
��ʾ���ݺ���
 * ������ : HT1621Wr_Num
 * ����   ��Data�����ڲɼ������ݣ�       
            addr��Ϊ��Ӧ����ĵ�ַ��0��Num1_8��1��Num9_16��2��Num17_18��3��Num19_20
            Seg_flag����Ӧ W1622_READ_MODIFY_WRITE������Segλ�ã���1~32��
            Com_flag��Ϊ��Ӧ W1622_READ_MODIFY_WRITE������COMλ�ã�0��0~3��1��4~5
 * ���   ��none 
 * ����   ����ʾ����С���������
******************************************************************************************/
void HT1621Wr_Num(unsigned char Data,u8 addr,u8 Seg_flag,u8 Com_flag )
{
	if(addr==0)
		{
				switch(Data)
				{
						case 0:
										W1622_READ_MODIFY_WRITE(Num1_8[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Num1_8[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Num1_8[2],Seg_flag,Com_flag);
										break;
						case 3:
										W1622_READ_MODIFY_WRITE(Num1_8[3],Seg_flag,Com_flag);
										break;
						case 4:
									  W1622_READ_MODIFY_WRITE(Num1_8[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Num1_8[5],Seg_flag,Com_flag);
									  break;
						case 6:
								    W1622_READ_MODIFY_WRITE(Num1_8[6],Seg_flag,Com_flag);
									  break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Num1_8[7],Seg_flag,Com_flag);
									  break;
						case 8:
									  W1622_READ_MODIFY_WRITE(Num1_8[8],Seg_flag,Com_flag);
								 	  break;
						case 9:
									  W1622_READ_MODIFY_WRITE(Num1_8[9],Seg_flag,Com_flag);
								    break;
						case '-':
							      W1622_READ_MODIFY_WRITE(0x04,Seg_flag,Com_flag);
						        break;
				}
		}
		else if(addr==1)
		{
		    switch(Data)
				{
						case 0:
										W1622_READ_MODIFY_WRITE(Num9_16[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Num9_16[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Num9_16[2],Seg_flag,Com_flag);
										break;
						case 3:
										W1622_READ_MODIFY_WRITE(Num9_16[3],Seg_flag,Com_flag);
										break;
						case 4:
									  W1622_READ_MODIFY_WRITE(Num9_16[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Num9_16[5],Seg_flag,Com_flag);
									  break;
						case 6:
									  W1622_READ_MODIFY_WRITE(Num9_16[6],Seg_flag,Com_flag);
									  break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Num9_16[7],Seg_flag,Com_flag);
								 	  break;
						case 8:
							  	  W1622_READ_MODIFY_WRITE(Num9_16[8],Seg_flag,Com_flag);
									  break;
						case 9:
								    W1622_READ_MODIFY_WRITE(Num9_16[9],Seg_flag,Com_flag);
							  	  break;
						case '-':
							      W1622_READ_MODIFY_WRITE(0x02,Seg_flag,Com_flag);
						        break;
				}
		}
		else if(addr==2)
		{
			  switch(Data)
				{
						case 0:
										W1622_READ_MODIFY_WRITE(Num17_18[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Num17_18[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Num17_18[2],Seg_flag,Com_flag);
										break;
						case 3:
								 	  W1622_READ_MODIFY_WRITE(Num17_18[3],Seg_flag,Com_flag);
									  break;
						case 4:
								    W1622_READ_MODIFY_WRITE(Num17_18[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Num17_18[5],Seg_flag,Com_flag);
								    break;
						case 6:
									  W1622_READ_MODIFY_WRITE(Num17_18[6],Seg_flag,Com_flag);
									  break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Num17_18[7],Seg_flag,Com_flag);
								    break;
						case 8:
								    W1622_READ_MODIFY_WRITE(Num17_18[8],Seg_flag,Com_flag);
								    break;
						case 9:
								    W1622_READ_MODIFY_WRITE(Num17_18[9],Seg_flag,Com_flag);
								    break;
						case '-':
								    W1622_READ_MODIFY_WRITE(0x20,Seg_flag,Com_flag);
								    break;
				}
		}
		else if(addr==3)
		{
			  switch(Data)
				{
						case 0: 
									  W1622_READ_MODIFY_WRITE(Num19_20[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Num19_20[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Num19_20[2],Seg_flag,Com_flag);
										break;
						case 3:
										W1622_READ_MODIFY_WRITE(Num19_20[3],Seg_flag,Com_flag);
										break;
						case 4:
									  W1622_READ_MODIFY_WRITE(Num19_20[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Num19_20[5],Seg_flag,Com_flag);
									  break;
						case 6:
									  W1622_READ_MODIFY_WRITE(Num19_20[6],Seg_flag,Com_flag);
								  	break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Num19_20[7],Seg_flag,Com_flag);
									  break;
						case 8:
								  	W1622_READ_MODIFY_WRITE(Num19_20[8],Seg_flag,Com_flag);
									  break;
						case 9:
								    W1622_READ_MODIFY_WRITE(Num19_20[9],Seg_flag,Com_flag);
								    break;
						case '-':
								    W1622_READ_MODIFY_WRITE(0x04,Seg_flag,Com_flag);
								    break;
				}
		
		}
		
}

/****************************************************************************************
��ʾ���ݺ���
 * ������ : HT1621Wr_Num
 * ����   ��Data�����ڲɼ������ݣ�       
            addr��Ϊ��Ӧ����ĵ�ַ��0��Nums1_8��1��Nums9_16��2��Nums17_18��3��Nums19_20
            Seg_flag����Ӧ W1622_READ_MODIFY_WRITE������Segλ�ã���1~32��
            Com_flag��Ϊ��Ӧ W1622_READ_MODIFY_WRITE������COMλ�ã�0��0~3��1��4~5
 * ���   ��none 
 * ����   ����ʾ����С���������
******************************************************************************************/
void HT1621Wr_Nums(unsigned char Data,u8 addr,u8 Seg_flag,u8 Com_flag )
{
	  if(addr==0)
		{
				switch(Data)
				{
						case 0:
										W1622_READ_MODIFY_WRITE(Nums1_8[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Nums1_8[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Nums1_8[2],Seg_flag,Com_flag);
										break;
						case 3:
										W1622_READ_MODIFY_WRITE(Nums1_8[3],Seg_flag,Com_flag);
										break;
						case 4:
									  W1622_READ_MODIFY_WRITE(Nums1_8[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Nums1_8[5],Seg_flag,Com_flag);
									  break;
						case 6:
								    W1622_READ_MODIFY_WRITE(Nums1_8[6],Seg_flag,Com_flag);
									  break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Nums1_8[7],Seg_flag,Com_flag);
									  break;
						case 8:
									  W1622_READ_MODIFY_WRITE(Nums1_8[8],Seg_flag,Com_flag);
								 	  break;
						case 9:
									  W1622_READ_MODIFY_WRITE(Nums1_8[9],Seg_flag,Com_flag);
								    break;
				}
		}
		else if(addr==1)
		{
		    switch(Data)
				{
						case 0:
										W1622_READ_MODIFY_WRITE(Nums9_16[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Nums9_16[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Nums9_16[2],Seg_flag,Com_flag);
										break;
						case 3:
										W1622_READ_MODIFY_WRITE(Nums9_16[3],Seg_flag,Com_flag);
										break;
						case 4:
									  W1622_READ_MODIFY_WRITE(Nums9_16[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Nums9_16[5],Seg_flag,Com_flag);
									  break;
						case 6:
									  W1622_READ_MODIFY_WRITE(Nums9_16[6],Seg_flag,Com_flag);
									  break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Nums9_16[7],Seg_flag,Com_flag);
								 	  break;
						case 8:
							  	  W1622_READ_MODIFY_WRITE(Nums9_16[8],Seg_flag,Com_flag);
									  break;
						case 9:
								    W1622_READ_MODIFY_WRITE(Nums9_16[9],Seg_flag,Com_flag);
							  	  break;
				}
		}
		else if(addr==2)
		{
			  switch(Data)
				{
						case 0:
										W1622_READ_MODIFY_WRITE(Nums17_18[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Nums17_18[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Nums17_18[2],Seg_flag,Com_flag);
										break;
						case 3:
								 	  W1622_READ_MODIFY_WRITE(Nums17_18[3],Seg_flag,Com_flag);
									  break;
						case 4:
								    W1622_READ_MODIFY_WRITE(Nums17_18[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Nums17_18[5],Seg_flag,Com_flag);
								    break;
						case 6:
									  W1622_READ_MODIFY_WRITE(Nums17_18[6],Seg_flag,Com_flag);
									  break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Nums17_18[7],Seg_flag,Com_flag);
								    break;
						case 8:
								    W1622_READ_MODIFY_WRITE(Nums17_18[8],Seg_flag,Com_flag);
								    break;
						case 9:
								    W1622_READ_MODIFY_WRITE(Nums17_18[9],Seg_flag,Com_flag);
								    break;
				}
		}
		else if(addr==3)
		{
			  switch(Data)
				{
						case 0: 
									  W1622_READ_MODIFY_WRITE(Nums19_20[0],Seg_flag,Com_flag);
										break;
						case 1:
										W1622_READ_MODIFY_WRITE(Nums19_20[1],Seg_flag,Com_flag);
										break;
						case 2:
										W1622_READ_MODIFY_WRITE(Nums19_20[2],Seg_flag,Com_flag);
										break;
						case 3:
										W1622_READ_MODIFY_WRITE(Nums19_20[3],Seg_flag,Com_flag);
										break;
						case 4:
									  W1622_READ_MODIFY_WRITE(Nums19_20[4],Seg_flag,Com_flag);
									  break;
						case 5:
									  W1622_READ_MODIFY_WRITE(Nums19_20[5],Seg_flag,Com_flag);
									  break;
						case 6:
									  W1622_READ_MODIFY_WRITE(Nums19_20[6],Seg_flag,Com_flag);
								  	break;
						case 7:
									  W1622_READ_MODIFY_WRITE(Nums19_20[7],Seg_flag,Com_flag);
									  break;
						case 8:
								  	W1622_READ_MODIFY_WRITE(Nums19_20[8],Seg_flag,Com_flag);
									  break;
						case 9:
								    W1622_READ_MODIFY_WRITE(Nums19_20[9],Seg_flag,Com_flag);
								    break;
				}
		
		}
		
}
