#include "stm32f4xx.h"
#include "ecRCC.h"
#include "ecGPIO.h"
#include "ecEXTI.h"


void EXTI_init(GPIO_TypeDef *port, int pin, int trig_type, int priority){
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	if(port == GPIOA){
		if(pin == 0){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI0;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI0_PA;
		}
		if(pin == 1){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI1;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI1_PA;
		}
		if(pin == 2){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI2;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI2_PA;
		}
		if(pin == 3){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI3;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI3_PA;
		}
		if(pin == 4){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI4;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI4_PA;
		}
		if(pin == 5){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI5;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI5_PA;
		}
		if(pin == 6){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI6;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI6_PA;
		}
		if(pin == 7){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI7;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI7_PA;
		}
		if(pin == 8){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI8;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI8_PA;
		}
		if(pin == 9){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI9;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI9_PA;
		}
		if(pin == 10){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI10;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI10_PA;
		}
		if(pin == 11){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI11;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI11_PA;
		}
		if(pin == 12){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI12;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI12_PA;
		}
		if(pin == 13){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI13;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI13_PA;
		}
		if(pin == 14){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI14;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI14_PA;
		}
		if(pin == 15){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI15;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI15_PA;
		}
	}
	
	if(port == GPIOB){
		if(pin == 0){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI0;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI0_PB;
		}
		if(pin == 1){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI1;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI1_PB;
		}
		if(pin == 2){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI2;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI2_PB;
		}
		if(pin == 3){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI3;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI3_PB;
		}
		if(pin == 4){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI4;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI4_PB;
		}
		if(pin == 5){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI5;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI5_PB;
		}
		if(pin == 6){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI6;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI6_PB;
		}
		if(pin == 7){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI7;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI7_PB;
		}
		if(pin == 8){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI8;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI8_PB;
		}
		if(pin == 9){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI9;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI9_PB;
		}
		if(pin == 10){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI10;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI10_PB;
		}
		if(pin == 11){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI11;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI11_PB;
		}
		if(pin == 12){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI12;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI12_PB;
		}
		if(pin == 13){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI13;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI13_PB;
		}
		if(pin == 14){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI14;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI14_PB;
		}
		if(pin == 15){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI15;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI15_PB;
		}
	}
	if(port == GPIOC){
		if(pin == 0){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI0;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI0_PC;
		}
		if(pin == 1){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI1;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI1_PC;
		}
		if(pin == 2){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI2;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI2_PC;
		}
		if(pin == 3){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR1_EXTI3;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR1_EXTI3_PC;
		}
		if(pin == 4){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI4;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI4_PC;
		}
		if(pin == 5){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI5;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI5_PC;
		}
		if(pin == 6){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI6;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI6_PC;
		}
		if(pin == 7){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR2_EXTI7;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR2_EXTI7_PC;
		}
		if(pin == 8){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI8;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI8_PC;
		}
		if(pin == 9){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI9;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI9_PC;
		}
		if(pin == 10){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI10;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI10_PC;
		}
		if(pin == 11){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR3_EXTI11;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR3_EXTI11_PC;
		}
		if(pin == 12){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI12;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI12_PC;
		}
		if(pin == 13){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI13;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI13_PC;
		}
		if(pin == 14){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI14;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI14_PC;
		}
		if(pin == 15){
		SYSCFG->EXTICR[pin/4] &= ~SYSCFG_EXTICR4_EXTI15;
		SYSCFG->EXTICR[pin/4] |= ~SYSCFG_EXTICR4_EXTI15_PC;
		}
	}
	
	
	if(trig_type == FALL) EXTI->FTSR |= 1UL << pin;
	if(trig_type == RISE) EXTI->RTSR |= 1UL << pin;
	
	if(pin == 0){
		NVIC_SetPriority(EXTI0_IRQn , priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI0_IRQn);
	}
	
	if(pin == 1){
		NVIC_SetPriority(EXTI1_IRQn, priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI1_IRQn);
	}
	
	if(pin == 2){
		NVIC_SetPriority(EXTI2_IRQn, priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI2_IRQn);
	}
	
	if(pin == 3){
		NVIC_SetPriority(EXTI3_IRQn, priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI3_IRQn);
	}
	
	if(pin == 4){
		NVIC_SetPriority(EXTI4_IRQn, priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI4_IRQn);
	}
	if(pin >= 5 && pin <= 9){
		NVIC_SetPriority(EXTI9_5_IRQn, priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI9_5_IRQn);
	}
	if(pin >= 10 && pin <= 15){
		NVIC_SetPriority(EXTI15_10_IRQn, priority);  		// Set EXTI priority as 0	
		NVIC_EnableIRQ(EXTI15_10_IRQn);
	}
}

void EXTI_enable(uint32_t pin){
	EXTI->IMR  |= 1UL << pin;  
}

void EXTI_disable(uint32_t pin){
	EXTI->EMR  |= 1UL << pin; 
}

uint32_t is_pending_EXTI(uint32_t pin){
   uint32_t btVal;
   btVal = EXTI->PR & (1UL << pin);
   return btVal;
}

void clear_pending_EXTI(uint32_t pin){
   EXTI->PR |= 1UL << pin;
}
