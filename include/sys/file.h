#pragma once

#include <kernel/device.h>

#define BUF_SIZE 64
#define FILE_READ_MODE  0x1
#define FILE_WRITE_MODE 0x2

#define FILE_ERR_BUFFER_FULL 0x1
#define FILE_ERR_MODE_WRONG 0x2

/**
 * @brief FILE structure. Abstraction over device buffers.
 */
typedef struct
{
    device_descriptor_t *device_desc;
    uint8_t *read_buffer;
    uint8_t *write_buffer;

    uint8_t *read_ptr;
    uint8_t *write_ptr;
    int rb_size;
    int wb_size;
    int err;
} FILE;

/**
 * @brief seek mode
 */
typedef enum
{
    SEEK_SET, ///< file start + offset
    SEEK_CUR, ///< current position + offset
    SEEK_END  ///< file end + offset
} seek_origin_t;

/**
 * @brief open file with specified mode
 * 
 * @param path file path
 * @param mode file open mode
 * @return FILE* opened file if successful, else NULL
 */
FILE* fopen(const char* path, const char* mode);

/**
 * @brief open device file with specified mode
 * 
 * @param device_desc device descriptor
 * @param mode file open mode
 * @return FILE* opened file if successful, else NULL
 */
FILE* fdopen(device_descriptor_t *device_desc, int mode);

/**
 * @brief close file
 * 
 * @param file target file to close
 */
void fclose(FILE* file);

/**
 * @brief write data to file
 * 
 * @param file target file
 * @param data data to write
 * @return int written bytes
 */
int fwrite(FILE* file, uint8_t data);

/**
 * @brief write string (unformatted) to file
 * 
 * @param file target file
 * @param data data string to write
 * @return int written bytes
 */
int fprint(FILE* file, const char* data);

/**
 * @brief read byte from file
 * 
 * @param file source file
 * @return uint8_t read byte
 */
uint8_t fread(FILE* file);

/**
 * @brief flush file buffers
 * 
 * @param file target file
 */
void fflush(FILE* file);

/**
 * @brief set file cursor at specified position
 * 
 * @param file target file
 * @param offset offset
 * @param seek_origin origin
 */
void fseek(FILE *file, int offset, int seek_origin);