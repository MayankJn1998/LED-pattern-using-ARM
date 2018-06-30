#include<stm32F4xx_HAL.h>

void config(){
	//Enabling clocks
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	//setting i/o pins
	GPIO_InitTypeDef def;
		def.Mode = GPIO_MODE_OUTPUT_PP;
		def.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		HAL_GPIO_Init(GPIOD,&def);

		def.Mode = GPIO_MODE_INPUT;
		def.Pin = GPIO_PIN_0;
		HAL_GPIO_Init(GPIOA,&def);
}

void delay(uint16_t ms){
	for(uint16_t i=0;i<4000*ms;++i);
}

void switch_1(){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	delay(500);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	delay(500);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	delay(500);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
	delay(500);
	
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
	delay(500);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
	delay(500);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	delay(500);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
	delay(500);	
	
}

void set1010(){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
}

void set1001(){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
}

void setOn(){
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
}

void toggle(){
		set1010();
		delay(500);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_12);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_13);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14);
		HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);
		delay(500);
}

void switch_3(){

	

}

int main(){

		config();
		int count=1; 
		while(1){
			
			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_SET){
					int temp=20000;
					setOn();
					while(temp>=0){
						if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0) == GPIO_PIN_SET){
							count++;
							if(count>=3) break;
						}
					}
			}
			
			switch(count){
				case 1:	switch_1();
								break;
				case 2:	toggle();
								break;
				case 3:	
								break;
			}
			
		}

}