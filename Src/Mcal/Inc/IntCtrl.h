/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  IntCtrl
 *
 *  Description:  header File for interfacing   
 *  
 *********************************************************************************************************************/
#ifndef INTCRTL_H_
#define INTCRTL_H_

#define SCB_VECTKEY					0x05FA0000UL

#define SCB_8_GPR_1_SUB_PR			4
#define SCB_4_GPR_2_SUB_PR			5
#define SCB_2_GPR_4_SUB_PR			6
#define SCB_1_GPR_8_SUB_PR			7

/******************************************************************************
 * Syntax          : IntCtr_Init(void) 
 * Description     : Initialize the interrupt sources with the user requirment
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void IntCtr_Init(void);

#endif