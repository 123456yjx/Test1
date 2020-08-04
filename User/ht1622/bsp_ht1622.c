
#include "bsp_ht1622.h"
#include "bsp_delay.h"
#include "bsp_printf.h"


unsigned char DIS_BUF1[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};//显示缓冲区
const unsigned char  Num1_8[10]={0xFA,0x60,0xD6,0xF4,0x6C,0xBC,0xBE,0xE0,0xFE,0xFC};
const unsigned char  Num9_16[10]={0xF5,0x60,0xB6,0xF2,0x63,0xD3,0xD7,0x70,0xF7,0xF3};   //0~~~~9; 
const unsigned char  Num17_18[10]={0x5F,0x50,0x3D,0x79,0x72,0x6B,0x6F,0x51,0x7F,0x7B};
const unsigned char  Num19_20[10]={0xFA,0x0A,0xBC,0x9E,0x4E,0xD6,0xF6,0x8A,0xFE,0xDE};//0~~~~~9;
/******************************加有小数点的显示***********************************/
const unsigned char  Nums1_8[10]={0xFB,0x61,0xD7,0xF5,0x6D,0xBD,0xBF,0xE1,0xFF,0xFD};
const unsigned char  Nums9_16[10]={0xFD,0x68,0xBE,0xFA,0x6B,0xDB,0xDF,0x78,0xFF,0xFB};   //0~~~~9; 
const unsigned char  Nums17_18[10]={0xDF,0xD0,0xBD,0xF9,0xF2,0xEB,0xEF,0xD1,0xFF,0xFB};
const unsigned char  Nums19_20[10]={0xFB,0x0B,0xBD,0x9F,0x4F,0xD7,0xF7,0x8B,0xFF,0xDF};//0~~~~~9;
unsigned char   dispram[32];    //8x32   
 

void HT1622_Init(void)
{
	u8  j = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // IO口时钟使能
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_7;  //初始化具体IO口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO 口速率
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //IO 工作模式 推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_SetBits(GPIOA,GPIO_Pin_4);

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB , ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  //初始化具体IO口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO 口速率
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //IO 工作模式 推挽输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	for(j=0; j<32; j++)
	{
			DIS_BUF1[j] = 0;
	}
	Sendcmd(RC32K);  //RC32k系统时钟源，片上RC振荡器
	Sendcmd(SYSEN);//打开系统振荡器
	Sendcmd(LCDON);  //打开 LCD偏压发生器
	
	Sendcmd(RC32K);  //RC32k系统时钟源，片上RC振荡器
	Sendcmd(SYSEN);//打开系统振荡器
	Sendcmd(LCDON);  //打开 LCD偏压发生器
}

void HT1622_R(void)//读数据
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // IO口时钟使能
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;  //初始化具体IO口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   //IO 工作模式 上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void HT1622_W(void)//写数据
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // IO口时钟使能
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_6;  //初始化具体IO口
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO 口速率
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //IO 工作模式 推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
/**********************************************************
 * 函数名 : LCD_Wr_Clk
 * 输入   ：none
 * 输出   ：none 
 * 功能   ：写时钟脉冲
 **********************************************************/
void LCD_Wr_Clk(void) 
{ 
	HT1622_WR_SCK_L;
	delay_us(2);
	HT1622_WR_SCK_H;
	delay_us(2);
} 

/**********************************************************
 * 函数名 : LCD_Rd_Clk
 * 输入   ：none
 * 输出   ：none 
 * 功能   ：读时钟脉冲
 **********************************************************/
void LCD_Rd_Clk(void) 
{ 
	HT1622_RD_SCK_L;
	delay_us(2);
	HT1622_RD_SCK_H;
	delay_us(2);
} 

/**********************************************************
 * 函数名 : SendBit_HL//写地址
 * 输入   ：dat 数据/命令 cnt 数据位
 * 输出   ：none 
 * 功能   ：dat 的高cnt 位写入HT1622，先发送高位
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
			dat <<= 1;//数据左移1位
    }
}
/**********************************************************
 * 函数名 : SendBit_LH写数据
 * 输入   ：dat 数据/命令 cnt 数据位
 * 输出   ：none 
 * 功能   ：dat 的低cnt 位写入HT1622，先发送低位
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
			dat >>= 1;//数据右移1位
	}
}

/**********************************************************
 * 函数名 : ReceiveBit_LH
 * 输入   ：
 * 输出   ：none 
 * 功能   ：读取com口状态//
 **********************************************************/
