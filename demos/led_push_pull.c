#include <stdint.h>

#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

/*
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif*
*/

#define LED PA5

int
main(void) {
	GPIO_init_t* onboard_led = &(GPIO_init_t) {
		.GPIO_pin_number = GPIO_PIN_5,
		.GPIO_pin_mode = GPIO_OUTPUT,
		.GPIO_pin_output_type = GPIO_PUSH_PULL,
		.GPIO_pin_pull = GPIO_NO_PULL,
		.GPIO_pin_speed = GPIO_HIGH_SPEED,
	};

	GPIO_clk_control(GPIOA, ENABLE);
	GPIO_init(GPIOA, onboard_led);

	while(1) {
		int i;

		GPIO_write_pin(GPIOA, LED, ENABLE);
		for(i = 0; i < 1e6; i++);

		GPIO_write_pin(GPIOA, LED, DISABLE);
		for(i = 0; i < 1e6; i++);
	}

	return 0;
}
