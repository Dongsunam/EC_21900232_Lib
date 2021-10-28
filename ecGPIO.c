#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecGPIO.h"

//GPIO init
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode){     
   
	if (Port == GPIOA)
		RCC_GPIOA_enable();
	if (Port == GPIOB)
		RCC_GPIOB_enable();
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

//sevensegement
void sevensegment_init(void){
	RCC_HSI_init();	
	GPIO_init(GPIOA, segement_a, OUTPUT);
	GPIO_init(GPIOA, segement_b, OUTPUT);
	GPIO_init(GPIOC, segement_c, OUTPUT);
	GPIO_init(GPIOA, segement_d, OUTPUT);
	GPIO_init(GPIOA, segement_e, OUTPUT);
	GPIO_init(GPIOA, segement_f, OUTPUT);
	GPIO_init(GPIOA, segement_g, OUTPUT);

}

void sevensegment_decoder(unsigned int num){
	
	if (num == 0){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, LOW);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, HIGH);
	}
	else if (num == 1){
		GPIO_write(GPIOA, segement_a, HIGH);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, HIGH);
		GPIO_write(GPIOA, segement_e, HIGH);
		GPIO_write(GPIOA, segement_f, HIGH);
		GPIO_write(GPIOA, segement_g, HIGH);
	}
	else if (num == 2){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, HIGH);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, LOW);
		GPIO_write(GPIOA, segement_f, HIGH);
		GPIO_write(GPIOA, segement_g, LOW);
	}	
	else if (num == 3){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, HIGH);
		GPIO_write(GPIOA, segement_f, HIGH);
		GPIO_write(GPIOA, segement_g, LOW);
	}
	else if (num == 4){
		GPIO_write(GPIOA, segement_a, HIGH);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, HIGH);
		GPIO_write(GPIOA, segement_e, HIGH);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, LOW);
	}
	else if (num == 5){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, HIGH);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, HIGH);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, LOW);
	}
	if (num == 6){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, HIGH);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, LOW);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, LOW);
	}
	else if (num == 7){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, HIGH);
		GPIO_write(GPIOA, segement_e, HIGH);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, HIGH);
	}
	else if (num == 8){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, LOW);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, LOW);
	}
	else if (num == 9){
		GPIO_write(GPIOA, segement_a, LOW);
		GPIO_write(GPIOA, segement_b, LOW);
		GPIO_write(GPIOC, segement_c, LOW);
		GPIO_write(GPIOA, segement_d, LOW);
		GPIO_write(GPIOA, segement_e, HIGH);
		GPIO_write(GPIOA, segement_f, LOW);
		GPIO_write(GPIOA, segement_g, LOW);
	}

}


void LED_init(void){
	RCC_HSI_init();	
	GPIO_init(GPIOA, LED_PIN, OUTPUT); 
}


void LED_toggle(void){
	GPIOA->ODR ^= (1UL<<(LED_PIN)); 
}
