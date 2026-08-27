#ifndef INC_STM32F446XX_EX_H_
#define INC_STM32F446XX_EX_H_

#define SET_BIT(REG, BIT) ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))

#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE

#endif
