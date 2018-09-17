#include <ksys/memory.h>
#include <kernel/memory.h>

void* malloc(uint32_t size)
{
    return kmalloc(size);
}

void free(void* ptr)
{
    kfree(ptr);
}

void* memset(void* buffer, int ch, size_t count)
{
    return kmemset(buffer, ch, count);
}