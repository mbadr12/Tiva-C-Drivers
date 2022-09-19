/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Platform_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define STD_HIGH     1u /* Physical state 5V or 3.3V */
# define STD_LOW      0u /* Physical state 0V */

# define STD_ACTIVE   1u /* Logical state active */
# define STD_IDLE     0u /* Logical state idle */

# define STD_ON       1u
# define STD_OFF      0u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/***************************************  NVIC DATA TYPES ************************************************************/

typedef enum
{
	GPIOA_Handler=0,      
	GPIOB_Handler,      
	GPIOC_Handler,      
	GPIOD_Handler,      
	GPIOE_Handler,      
	UART0_Handler,      
	UART1_Handler,      
	SSI0_Handler,       
	I2C0_Handler,       
	PMW0_FAULT_Handler, 
	PWM0_0_Handler,     
	PWM0_1_Handler,     
	PWM0_2_Handler,     
	QEI0_Handler,      
	ADC0SS0_Handler,    
	ADC0SS1_Handler,    
	ADC0SS2_Handler,    
	ADC0SS3_Handler,    
	WDT0_Handler,       
	TIMER0A_Handler,    
	TIMER0B_Handler,    
	TIMER1A_Handler,    
	TIMER1B_Handler,    
	TIMER2A_Handler,    
	TIMER2B_Handler,    
	COMP0_Handler,      
	COMP1_Handler,            
	SYSCTL_Handler=28,     
	FLASH_Handler,      
	GPIOF_Handler,            
	UART2_Handler=33,      
	SSI1_Handler,       
	TIMER3A_Handler,    
	TIMER3B_Handler,    
	I2C1_Handler,       
	QEI1_Handler,       
	CAN0_Handler,       
	CAN1_Handler,                        
	HIB_Handler=43,        
	USB0_Handler,       
	PWM0_3_Handler,     
	UDMA_Handler,       
	UDMAERR_Handler,    
	ADC1SS0_Handler,    
	ADC1SS1_Handler,    
	ADC1SS2_Handler,    
	ADC1SS3_Handler,       
	SSI2_Handler=57,     
	SSI3_Handler,       
	UART3_Handler,      
	UART4_Handler,      
	UART5_Handler,      
	UART6_Handler,      
	UART7_Handler,                       
	I2C2_Handler=68,      
	I2C3_Handler,    
	TIMER4A_Handler,    
	TIMER4B_Handler,       
	TIMER5A_Handler=92,    
	TIMER5B_Handler,
	WTIMER0A_Handler,   
	WTIMER0B_Handler,   
	WTIMER1A_Handler,   
	WTIMER1B_Handler,   
	WTIMER2A_Handler,   
	WTIMER2B_Handler,   
	WTIMER3A_Handler,   
	WTIMER3B_Handler,   
	WTIMER4A_Handler,   
	WTIMER4B_Handler,   
	WTIMER5A_Handler,   
	WTIMER5B_Handler,   
	FPU_Handler,      
	PMW1_0_Handler=134,     
	PWM1_1_Handler,     
	PWM1_2_Handler,     
	PWM1_3_Handler,     
	PWM1_FAULT_Handler
}IRQ_Num;

typedef struct
{
	IRQ_Num NVIC_Peripheral;
	uint8 GRP_PR;
	uint8 Sub_PR;
}NVIC_Config_t;

typedef enum
{
	GPIO_PORTA=0,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE,
	GPIO_PORTF
}GPIO_Port_t;

typedef enum
{
	GPIO_PIN0=0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7
}GPIO_pin_t;

typedef enum
{
	GPIO_PIN_INPUT=0,
	GPIO_PIN_OUTPUT,
	GPIO_PIN_ALTFUNC,
	GPIO_PIN_ANALOG
}GPIO_pinMode_t;

typedef enum
{
	GPIO_PIN_LOW=0,
    GPIO_PIN_HIGH
}GPIO_pinState_t;

typedef enum
{
	GPIO_OPENDRAIN=0,
	GPIO_PULLUP,
	GPIO_PULLDOWN
}GPIO_PullUpDown_t;

typedef enum
{
	ALTFUNC0,
	ALTFUNC1,
	ALTFUNC2,
	ALTFUNC3,
	ALTFUNC4,
	ALTFUNC5,
	ALTFUNC6,
	ALTFUNC7
}GPIO_AltFunc_t;

typedef enum
{
	GPIO_2MA_DRIVE,
	GPIO_4MA_DRIVE,
	GPIO_8MA_DRIVE
}GPIO_OutputCurrent_t;

typedef struct
{
	GPIO_Port_t Port;
	GPIO_pin_t Pin;
	GPIO_pinMode_t Mode;
	GPIO_PullUpDown_t PullUpDown;
	GPIO_OutputCurrent_t OutputCurrent;
	GPIO_AltFunc_t AltFunc;
}GPIO_PinConfig_t;

#define GPIO_DONT_CARE	9

typedef	uint8 DIO_LevelType;

typedef uint8 Std_ReturnType;
#define E_OK          0u
#define E_NOT_OK      1u

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NULL		0
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
