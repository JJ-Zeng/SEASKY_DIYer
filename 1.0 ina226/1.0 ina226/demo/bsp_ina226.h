#ifndef __INA226_H
#define __INA226_H
#include "sys.h"
#include "bsp_iic.h"
#define 	CFG_REG	 		0x00		//
#define 	SV_REG 			0x01		//������ѹ
#define 	BV_REG 			0x02		//���ߵ�ѹ
#define 	PWR_REG 		0x03		//��Դ����
#define 	CUR_REG 		0x04		//����
#define 	CAL_REG 		0x05		//У׼���趨�����̷�Χ�Լ������͹��ʲ����� 
#define 	ONFF_REG 		0x06		//���� ʹ�� �������ú�ת��׼������
#define 	AL_REG 			0x07		//��������ѡ����������Ƚϵ��޶�ֵ
#define 	INA226_GET_ADDR 0XFF		//����Ψһ��оƬ��ʶ��
#define   	INA226_ADDR1	0x80 
//#define   INA226_GETALADDR	0x14 

//������������
#define 	INA226_VAL_LSB	2.5f	//������ѹ LSB 2.5uV
#define     Voltage_LSB		1.25f   //���ߵ�ѹ LSB 1.25mV
#define     CURRENT_LSB 	1.0f 	//����LSB 1mA
#define     POWER_LSB       25*CURRENT_LSB
#define     CAL             456     //0.00512/(Current_LSB*R_SHUNT) = 470  //����ƫ���С

typedef struct
{
	float voltageVal;			//mV
	float Shunt_voltage;		//uV
	float Shunt_Current;		//mA
	float Power_Val;				//����
	float Power;				//����mW
	u32   ina226_id;
}INA226;

void INA226_SetRegPointer(u8 addr,u8 reg);
void INA226_SendData(u8 addr,u8 reg,u16 data);

u16 INA226_ReadData(u8 addr);
void INA226_Get_ID(u8 addr);			//��ȡ id
u16 INA226_GetVoltage( u8 addr);		//��ȡ���ߵ�ѹװ��ֵ
u16 INA226_GetShunt_Current(u8 addr);	//��ȡ��������װ��ֵ
u16 INA226_GetShuntVoltage(u8 addr);	//������ѹװ��ֵ
//u16 INA226_Get_Power(u8 addr);		//��ȡ����װ��ֵ����ʹ��
u16 INA226_GET_CAL_REG(u8 addr);		//��ȡУ׼ֵ

void mx_ina226_init(void);
void GetVoltage(float *Voltage);		
void Get_Shunt_voltage(float *Current);
void Get_Shunt_Current(float *Current);
void get_power(void);						////��ȡ����= ���ߵ�ѹ * ����

u8	INA226_AlertAddr(void);
void Get_Power(float *Power);
extern INA226 ina226_data;
#endif
