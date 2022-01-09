#include "stm32f10x.h"
#include "GPIO_HAL.h"
#include "stdint.h" 

static int32_t start_bit[16]={(0x00),(0x04),(0x08),(0x0C),(0x10),(0x14),(0x18),(0x1C),(0x00),(0x04),(0x08),(0x0C),(0x10),(0x14),(0x18),(0x1C)};


void RCC_ENABLE(uint8_t value) 
{
	RCC->APB2ENR |= (1<<value);	
}


void pin_mode(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t modeType)
{
	if(pinNumber>=8)
	{
		switch(modeType)
		{
			case INPUT_MODE :
				port->CRH &= ~(1<<MODE_B1);
				port->CRH &= ~(1<<MODE_B2);
			break;
			
			case OUTPUT_02MHZ :
				port->CRH |= 1<<MODE_B1;
				port->CRH &= ~(1<<MODE_B2);
			break;
			
			case OUTPUT_10MHZ :
				port->CRH &= ~(1<<MODE_B1);
				port->CRH |= 1<<MODE_B2;
			break;
			
			case OUTPUT_50MHZ :
				port->CRH |= 1<<MODE_B1;
				port->CRH |= 1<<MODE_B2;
			break;
		}
	}
	else
	{
		switch(modeType)
		{
			case INPUT_ANALOG | OUTPUT_GP_PP :
				port->CRL &= ~(1<<MODE_B1);
				port->CRL &= ~(1<<MODE_B2);
			break;
			
			case INPUT_FLOATING | OUTPUT_GP_OD :
				port->CRL |= 1<<MODE_B1;
				port->CRL &= ~(1<<MODE_B2);
			break;
			
			case INPUT_PUPD | OUTPUT_AF_PP :
				port->CRL &= ~(1<<MODE_B1);
				port->CRL |= 1<<MODE_B2;
			break;
			
			case OUTPUT_AF_OD :
				port->CRL |= 1<<MODE_B1;
				port->CRL |= 1<<MODE_B2;
			break;
		}
	}
}




void pin_config(GPIO_TypeDef *port, uint32_t pinNumber, uint32_t configType)
	{
	if(pinNumber>=8)
	{
		switch(configType)
		{
			case INPUT_ANALOG | OUTPUT_GP_PP :
				port->CRH &= ~(1<<CONFIG_B1);
				port->CRH &= ~(1<<CONFIG_B2);
			break;
			
			case INPUT_FLOATING | OUTPUT_GP_OD :
				port->CRH |= 1<<CONFIG_B1;
				port->CRH &= ~(1<<CONFIG_B2);
			break;
			
			case INPUT_PUPD | OUTPUT_AF_PP :
				port->CRH &= ~(1<<CONFIG_B1);
				port->CRH |= 1<<CONFIG_B2;
			break;
			
			case OUTPUT_AF_OD :
				port->CRH |= 1<<CONFIG_B1;
				port->CRH |= 1<<CONFIG_B2;
			break;
		}
	}
	else
	{
		switch(configType)
		{
			case INPUT_ANALOG | OUTPUT_GP_PP :
				port->CRL &= ~(1<<CONFIG_B1);
				port->CRL &= ~(1<<CONFIG_B2);
			break;
			
			case INPUT_FLOATING | OUTPUT_GP_OD :
				port->CRL |= 1<<CONFIG_B1;
				port->CRL &= ~(1<<CONFIG_B2);
			break;
			
			case INPUT_PUPD | OUTPUT_AF_PP :
				port->CRL &= ~(1<<CONFIG_B1);
				port->CRL |= 1<<CONFIG_B2;
			break;
			
			case OUTPUT_AF_OD :
				port->CRL |= 1<<CONFIG_B1;
				port->CRL |= 1<<CONFIG_B2;
			break;
		}
	}
}
	
void pin_write(GPIO_TypeDef *port,uint32_t pinNumber,uint8_t state)
{
	if(state)
		port->BSRR = (1<<(pinNumber +16));  
	else
		port->BSRR = (1<<(pinNumber));	
}

void pin_toggle(GPIO_TypeDef *port,uint32_t pinNumber)
{
	port->ODR ^= (1<<(pinNumber));	
}

