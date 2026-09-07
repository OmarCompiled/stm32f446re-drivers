#ifndef INC_STM32F446XX_GPIO_EX_H_
#define INC_STM32F446XX_GPIO_EX_H_

typedef enum {
  GPIO_PIN_0 = ((uint16_t)0x0001),   /* Pin 0 selected    */
  GPIO_PIN_1 = ((uint16_t)0x0002),   /* Pin 1 selected    */
  GPIO_PIN_2 = ((uint16_t)0x0004),   /* Pin 2 selected    */
  GPIO_PIN_3 = ((uint16_t)0x0008),   /* Pin 3 selected    */
  GPIO_PIN_4 = ((uint16_t)0x0010),   /* Pin 4 selected    */
  GPIO_PIN_5 = ((uint16_t)0x0020),   /* Pin 5 selected    */
  GPIO_PIN_6 = ((uint16_t)0x0040),   /* Pin 6 selected    */
  GPIO_PIN_7 = ((uint16_t)0x0080),   /* Pin 7 selected    */
  GPIO_PIN_8 = ((uint16_t)0x0100),   /* Pin 8 selected    */
  GPIO_PIN_9 = ((uint16_t)0x0200),   /* Pin 9 selected    */
  GPIO_PIN_10 = ((uint16_t)0x0400),  /* Pin 10 selected   */
  GPIO_PIN_11 = ((uint16_t)0x0800),  /* Pin 11 selected   */
  GPIO_PIN_12 = ((uint16_t)0x1000),  /* Pin 12 selected   */
  GPIO_PIN_13 = ((uint16_t)0x2000),  /* Pin 13 selected   */
  GPIO_PIN_14 = ((uint16_t)0x4000),  /* Pin 14 selected   */
  GPIO_PIN_15 = ((uint16_t)0x8000),  /* Pin 15 selected   */
  GPIO_PIN_All = ((uint16_t)0xFFFF), /* All pins selected */
} GPIO_pin_t;

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7
#define PA8 8
#define PA9 9
#define PA10 10
#define PA11 11
#define PA12 12
#define PA13 13
#define PA14 14
#define PA15 15

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7
#define PB8 8
#define PB9 9
#define PB10 10
#define PB11 11
#define PB12 12
#define PB13 13
#define PB14 14
#define PB15 15

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7
#define PC8 8
#define PC9 9
#define PC10 10
#define PC11 11
#define PC12 12
#define PC13 13
#define PC14 14
#define PC15 15

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7
#define PD8 8
#define PD9 9
#define PD10 10
#define PD11 11
#define PD12 12
#define PD13 13
#define PD14 14
#define PD15 15

#define PE0 0
#define PE1 1
#define PE2 2
#define PE3 3
#define PE4 4
#define PE5 5
#define PE6 6
#define PE7 7
#define PE8 8
#define PE9 9
#define PE10 10
#define PE11 11
#define PE12 12
#define PE13 13
#define PE14 14
#define PE15 15

#define PF0 0
#define PF1 1
#define PF2 2
#define PF3 3
#define PF4 4
#define PF5 5
#define PF6 6
#define PF7 7
#define PF8 8
#define PF9 9
#define PF10 10
#define PF11 11
#define PF12 12
#define PF13 13
#define PF14 14
#define PF15 15

#define PG0 0
#define PG1 1
#define PG2 2
#define PG3 3
#define PG4 4
#define PG5 5
#define PG6 6
#define PG7 7
#define PG8 8
#define PG9 9
#define PG10 10
#define PG11 11
#define PG12 12
#define PG13 13
#define PG14 14
#define PG15 15

#define PH0 0
#define PH1 1
#define PH2 2
#define PH3 3
#define PH4 4
#define PH5 5
#define PH6 6
#define PH7 7
#define PH8 8
#define PH9 9
#define PH10 10
#define PH11 11
#define PH12 12
#define PH13 13
#define PH14 14
#define PH15 15

#endif
