#include <sys/types.h>

/**
 * @brief nanostdlib allocate memory chunk
 * 
 * @param size requested chunk size
 * @return void* allocated chunk address if successful, else NULL
 */
void *malloc(uint32_t size);

/**
 * @brief nanostdlib 
 * 
 * @param ptr allocated memory address
 */
void free(void* ptr);
