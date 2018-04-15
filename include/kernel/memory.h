#pragma once

#include <sys/types.h>

/**
 * @brief align address
 */
#define kalign(address, alignment) (((address) + ((alignment) - 1)) & ~((alignment) - 1))

/**
 * @brief allocate memory chunk 
 * 
 * @param size requested chunk size
 * @return void* allocated chunk address if successful, else NULL
 */
void* kmalloc(uint32_t size);

/**
 * @brief deallocate memory chunk
 * 
 * @param ptr allocated memory address
 */
void kfree(void* ptr);