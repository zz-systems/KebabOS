#include <plasma_soc.h>
#include <kernel/device.h>
#include <kernel/memory.h>
#include <ksys/string.h>

void kd_await_ready(device_t* device)
{
    while((device->status & DEVICE_READY) == 0);
}

void kd_await_data(device_t* device)
{
    while((device->status & DEVICE_DAVAIL) == 0);
}

void kd_reset(device_t* device)
{
    device->control |= DEVICE_RESET;
    device->control &= ~DEVICE_RESET;

    //device_await_ready(device);
}

void kd_enable(device_t* device)
{
    device->control |= DEVICE_ENABLE;

    //device_await_ready(device);
}

void kd_disable(device_t* device)
{
    device->control &= ~DEVICE_ENABLE;
}

device_descriptor_t *kdopen(const char* path)
{
    device_descriptor_t *descriptor = (device_descriptor_t*) kmalloc(sizeof(device_descriptor_t));
    if(descriptor != NULL)
    {    
        descriptor->device = NULL;
        descriptor->type = DEVICE_UNKNOWN;

        if(strcmp(path, "dev/counter0") == 0)
        {
            descriptor->device = &counter0->device;
            descriptor->type = DEVICE_COUNTER; 
        }
        else if(strcmp(path, "dev/counter1") == 0)
        {
            descriptor->device  = &counter1->device;
            descriptor->type    = DEVICE_COUNTER;
        }
        else if(strcmp(path, "dev/counter2") == 0)
        {
            descriptor->device = &counter2->device;
            descriptor->type = DEVICE_COUNTER;
        }
        else if(strcmp(path, "dev/counter3") == 0)
        {
            descriptor->device = &counter3->device;
            descriptor->type = DEVICE_COUNTER; 
        }
        else if(strcmp(path, "dev/irc0") == 0)
        {
            descriptor->device = &irc0->device;
            descriptor->type = DEVICE_IRC; 
        }
        else if(strcmp(path, "dev/gpio0") == 0)
        {
            descriptor->device = &gpio0->device;
            descriptor->type = DEVICE_GPIO; 
        }
        else if(strcmp(path, "dev/uart0") == 0)
        {
            descriptor->device = &uart0->device;
            descriptor->type = DEVICE_UART; 
        }
        #ifdef display0
        else if(strcmp(path, "dev/display0") == 0)
        {
            descriptor->device = &display0->device;
            descriptor->type = DEVICE_DISPLAY;
        }
        #endif
        else
        {
            kfree(descriptor);
            descriptor = NULL;
        }
    }

    return descriptor;
}