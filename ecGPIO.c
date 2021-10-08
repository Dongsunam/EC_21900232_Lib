#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecGPIO.h"

//GPIO init
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode){     
   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	if (Port == GPIOC)
		RCC_GPIOC_enable();
 

	GPIO_mode(Port, pin, mode);
	
}
// GPIO Mode          : Input(00), Output(01), AlterFunc(10), Analog(11, reset)
void GPIO_mode(GPIO_TypeDef *Port, int pin, int mode){

	
   Port->MODER &= ~(3UL<<(2*pin));     
   Port->MODER |= mode<<(2*pin);    
}
//GPIO write
void GPIO_write(GPIO_TypeDef *Port, int pin, int Output){
//ODR	
	 Port->ODR &= ~(1UL<<(pin));     
   Port->ODR |= Output<<(pin); 
}

int GPIO_read(GPIO_TypeDef *Port, int pin){
	//IDR	
	 unsigned int btVal;
	 btVal = (Port->IDR) & (1UL<<(pin)); 
	 return btVal;
}

void GPIO_ospeed(GPIO_TypeDef* Port, int pin, int speed){
	//OSPEEDR
	 Port->OSPEEDR &= ~(1UL<<(pin));     
   Port->OSPEEDR |= speed<<(pin);
}

void GPIO_otype(GPIO_TypeDef* Port, int pin, int type){
	//OTYPE
	 Port->OTYPER &= ~(1UL<<(pin));     
   Port->OTYPER |= type<<(pin);
}

void GPIO_pudr(GPIO_TypeDef* Port, int pin, int pudr){
	//PUPDR
	 Port->PUPDR &= ~(1UL<<(pin));     
   Port->PUPDR |= pudr<<(pin);
}