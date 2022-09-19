/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STK.h
 *       Module:  STK
 *
 *  Description:  header File for interfacing     
 *  
 *********************************************************************************************************************/
 
 #ifndef STK_H_
 #define STK_H_

extern uint32 OnTimeMS;
extern uint32 OffTimeMS;

/******************************************************************************
 * Syntax          : void STK_init(void) 
 * Description     : Initailize the SysTick 
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void STK_init(void);

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
void STK_SetTime(uint8 OnTime,uint8 OffTime);

/******************************************************************************
 * Syntax          : void STK_SetCallBack(void(*pvCallBackFunc)(void))
 * Description     : get the address of the user function to be used by ISR
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : void(*pvCallBackFunc)(void)
 * Parameters (out): None
 * Return value:   : void
 ******************************************************************************/
void STK_SetCallBack(void(*pvCallBackFunc)(void));
 
 #endif