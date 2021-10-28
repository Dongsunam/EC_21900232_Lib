#include "stm32f411xe.h"
#include "ecPWM.h"

void PWM_init(PWM_t *pwm, GPIO_TypeDef *port, int pin){
   
   // 0. Match Output Port and Pin for TIMx 	
		pwm->port = port;
		pwm->pin  = pin;
		PWM_pinmap(pwm);
		TIM_TypeDef *TIMx = pwm->timer;
		int CHn = pwm->ch;	

// 1. Initialize GPIO port and pin as AF
		GPIO_init(port, pin, AF);  // AF=2
		GPIO_ospeed(port, pin, highspeed);  // speed VHIGH=3
		GPIO_otype(port, pin, pushpull);
		GPIO_pudr(port, pin, nopupd);

   
   // 2. CONFIGURE GPIO AFR BY PIN NUMBER
   uint32_t TIMx_AFn = 0;
   //TIMER 1,2          ==> 1UL
   //TIMER 3, 4, 5    ==> 2UL
   //TIMER 9, 10, 11 ==> 3UL
   
   if (TIMx == TIM1 || TIMx == TIM2) 
      TIMx_AFn = 1UL;
   else if(TIMx == TIM3 || TIMx == TIM4 || TIMx == TIM5)
      TIMx_AFn = 2UL;
   else
      TIMx_AFn = 3UL;
   
   if(pin <= 7)    port->AFR[0] = TIMx_AFn<<4*pin;
   else                port->AFR[1] = TIMx_AFn<<4*pin;
   
   // 3. TIMER/COUNTER SETTING
   TIM_init(TIMx, 1);
   
   TIMx->CR1 &= ~(1UL<<4);
   
   // 4. CONFIGURE TIMER OUTPUT MODE AS PWM
	uint32_t ccVal=TIMx->ARR/2;  // default value  CC=ARR/2
	if(CHn == 1){
		TIMx->CCMR1 &= ~TIM_CCMR1_OC1M;                     // Clear ouput compare mode bits for channel 1
		TIMx->CCMR1 |= TIM_CCMR1_OC1M_1|TIM_CCMR1_OC1M_2; 	// OC1M = 110 for PWM Mode 1 output on ch1. #define TIM_CCMR1_OC1M_1          (0x2UL << TIM_CCMR1_OC1M_Pos)
		TIMx->CCMR1	|= TIM_CCMR1_OC1PE;                     // Output 1 preload enable (make CCR1 value changable)
		TIMx->CCR1  = ccVal; 																// Output Compare Register for channel 1 (default duty ratio = 50%)		
		TIMx->CCER &= ~TIM_CCER_CC1P;                       // select output polarity: active high	
		TIMx->CCER |= TIM_CCER_CC1E;												// Enable output for ch1
	}
	else if(CHn == 2){
		TIMx->CCMR1 &= ~TIM_CCMR1_OC2M;                     // Clear ouput compare mode bits for channel 2
		TIMx->CCMR1 |= TIM_CCMR1_OC2M_1|TIM_CCMR1_OC2M_2; 	// OC1M = 110 for PWM Mode 1 output on ch1. #define TIM_CCMR1_OC1M_1          (0x2UL << TIM_CCMR1_OC1M_Pos)
		TIMx->CCMR1	|= TIM_CCMR1_OC2PE;                     // Output 1 preload enable (make CCR1 value changable)
		TIMx->CCR2  = ccVal; 																// Output Compare Register for channel 1 (default duty ratio = 50%)		
		TIMx->CCER &= ~TIM_CCER_CC2P;                       // select output polarity: active high	
		TIMx->CCER |= TIM_CCER_CC2E;												// Enable output for ch2
	}
	else if(CHn == 3){
		TIMx->CCMR2 &= ~TIM_CCMR2_OC3M;                     // Clear ouput compare mode bits for channel 3
		TIMx->CCMR2 |= TIM_CCMR2_OC3M_1|TIM_CCMR2_OC3M_2; 	// OC1M = 110 for PWM Mode 1 output on ch1. #define TIM_CCMR1_OC1M_1          (0x2UL << TIM_CCMR1_OC1M_Pos)
		TIMx->CCMR2	|= TIM_CCMR2_OC3PE;                     // Output 1 preload enable (make CCR1 value changable)
		TIMx->CCR3  = ccVal; 																// Output Compare Register for channel 1 (default duty ratio = 50%)		
		TIMx->CCER &= ~TIM_CCER_CC3P;                       // select output polarity: active high	
		TIMx->CCER |= TIM_CCER_CC3E;												// Enable output for ch2
	}
	else if(CHn == 4){
		TIMx->CCMR2 &= ~TIM_CCMR2_OC4M;                     // Clear ouput compare mode bits for channel 3
		TIMx->CCMR2 |= TIM_CCMR2_OC4M_1|TIM_CCMR2_OC4M_2; 	// OC1M = 110 for PWM Mode 1 output on ch1. #define TIM_CCMR1_OC1M_1          (0x2UL << TIM_CCMR1_OC1M_Pos)
		TIMx->CCMR2	|= TIM_CCMR2_OC4PE;                     // Output 1 preload enable (make CCR1 value changable)
		TIMx->CCR4  = ccVal; 																// Output Compare Register for channel 1 (default duty ratio = 50%)		
		TIMx->CCER &= ~TIM_CCER_CC4P;                       // select output polarity: active high	
		TIMx->CCER |= TIM_CCER_CC4E;
	}
   
   
   if(TIMx == TIM1) TIM1->BDTR |= 1UL<<15;
   TIMx->CR1 |= TIM_CR1_CEN;
}


