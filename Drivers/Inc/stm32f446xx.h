#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include "stm32f446xx_ex.h"
#include <stdint.h>

/*
 *	Any value not used in functions or struct definitions
 *	or used internally to a single file will be kept
 *	as a #define.
 *
 *	Addresses are an exception.
 */

#define __IO volatile

/* ARM M4 Cortex Specifics */
/* Refer to Cortec-M4 Technical Reference Manual */
#define NVIC_BASE 0xE000E100U

typedef struct {
  __IO uint32_t ISER[8]; // Interrupt Set-Enable Registers
  uint32_t __reserved0[24];
  __IO uint32_t ICER[8]; // Interrupt Clear-Enable Registers
  uint32_t __reserved1[24];
  __IO uint32_t ISPR[8]; // Interrupt Set-Pending Registers
  uint32_t __reserved2[24];
  __IO uint32_t ICPR[8]; // Interrupt Clear-Pending Registers
  uint32_t __reserved3[24];
  __IO uint32_t IABR[8]; // Interrupt Active-Bit Registers
  uint32_t __reserved4[56];
  __IO uint8_t IPR[240]; // Interrupt Priority Registers
  uint32_t __reserved5[644];
  __IO uint32_t STIR; // Software Trigger Interrupt Register
} NVIC_t;

#define NVIC ((NVIC_t *)NVIC_BASE)

typedef struct {
  __IO uint32_t CR; // RCC control register; offset: 0x00
  __IO uint32_t PLLCFGR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t AHB1RSTR;
  __IO uint32_t AHB2RSTR;
  __IO uint32_t AHB3RSTR;
  uint32_t __reserved0; // Reserved; 0x1C
  __IO uint32_t APB1RSTR;
  __IO uint32_t APB2RSTR;
  uint32_t __reserved1[2]; // Reserved; 0x28-0x2C
  __IO uint32_t AHB1ENR;
  __IO uint32_t AHB2ENR;
  __IO uint32_t AHB3ENR;
  uint32_t __reserved2; // Reserved; 0x3C
  __IO uint32_t APB1ENR;
  __IO uint32_t APB2ENR;
  uint32_t __reserved3[2]; // Reserved; 0x48-0x4C
  __IO uint32_t AHB1LPENR;
  __IO uint32_t AHB2LPENR;
  __IO uint32_t AHB3LPENR;
  uint32_t __reserved4; // Reserved; 0x5C
  __IO uint32_t APB1LPENR;
  __IO uint32_t APB2LPENR;
  uint32_t __reserved5[2]; // Reserved; 0x68-0x6C
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
  uint32_t __reserved6[2]; // Reserved; 0x78-0x7C
  __IO uint32_t SSCGR;
  __IO uint32_t PLLI2SCFGR;
  __IO uint32_t PLLSAICFGR;
  __IO uint32_t DCKCFGR;
  __IO uint32_t CKGATENR;
  __IO uint32_t DCKCFGR2;
} RCC_t;

typedef struct {
  __IO uint32_t MODER;   // GPIO port mode register;                offset: 0x00
  __IO uint32_t OTYPER;  // GPIO port output type register;         offset: 0x04
  __IO uint32_t OSPEEDR; // GPIO port output speed register;        offset: 0x08
  __IO uint32_t PUPDR;   // GPIO port pull-up/pull-down register;   offset: 0x0C
  __IO uint32_t IDR;     // GPIO port input data register;          offset: 0x10
  __IO uint32_t ODR;     // GPIO port output data register;         offset: 0x14
  __IO uint32_t BSRR;    // GPIO port bit set/reset register;       offset: 0x18
  __IO uint32_t LCKR;    // GPIO port configuration lock register   offset: 0x1C
  __IO uint32_t
      AFR[2]; // GPIO port alternate function registers  offset: 0x20 - 0x24
} GPIO_t;     // GPIO registers struct type

typedef struct {
  __IO uint32_t MEMRMP;
  __IO uint32_t PMC;
  __IO uint32_t EXTICR[4];
  uint32_t __reserved0[2];
  __IO uint32_t CMPCR;
  uint32_t __reserved1[2];
  __IO uint32_t CFGR;
} SYSCFG_t;

typedef struct {
  __IO uint32_t IMR;   // EXTI interrupt mask register;            offset: 0x00
  __IO uint32_t EMR;   // EXTI event mask register;                offset: 0x04
  __IO uint32_t RTSR;  // EXTI rising trigger selection register;  offset: 0x08
  __IO uint32_t FTSR;  // EXTI falling trigger selection register; offset: 0x0C
  __IO uint32_t SWIER; // EXTI software interrupt event register;  offset: 0x10
  __IO uint32_t PR;    // EXTI pending register;                   offset: 0x14
} EXTI_t;

