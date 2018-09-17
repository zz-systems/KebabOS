#include <kdev/counter.h>
#include <kernel/io.h>

void counter_set_reload(kos_counter_t* counter, uint32_t value)
{
    counter->reload = value;
}

void counter_reset(kos_counter_t* counter, uint32_t flags)
{
    kdc_write(counter, DEVICE_RESET | flags);
    kdc_write(counter, flags);
}

void counter_enable(kos_counter_t* counter, uint32_t flags)
{
    kdc_write(counter, DEVICE_ENABLE | flags);
}