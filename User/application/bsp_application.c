#include "bsp_application.h"
u8 KeyPressNum = 0;
u8 GetKeyValue = 0;
PAGE_NUM  PageNum;
#define MenuNum_Max 7
#define MenuNum_Min 0

 u8 flag_sand1=0;

enum
{
    VoltageDataPage = 0,/*电压*/
    ElectricCurrent,/*电流*/
    ActivePower,/*有功功率*/
    ReactivePower,/*无功功率*/
    ApparentPower,/*视在功率*/
    PowerFactor,/*功率因数*/
	  ActiveEnergy,/*有功电能参数*/
	  ReactiveEnergy,/*无功电能参数*/
};

void KeyDeal(void)
{
    GetKeyValue = Key_Scan();
    switch (GetKeyValue)
    {
    case 1:
        if (KeyPressNum > MenuNum_Min)
        {
            
            KeyPressNum--;
					
           // cleandisp();
        }
        else
            KeyPressNum = MenuNum_Max;
        break;
    case 2:
        KeyPressNum++;
        if (KeyPressNum > MenuNum_Max)
        {
            
            KeyPressNum = MenuNum_Min;
             
        }
     
        break;
    default:
        break;
    }
}

void Menu_Display(void)
{
	 KeyDeal();
    if (KeyPressNum == VoltageDataPage) //显示界面1
    {
        Parameter_SendData(0x01,1);
	      PageNum.NUM_1=FlagTure;		
    }
    if (KeyPressNum == ElectricCurrent) //显示界面2
    {
        Parameter_SendData(0x01,2);
			  PageNum.NUM_2=FlagTure;	
    }
    if (KeyPressNum == ActivePower) //显示界面3
    {
        Parameter_SendData(0x01,3);
			  PageNum.NUM_3=FlagTure;	
    }
    if (KeyPressNum == ReactivePower) //显示界面4
    {
        Parameter_SendData(0x01,4);
			  PageNum.NUM_4=FlagTure;	
    }
    if (KeyPressNum == ApparentPower) //显示界面5
    {
        Parameter_SendData(0x01,5);
			  PageNum.NUM_5=FlagTure;	
    }
    if (KeyPressNum == PowerFactor) //显示界面6
    {
        Parameter_SendData(0x01,6);
			  PageNum.NUM_6=FlagTure;	
    }
    if (KeyPressNum == ActiveEnergy) //显示界面7
    {
        Parameter_SendData(0x01,7);
		  	PageNum.NUM_7=FlagTure;	
    }
		if(KeyPressNum==ReactiveEnergy)
		{
			  Parameter_SendData(0x01,8);
			  PageNum.NUM_8=FlagTure;
		}
}