// typedef struct {
//
// } TIM_t;

typedef struct {
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t OAR1;
  __IO uint32_t OAR2;
  __IO uint32_t DR;
  __IO uint32_t SR1;
  __IO uint32_t SR2;
  __IO uint32_t CCR;
  __IO uint32_t TRISE;
  __IO uint32_t FLTR;
} I2C_t;

/*
 * Memory base address definitions
 */

#define FLASH_BASE 0x08000000U // Main memory;    up to 512 kB
#define ROM_BASE 0x1FFF0000U   // System memory;  up to 30 kB
#define SRAM1_BASE 0x20000000U // SRAM1; aliased; up to 112 kB
#define SRAM2_BASE 0x2001C000U // SRAM2; aliased; up to 16 kB
#define SRAM_BASE SRAM1_BASE

/*
 * Peripheral bus base address definitions
 */

#define APB1PERIPH_BASE 0x40000000U
#define APB2PERIPH_BASE 0x40010000U
#define AHB1PERIPH_BASE 0x40020000U
#define AHB2PERIPH_BASE 0x50000000U
#define AHB3PERIPH_BASE 0x60000000U

#define RCC_BASE (AHB1PERIPH_BASE + 0x3800U)

/*
 * GPIO port base address definitions
 */

#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASE (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE (AHB1PERIPH_BASE + 0x1C00U)

/*
 * I2C base address definitions
 */
#define I2C1_BASE (APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASE (APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASE (APB1PERIPH_BASE + 0x5C00U)

/*
 * SPI base address definitions
 */
#define SPI1_BASE (APB2PERIPH_BASE + 0x3000U)
#define SPI2_BASE (APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASE (APB1PERIPH_BASE + 0x3C00U)
#define SPI4_BASE (APB2PERIPH_BASE + 0x3400U)

/*
 * UART/USART base address definitions
 */
#define USART1_BASE (APB2PERIPH_BASE + 0x1000U)
#define USART2_BASE (APB1PERIPH_BASE + 0x4400U)
#define USART3_BASE (APB1PERIPH_BASE + 0x4800U)
#define UART4_BASE (APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASE (APB1PERIPH_BASE + 0x5000U)
#define USART6_BASE (APB2PERIPH_BASE + 0x1400U)

#define EXTI_BASE (APB2PERIPH_BASE + 0x3C00U)
#define SYSCFG_BASE (APB2PERIPH_BASE + 0x3800U)

/*
 * GPIO port definitions
 */
#define GPIOA ((GPIO_t *)GPIOA_BASE)
#define GPIOB ((GPIO_t *)GPIOB_BASE)
#define GPIOC ((GPIO_t *)GPIOC_BASE)
#define GPIOD ((GPIO_t *)GPIOD_BASE)
#define GPIOE ((GPIO_t *)GPIOE_BASE)
#define GPIOF ((GPIO_t *)GPIOF_BASE)
#define GPIOG ((GPIO_t *)GPIOG_BASE)
#define GPIOH ((GPIO_t *)GPIOH_BASE)

#define RCC ((RCC_t *)RCC_BASE)

#define EXTI ((EXTI_t *)EXTI_BASE)

#define SYSCFG ((SYSCFG_t *)SYSCFG_BASE)

#define RCC_APB2ENR_SYSCFGEN (0x1U << 14)

/*
 * RCC GPIO bit definitions
 */
#define RCC_AHB1ENR_GPIOAEN (0x1U << 0)
#define RCC_AHB1ENR_GPIOBEN (0x1U << 1)
#define RCC_AHB1ENR_GPIOCEN (0x1U << 2)
#define RCC_AHB1ENR_GPIODEN (0x1U << 3)
#define RCC_AHB1ENR_GPIOEEN (0x1U << 4)
#define RCC_AHB1ENR_GPIOFEN (0x1U << 5)
#define RCC_AHB1ENR_GPIOGEN (0x1U << 6)
#define RCC_AHB1ENR_GPIOHEN (0x1U << 7)

#define RCC_AHB1RSTR_GPIOAEN (0x1U << 0)
#define RCC_AHB1RSTR_GPIOBEN (0x1U << 1)
#define RCC_AHB1RSTR_GPIOCEN (0x1U << 2)
#define RCC_AHB1RSTR_GPIODEN (0x1U << 3)
#define RCC_AHB1RSTR_GPIOEEN (0x1U << 4)
#define RCC_AHB1RSTR_GPIOFEN (0x1U << 5)
#define RCC_AHB1RSTR_GPIOGEN (0x1U << 6)
#define RCC_AHB1RSTR_GPIOHEN (0x1U << 7)

