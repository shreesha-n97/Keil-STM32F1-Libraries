#ifndef GPIO_HAL
#define GPIO_HAL
#include "stm32f10x.h"

//CLOCK ENABLE
#define CE_AF				0
#define CE_PORTA		2		
#define CE_PORTB		3		
#define CE_PORTC		4		
#define CE_PORTD		5		
#define CE_PORTE		6	
#define CE_PORTF		7		
#define CE_PORTG		8		
	

//PORT NAME
#define PORTA	GPIOA
#define PORTB	GPIOB
#define PORTC	GPIOC
#define PORTD	GPIOD
#define PORTE	GPIOE
#define PORTF	GPIOF
#define PORTG	GPIOG

//PIN MODE
#define INPUT_MODE				((uint32_t) 0x00)
#define OUTPUT_02MHZ			((uint32_t) 0x02)
#define OUTPUT_10MHZ			((uint32_t) 0x01)
#define OUTPUT_50MHZ			((uint32_t) 0x03)

//INPUT CONFIG TYPES
#define INPUT_ANALOG		((uint32_t) 0x00)
#define INPUT_FLOATING	((uint32_t) 0x01)
#define INPUT_PUPD			((uint32_t) 0x02)

//OUTPUT CONFIG TYPES
#define OUTPUT_GP_PP		((uint32_t) 0x00)
#define OUTPUT_GP_OD		((uint32_t) 0x01)
#define OUTPUT_AF_PP		((uint32_t) 0x02)
#define OUTPUT_AF_OD	  ((uint32_t) 0x03)


//PORT CONFIG REGISTER BITs
#define MODE_B1 	(start_bit[pinNumber])
#define MODE_B2		(start_bit[pinNumber] + 1)
#define CONFIG_B1 (start_bit[pinNumber] + 2)
#define CONFIG_B2 (start_bit[pinNumber] + 3)


typedef struct
{
	GPIO_TypeDef *port;
	uint32_t pin;
	uint32_t mode;
	uint32_t mode_type;
	uint32_t pull;
	uint32_t speed;
	uint32_t alt_func;
	}GPIO_TYPE;

/*************************************************************************************
FUNCTION PROTOTYPE
void RCC_ENABLE(uint8_t value);
	
AVAILABLE PARAMETER
	- CE_AF,CE_PORTx
**************************************************************************************/
void RCC_ENABLE(uint8_t value);
	
/*************************************************************************************
FUNCTION PROTOTYPE
void pin_mode(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t modeType);
	
USABLE PARAMETER
	- port 			=	PORTx
	- pinNumber = x;
	- modeType  =	INPUT_MODE,OUTPUT_02MHZ,OUTPUT_10MHZ,OUTPUT_50MHZ
*************************************************************************************/
void pin_mode(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t modeType);

/*************************************************************************************
FUNCTION PROTOTYPE
void pin_config(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t configType);
	
USABLE PARAMETER
	- port 				=	PORTx
	- pinNumber 	= x;
	- configType  =	INPUT_ANALOG,INPUT_FLOATING,INPUT_PUPD,,OUTPUT_GP_PP,OUTPUT_GP_OD,OUTPUT_AF_PP,OUTPUT_AF_OD
*************************************************************************************/
void pin_config(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t configType);

/*************************************************************************************
FUNCTION PROTOTYPE
void pin_write(GPIO_TypeDef *port,uint32_t pinNumber,uint8_t state);

USABLE PARAMETER
	- port 			=	PORTx
	- pinNumber = x;
	- state  		=	1
*************************************************************************************/
void pin_write(GPIO_TypeDef *port,uint32_t pinNumber,uint8_t state);
/*************************************************************************************
FUNCTION PROTOTYPE
void pin_write(GPIO_TypeDef *port,uint32_t pinNumber,uint8_t state);

USABLE PARAMETER
	- port 			=	PORTx
	- pinNumber = x;
*************************************************************************************/	
void pin_toggle(GPIO_TypeDef *port,uint32_t pinNumber);


#endif
