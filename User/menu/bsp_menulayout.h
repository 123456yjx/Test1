#ifndef __BSP_MENULAYOUT_H
#define __BSP_MENULAYOUT_H
#include "stm32f10x.h"
#include "board.h"
//#pragma  diag_suppress 870


void Voltage_DataPage_Menu(uint8_t Package_type,int Data);//��һҳ��ѹ
void ElectricCurrent_Power_Menu(uint8_t Package_type,int Data);//�ڶ�ҳ����
void ActivePower_Menu(uint8_t Package_type,int Data);//����ҳ�й�����
void ReactivePower_Menu(uint8_t Package_type,int Data);//����ҳ�޹�����
void ApparentPower_Menu(uint8_t Package_type,int Data);//����ҳ���ڹ���
void PowerFactor_Menu(uint8_t Package_type,int Data);//����ҳ��������
void ActiveEnergy_Menu(uint8_t Package_type,int Data);//����ҳΪ�й����ܲ���
void ReactiveEnergy_Menu(uint8_t Package_type,int Data);//�ڰ�ҳΪ���ܵ��ܲ���
void DamageEx_Menu(int Data);//�ھ�ҳΪ�����ź���ʾ

void Electricity_sign(u8 sign);
void MenuLayout_Display(void);
extern u8 Synbol;
#endif
