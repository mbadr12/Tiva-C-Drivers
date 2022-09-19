/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Lcfg.c
 *       Module:  Port
 *
 *  Description:  C File to Link Time Configurations    
 *  
 *********************************************************************************************************************/

#include "Platform_Types.h"
#include "Std_Types.h"
#include "Port.h"
#include "Port_Cfg.h"

/*Array of Structs to Enter The configuration of the Pins you Want to Configured
 *The Arguments of The Struct Are:
 *Note: you can Find The Options of The Arguments in the Std_Types.h
 *1- Port: The port of Pin you Want To Configure
 *2- Pin: The Pin number You Want to Configure
 *3- Mode: The Mode you want for Pin
 *4- PullUpDown:the State of iternal Resistor
 *5- OutputCurrent: The Output Current of Pin
 *6- AltFunc: the AltFun Number If the Pin is In Alternative Function Mode*/

GPIO_PinConfig_t Config_ports[CNFGED_PINS_NUM]={
							{GPIO_PORTF,
							GPIO_PIN1,
							GPIO_PIN_OUTPUT,
							GPIO_DONT_CARE,
							GPIO_2MA_DRIVE,
							GPIO_DONT_CARE}};
												