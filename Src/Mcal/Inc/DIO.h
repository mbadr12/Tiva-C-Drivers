/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  header File for interfacing   
 *  
 *********************************************************************************************************************/
 
#ifndef DIO_H_
#define DIO_H_

/******************************************************************************
 * Syntax          :  DIO_LevelType DIO_ReadPort(GPIO_Port_t port_Num) 
 * Description     :  get the reading of DIO Port
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : port_Num  The port you want to get its value
 * Parameters (out): Port state
 * Return value:   : DIO_LevelType
 *******************************************************************************/
DIO_LevelType DIO_ReadPort(GPIO_Port_t port_Num);

/******************************************************************************
 * Syntax          :  DIO_LevelType DIO_ReadPIN(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num) 
 * Description     :  get the reading of DIO Pin
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : port_Num  The port of the pin you want to get its value
					 Pin_Num The pin you want to get its value
 * Parameters (out): pin state
 * Return value:   : DIO_LevelType
 *******************************************************************************/
DIO_LevelType DIO_ReadPIN(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num);

/******************************************************************************
 * Syntax          : void void DIO_SetPortValue(GPIO_Port_t port_Num, DIO_LevelType Value) 
 * Description     : set the value of DIO Pin
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : port_Num  The port you want to set its value
					 value: the value you want the port be
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void DIO_SetPortValue(GPIO_Port_t port_Num, DIO_LevelType Value);

/******************************************************************************
 * Syntax          : void DIO_SetPinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num , GPIO_pinState_t Value) 
 * Description     : set the value of DIO Pin
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : port_Num  The port of the pin you want to set its value
					 Pin_Num The pin you want to set its value
					 value: the value you want the pin be input/output
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void DIO_SetPinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num , GPIO_pinState_t Value);

/******************************************************************************
 * Syntax          : void DIO_TogglePinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num) 
 * Description     : Toggle the value of DIO Pin
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : port_Num  The port of the pin you want to toggel its value
					 Pin_Num The pin you want to toggle its value
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void DIO_TogglePinValue(GPIO_Port_t port_Num , GPIO_pin_t Pin_Num);

#endif
