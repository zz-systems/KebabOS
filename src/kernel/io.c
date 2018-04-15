#include <kernel/io.h>

uint32_t kd_read(device_t* device)
{
    kd_await_data(device);

    return device->data;
}

void kd_write(device_t* device, uint32_t data)
{
    kd_await_ready(device);

    device->data = data;
}

int kd_putc(device_t* device, uint8_t character)
{
    kd_write(device, character);
    return 0;
}

uint8_t kd_getc(device_t* device)
{
    return kd_read(device);
}

int kd_puts(device_t* device, const char *string)
{
    while(*string)
    {
        if(*string == '\n')
            kd_putc(device, '\r');
        kd_putc(device, *string++);
    }
    return 0;
}