void PWM_period_ms(PWM_t *PWM_pin, uint32_t msec){
   TIM_TypeDef *TIMx = PWM_pin->timer;
   TIM_period_ms(TIMx, msec);  //YOUR CODE GOES HERE
}

void PWM_period_us(PWM_t *PWM_pin, uint32_t usec){
   TIM_TypeDef *TIMx = PWM_pin->timer;
   TIM_period_us(TIMx, usec);    //YOUR CODE GOES HERE
}


void PWM_pulsewidth_ms(PWM_t *pwm, float pulse_width_ms){ 
   TIM_TypeDef *TIMx = pwm->timer;
   int CHn = pwm->ch;
   uint32_t fsys = 0;
   uint32_t psc=TIMx->PSC;
   
   // Check System CLK: PLL or HSI
   if((RCC->CFGR & (3<<0)) == 2)      { fsys = 84000; }  // for msec 84MHz/1000
   else if((RCC->CFGR & (3<<0)) == 0) { fsys = 16000; }
   
   //YOUR CODE GOES HERE
   float fclk = fsys/(psc+1);                  // fclk=fsys/(psc+1);
   uint32_t ccval = pulse_width_ms*fclk;   // width_ms *fclk;
   
   //YOUR CODE GOES HERE
   switch(CHn){
      case 1: TIMx->CCR1 = ccval; break;
      case 2: TIMx->CCR2 = ccval; break;
      case 3: TIMx->CCR3 = ccval; break;
      case 4: TIMx->CCR4 = ccval; break;
      default: break;
   }
}


void   PWM_duty(PWM_t *pwm, float duty) {         //  duty=0 to 1   
      float ccval = (pwm->timer->ARR+1)*duty;       // (ARR+1)*dutyRatio          
      int CHn = pwm->ch;
	
			TIM_TypeDef *TIMx = pwm->timer;
	
      //YOUR CODE GOES HERE   
      switch(CHn){
         case 1: TIMx->CCR1 = ccval; break;
         case 2: TIMx->CCR2 = ccval; break;
         case 3: TIMx->CCR3 = ccval; break;
         case 4: TIMx->CCR4 = ccval; break;
         default: break;
      }
}




void PWM_pinmap(PWM_t *PWM_pin){
   GPIO_TypeDef *port = PWM_pin->port;
   int pin = PWM_pin->pin;
   
   if(port == GPIOA) {
      switch(pin){
         case 0 : PWM_pin->timer = TIM2; PWM_pin->ch = 1; break;
            //case 0 : PWM_pin->timer = TIM5; PWM_pin->ch = 1; break;
         case 1 : PWM_pin->timer = TIM2; PWM_pin->ch = 2; break;
             case 2 : PWM_pin->timer = TIM2; PWM_pin->ch = 3; break;
             case 3 : PWM_pin->timer = TIM2; PWM_pin->ch = 4; break;
         case 5 : PWM_pin->timer = TIM2; PWM_pin->ch = 1; break;
         case 6 : PWM_pin->timer = TIM3; PWM_pin->ch = 1; break;
         //case 7: PWM_pin->timer = TIM1; PWM_pin->ch = 1N; break;
         case 8 : PWM_pin->timer = TIM1; PWM_pin->ch = 1; break;
         case 9 : PWM_pin->timer = TIM1; PWM_pin->ch = 2; break;
         case 10: PWM_pin->timer = TIM1; PWM_pin->ch = 3; break;
         case 15: PWM_pin->timer = TIM2; PWM_pin->ch = 1; break;
         default: break;
      }         
   }
   else if(port == GPIOB) {
      switch(pin){
         //case 0: PWM_pin->timer = TIM1; PWM_pin->ch = 2N; break;
         //case 1: PWM_pin->timer = TIM1; PWM_pin->ch = 3N; break;
         case 3 : PWM_pin->timer = TIM2; PWM_pin->ch = 2; break;
         case 4 : PWM_pin->timer = TIM3; PWM_pin->ch = 1; break;
         case 5 : PWM_pin->timer = TIM3; PWM_pin->ch = 2; break;
         case 6 : PWM_pin->timer = TIM4; PWM_pin->ch = 1; break;
         case 7 : PWM_pin->timer = TIM4; PWM_pin->ch = 2; break;
         case 8 : PWM_pin->timer = TIM4; PWM_pin->ch = 3; break;
         case 9 : PWM_pin->timer = TIM4; PWM_pin->ch = 3; break;
         case 10: PWM_pin->timer = TIM2; PWM_pin->ch = 3; break;
         
         default: break;
      }
   }
   else if(port == GPIOC) {
      switch(pin){
         case 6 : PWM_pin->timer = TIM3; PWM_pin->ch = 1; break;
         case 7 : PWM_pin->timer = TIM3; PWM_pin->ch = 2; break;
         case 8 : PWM_pin->timer = TIM3; PWM_pin->ch = 3; break;
         case 9 : PWM_pin->timer = TIM3; PWM_pin->ch = 4; break;
         
         default: break;
      }
   }
    // TIM5 needs to be added, if used.
}