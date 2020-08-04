#include <string.h>
#include <math.h>
#include "bsp_menulayout.h"

 u8 Synbol=0;

void Voltage_DataPage_Menu(uint8_t Package_type,int Data)//第一页电压
{
	  float Datas;
		W1622_READ_MODIFY_WRITE(0,12,0);
  	W1622_READ_MODIFY_WRITE(0,12,1);
		W1622_READ_MODIFY_WRITE(0,14,0);
  	W1622_READ_MODIFY_WRITE(0,14,1);
	  Datas=(float)Data/8192;
	  switch(Package_type)
	  {
	    case 1:	  /*A相电压*/
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
	 	case 2:   /*B相电压*/   
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
		case 3: /*C相电压*/ 
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
/*第二页电流显示页面*/
void ElectricCurrent_Power_Menu(uint8_t Package_type,int Data) //第二页电流
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
		  case 4:/*A相电流*/
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
		case 5:		/*B相电流*/
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
		case 6:		/*C相电流*/						  
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
/*第三页有功功率显示页面*/
void ActivePower_Menu(uint8_t Package_type,int Data) //第三页有功功率
{
	   float Datas;
	//	 DamageEx_Menu(Package_type,Data);
	   if(Data>8388608)
		 {
					Data=Data-16777216;
		 }
		 Datas=(float)Data*0.022;
		 Datas=Datas/1000;//将W换算成KW
		 switch(Package_type)
		 {
			 case 7:/*A相有功功率*/
		          if(Datas<10)/*有功功率9.999KW*/
							{
										Data=Datas*1000;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Nums(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
							}else if(Datas<100)/*有功功率99.99KW*/
							{
										Data=Datas*100;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Nums(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
							}else if(Datas<1000)/*有功功率999.9KW*/
							{
										Data=Datas*10;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Nums(Data%100%10,0,22,1);   
						  }else /*有功功率9999KW*/
							{
										Data=Datas;
										HT1621Wr_Num(Data/1000,0,16,1);
										HT1621Wr_Num(Data/100%100%10,0,18,1);
										HT1621Wr_Num(Data/10%100%10,0,20,1);
										HT1621Wr_Num(Data%100%10,0,22,1);
							}
							break;
			case 8:/*B相有功功率*/
						 if(Datas<10)/*有功功率9.999KW*/
						 {
									Data=Datas*1000;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Nums(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);  
						 }else if(Datas<100)/*有功功率99.99KW*/
						{
									Data=Datas*100;
                  HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Nums(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);
						}else if(Datas<1000)/*有功功率999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Nums(Data%100%10,0,22,0);
						}else /*有功功率9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,0,16,0);
									HT1621Wr_Num(Data/100%100%10,0,18,0);
									HT1621Wr_Num(Data/10%100%10,0,20,0);
									HT1621Wr_Num(Data%100%10,0,22,0);      
						}
						break;
		 case 9:/*C相有功功率*/
						if(Datas<10)/*有功功率9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Nums(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0); 
						}else if(Datas<100)/*有功功率99.99KW*/
						{
									Data=Datas*100;
                  HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Nums(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0); 
						}else if(Datas<10)/*有功功率999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Nums(Data%100%10,1,10,0);
						}else /*有功功率9999KW*/
						{
									Data=Datas;
									HT1621Wr_Num(Data/1000,1,4,0);
									HT1621Wr_Num(Data/100%100%10,1,6,0);
									HT1621Wr_Num(Data/10%100%10,1,8,0);
									HT1621Wr_Num(Data%100%10,1,10,0);   
						}
					 break;
		 case 0x0A://合相有功共率
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
/*************************************第四页无功功率********************************************/
void ReactivePower_Menu(uint8_t Package_type,int Data) //第四页无功功率
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
			case 0x0B:/*A相无功功率*/
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
			case 0x0C:/*B相无功功率*/
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
							//    printf("B相无功功率%f\r\n",Datas);
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Nums(Data/10%100%10,0,20,0);
							    HT1621Wr_Num(Data%100%10,0,22,0);
					  }else if(Datas<1000)//999.9
            {					
					        Data=Datas*10;
							//    printf("B相无功功率%f\r\n",Datas);
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Nums(Data%100%10,0,22,0);
					  }else if(Datas<10000)//9999
            {					
					        Data=Datas;
							 //   printf("B相无功功率%f\r\n",Datas);
							    HT1621Wr_Num(Data/1000,0,16,0);
							    HT1621Wr_Num(Data/100%100%10,0,18,0);
							    HT1621Wr_Num(Data/10%100%10,0,20,0);
							    HT1621Wr_Nums(Data%100%10,0,22,0);
						}  
           }							 
						break;
		case 0x0D:/*C相无功功率*/
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
		case 0X0E://合相无功功率
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

void ApparentPower_Menu(uint8_t Package_type,int Data) //第五页视在功率
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
			case 0x0F:/*A相视在功率*/
		       if(Datas<10)/*视在功率9.999KW*/
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
		case 0x10:/*B相视在功率*/
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
		case 0x11:/*C相视在功率*/
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
		case 0x12://合相视在功率
						Datas=Datas*2;
			    	if(Datas<10)/*功率9.999KW*/
						{
									Data=Datas*1000;
									HT1621Wr_Nums(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else if(Datas<100)/*视在功率99.99KW*/
						{
									Data=Datas*100;
                 	HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Nums(Data/100%100%10,2,14,1);
									HT1621Wr_Num(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);  
						}else if(Datas<1000)/*视在功率999.9KW*/
						{
									Data=Datas*10;
									HT1621Wr_Num(Data/1000,2,12,1);
									HT1621Wr_Num(Data/100%100%10,2,14,1);
									HT1621Wr_Nums(Data/10%100%10,3,14,0);
									HT1621Wr_Num(Data%100%10,3,12,0);   
						}else /*有功功率9999KW*/
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

void PowerFactor_Menu(uint8_t Package_type,int Data) //第六页功率因数
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
		    case 0x13:/*A相功率因数*/
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
				case 0x14:/*B相功率因数*/
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
			case 0x15:/*C相功率因数*/
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

void ActiveEnergy_Menu(uint8_t Package_type,int Data)/*第七页有功功能显示页面*/
{
	   float Datas;
	   //DamageEx_Menu(Package_type,Data);
	   Datas=(float)Data/1000;				           
	   switch(Package_type)
		 {
	    case 0x16: /*A相有功功能*/
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
			case 0x17:/*B相有功功能*/
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
			case 0x18:/*C相有功电能*/
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
			case 0x19:/*合相有功电能*/
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
						}else /*有功功率9999KW*/
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
void ReactiveEnergy_Menu(uint8_t Package_type,int Data)//无功电能
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
	      case 0x1A:/*A相无功电能*/ 
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
				case 0x1B:/*B相无功电能*/ 
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
			case 0x1C:  /*C相无功电能*/ 
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
			/*合相无功电能*/ 
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
			     case 0:	/*电压*/
					      dispOFF(5,0);
								dispOFF(5,2);
								dispOFF(5,24);/*单位A*/		   
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
								dispON(7,24);/*单位V*/		 
				        break;
			    case 1:	/*电流*/
								dispOFF(4,0);
								dispOFF(4,3);	
								dispOFF(5,0);
					      dispOFF(6,3);
						    dispOFF(6,24);	
								dispOFF(7,0);
								dispOFF(7,3);	
								dispOFF(7,24);/*单位V*/
					
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(0,1);
								dispON(4,1);
								dispON(4,2);
								dispON(5,2);
								dispON(5,24);/*单位A*/
								dispON(6,1);
						 		dispON(7,1);
								dispON(7,2);
								break;					 
					case 2:  /*有功率*/
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
						    dispON(6,24);/*单位KW*/
								dispON(7,0);
								dispON(7,1);
								dispON(7,2);
								dispON(7,3);
								break;	
					case 3://无功功率KVAR
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
					case 4://视在	KYVA
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
					case 5:/*功率因数s*/
						   dispOFF(7,3);
					      dispOFF(7,2);
					      dispOFF(7,1);
					      dispOFF(7,0);
					      dispOFF(6,3);
					      dispOFF(5,0);
					      dispOFF(4,2);
					      dispOFF(4,1);
								dispOFF(4,3); 
					      dispOFF(3,24);/*单位KVR*/
					      dispOFF(0,24);/*单位Kwh*/
					
					      dispON(0,1);
					      dispON(1,0);				 
					      dispON(3,0);
					      dispON(2,1);//PF
					      break;
					case 6://电能E
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
					      dispON(0,24);/*单位Kwh*/
						    break;
					case 7:	
						    dispOFF(0,24);
						    dispOFF(7,0);
								dispOFF(4,0);
								dispOFF(7,24);/*单位V*/
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


