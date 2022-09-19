/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.c
 *       Module:  Port
 *
 *  Description:  C File to Impelement the Function    
 *  
 *********************************************************************************************************************/
 
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Mcu_Hw.h"

#include "Port.h"
#include "Port_Cfg.h"

/*Array of pointers to struct of ports*/

GPIO_RegDef_t* GPIO_PortArr[GPIO_PORT_NUM]={GPIOA ,GPIOB ,GPIOC ,GPIOD ,GPIOE ,GPIOF};

extern GPIO_PinConfig_t Config_ports[CNFGED_PINS_NUM];

/******************************************************************************
 * Syntax          : Port_Init(void) 
 * Description     : Initialize the pin with the user requirment
 * Sync\Async      : Synchronous
 * Reentrancy      : Reentrant
 * Parameters (in) : None
 * Parameters (out): None
 * Return value:   : void
 *******************************************************************************/
void Port_Init(void)
{
	uint8 iterator=0;
	for(iterator=0; iterator < CNFGED_PINS_NUM ; iterator++)
	{
		/*1- open Clock on the port*/
		RC_RCGCGPIO |= 1<<(Config_ports[iterator].Port);
		/*2- Choose The Mode of the Pin*/
		switch(Config_ports[iterator].Mode)
		{
			case GPIO_PIN_INPUT:
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIODIR &= ~(1<< (Config_ports[iterator].Pin)); 
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIODEN |= (1<< (Config_ports[iterator].Pin)); break;
			case GPIO_PIN_OUTPUT:
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIODEN |= (1<< (Config_ports[iterator].Pin));
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIODIR |= (1<< (Config_ports[iterator].Pin)); 
			/*Case The pin output: Choose The OutputCurrent*/
			switch(Config_ports[iterator].OutputCurrent)
			{
				case GPIO_2MA_DRIVE:
				(GPIO_PortArr[Config_ports[iterator].Port])->GPIODR2R |= (1<< (Config_ports[iterator].Pin)); break;
				case GPIO_4MA_DRIVE:
				(GPIO_PortArr[Config_ports[iterator].Port])->GPIODR4R |= (1<< (Config_ports[iterator].Pin)); break;
				case GPIO_8MA_DRIVE:
				(GPIO_PortArr[Config_ports[iterator].Port])->GPIODR8R |= (1<< (Config_ports[iterator].Pin)); break;
			}break;
			case GPIO_PIN_ALTFUNC: 
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIOAFSEL |= (1<< (Config_ports[iterator].Pin)); 
			/*Case The Pin is Alternative Function: Choose The coresponding AltFunc*/
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIOPCTL |=(uint32)((Config_ports[iterator].AltFunc) << ((Config_ports[iterator].Pin)*4)); break;
			case GPIO_PIN_ANALOG:
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIOAMSEL |= (1<< (Config_ports[iterator].Pin)); break;
		}
		/*3- Choose The Pin Pull Up Down State*/
		switch(Config_ports[iterator].PullUpDown)
		{
			case GPIO_OPENDRAIN:
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIOODR |= (1<< (Config_ports[iterator].Pin)); break;
			case GPIO_PULLUP:
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIOPUR |= (1<< (Config_ports[iterator].Pin)); break;
			case GPIO_PULLDOWN:
			(GPIO_PortArr[Config_ports[iterator].Port])->GPIOPDR |= (1<< (Config_ports[iterator].Pin)); break;
		}
	}
}
