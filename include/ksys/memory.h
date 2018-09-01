#include <ksys/types.h>

/**
 * @brief allocate memory chunk
 * 
 * @param size requested chunk size
 * @return void* allocated chunk address if successful, else NULL
 */
void *malloc(uint32_t size);

/**
 * @brief deallocate memory chunk
 * 
 * @param ptr allocated memory address
 */
void free(void* ptr);

/**
 * @brief copies ch into the first count characters of buffer
 * 
 * @param ptr allocated memory address
 */
void* memset(void* buffer, int ch, size_t count);