/*
 * RCC I2C bit definitions
 */
#define RCC_APB1ENR_I2C1EN (0x1U << 21)
#define RCC_APB1ENR_I2C2EN (0x1U << 22)
#define RCC_APB1ENR_I2C3EN (0x1U << 23)

/*
 * RCC SPI bit definitions
 */
#define RCC_APB2ENR_SPI1EN (0x1U << 12)
#define RCC_APB1ENR_SPI2EN (0x1U << 14)
#define RCC_APB1ENR_SPI3EN (0x1U << 15)
#define RCC_APB2ENR_SPI4EN (0x1U << 13)

/*
 * RCC USART/UART bit definitions
 */
#define RCC_APB2ENR_USART1EN (0x1U << 4)
#define RCC_APB1ENR_USART2EN (0x1U << 17)
#define RCC_APB1ENR_USART3EN (0x1U << 18)
#define RCC_APB1ENR_UART4EN (0x1U << 19)
#define RCC_APB1ENR_UART5EN (0x1U << 20)
#define RCC_APB2ENR_USART6EN (0x1U << 5)

#define RCC_SYSCFG_CLK_ENABLE() SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN)
#define RCC_SYSCFG_CLK_DISABLE() CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN)

/*
 * RCC GPIO Clock enable macro definitions
 */
#define RCC_GPIOA_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN)
#define RCC_GPIOB_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN)
#define RCC_GPIOC_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN)
#define RCC_GPIOD_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN)
#define RCC_GPIOE_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN)
#define RCC_GPIOF_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN)
#define RCC_GPIOG_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN)
#define RCC_GPIOH_CLK_ENABLE() SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN)

/*
 * RCC I2C Clock enable macro definitions
 */
#define RCC_I2C1_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN)
#define RCC_I2C2_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN)
#define RCC_I2C3_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN)

/*
 * RCC SPI Clock enable macro definitions
 */
#define RCC_SPI1_CLK_ENABLE() SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN)
#define RCC_SPI2_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN)
#define RCC_SPI3_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN)
#define RCC_SPI4_CLK_ENABLE() SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN)

/*
 * RCC USART/UART Clock enable macro definitions
 */
#define RCC_USART1_CLK_ENABLE() SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN)
#define RCC_USART2_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN)
#define RCC_USART3_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN)
#define RCC_UART4_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN)
#define RCC_UART5_CLK_ENABLE() SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN)
#define RCC_USART6_CLK_ENABLE() SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART6EN)

/*
 * RCC GPIO Clock disable macro definitions
 */
#define RCC_GPIOA_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN)
#define RCC_GPIOB_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN)
#define RCC_GPIOC_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN)
#define RCC_GPIOD_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN)
#define RCC_GPIOE_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN)
#define RCC_GPIOF_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN)
#define RCC_GPIOG_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN)
#define RCC_GPIOH_CLK_DISABLE() CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN)

/*
 * RCC I2C Clock disable macro definitions
 */
#define RCC_I2C1_CLK_DISABLE() CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN)
#define RCC_I2C2_CLK_DISABLE() CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN)
#define RCC_I2C3_CLK_DISABLE() CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C3EN)

/*
 * RCC SPI Clock disable macro definitions
 */
#define RCC_SPI1_CLK_DISABLE() CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN)
#define RCC_SPI2_CLK_DISABLE() CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN)
#define RCC_SPI3_CLK_DISABLE() CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN)
#define RCC_SPI4_CLK_DISABLE() CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI4EN)

#define RCC_GPIOA_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOAEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOAEN);                            \
  } while (0)

#define RCC_GPIOB_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOBEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOBEN);                            \
  } while (0)

#define RCC_GPIOC_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOCEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIODEN);                            \
  } while (0)

#define RCC_GPIOD_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIODEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIODEN);                            \
  } while (0)

#define RCC_GPIOE_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOEEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOEEN);                            \
  } while (0)

#define RCC_GPIOF_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOFEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOFEN);                            \
  } while (0)

#define RCC_GPIOG_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOGEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOGEN);                            \
  } while (0)

#define RCC_GPIOH_RESET()                                                      \
  do {                                                                         \
    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOHEN);                              \
    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPIOHEN);                            \
  } while (0)

#include "stm32f446xx_nvic.h" // since the NVIC is a general peripheral

#endif /* INC_STM32F446XX_H_ */