u8  ReceiveBit_LH(void)
{
	u8 i;
	u8 j=0x01;
	u8 dat=0x00;
	HT1622_R();//配置成输入模式读取com口状态
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
 * 函数名 : Sendcmd
 * 输入   ：command 命令
 * 输出   ：none 
 * 功能   ：指令模式
 **********************************************************/
void  Sendcmd(u8  command)
{
    HT1622_CS_L;
    SendBit_HL(0x80,3);     //写入标志码"100"
    SendBit_HL(command,9);  //写入 9 位数据,其中前 8 位为 command 命令,最后 1 位任意
    HT1622_CS_H;
}
/**********************************************************
 * 函数名 : W1622_q
 * 输入   ：addr 地址 dat 数据//写数据
 * 输出   ：none 
 * 功能   ：指令模式
 **********************************************************/
void W1622_q(u8 addr,u8 dat)
{  
    HT1622_CS_L;
	 // dat<<=4;//地址左移四位，
    SendBit_HL(0xa0,3); //写入标志码"101"高三位有效
    SendBit_HL(addr<<2,6); //现先将实际地址挪到高位，写入 6 位 addr,高6位有效，
	
    SendBit_LH(dat,4); //写入低4位数据
    HT1622_CS_H;
}

	
/**********************************************************
 * 函数名 : W1622_byte
 * 输入   ：SEG 地址 dat 数据
 * 输出   ：none 
 * 功能   ：写SEG脚上所有的位，SEG( 0~31 )
 **********************************************************/
void  W1622_byte(u8 SEG,u8 dat)//显示单位
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
 * 函数名 : W1622_q
 * 输入   ：addr 地址 dat 数据
 * 输出   ：none 
 * 功能   ：指令模式//
 **********************************************************/
u8 W1622_Read_byte(u8 addr)
{
	 u8 i=0;
	 u8 dat=0;
	 for(i=0;i<2;i++)
		{
			HT1622_CS_L;
			SendBit_HL(0xc0,3);    //写入标志码"110"
			SendBit_HL(addr<<2,6); //写入 6 位 addr
			dat|=ReceiveBit_LH();  //读出低4位数据
			HT1622_CS_H;
			dat<<=4;
		}
	 return dat;
}
/**********************************************************
 * 函数名 : W1622_READ_MODIFY_WRITE 
* 输入   ： dat：需要写入的数据;  SEG：位选端(0~32)； flag：com的标志位，0: Com0~com3,1:com4~com7:
 * 输出   ：none 
 * 功能   ：读写同时进行，显示真值表上的数据;
 **********************************************************/

void W1622_READ_MODIFY_WRITE(u8 dat,u8 SEG,u8 flag)//显示com1-com4的内容
{
   u8 addr,temp;
   u8 addr_1;	
   addr = SEG * 2;//宽度乘以2
	 if(flag==0)
	 {
			addr_1=addr;
			temp=dat;
			temp&=ReceiveBit_LH();
			W1622_q(addr_1,dat);//读数据
			addr +=2;//地址加1
			temp=dat>>4;//获取写入数据高4位	
			temp&=ReceiveBit_LH();//读取COM8口状态
			HT1622_W();//设置数据端口为输出模式
			W1622_q(addr,temp);//写入数据
	 }
	 else  // 显示com5-com8的内容
	 {
			 addr_1=addr+1;
			 temp=dat;
			 temp&=ReceiveBit_LH();
			 W1622_q(addr_1,dat);//读数据
			 addr +=3;//地址加1
			 temp=dat>>4;//获取写入数据高4位	
			 temp&=ReceiveBit_LH();//读取COM8口状态
			 HT1622_W();//设置数据端口为输出模式
			 W1622_q(addr,temp);//写入数据
	 }
}

/**********************************************************
 * 函数名 : W1622_Write_Seg (com1-com4)
 **********************************************************/
void W1622_Write_Seg(u8 SEG,u8 dat)
{
  u8 addr;
	u8 data=0x0f;
	u8 dat_1=dat;
  addr = SEG * 2;
	SendBit_HL(0xa0,3);    //写入标志码"101"
  SendBit_HL((addr+1)<<2,6);//写入 6 位 addr
	dat_1&=0x01;//获取写入数据低位
	data&=ReceiveBit_LH();//读取COM口高4位状态
	HT1622_W();       //设置数据端口为输出模式
	W1622_q(addr,dat);//写入数据
}

/**********************************************************
 * 函数名 : W1622_success
 * 输入   ：
 * 输出   ：none 
 * 功能   ：连续写单元 SEG(0~31)//单个段式数码管连续刷新
 **********************************************************/
void W1622_success(u8 SEG,u8 cnt,u8 *p)
{
    u8 i,addr;
    addr = SEG * 2;
    HT1622_CS_L;
    SendBit_HL(0xa0,3);    //写入标志码"101"
    SendBit_HL(addr<<2,6); //写入 6 位 addr
    for(i =0; i<cnt;i++)
    {
			SendBit_LH(*p,4);
			SendBit_LH(*p>>4,4);
		  p++;
    }
    HT1622_CS_H;
}



void disp_renew(void)   //显示更新,所有8x32段全部刷新
{
    W1622_success(0,32,(u8*)DIS_BUF1);
}

/*************************************************************************************
//更具真值表上的位置显示对应com，seg上的数据。
//com(0-7)  SEG(0-31)
***************************************************************************************/
void  dispON(u8 com,u8 SEG)
{
	  dispram[SEG] |= (1<<com);
    W1622_byte(SEG,dispram[SEG]);     //去掉注释后，写完就马上显示
}
void dispOFF(u8 com,u8 SEG)
{
		dispram[SEG]&=~(1<<com);
	  W1622_byte(SEG,dispram[SEG]);//去掉注释后，写完就马上灭掉
}

/****************************************************************************************
全部清空函数
******************************************************************************************/
void  cleandisp(void)
{
    u8  i;
    HT1622_CS_L;           //清屏幕
    SendBit_HL(0xa0,3);    //写入标志码"101"
    SendBit_HL(0,6);       //写入 6 位 addr
    for(i =0; i <32; i++)  //连续写入数据
    {
        SendBit_LH(0,4);
        SendBit_LH(0,4);
    }
    HT1622_CS_H;
    for(i=0; i<32; i++)
    {
       DIS_BUF1[i] = 0x00;    //清空显存
    }
}


/****************************************************************************************
全部显示函数
******************************************************************************************/
void  disp_All(void)
{
    u8  i;
    HT1622_CS_L;           //全显示屏幕
    SendBit_HL(0xa0,3);    //写入标志码"101"
    SendBit_HL(0,6);       //写入 6 位 addr
    for(i =0; i <32; i++)  //连续写入数据
    {
        SendBit_LH(0xFF,4);
        SendBit_LH(0xFF,4);
    }
    HT1622_CS_H;
    for(i=0; i<32; i++)
    {
       DIS_BUF1[i] = 0xFF;    //清空显存
    }    
  
}


/****************************************************************************************
显示数据函数
 * 函数名 : HT1621Wr_Num
 * 输入   ：Data：串口采集的数据；       
            addr：为对应数组的地址，0：Num1_8；1：Num9_16；2：Num17_18；3：Num19_20
            Seg_flag：对应 W1622_READ_MODIFY_WRITE函数的Seg位置，（1~32）
            Com_flag：为对应 W1622_READ_MODIFY_WRITE函数的COM位置，0：0~3；1：4~5
 * 输出   ：none 
 * 功能   ：显示不带小数点的数据
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
显示数据函数
 * 函数名 : HT1621Wr_Num
 * 输入   ：Data：串口采集的数据；       
            addr：为对应数组的地址，0：Nums1_8；1：Nums9_16；2：Nums17_18；3：Nums19_20
            Seg_flag：对应 W1622_READ_MODIFY_WRITE函数的Seg位置，（1~32）
            Com_flag：为对应 W1622_READ_MODIFY_WRITE函数的COM位置，0：0~3；1：4~5
 * 输出   ：none 
 * 功能   ：显示带有小数点的数据
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
