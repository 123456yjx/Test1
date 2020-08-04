#include <string.h>
#include <math.h>
#include "bsp_menulayout.h"

 u8 Synbol=0;

void Voltage_DataPage_Menu(uint8_t Package_type,int Data)//��һҳ��ѹ
{
	  float Datas;
		W1622_READ_MODIFY_WRITE(0,12,0);
  	W1622_READ_MODIFY_WRITE(0,12,1);
		W1622_READ_MODIFY_WRITE(0,14,0);
  	W1622_READ_MODIFY_WRITE(0,14,1);
	  Datas=(float)Data/8192;
	  switch(Package_type)
	  {
	    case 1:	  /*A���ѹ*/
						 if(Datas<10)/*9.999*/
							{																	 
									Data=Datas*1000;																    
									HT1621Wr_Num(Data/1000,0,16,1);
									HT1621Wr_Nums(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);
							}else if(Datas<100)/*99.99*/
							{   																		
								  Data=Datas*100;									
									HT1621Wr_Num(Data/1000,0,16,1);
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Nums(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);                                    																	  
							}else if(Datas<1000)/*999.9*/
							{																    
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,0,16,1);
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Nums(Data%100%10,0,22,1);																	
							}else if(Datas<10000)/*9999*/
              {
									Data=Datas;
  								HT1621Wr_Num(Data/1000,0,16,1);
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);	
							}	
							break;	
	 	case 2:   /*B���ѹ*/   
		         if(Datas<10)/*9.999*/
							{																	 
									Data=Datas*1000;								
									HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Nums(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);
							}else if(Datas<100)/*99.99*/
							{   																		
								  Data=Datas*100;									
									HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Nums(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);                                   																	  
							}else if(Datas<1000)/*999.9*/
							{																    
									Data=Datas*10;
								  HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Nums(Data%100%10,0,22,0);																
							}else if(Datas<10000)/*9999*/
              {
									Data=Datas;
  						    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);
							}
			        break;
		case 3: /*C���ѹ*/ 
		          if(Datas<10)/*9.999*/
							{																	 
									Data=Datas*1000;								
									HT1621Wr_Num(Data/1000,1,4,0);
						    	HT1621Wr_Nums(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
						    	HT1621Wr_Num(Data%100%10,1,10,0);
							}else if(Datas<100)/*99.99*/
							{   																		
								  Data=Datas*100;							
									HT1621Wr_Num(Data/1000,1,4,0);
						     	HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Nums(Data/10%100%10,1,8,0);
							    HT1621Wr_Num(Data%100%10,1,10,0);                                   																	  
							}else if(Datas<1000)/*999.9*/
							{																    
									Data=Datas*10;
								  HT1621Wr_Num(Data/1000,1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
							    HT1621Wr_Nums(Data%100%10,1,10,0);																
							}else if(Datas<10000)/*9999*/
              {
									Data=Datas;
  						    HT1621Wr_Num(Data/1000,1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0); 
						    	HT1621Wr_Nums(Data%100%10,1,10,0);
							}
			   break;
		}	
		Electricity_sign(0);
}
/*�ڶ�ҳ������ʾҳ��*/
void ElectricCurrent_Power_Menu(uint8_t Package_type,int Data) //�ڶ�ҳ����
{
    float Datas;
		W1622_READ_MODIFY_WRITE(0,12,0);
  	W1622_READ_MODIFY_WRITE(0,12,1);
		W1622_READ_MODIFY_WRITE(0,14,0);
  	W1622_READ_MODIFY_WRITE(0,14,1);
    //DamageEx_Menu(Package_type,Data);
		Datas=((float)Data/8192)/2.4;
	  switch(Package_type)
	  {
		  case 4:/*A�����*/
		         if(Datas<10)/*9.999A*/
		         {
										Data=Datas*1000; 
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Nums(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);  
					   }else if(Datas<100)/*99,99A*/
					   {
										Data=Datas*100; 
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Nums(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
					   }else if(Datas<1000)/*999,9A*/
					   {
										Data=Datas*10;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Nums(Data%100%10,0,22,1);
			  		 }else if(Datas<10000)
			  		 {
										Data=Datas;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
			  		  }		
			  		  break;									
		case 5:		/*B�����*/
		         if(Datas<10)/*9.999A*/  
						 {					
                  	Data=Datas*1000;
										HT1621Wr_Num(Data/1000,0,16,0);
										HT1621Wr_Nums(Data/100%100%10,0,18,0);
										HT1621Wr_Num(Data/10%100%10,0,20,0);
										HT1621Wr_Num(Data%100%10,0,22,0);
						}else if(Datas<100)/*99,99A*/
						{
										Data=Datas*100;
										HT1621Wr_Num(Data/1000,0,16,0);
										HT1621Wr_Num(Data/100%100%10,0,18,0);
										HT1621Wr_Nums(Data/10%100%10,0,20,0);
										HT1621Wr_Num(Data%100%10,0,22,0); 
						}else if(Datas<1000)/*999,9A*/
						{
										Data=Datas*10;
									  HT1621Wr_Num(Data/1000,0,16,0);
										HT1621Wr_Num(Data/100%100%10,0,18,0);
										HT1621Wr_Num(Data/10%100%10,0,20,0);
										HT1621Wr_Nums(Data%100%10,0,22,0); 
						}else if(Datas<10000)
						{
										Data=Datas;
										HT1621Wr_Num(Data/1000,0,16,0);
										HT1621Wr_Num(Data/100%100%10,0,18,0);
										HT1621Wr_Num(Data/10%100%10,0,20,0);
										HT1621Wr_Num(Data%100%10,0,22,0); 
						}	  
						break;									
		case 6:		/*C�����*/						  
						if(Datas<10)/*9.999*/
					 {																	 
							  		Data=Datas*1000;								
							  		HT1621Wr_Num(Data/1000,1,4,0);
							  		HT1621Wr_Nums(Data/100%100%10,1,6,0);
							  		HT1621Wr_Num(Data/10%100%10,1,8,0);
							  		HT1621Wr_Num(Data%100%10,1,10,0);
					 }else if(Datas<100)/*99.99*/
					 {   																		
						  		  Data=Datas*100;									
						  			HT1621Wr_Num(Data/1000,1,4,0);
						  			HT1621Wr_Num(Data/100%100%10,1,6,0);
						  			HT1621Wr_Nums(Data/10%100%10,1,8,0);
						  			HT1621Wr_Num(Data%100%10,1,10,0);                                   																	  
					 }else if(Datas<1000)/*999.9*/
					 {																    
							  		Data=Datas*10;
									  HT1621Wr_Num(Data/1000,1,4,0);
								  	HT1621Wr_Num(Data/100%100%10,1,6,0);
									  HT1621Wr_Num(Data/10%100%10,1,8,0);
									  HT1621Wr_Nums(Data%100%10,1,10,0);																
					}else if(Datas<10000)/*9999*/
					{
								    Data=Datas; 
								    HT1621Wr_Num(Data/1000,1,4,0);
								    HT1621Wr_Num(Data/100%100%10,1,6,0);
							  	  HT1621Wr_Num(Data/10%100%10,1,8,0);
							  	  HT1621Wr_Num(Data%100%10,1,10,0);
					}
					 break;	
			}
		 Electricity_sign(1);
}
/*����ҳ�й�������ʾҳ��*/
void ActivePower_Menu(uint8_t Package_type,int Data) //����ҳ�й�����
{
	   float Datas;
	//	 DamageEx_Menu(Package_type,Data);
	   if(Data>8388608)
		 {
					Data=Data-16777216;
		 }
		 Datas=(float)Data*0.022;
		 Datas=Datas/1000;//��W�����KW
		 switch(Package_type)
		 {
			 case 7:/*A���й�����*/
		          if(Datas<10)/*�й�����9.999KW*/
							{
										Data=Datas*1000;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Nums(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
							}else if(Datas<100)/*�й�����99.99KW*/
							{
										Data=Datas*100;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Nums(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
							}else if(Datas<1000)/*�й�����999.9KW*/
							{
										Data=Datas*10;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Nums(Data%100%10,0,22,1);   
						  }else /*�й�����9999KW*/
							{
										Data=Datas;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
							}
							break;
			case 8:/*B���й�����*/
						 if(Datas<10)/*�й�����9.999KW*/
						 {
									Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Nums(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);  
						 }else if(Datas<100)/*�й�����99.99KW*/
						{
									Data=Datas*100;
                  HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Nums(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
						}else if(Datas<1000)/*�й�����999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Nums(Data%100%10,0,22,0);
						}else /*�й�����9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);      
						}
						break;
		 case 9:/*C���й�����*/
						if(Datas<10)/*�й�����9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Nums(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0); 
						}else if(Datas<100)/*�й�����99.99KW*/
						{
									Data=Datas*100;
                  HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Nums(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0); 
						}else if(Datas<10)/*�й�����999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Nums(Data%100%10,1,10,0);
						}else /*�й�����9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);   
						}
					 break;
		 case 0x0A://�����й�����
			      Datas=Datas*2;
			    	if(Datas<10)/*9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Nums(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0); 
						}else if(Datas<100)/*99.99KW*/
						{
									Data=Datas*100;
                 	HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else if(Datas<1000)/*999.9KW*/
						{
									Data=Datas/10;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);
						}else /*9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);     
						}
						break;
			}
		  Electricity_sign(2);
}
/*************************************����ҳ�޹�����********************************************/
void ReactivePower_Menu(uint8_t Package_type,int Data) //����ҳ�޹�����
{
	  float Datas;
	  //DamageEx_Menu(Package_type,Data);  
    if(Data>8388608)
		{
					Data=Data-16777216;
	  }
		Datas=(float)Data*0.022;
		Datas=Datas/1000;
		if(Datas<0)
		{
		      Datas=(-Datas);		
			    Synbol=1;
		}
		switch(Package_type)
		{
			case 0x0B:/*A���޹�����*/
				if(Synbol==1)
					{
					        if(Datas<10)//-9.99
					        {
											Data=Datas*100;
											HT1621Wr_Num('-',0,16,1);
											HT1621Wr_Num(Data/100%100%10,0,18,1);
											HT1621Wr_Nums(Data/10%100%10,0,20,1);
											HT1621Wr_Num(Data%100%10,0,22,1);
									}else if(Datas<100)//-99.9
									{
											Data=Datas*10;
											HT1621Wr_Num('-',0,16,1);
											HT1621Wr_Num(Data/100%100%10,0,18,1);
											HT1621Wr_Num(Data/10%100%10,0,20,1);
											HT1621Wr_Nums(Data%100%10,0,22,1);
									}else if(Datas<1000)//-999
									{					
											Data=Datas;
											HT1621Wr_Num('-',0,16,1);
											HT1621Wr_Num(Data/100%100%10,0,18,1);
											HT1621Wr_Num(Data/10%100%10,0,20,1);
											HT1621Wr_Num(Data%100%10,0,22,1);
									}
									Synbol=0;
					}	else{		
						   if(Datas<10)//9.99
						   {  
										 	Data=Datas*1000;
											HT1621Wr_Num(Data/1000,0,16,1);
											HT1621Wr_Nums(Data/100%100%10,0,18,1);
											HT1621Wr_Num(Data/10%100%10,0,20,1);
											HT1621Wr_Num(Data%100%10,0,22,1);
					    }else if(Datas<100)//99.99
					    {
								  Data=Datas*100;
							    HT1621Wr_Num(Data/1000,0,16,1);
							    HT1621Wr_Num(Data/100%100%10,0,18,1);
							    HT1621Wr_Nums(Data/10%100%10,0,20,1);
							    HT1621Wr_Num(Data%100%10,0,22,1);
					  }else if(Datas<1000)//999.9
            {					
					        Data=Datas*10;
							    HT1621Wr_Num(Data/1000,0,16,1);
							    HT1621Wr_Num(Data/100%100%10,0,18,1);
							    HT1621Wr_Num(Data/10%100%10,0,20,1);
							    HT1621Wr_Nums(Data%100%10,0,22,1); 
					  }else if(Datas<10000)//9999
            {					
					        Data=Datas;
							    HT1621Wr_Num(Data/1000,0,16,1);
							    HT1621Wr_Num(Data/100%100%10,0,18,1);
							    HT1621Wr_Num(Data/10%100%10,0,20,1);
							    HT1621Wr_Nums(Data%100%10,0,22,1);   	
            }	
			   }						
						break;
			case 0x0C:/*B���޹�����*/
				if(Synbol==1){
					    if(Datas<10)//9.99
					    {
							    Data=Datas*100;
							    HT1621Wr_Num('-',0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Nums(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);
							   
					    }else if(Datas<100)
					    {
							    Data=Datas*10;
							    HT1621Wr_Num('-',0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Nums(Data%100%10,0,22,0); 
					   }else if(Datas<1000)
             {					
					        Data=Datas;
							    HT1621Wr_Num('-',0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);   
						 }
						 Synbol=0;
	    }else{
						  if(Datas<10)//9.99
						  {  
							    Data=Datas*1000;
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Nums(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);
					   }else if(Datas<100)//99.99
					   {
								  Data=Datas*100;
							//    printf("B���޹�����%f\r\n",Datas);
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Nums(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);
					  }else if(Datas<1000)//999.9
            {					
					        Data=Datas*10;
							//    printf("B���޹�����%f\r\n",Datas);
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Nums(Data%100%10,0,22,0);
					  }else if(Datas<10000)//9999
            {					
					        Data=Datas;
							 //   printf("B���޹�����%f\r\n",Datas);
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Nums(Data%100%10,0,22,0);
						}  
           }							 
						break;
		case 0x0D:/*C���޹�����*/
			if(Synbol==1)
			{
					    if(Datas<10)
					    {
							    Data=Datas*100;
							    HT1621Wr_Num('-',1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Nums(Data/10%100%10,1,8,0);
							    HT1621Wr_Num(Data%100%10,1,10,0);
							   
					    }else if(Datas<100)
					    {
							    Data=Datas*10;
							    HT1621Wr_Num('-',1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
							    HT1621Wr_Nums(Data%100%10,1,10,0);
							    
					   }else if(Datas<1000)
             {					
					        Data=Datas;
							    HT1621Wr_Num('-',1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
							    HT1621Wr_Num(Data%100%10,1,10,0);					    
						 }
						 Synbol=0;
		}else{
						 if(Datas<10)//9.99
						 {  
							    Data=Datas*1000;
							    HT1621Wr_Num(Data/1000,1,4,0);
							    HT1621Wr_Nums(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
							    HT1621Wr_Num(Data%100%10,1,10,0); 
					   }else if(Datas<100)//99.99
					   {
								  Data=Datas*100;
							    HT1621Wr_Num(Data/1000,1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Nums(Data/10%100%10,1,8,0);
							    HT1621Wr_Num(Data%100%10,1,10,0);   
					  }else if(Datas<1000)//999.9
            {					
					        Data=Datas*10;
							    HT1621Wr_Num(Data/1000,1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
							    HT1621Wr_Nums(Data%100%10,1,10,0);    
					  }else if(Datas<10000)//9999
            {					
					        Data=Datas;
							    HT1621Wr_Num(Data/1000,1,4,0);
							    HT1621Wr_Num(Data/100%100%10,1,6,0);
							    HT1621Wr_Num(Data/10%100%10,1,8,0);
							    HT1621Wr_Nums(Data%100%10,1,10,0);   
            }					
			}
		break;		
		case 0X0E://�����޹�����
		Datas=Datas*2;
		if(Synbol==1){
			     if(Datas<10)//-9.99KW
						 {
						      Data=Datas*100;
									HT1621Wr_Num('-',2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);
						 }
						 else if(Datas<100)//-99.9
						 {
						      Data=Datas*10;
									HT1621Wr_Num('-',2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);
						 } else if (Datas<1000)//-999
						 {
						      Data=Datas;						
									HT1621Wr_Num('-',2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);
						 }
					 Synbol=0;	 
	 }else{
			    	if(Datas<10)/*9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Nums(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);   
						}else if(Datas<100)/*99.99KW*/
						{
									Data=Datas*100;
                 	HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);
						}else if(Datas<1000)/*999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else /*9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);   
						}	
					}
	    break;
		}
		 Electricity_sign(3);
}

void ApparentPower_Menu(uint8_t Package_type,int Data) //����ҳ���ڹ���
{
		float Datas;
	 // DamageEx_Menu(Package_type,Data);
	  if(Data>8388608)
		{
				Data=Data-16777216;
		}
		Datas=(float)Data*0.022;
		Datas=Datas/1000;
		switch(Package_type)
		{
			case 0x0F:/*A�����ڹ���*/
		       if(Datas<10)/*���ڹ���9.999KW*/
		       {
								Data=Datas*1000;
								HT1621Wr_Num(Data/1000,0,16,1);
								HT1621Wr_Nums(Data/100%100%10,0,18,1);
								HT1621Wr_Num(Data/10%100%10,0,20,1);
								HT1621Wr_Num(Data%100%10,0,22,1);		
					 }else if(Datas<100)/*99.99KW*/
					 {
								Data=Datas*100;
								HT1621Wr_Num(Data/1000,0,16,1);
								HT1621Wr_Num(Data/100%100%10,0,18,1);
								HT1621Wr_Nums(Data/10%100%10,0,20,1);
								HT1621Wr_Num(Data%100%10,0,22,1); 
					}else if(Datas<1000)/*999.9KW*/
					{
								Data=Datas*10;
								HT1621Wr_Num(Data/1000,0,16,1);
								HT1621Wr_Num(Data/100%100%10,0,18,1);
								HT1621Wr_Num(Data/10%100%10,0,20,1);
								HT1621Wr_Nums(Data%100%10,0,22,1);
					}else /*9999KW*/
					{
								Data=Datas;
								HT1621Wr_Num(Data/1000,0,16,1);
								HT1621Wr_Num(Data/100%100%10,0,18,1);
								HT1621Wr_Num(Data/10%100%10,0,20,1);
							  HT1621Wr_Num(Data%100%10,0,22,1);
					}
					break;
		case 0x10:/*B�����ڹ���*/
					if(Datas<10)/*9.999KW*/
					{
									Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Nums(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
					}else if(Datas<100)/*99.99KW*/
					{
									Data=Datas*100;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Nums(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);  
					}else if(Datas<1000)/*999.9KW*/
					{
									Data=Datas/10;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Nums(Data%100%10,0,22,0);
					}else /*9999KW*/
					{
									Data=Datas;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);  
				 }
				 break;
		case 0x11:/*C�����ڹ���*/
					if(Datas<10)/*9.999KW*/
					{
								Data=Datas*1000;
								HT1621Wr_Num(Data/1000,1,4,0);
								HT1621Wr_Nums(Data/100%100%10,1,6,0);
								HT1621Wr_Num(Data/10%100%10,1,8,0);
							  HT1621Wr_Num(Data%100%10,1,10,0); 
					}else if(Datas<100)/*99.99KW*/
					{
								Data=Datas*100;
								HT1621Wr_Num(Data/1000,1,4,0);
								HT1621Wr_Num(Data/100%100%10,1,6,0);
								HT1621Wr_Nums(Data/10%100%10,1,8,0);
								HT1621Wr_Num(Data%100%10,1,10,0); 
					}else if(Datas<1000)/*999.9KW*/
					{
								Data=Datas*10;
								HT1621Wr_Num(Data/1000,1,4,0);
								HT1621Wr_Num(Data/100%100%10,1,6,0);
								HT1621Wr_Num(Data/10%100%10,1,8,0);
								HT1621Wr_Nums(Data%100%10,1,10,0);     
					}else /*9999KW*/
					{
								Data=Datas;;
								HT1621Wr_Num(Data/1000,1,4,0);
								HT1621Wr_Num(Data/100%100%10,1,6,0);
								HT1621Wr_Num(Data/10%100%10,1,8,0);
								HT1621Wr_Num(Data%100%10,1,10,0);    
					}
					break;
		case 0x12://�������ڹ���
						Datas=Datas*2;
			    	if(Datas<10)/*����9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Nums(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else if(Datas<100)/*���ڹ���99.99KW*/
						{
									Data=Datas*100;
                 	HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else if(Datas<1000)/*���ڹ���999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);   
						}else /*�й�����9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);        
						}
						break;			
			}
		 Electricity_sign(4);
}

void PowerFactor_Menu(uint8_t Package_type,int Data) //����ҳ��������
{
		float Datas;
		W1622_READ_MODIFY_WRITE(0,12,0);
  	W1622_READ_MODIFY_WRITE(0,12,1);
		W1622_READ_MODIFY_WRITE(0,14,0);
  	W1622_READ_MODIFY_WRITE(0,14,1);
	 // DamageEx_Menu(Package_type,Data);
	  if(Data>8388608)
		{
					Data=Data-16777216;
		}
		Datas=(float)Data/8388608;
		switch(Package_type)
		{
		    case 0x13:/*A�๦������*/
						if(Datas<10)
						{
								Data=Datas*1000;
							  HT1621Wr_Num(Data/1000,0,16,1);
								HT1621Wr_Nums(Data/100%100%10,0,18,1);
								HT1621Wr_Num(Data/10%100%10,0,20,1);
								HT1621Wr_Num(Data%100%10,0,22,1);   
						}else
						{
							  HT1621Wr_Num(0,0,16,1);
								HT1621Wr_Nums(0,0,18,1);
								HT1621Wr_Num(0,0,20,1);
								HT1621Wr_Num(0,0,22,1);   
						}
						break;
				case 0x14:/*B�๦������*/
						if(Datas<10)
						{
								Data=Datas*1000;
								HT1621Wr_Num(Data/1000,0,16,0);
								HT1621Wr_Nums(Data/100%100%10,0,18,0);
								HT1621Wr_Num(Data/10%100%10,0,20,0);
								HT1621Wr_Num(Data%100%10,0,22,0);    
						}
						else
						{
							  HT1621Wr_Num(0,0,16,0);
								HT1621Wr_Nums(0,0,18,0);
								HT1621Wr_Num(0,0,20,0);
								HT1621Wr_Num(0,0,22,0);   
						}
						break;
			case 0x15:/*C�๦������*/
					if(Datas<10)
					{
								Data=Datas*1000;
								HT1621Wr_Num(Data/1000,1,4,0);
								HT1621Wr_Nums(Data/100%100%10,1,6,0);
								HT1621Wr_Num(Data/10%100%10,1,8,0);
								HT1621Wr_Num(Data%100%10,1,10,0);
				 }
					else{
							   HT1621Wr_Num(0,1,4,0);
								HT1621Wr_Nums(0,1,6,0);
								HT1621Wr_Num(0,1,8,0);
								HT1621Wr_Num(0,1,10,0);
					}
				break;
		}	
    Electricity_sign(5);		
}

void ActiveEnergy_Menu(uint8_t Package_type,int Data)/*����ҳ�й�������ʾҳ��*/
{
	   float Datas;
	   //DamageEx_Menu(Package_type,Data);
	   Datas=(float)Data/1000;				           
	   switch(Package_type)
		 {
	    case 0x16: /*A���й�����*/
					 if(Datas<10)/**/
					 {
						      Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Nums(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);
																					 
						}else if(Datas<100)
						{
							    Data=Datas*100;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Nums(Data/10%100%10,0,20,1);
							  	HT1621Wr_Num(Data%100%10,0,22,1);
									
						}else if(Datas<1000)
						{
							    Data=Datas/10;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Nums(Data%100%10,0,22,1);	
						}else
						{
							    Data=Datas;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);	
						}
						break;
			case 0x17:/*B���й�����*/
					if(Datas<10)
					{
						      Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Nums(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
																			 
					}else if(Datas<100)
					{
						      Data=Datas*100;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Nums(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);	
					}else if(Datas<1000)
					{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Nums(Data%100%10,0,22,0);
					 }else
					 {
									Data=Datas;
								  HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
					 }
					break;
			case 0x18:/*C���й�����*/
						if(Datas<10)
						{
							    Data=Datas*1000;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Nums(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);
																			 
						}else if(Datas<100)
						{
							    Data=Datas*100;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Nums(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);
						}else if(Datas<1000)
						{
							    Data=Datas*10;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Nums(Data%100%10,1,10,0);
						}else
						{
							    Data=Datas;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);
						}
						 break;
			case 0x19:/*�����й�����*/
				if(Datas<10)/*9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Nums(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);   
						}else if(Datas<100)/*99.99KW*/
						{
									Data=Datas/100;
                 	HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0); 
						}else if(Datas<1000)/*999.9KW*/
						{
									Data=Datas/10;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else /*�й�����9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);
						}
						break;
			}
		  Electricity_sign(6);
}
void ReactiveEnergy_Menu(uint8_t Package_type,int Data)//�޹�����
{
     u8  Synbol=0;
		 float Datas;
	
	 //  DamageEx_Menu(Package_type,Data);
  	if(Data<0)
		{
		      Datas=(-Data);		
			    Synbol=1;
		}	else
    {
		       Datas=Data;
		}		
		Datas=Datas/1000;
	  switch(Package_type)
	  {
	      case 0x1A:/*A���޹�����*/ 
				if( Synbol==1){
					 if(Datas<10)//-9.99
					 {
						       Data=Datas*100;
								   HT1621Wr_Num('-',0,16,1);
									 HT1621Wr_Num(Data/100%100%10,0,18,1);
									 HT1621Wr_Nums(Data/10%100%10,0,20,1);
									 HT1621Wr_Num(Data%100%10,0,22,1);
																				 
						}else if(Datas<100)//-99.9
						{
							     Data=Datas*10;
								   HT1621Wr_Num('-',0,16,1);
									 HT1621Wr_Num(Data/100%100%10,0,18,1);
									 HT1621Wr_Num(Data/10%100%10,0,20,1);
									 HT1621Wr_Nums(Data%100%10,0,22,1);
									
						}else if(Datas<1000)//999
						{
							     Data=Datas;
								   HT1621Wr_Num('-',0,16,1);
									 HT1621Wr_Num(Data/100%100%10,0,18,1);
									 HT1621Wr_Num(Data/10%100%10,0,20,1);
									 HT1621Wr_Num(Data%100%10,0,22,1);
						}
				   Synbol=0;
		}else{
					 if(Datas<10)//9.999
					 {
						      Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Nums(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);
																				 
						}else if(Datas<100)//99.99
						{
							    Data=Datas*100;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Nums(Data/10%100%10,0,20,1);
							  	HT1621Wr_Num(Data%100%10,0,22,1);
									
						}else if(Datas<1000)//999.9
						{
							    Data=Datas*10;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Nums(Data%100%10,0,22,1);	
						}else//9999
						{
							    Data=Datas;
									HT1621Wr_Num(Data/1000,0,16,1);/**/
									HT1621Wr_Num(Data/100%100%10,0,18,1);
									HT1621Wr_Num(Data/10%100%10,0,20,1);
									HT1621Wr_Num(Data%100%10,0,22,1);		
						}
					}
				break;   
				case 0x1B:/*B���޹�����*/ 
		     if( Synbol==1){
				  if(Datas<10)//-9.99Kwh
					  {
									Data=Datas*1000;
									HT1621Wr_Num('-',0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Nums(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);											 
				  	}else if(Datas<100)//-99.9Kwh
				  	{
									Data=Datas*100;
									HT1621Wr_Num('-',0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Nums(Data%100%10,0,22,0);	
					  }else if(Datas<1000)//-999Kwh
				  	{
						      Data=Datas*10;
									HT1621Wr_Num('-',0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
									
					  }
				Synbol=0;	     
	}	else{
					if(Datas<10)//9.999Kwh
					{
									Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Nums(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
																			 
					}else if(Datas<100)//99.99Kwh
					{
									Data=Datas*100;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Nums(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
									
					}else if(Datas<1000)//999.9Kwh
					{
						      Data=Datas*10;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Nums(Data%100%10,0,22,0);
									
					 }else//9999Kwh
					 {
						      Data=Datas;
								  HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
					 }			
			} 
			case 0x1C:  /*C���޹�����*/ 
	  	if( Synbol==1){
				    if(Datas<10)
						{
							    Data=Datas*100;
									HT1621Wr_Num('-',1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Nums(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);												 
						}else if(Datas<100)
					  {
							    Data=Datas*10;
									HT1621Wr_Num('-',1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Nums(Data%100%10,1,10,0);
									
						}else if(Datas<1000)
						{
							    Data=Datas;
									HT1621Wr_Num('-',1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);		
						}
				    Synbol=0;
				}else{
						if(Datas<10)
						{
							    Data=Datas*1000;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Nums(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);													 
						}else if(Datas<100)
					  {
							    Data=Datas*100;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Nums(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);	
						}else if(Datas<1000)
						{
							    Data=Datas*10;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Nums(Data%100%10,1,10,0);		
						}else
						{
							    Data=Datas;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);	
						}
					}
		break;
			/*�����޹�����*/ 
		case 0x1D:
				if( Synbol==1){
				     if(Datas<10)/*9.99KW*/
						 {
									Data=Datas*100;
									HT1621Wr_Num('-',2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);    
						 }else if(Datas<100)/*99.99KW*/
						 {
									Data=Datas*10;
                 	HT1621Wr_Num('-',2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Nums(Data%100%10,3,12,0);  
						 }else if(Datas<1000)/*999.9KW*/
						 {
									Data=Datas;
									HT1621Wr_Num('-',2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);         
						}		
				   Synbol=0;
				}else{
				    if(Datas<10)/*9.999KW*/
						 {
									Data=Datas*1000;
									HT1621Wr_Nums(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Nums(Data%100%10,3,12,0);   
						}else if(Datas<100)/*99.99KW*/
						{
									Data=Datas*100;
                 	HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Nums(Data%100%10,3,12,0);
                 
						}else if(Datas<1000)/*999.9KW*/
						{
									Data=Datas/10;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Nums(Data%100%10,3,12,0);    
						}else /*9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Nums(Data%100%10,3,12,0);
						}     
				}
			break;	
		}
		  Electricity_sign(7);
}   

void DamageEx_Menu(int Data)
{
	  unsigned char bin_str[8];
	  u8 i;	
          for( i=0;i<8;++i)
	        {
			          bin_str[i]=Data%2;
	              Data/=2;
					}

					if(bin_str[0]==1)
					{
									dispON(1,2);
					}else{
					          dispOFF(1,2);
					      }
														
					if(bin_str[1]==1)
					{
									dispON(0,2);
					}else{
					         dispOFF(0,2);
					     }
													
				  if(bin_str[2]==1)
					{
									dispON(0,3);
					}else{
									dispOFF(0,3);
							 }
													
					if(bin_str[3]==1)
					{
									dispON(1,3);
					}else{
					        dispOFF(1,3);
					     }
													
				 if(bin_str[4]==1)
				 {
									dispON(2,3);
				 }else{
				          dispOFF(2,3);
				      }
													
				 if(bin_str[5]==1)
				 {
										dispON(3,3);
				 }else{
				            dispOFF(3,3);
				      }
     
		 dispON(3,2);
}

void Electricity_sign(u8 sign)
{
		switch(sign)
		{
			     case 0:	/*��ѹ*/
					      dispOFF(5,0);
								dispOFF(5,2);
								dispOFF(5,24);/*��λA*/		   
								dispOFF(6,1);
					      dispOFF(6,3);
					      dispOFF(7,1);
					      dispOFF(7,2);
					 
						    dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);	
								dispON(4,0);
								dispON(4,1);
								dispON(4,2);
								dispON(4,3);
					      dispON(7,0);
								dispON(7,3);	
								dispON(7,24);/*��λV*/		 
				        break;
			    case 1:	/*����*/
								dispOFF(4,0);
								dispOFF(4,3);	
								dispOFF(5,0);
					      dispOFF(6,3);
						    dispOFF(6,24);	
								dispOFF(7,0);
								dispOFF(7,3);	
								dispOFF(7,24);/*��λV*/
					
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
								dispON(4,1);
								dispON(4,2);
								dispON(5,2);
								dispON(5,24);/*��λA*/
								dispON(6,1);
						 		dispON(7,1);
								dispON(7,2);
								break;					 
					case 2:  /*�й���*/
								dispOFF(4,1);
								dispOFF(4,2);
					      dispOFF(4,24);
								dispOFF(5,2);
								dispOFF(5,24);
              	dispOFF(6,1);	
					
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
								dispON(4,3);
								dispON(5,0);
								dispON(6,3);
						    dispON(6,24);/*��λKW*/
								dispON(7,0);
								dispON(7,1);
								dispON(7,2);
								dispON(7,3);
								break;	
					case 3://�޹�����KVAR
					      dispOFF(3,24);
						    dispOFF(6,24);
					
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
								dispON(4,3);
					      dispON(4,24);
								dispON(5,0);
								dispON(6,3);
								dispON(7,0);
								dispON(7,1);
								dispON(7,2);
								dispON(7,3);
				   	break;	
					case 4://����	KYVA
					      dispOFF(4,24);
				      	dispOFF(2,1);
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
								dispON(7,0);
								dispON(7,1);
								dispON(7,2);
								dispON(7,3);
								dispON(6,3);
								dispON(5,0);
								dispON(4,3);
					      dispON(3,24);
				     	break;	
					case 5:/*��������s*/
						   dispOFF(7,3);
					      dispOFF(7,2);
					      dispOFF(7,1);
					      dispOFF(7,0);
					      dispOFF(6,3);
					      dispOFF(5,0);
					      dispOFF(4,2);
					      dispOFF(4,1);
								dispOFF(4,3); 
					      dispOFF(3,24);/*��λKVR*/
					      dispOFF(0,24);/*��λKwh*/
					
					      dispON(0,1);
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(2,1);//PF
					      break;
					case 6://����E
                dispOFF(2,1);
					
						    dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
					
					      dispON(7,3);
					      dispON(7,2);
					      dispON(7,1);
					      dispON(6,3);
					      dispON(5,0);
					      dispON(4,3);
					      dispON(4,2);
					      dispON(4,1);
					      dispON(0,24);/*��λKwh*/
						    break;
					case 7:	
						    dispOFF(0,24);
						    dispOFF(7,0);
								dispOFF(4,0);
								dispOFF(7,24);/*��λV*/
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
					      dispON(7,3);
					      dispON(7,2);
					      dispON(7,1);
					      dispON(6,3);
					      dispON(5,0);
					      dispON(4,3);
					      dispON(4,2);
					      dispON(4,1);
					break;
		}
}


