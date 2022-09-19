/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Lcfg.c
 *       Module:  IntCtrl
 *
 *  Description:  C File to Link Time Configurations    
 *  
 *********************************************************************************************************************/

#include "Platform_Types.h"
#include "Std_Types.h"
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"

/*The NVIC_Arr is Array of structs and every struct contains:
 *1- NVIC_Peripheral: The peripheral you want to activate
 *2- GRP_PR: The group priority of Peripheral
 *3- Sub_PR: The Sub priority of Peripheral*/

NVIC_Config_t NVIC_Arr[NVIC_Activate_Peripherals_NUM]={{GPIOA_Handler,2,0},
													   {UART6_Handler,1,1}};
										 
/*Choose the Configuration of Group and sub priority:
 * SCB_8_GPR_1_SUB_PR
 * SCB_4_GPR_2_SUB_PR
 * SCB_2_GPR_4_SUB_PR
 * SCB_1_GPR_8_SUB_PR
*/
uint8 SCB_GRP_SUB_PR = SCB_4_GPR_2_SUB_PR;
