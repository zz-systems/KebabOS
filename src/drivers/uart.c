#include <kdev/uart.h>
#include <kernel/io.h>

void uart_reset(kos_uart_t* uart)
{
    kd_reset(&uart->device);
}

void uart_enable(kos_uart_t* uart)
{
    kd_enable(&uart->device);
}

void uart_disable(kos_uart_t* uart)
{
    kd_disable(&uart->device);
}

uint8_t uart_read(kos_uart_t* uart)
{
    return kdd_read(uart);
}

void uart_write(kos_uart_t* uart, uint8_t data)
{
    kdd_write(uart, data);
}