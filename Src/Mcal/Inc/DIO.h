/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  header File for interfacing   
 *  
 *********************************************************************************************************************/
 
#ifndef DIO_H_
#define DIO_H_

DIO_LevelType DIO_ReadPort(GPIO_Port_t port_Num);

DIO_LevelType DIO_ReadPIN(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num);

void DIO_SetPortValue(GPIO_Port_t port_Num, DIO_LevelType Value);

void DIO_SetPinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num , GPIO_pinState_t Value);

void DIO_TogglePinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num);

#endif
