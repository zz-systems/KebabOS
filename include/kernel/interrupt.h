#pragma once

/**
 * @brief interrupt handler signature
 */
typedef void (*ir_handler)(void);

/**
 * @brief register interrupt handler
 * 
 * @param handler handler function
 * @param ir_flag lower 5 bits: interrupt number, bit 16: polarity, bit 17: edge detection
 */
void kir_register_handler(ir_handler handler, unsigned ir_flag);

/**
 * @brief enable system interrupts
 * 
 * @param enable enable (boolean)
 */
extern void kir_enable(unsigned enable);