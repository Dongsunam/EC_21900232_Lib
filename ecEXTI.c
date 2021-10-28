#include "stm32f4xx.h"
#include "stm32f411xe.h"
#include "ecEXTI.h"

void EXTI_init(GPIO_TypeDef *port, int pin, int trig_type, int priority){
   // SYSCFG peripheral clock enable
   RCC->APB2ENR |=    RCC_APB2ENR_SYSCFGEN;
   
   // Connect External Line to the GPIO
   SYSCFG->EXTICR[pin/4] &= ~(0xFUL<<4UL);  
   
   if (port == GPIOA)
      SYSCFG->EXTICR[pin/4] |= 0UL<<(4*(pin%4)); 
   else if (port == GPIOB)
      SYSCFG->EXTICR[pin/4] |= 1UL<<(4*(pin%4)); 
   else if (port == GPIOC)
      SYSCFG->EXTICR[pin/4] |= 2UL<<(4*(pin%4)); 
   else if (port == GPIOD)
      SYSCFG->EXTICR[pin/4] |= 3UL<<(4*(pin%4)); 
   else if (port == GPIOE)
      SYSCFG->EXTICR[pin/4] |= 4UL<<(4*(pin%4)); 
   else
      SYSCFG->EXTICR[pin/4] |= 7UL<<(4*(pin%4)); 
   
   if (trig_type==FALL){
      // Falling trigger enable (Button: pull-up)
      EXTI->FTSR |= 1UL << pin;
      EXTI->RTSR |= 0UL << pin;
   }
   else if (trig_type==RISE){
      // Falling trigger enable (Button: pull-up)
      EXTI->RTSR |= 1UL << pin;
      EXTI->FTSR |= 0UL << pin;
   }
   else{
      EXTI->RTSR |= 1UL << pin;
      EXTI->FTSR |= 1UL << pin;
   }
   // Unmask (Enable) EXT interrupt
   EXTI_enable((uint32_t) pin);
   
   // Interrupt IRQn, Priority
   NVIC_EnableIRQ(EXTI15_10_IRQn);                // Enable EXTI 
   NVIC_SetPriority(EXTI15_10_IRQn, priority);        // Set EXTI priority as 0   
   
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