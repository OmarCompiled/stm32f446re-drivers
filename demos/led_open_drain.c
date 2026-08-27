#include <stdint.h>

#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

#define LED PA5

int
main(void) {
  GPIO_init_t* onboard_led = &(GPIO_init_t) {
    .GPIO_pin_number = GPIO_PIN_5,
    .GPIO_pin_mode = GPIO_OUTPUT,
    .GPIO_pin_output_type = GPIO_OPEN_DRAIN,
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
