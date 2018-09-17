// --------------------------------------------------------------------------------
// -- TITLE:  Plasma UART controller device
// -- AUTHOR: Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
// --------------------------------------------------------------------------------
// -- INTERRUPT CONTROLLER
// ----------------|-----------|-------|-------------------------------------------
// -- REGISTER     | address   | mode  | description
// ----------------|-----------|-------|-------------------------------------------
// -- control      | 0x00      | r/w   | control register
// -- status       | 0x04      | r     | status register
// -- data         | 0x0C      | r/w   | UART RX/TX
// ----------------|-----------|-------|-------------------------------------------
// -- CONTROL      |           |       | 
// ----------------|-----------|-------|-------------------------------------------
// -- reset        | 0         | r/w   | reset device
// -- enable       | 1         | r/w   | enable device
// ----------------|-----------|-------|-------------------------------------------
// -- STATUS       |           |       | 
// ----------------|-----------|-------|-------------------------------------------
// -- ready        | 0         | r     | device ready
// -- davail       | 1         | r     | data available
// ----------------|-----------|-------|-------------------------------------------

#pragma once

#include <kernel/kernel.h>
#include <kernel/device.h>
#include <ksys/types.h>

typedef struct kos_uart_t
{
    device_t device;
} kos_uart_t;


void uart_reset     (kos_uart_t* uart);
void uart_enable    (kos_uart_t* uart);
void uart_disable   (kos_uart_t* uart);
uint8_t uart_read   (kos_uart_t* uart);
void uart_write     (kos_uart_t* uart, uint8_t data);