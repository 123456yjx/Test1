#ifndef __BSP_CRC16_H
#define __BSP_CRC16_H
#include "stm32f10x.h"
#include "board.h"


uint16_t CRC16(const uint8_t *u8PtrMsg, uint16_t u16DataLen);
void Parameter_ReceiveData(void);//�������ݺ���
void Parameter_SendData(uint8_t Package_type ,uint16_t Data_Msg);//�������ݺ���
void Start_system(void);

extern u8 Send_Statflag;
#endif
