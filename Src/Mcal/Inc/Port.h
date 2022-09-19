/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  header File for interfacing   
 *  
 *********************************************************************************************************************/
 
#ifndef PORT__H_
#define PORT__H_

#define GPIO_PORT_NUM				6
	
#define GPIO_ACTIVE_AHB_BUS			0x3f

/******************************************************************************
 * Syntax          : Port_Init(void) 
 * Description     : Initialize the pin with the user requirment
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void Port_Init(void);

#endif
