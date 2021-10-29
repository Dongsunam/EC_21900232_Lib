/********************************************************************************
* @author  Dongsu Nam
* @Mod		 2021-8-12 by YKKIM  	
* @brief   Embedded Controller:  LAB Digital In/Out
*					 - Toggle LED LD2 by Button B1  pressing
* 
******************************************************************************
*/

#include "stm32f4xx.h"
#include "ecGPIO.h"
#include "ecRCC.h"

#define BUTTON_PIN 13
#define LED1 5
#define LED2 6
#define LED3 7
#define LED4 7


void setup(void);

int main(void) { 
	int flag1_1 = 1;
	int flag1_2 = 0;
	int flag1_3 = 0;
	int flag1_4 = 0;
	
	int flag2_1 = 0;
	int flag2_2 = 0;
	int flag2_3 = 0;
	int flag2_4 = 0;
	setup();
	
	while(1){
		if(GPIO_read(GPIOC, BUTTON_PIN) == 0){
			
			if(flag1_1 != 0){
				GPIO_write(GPIOA, LED1, HIGH);
				GPIO_write(GPIOA, LED2, LOW);
				GPIO_write(GPIOA, LED3, LOW);
				GPIO_write(GPIOC, LED4, LOW);
				flag2_4 = 0;
				flag2_1 +=1;
			}
			
			if(flag1_2 != 0){
				GPIO_write(GPIOA, LED1, LOW);
				GPIO_write(GPIOA, LED2, HIGH);
				GPIO_write(GPIOA, LED3, LOW);
				GPIO_write(GPIOC, LED4, LOW);
				flag2_1 = 0;
				flag2_2 +=1;
			}
			
			if(flag1_3 != 0){
				GPIO_write(GPIOA, LED1, LOW);
				GPIO_write(GPIOA, LED2, LOW);
				GPIO_write(GPIOA, LED3, HIGH);
				GPIO_write(GPIOC, LED4, LOW);
				flag2_2 = 0;
				flag2_3 +=1;
			}
			if(flag1_4 != 0){
				GPIO_write(GPIOA, LED1, LOW);
				GPIO_write(GPIOA, LED2, LOW);
				GPIO_write(GPIOA, LED3, LOW);
				GPIO_write(GPIOC, LED4, HIGH);
				flag2_3 = 0;
				flag2_4 +=1;
			}
		}
		
		else{
			if(flag2_1 != 0){
				GPIO_write(GPIOA, LED1, HIGH);
				GPIO_write(GPIOA, LED2, LOW);
				GPIO_write(GPIOA, LED3, LOW);
				GPIO_write(GPIOC, LED4, LOW);
				flag1_1 = 0;
				flag1_2 +=1;
			}
			
			if(flag2_2 != 0){
				GPIO_write(GPIOA, LED1, LOW);
				GPIO_write(GPIOA, LED2, HIGH);
				GPIO_write(GPIOA, LED3, LOW);
				GPIO_write(GPIOC, LED4, LOW);
				flag1_2 = 0;
				flag1_3 +=1;
			}
			
			if(flag2_3 != 0){
				GPIO_write(GPIOA, LED1, LOW);
				GPIO_write(GPIOA, LED2, LOW);
				GPIO_write(GPIOA, LED3, HIGH);
				GPIO_write(GPIOC, LED4, LOW);
				flag1_3 = 0;
				flag1_4 +=1;
			}
			if(flag2_4 != 0){
				GPIO_write(GPIOA, LED1, LOW);
				GPIO_write(GPIOA, LED2, LOW);
				GPIO_write(GPIOA, LED3, LOW);
				GPIO_write(GPIOC, LED4, HIGH);
				flag1_4 = 0;
				flag1_1 +=1;
			}
		}
	}
}



void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(GPIOC, BUTTON_PIN, INPUT); 
	GPIO_init(GPIOA, LED1, OUTPUT);
	GPIO_init(GPIOA, LED2, OUTPUT);
	GPIO_init(GPIOA, LED3, OUTPUT);
	GPIO_init(GPIOC, LED4, OUTPUT);
}
