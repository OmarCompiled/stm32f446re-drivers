#include "stm32f446xx_gpio.h"

#define GPIO_COUNT 16U

void GPIO_init(GPIO_t *GPIO_port, GPIO_init_t *GPIO_init) {
  uint32_t temp = 0x00U;
  uint32_t position = 0x00U;
  uint32_t io_current = 0x00U;
  uint32_t io_position = 0x00U;

  for (position = 0U; position < GPIO_COUNT; position++) {
    io_position = 0x01U << position;
    io_current = (uint32_t)(GPIO_init->GPIO_pin_number) & io_position;

    if (io_position == io_current) {
      /* Mode */
      if (GPIO_init->GPIO_pin_mode <= GPIO_ANALOG) {
        temp = GPIO_port->MODER;
        temp &= ~(0x3U << (position * 2U));
        temp |= (GPIO_init->GPIO_pin_mode << (position * 2U));
        GPIO_port->MODER = temp;
      } else {
        switch (GPIO_init->GPIO_pin_mode) {
        case GPIO_EXTI_IT_RISING:
          EXTI->FTSR &= ~(0x1U << position);
          EXTI->RTSR |= (0x1U << position);
          break;
        case GPIO_EXTI_IT_FALLING:
          EXTI->RTSR &= ~(0x1U << position);
          EXTI->FTSR |= (0x1U << position);
          break;
        case GPIO_EXTI_IT_RISING_FALLING:
          EXTI->RTSR |= (0x1U << position);
          EXTI->FTSR |= (0x1U << position);
          break;
        default:
          break;
        }
        // syscfg_exticr setup
        RCC_SYSCFG_CLK_ENABLE();
        temp = position / 4;
        SYSCFG->EXTICR[temp] |=
            (GPIO_EXTI_port_code(GPIO_port) << (4 * (position % 4)));

        EXTI->IMR |= (0x1U << position);
      }

      /* Output type */
      temp = GPIO_port->OTYPER;
      temp &= ~(0x1U << position);
      temp |= (GPIO_init->GPIO_pin_output_type << position);
      GPIO_port->OTYPER = temp;

      temp = GPIO_port->OSPEEDR;
      temp &= ~(0x3U << (position * 2U));
      temp |= (GPIO_init->GPIO_pin_speed << (position * 2U));
      GPIO_port->OSPEEDR = temp;

      temp = GPIO_port->PUPDR;
      temp &= ~(0x3U << (position * 2U));
      temp |= (GPIO_init->GPIO_pin_pull << (position * 2U));
      GPIO_port->PUPDR = temp;

      if (GPIO_init->GPIO_pin_mode == GPIO_ALT_FUNCTION) {
        temp = GPIO_port->AFR[position >> 3U];
        temp &= ~(0xFU << (((uint32_t)position & 0x7U) * 4U));
        temp |= (GPIO_init->GPIO_pin_alt_function
                 << (((uint32_t)position & 0x7U) * 4U));
        GPIO_port->AFR[position >> 3U] = temp;
      }
    }
  }
}

void GPIO_deinit(GPIO_t *GPIO_port) {
  if (GPIO_port == GPIOA) {
    RCC_GPIOA_RESET();
  } else if (GPIO_port == GPIOB) {
    RCC_GPIOB_RESET();
  } else if (GPIO_port == GPIOC) {
    RCC_GPIOC_RESET();
  } else if (GPIO_port == GPIOD) {
    RCC_GPIOD_RESET();
  } else if (GPIO_port == GPIOE) {
    RCC_GPIOE_RESET();
  } else if (GPIO_port == GPIOF) {
    RCC_GPIOF_RESET();
  } else if (GPIO_port == GPIOG) {
    RCC_GPIOG_RESET();
  } else if (GPIO_port == GPIOH) {
    RCC_GPIOH_RESET();
  }
}

void GPIO_write_pin(GPIO_t *GPIO_port, uint8_t pin_number, uint8_t pin_state) {
  uint32_t temp = 0x00U;
  temp = GPIO_port->ODR;
  temp &= ~(0x1U << pin_number);
  temp |= (pin_state << pin_number);
  GPIO_port->ODR = temp;
}

uint8_t GPIO_read_pin(GPIO_t *GPIO_port, uint8_t pin_number) {
  uint16_t temp = GPIO_port->IDR >> pin_number; // 16 bits accessible in IDR;
  return (uint8_t)(temp & 0x1U);
}

void GPIO_enable_clock(GPIO_t *GPIO_port) {
  if (GPIO_port == GPIOA) {
    RCC_GPIOA_CLK_ENABLE();
  } else if (GPIO_port == GPIOB) {
    RCC_GPIOB_CLK_ENABLE();
  } else if (GPIO_port == GPIOC) {
    RCC_GPIOC_CLK_ENABLE();
  } else if (GPIO_port == GPIOD) {
    RCC_GPIOD_CLK_ENABLE();
  } else if (GPIO_port == GPIOE) {
    RCC_GPIOE_CLK_ENABLE();
  } else if (GPIO_port == GPIOF) {
    RCC_GPIOF_CLK_ENABLE();
  } else if (GPIO_port == GPIOG) {
    RCC_GPIOG_CLK_ENABLE();
  } else if (GPIO_port == GPIOH) {
    RCC_GPIOH_CLK_ENABLE();
  }
}

void GPIO_disable_clock(GPIO_t *GPIO_port) {
  if (GPIO_port == GPIOA) {
    RCC_GPIOA_CLK_DISABLE();
  } else if (GPIO_port == GPIOB) {
    RCC_GPIOB_CLK_DISABLE();
  } else if (GPIO_port == GPIOC) {
    RCC_GPIOC_CLK_DISABLE();
  } else if (GPIO_port == GPIOD) {
    RCC_GPIOD_CLK_DISABLE();
  } else if (GPIO_port == GPIOE) {
    RCC_GPIOE_CLK_DISABLE();
  } else if (GPIO_port == GPIOF) {
    RCC_GPIOF_CLK_DISABLE();
  } else if (GPIO_port == GPIOG) {
    RCC_GPIOG_CLK_DISABLE();
  } else if (GPIO_port == GPIOH) {
    RCC_GPIOH_CLK_DISABLE();
  }
}

uint8_t GPIO_EXTI_port_code(GPIO_t *GPIO_port) {
  if (GPIO_port == GPIOA) {
    return 0;
  } else if (GPIO_port == GPIOB) {
    return 1;
  } else if (GPIO_port == GPIOC) {
    return 2;
  } else if (GPIO_port == GPIOD) {
    return 3;
  } else if (GPIO_port == GPIOE) {
    return 4;
  } else if (GPIO_port == GPIOF) {
    return 5;
  } else if (GPIO_port == GPIOG) {
    return 6;
  } else if (GPIO_port == GPIOH) {
    return 7;
  }
}

void GPIO_handle_IRQ(uint8_t pin_number) {
	if (EXTI->PR & (0x1U << pin_number)) {
		EXTI->PR |= (0x1U << pin_number);
	}
}
