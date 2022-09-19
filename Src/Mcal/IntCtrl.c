/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.c
 *       Module:  IntCtrl
 *
 *  Description:  C File to Impelement the Function    
 *  
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"

#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"

extern NVIC_Config_t NVIC_Arr[NVIC_Activate_Peripherals_NUM];
extern uint8 SCB_GRP_SUB_PR;

/******************************************************************************
 * Syntax          : IntCtr_Init(void) 
 * Description     : Initialize the interrupt sources with the user requirment
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void IntCtr_Init(void)
{
	/*1- determine number of bits for GRP Priority and Sub Priority*/
	SCB_APINT = (SCB_VECTKEY | (SCB_GRP_SUB_PR<<8));
	for(uint8 itrator=0 ; itrator < NVIC_Activate_Peripherals_NUM ; itrator++)
	{
	 /*2- determine the GRP Priority and Sub Priority*/
		uint8 peripheral_priority;
		switch(SCB_GRP_SUB_PR)
		{
			case SCB_8_GPR_1_SUB_PR: peripheral_priority = NVIC_Arr[itrator].GRP_PR <<5; break;
			case SCB_4_GPR_2_SUB_PR: peripheral_priority = ((NVIC_Arr[itrator].GRP_PR<<1) | (NVIC_Arr[itrator].Sub_PR))<<5; break;
			case SCB_2_GPR_4_SUB_PR: peripheral_priority = ((NVIC_Arr[itrator].GRP_PR<<2) | (NVIC_Arr[itrator].Sub_PR))<<5; break;
			case SCB_1_GPR_8_SUB_PR: peripheral_priority = NVIC_Arr[itrator].Sub_PR <<5; break;
		}
		NVIC->PRI[(NVIC_Arr[itrator].NVIC_Peripheral)] = peripheral_priority;
	 /*3- Enable peripheral NVIC interrupt*/
		uint8 register_num = ((NVIC_Arr[itrator].NVIC_Peripheral) /32);
		uint8 bit_num = ((NVIC_Arr[itrator].NVIC_Peripheral) % 32);
		NVIC->EN[register_num] |= 1 << bit_num;
	}
}