/********************************************************************************
* @author  Dongsu Nam
* @Mod		 2021-8-12 by YKKIM  	
* @brief   Embedded Controller:  LAB 7segment
*					 
* 
*******************************************************************************/

#include "stm32f4xx.h"
#include "ecGPIO.h"
#include "ecRCC.h"

void setup(void);

int main(void){
	int flag1_1 = 1;
	int flag1_2 = 0;
	
	int flag2_1 = 0;
	int flag2_2 = 0;
	
	unsigned int zero1 = 1;
	unsigned int one1 = 0;
	unsigned int two1 = 0;
	unsigned int three1 = 0;
	unsigned int four1 = 0;
	unsigned int five1 = 0;
	unsigned int six1 = 0;
	unsigned int seven1 = 0;
	unsigned int eight1 = 0;
	unsigned int nine1 = 0;
	
	unsigned int zero2 = 1;
	unsigned int one2 = 0;
	unsigned int two2 = 0;
	unsigned int three2 = 0;
	unsigned int four2 = 0;
	unsigned int five2 = 0;
	unsigned int six2 = 0;
	unsigned int seven2 = 0;
	unsigned int eight2 = 0;
	unsigned int nine2 = 0;
	
	int reverse = 0;
	
	setup();

	while(1){
			if(GPIO_read(GPIOC, BUTTON_PIN)==0){
				if(flag1_1 != 0){
					GPIO_write(GPIOA, LED_PIN, HIGH);
					flag2_1 += 1;
					flag2_2 = 0;
					if (zero1 != 0){
						sevensegment_decoder(0);
						reverse = 0;
						
						zero2 +=1;
						one2 = 0;
					}
					if (one1 != 0){
						sevensegment_decoder(1);
						
						if(reverse == 0){
							one2 +=1;
							zero2 =0;
						}
						if(reverse == 1){
							one2 +=1;
							two2 = 0;
						}
					}
					if (two1 != 0){
						sevensegment_decoder(2);

						if(reverse == 0){
							two2 +=1;
							one2 =0;
						}
						if(reverse == 1){
							two2 +=1;
							three2 = 0;
						}
					}
					if (three1 != 0){
						sevensegment_decoder(3);
						
						if(reverse == 0){
							three2 +=1;
							two2 =0;
						}
						if(reverse == 1){
							three2 +=1;
							four2 = 0;
						}
					}
					if (four1 != 0){
						sevensegment_decoder(4);
						
						if(reverse == 0){
							four2 +=1;
							three2 =0;
						}
						if(reverse == 1){
							four2 +=1;
							five2 = 0;
						}
					}
					if (five1 != 0){
						sevensegment_decoder(5);
						
						if(reverse == 0){
							five2 +=1;
							four2 =0;
						}
						if(reverse == 1){
							five2 +=1;
							six2 = 0;
						}
					}
					if (six1 != 0){
						sevensegment_decoder(6);
						
						if(reverse == 0){
							six2 +=1;
							five2 =0;
						}
						if(reverse == 1){
							six2 +=1;
							seven2 = 0;
						}
					}
					if (seven1 != 0){
						sevensegment_decoder(7);
						
						if(reverse == 0){
							seven2 +=1;
							six2 =0;
						}
						if(reverse == 1){
							seven2 +=1;
							eight2 = 0;
						}
					}
					if (eight1 != 0){
						sevensegment_decoder(8);
						
						if(reverse == 0){
							eight2 +=1;
							seven2 =0;
						}
						if(reverse == 1){
							eight2 +=1;
							nine2 = 0;
						}
					}
					if (nine1 != 0){
						sevensegment_decoder(9);
						reverse = 1;
					
						nine2 += 1;
						eight2 = 0;
					}
						

				}
				
				if(flag1_2 != 0){
					GPIO_write(GPIOA, LED_PIN, LOW);
					flag2_1 = 0;
					flag2_2+= 1;
					if (zero1 != 0){
						sevensegment_decoder(0);
						reverse = 0;
						
						zero2 +=1;
						one2 = 0;
					}
					if (one1 != 0){
						sevensegment_decoder(1);
						
						if(reverse == 0){
							one2 +=1;
							zero2 =0;
						}
						if(reverse == 1){
							one2 +=1;
							two2 = 0;
						}
					}
					if (two1 != 0){
						sevensegment_decoder(2);
						
						if(reverse == 0){
							two2 +=1;
							one2 =0;
						}
						if(reverse == 1){
							two2 +=1;
							three2 = 0;
						}
					}
					if (three1 != 0){
						sevensegment_decoder(3);
						
						if(reverse == 0){
							three2 +=1;
							two2 =0;
						}
						if(reverse == 1){
							three2 +=1;
							four2 = 0;
						}
					}
					if (four1 != 0){
						sevensegment_decoder(4);
						
						if(reverse == 0){
							four2 +=1;
							three2 =0;
						}
						if(reverse == 1){
							four2 +=1;
							five2 = 0;
						}
					}
					if (five1 != 0){
						sevensegment_decoder(5);
						
						if(reverse == 0){
							five2 +=1;
							four2 =0;
						}
						if(reverse == 1){
							five2 +=1;
							six2 = 0;
						}
					}
					if (six1 != 0){
						sevensegment_decoder(6);
						
						if(reverse == 0){
							six2 +=1;
							five2 =0;
						}
						if(reverse == 1){
							six2 +=1;
							seven2 = 0;
						}
					}
					if (seven1 != 0){
						sevensegment_decoder(7);
						
						if(reverse == 0){
							seven2 +=1;
							six2 =0;
						}
						if(reverse == 1){
							seven2 +=1;
							eight2 = 0;
						}
					}
					if (eight1 != 0){
						sevensegment_decoder(8);
						
						if(reverse == 0){
							eight2 +=1;
							seven2 =0;
						}
						if(reverse == 1){
							eight2 +=1;
							nine2 = 0;
						}
					}
					if (nine1 != 0){
						sevensegment_decoder(9);
						reverse = 1;
						
						nine2 += 1;
						eight2 = 0;
					}
						

				}
			}
			else{
				if(flag2_1 != 0){		
					GPIO_write(GPIOA, LED_PIN, HIGH);
					flag1_2 += 1;
					flag1_1 = 0;					
					if (zero2 != 0){					
						sevensegment_decoder(0);
						reverse = 0;
		
						one1 +=1;
						zero1 = 0;
					}
					
					if (one2 != 0){			
						sevensegment_decoder(1);
						
						if(reverse == 0){
							two1 +=1;
							one1 =0;
						}
						if(reverse == 1){
							zero1 +=1;
							one1 = 0;
						}
					}
					if (two2 != 0){
						sevensegment_decoder(2);
						
						if(reverse == 0){
							three1 +=1;
							two1 =0;
						}
						if(reverse == 1){
							one1 +=1;
							two1 = 0;
						}
					}
					if (three2 != 0){
						sevensegment_decoder(3);
						
						if(reverse == 0){
							four1 +=1;
							three1 =0;
						}
						if(reverse == 1){
							two1 +=1;
							three1 = 0;
						}
					}
					if (four2 != 0){					
						sevensegment_decoder(4);
						
						if(reverse == 0){
							five1 +=1;
							four1 =0;
						}
						if(reverse == 1){
							three1 +=1;
							four1 = 0;
						}
					}
					if (five2 != 0){				
						sevensegment_decoder(5);
						
						if(reverse == 0){
							six1 +=1;
							five1 =0;
						}
						if(reverse == 1){
							four1 +=1;
							five1 = 0;
						}
					}
					if (six2 != 0){					
						sevensegment_decoder(6);
						
						if(reverse == 0){
							seven1 +=1;
							six1 =0;
						}
						if(reverse == 1){
							five1 +=1;
							six1 = 0;
						}
					}
					if (seven2 != 0){					
						sevensegment_decoder(7);
						
						if(reverse == 0){
							eight1 +=1;
							seven1 =0;
						}
						if(reverse == 1){
							six1 +=1;
							seven1 = 0;
						}
					}
					if (eight2 != 0){		
						sevensegment_decoder(8);
						
						if(reverse == 0){
							nine1 +=1;
							eight1 =0;
						}
						if(reverse == 1){
							seven1 +=1;
							eight1 = 0;
						}
					}
					if (nine2 != 0){
						sevensegment_decoder(9);
						reverse = 1;
						
						eight1 += 1;
						nine1 = 0;
					}
				}				
				if(flag2_2 != 0){
					GPIO_write(GPIOA, LED_PIN, LOW);
					flag1_1 += 1;
					flag1_2 = 0;
					if (zero2 != 0){
						sevensegment_decoder(0);
						reverse = 0;
		
						one1 +=1;
						zero1 = 0;
					}
					
					if (one2 != 0){
						sevensegment_decoder(1);
						
						if(reverse == 0){
							two1 +=1;
							one1 =0;
						}
						if(reverse == 1){
							zero1 +=1;
							one1 = 0;
						}
					}
					if (two2 != 0){
						sevensegment_decoder(2);
						
						if(reverse == 0){
							three1 +=1;
							two1 =0;
						}
						if(reverse == 1){
							one1 +=1;
							two1 = 0;
						}
					}
					if (three2 != 0){
						sevensegment_decoder(3);
						
						if(reverse == 0){
							four1 +=1;
							three1 =0;
						}
						if(reverse == 1){
							two1 +=1;
							three1 = 0;
						}
					}
					if (four2 != 0){
						sevensegment_decoder(4);
						
						if(reverse == 0){
							five1 +=1;
							four1 =0;
						}
						if(reverse == 1){
							three1 +=1;
							four1 = 0;
						}
					}
					if (five2 != 0){
						GPIO_write(GPIOA, LED_PIN, LOW);
						flag1_1 += 1;
						flag1_2 = 0;
						
						sevensegment_decoder(5);
						
						if(reverse == 0){
							six1 +=1;
							five1 =0;
						}
						if(reverse == 1){
							four1 +=1;
							five1 = 0;
						}
					}
					if (six2 != 0){
						sevensegment_decoder(6);
						
						if(reverse == 0){
							seven1 +=1;
							six1 =0;
						}
						if(reverse == 1){
							five1 +=1;
							six1 = 0;
						}
					}
					if (seven2 != 0){
						sevensegment_decoder(7);
						
						if(reverse == 0){
							eight1 +=1;
							seven1 =0;
						}
						if(reverse == 1){
							six1 +=1;
							seven1 = 0;
						}
					}
					if (eight2 != 0){
						sevensegment_decoder(8);
						
						if(reverse == 0){
							nine1 +=1;
							eight1 =0;
						}
						if(reverse == 1){
							seven1 +=1;
							eight1 = 0;
						}
					}
					if (nine2 != 0){
						sevensegment_decoder(9);
						reverse = 1;
						
						eight1 += 1;
						nine1 = 0;
					}
				}
			}
	}
}
	



void setup(void){	
	RCC_HSI_init();		
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()	
	GPIO_init(GPIOA, LED_PIN, OUTPUT);
	sevensegment_init();
}