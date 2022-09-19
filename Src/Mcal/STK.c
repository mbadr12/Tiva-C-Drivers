/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STK.c
 *       Module:  STK
 *
 *  Description:  C File to Impelement the Function    
 *  
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"

#include "STK.h"
#include "STK_Cfg.h"

/*Global pointer to function*/
void (*STK_pvCallBackFunc)(void)=NULL;

/*Global variables for on and off time*/

uint32 OnTimeMS;
uint32 OffTimeMS;

/******************************************************************************
 * Syntax          : void STK_init(void) 
 * Description     : Initailize the SysTick 
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void STK_init(void)
{
	/*1- Program the value in the STRELOAD register*/
	STK->STRELOAD = 4000*STK_LOAD_VALUE;
	/*2- Clear the STCURRENT register by writing to it with any value*/
	STK->STCURRENT=0x10;
	/*3- Configure the STCTRL register for the required operation*/
	/*3.1- set the clock source as Precision internal oscillator (PIOSC) divided by 4*/
	STK->STCTRL &= ~(1<<2);
	/*3.2 Interrupt generation is enabled*/
	STK->STCTRL |= (1<<1);
	/*3.3- Enables SysTick to operate in a multi-shot way*/
	STK->STCTRL |= 1;
}
/******************************************************************************
 * Syntax          :  void STK_SetTime(uint8 OnTime,uint8 OffTime) 
 * Description     :  Set two delay durations for the SysTick ISR 
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : OnTime  The amount of time for the LED to be on 
                     OffTime The amount of time for the LED to be off
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void STK_SetTime(uint8 OnTime,uint8 OffTime)
{
	/*Passing on time to global variable to be in Ms*/
	OnTimeMS=OnTime*1000;
	/*Passing off time to global variable to be in Ms*/
	OffTimeMS=OffTime*1000;
}
/******************************************************************************
 * Syntax          : void STK_SetCallBack(void(*pvCallBackFunc)(void))
 * Description     : get the address of the user function to be used by ISR
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : void(*pvCallBackFunc)(void)
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void STK_SetCallBack(void(*pvCallBackFunc)(void))
{
	/*Passing pointer to function to Global pointer function*/
	STK_pvCallBackFunc = pvCallBackFunc;

}

/******************************************************************************
 * Syntax          : void SysTick_Handler(void)
 * Description     : SysTick ISR
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant/Non Reentrant --> Depends on the user implementation of the ISR
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
/* ISR IS EXECUTED EVERY 1 MS */
void SysTick_Handler(void)
{
	if(STK_pvCallBackFunc != NULL)
	{
		STK_pvCallBackFunc();
	}
}