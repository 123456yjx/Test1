#ifndef __BSP_MENULAYOUT_H
#define __BSP_MENULAYOUT_H
#include "stm32f10x.h"
#include "board.h"
//#pragma  diag_suppress 870


void Voltage_DataPage_Menu(uint8_t Package_type,int Data);//第一页电压
void ElectricCurrent_Power_Menu(uint8_t Package_type,int Data);//第二页电流
void ActivePower_Menu(uint8_t Package_type,int Data);//第三页有功功率
void ReactivePower_Menu(uint8_t Package_type,int Data);//第四页无功功率
void ApparentPower_Menu(uint8_t Package_type,int Data);//第五页视在功率
void PowerFactor_Menu(uint8_t Package_type,int Data);//第六页功率因数
void ActiveEnergy_Menu(uint8_t Package_type,int Data);//第七页为有功电能参数
void ReactiveEnergy_Menu(uint8_t Package_type,int Data);//第八页为电能电能参数
void DamageEx_Menu(int Data);//第九页为输入信号显示

void Electricity_sign(u8 sign);
void MenuLayout_Display(void);
extern u8 Synbol;
#endif
