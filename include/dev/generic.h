#include <kernel/kernel.h>
#include <kernel/device.h>
#include <sys/types.h>

typedef struct generic_device
{
    device_t    device;
} generic_device_t;