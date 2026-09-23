#include "stm32f446xx.h"

void NVIC_enable_IRQ(IRQ_t IRQ) {
	if (IRQ < 0) {
		return;
	}

	NVIC->ISER[IRQ / 32] |= (0x1U << (IRQ % 32));
}

void NVIC_disable_IRQ(IRQ_t IRQ) {
	if (IRQ < 0) {
		return;
	}	

	NVIC->ICER[IRQ / 32] &= ~(0x1U << (IRQ % 32));
}

void NVIC_set_pending_IRQ(IRQ_t IRQ) {
	if (IRQ < 0) {
		return;
	}

	NVIC->ISPR[IRQ / 32] |= (0x1U << (IRQ % 32));
}

void NVIC_clear_pending_IRQ(IRQ_t IRQ) {
	if (IRQ < 0) {
		return;
	}

	NVIC->ICPR[IRQ / 32] |= (0x1U << (IRQ % 32));
}

void NVIC_set_priority_IRQ(IRQ_t IRQ) {
	if (IRQ < 0) {
		return;
	}

	if (0 > priority || priority > 255) {
		return;
	}

	/* STM32F4 ignores the lower 4 bits;
	 * Hence the << 4*/
	NVIC->IPR[IRQ] = (priority & 0xF) << 4;
}
