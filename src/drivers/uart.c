#include <kdev/uart.h>
#include <kernel/io.h>

void uart_reset(uart* uart)
{
    kd_reset(&uart->device);
}

void uart_enable(uart* uart)
{
    kd_enable(&uart->device);
}

void uart_disable(uart* uart)
{
    kd_disable(&uart->device);
}

uint8_t uart_read(uart* uart)
{
    return kdd_read(uart);
}

void uart_write(uart* uart, uint8_t data)
{
    kdd_write(uart, data);
}