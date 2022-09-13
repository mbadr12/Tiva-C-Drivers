/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.c
 *       Module:  DIO
 *
 *  Description:  C File to Impelement the Function    
 *  
 *********************************************************************************************************************/

#include "Platform_Types.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"

#include "DIO.h"

extern GPIO_RegDef_t* GPIO_PortArr[6];

DIO_LevelType DIO_ReadPort(GPIO_Port_t port_Num)
{
	/*The Address of GPIODATA Bits from 2 to 9 should Be ones and GPIODATA[255] Fullfils the condition*/
	return (uint8)GPIO_PortArr[port_Num]->GPIODATA[255];
}

DIO_LevelType DIO_ReadPIN(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num)
{
	/*The Address of GPIODATA Bits from 2 to 9 coresponds to pins from 0 to 7*/
	uint8 iterator=0 , DataRegNum=1;
	for(iterator=0; iterator < Pin_Num ; iterator++)
	{
		DataRegNum*=2;
	}
	return (uint8)((GPIO_PortArr[port_Num]->GPIODATA[DataRegNum])<< Pin_Num);
}

void DIO_SetPortValue(GPIO_Port_t port_Num, DIO_LevelType Value)
{
	/*The Address of GPIODATA Bits from 2 to 9 should Be ones and GPIODATA[255] Fullfils the condition*/
	GPIO_PortArr[port_Num]->GPIODATA[255] = Value;
}

void DIO_SetPinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num , GPIO_pinState_t Value)
{
	/*The Address of GPIODATA Bits from 2 to 9 coresponds to pins from 0 to 7*/
	uint8 iterator=0 , DataRegNum=1;
	for(iterator=0; iterator < Pin_Num ; iterator++)
	{
		DataRegNum*=2;
	}
	GPIO_PortArr[port_Num]->GPIODATA[DataRegNum]= (uint32)(Value << Pin_Num);
}

void DIO_TogglePinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num)
{
	/*The Address of GPIODATA Bits from 2 to 9 coresponds to pins from 0 to 7*/
	uint8 iterator=0 , DataRegNum=1;
	for(iterator=0; iterator < Pin_Num ; iterator++)
	{
		DataRegNum*=2;
	}
	GPIO_PortArr[port_Num]->GPIODATA[DataRegNum] ^= (1 << Pin_Num);
}
