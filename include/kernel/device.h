// -----------------------------------------------------------------------------
// -- TITLE:  device
// -- AUTHOR: Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
// -----------------------------------------------------------------------------

#pragma once

#include <ksys/types.h>

// Simplify address binding
#define kbind_device(device_type, address) ((device_type*)(address))

// common control register bits
#define DEVICE_RESET                        0x01 
#define DEVICE_ENABLE                       0x02

// common status register bits
#define DEVICE_READY                        0x01
#define DEVICE_DAVAIL                       0x02

/**
 * @brief base device structure. Memory-Mapped. 
 */
typedef struct
{
    reg32_t control;    ///< control register
    reg32_t status;     ///< status register
    reg32_t data;       ///< data register
} volatile device_t;

#define OFFSET_CONTROL  0x0
#define OFFSET_STATUS   0x4
#define OFFSET_DATA     0x8

/**
 * @brief Device descriptor: device base registers associated with device type
 * 
 */
typedef struct
{
    device_t *device;   ///< device base registers
    int type;           ///< device type
} device_descriptor_t;

/**
 * @brief Device types enumeration
 */
typedef enum 
{
    DEVICE_UNKNOWN,     ///< unknown device
    DEVICE_COUNTER,     ///< counter
    DEVICE_TIMER,       ///< timer
    DEVICE_IRC,         ///< interrupt controller
    DEVICE_GPIO,        ///< GPIO
    DEVICE_UART,        ///< UART controller
    DEVICE_SPIC,        ///< SPI controller
    DEVICE_DISPLAY,     ///< display controller
    DEVICE_FS           ///< file system
} devices_t;

/**
 * @brief wait & block until device signals ready state
 * 
 * @param device device to await
 */
void kd_await_ready         (device_t* device);

/**
 * @brief wait & block until device signals available data
 * 
 * @param device device to await
 */
void kd_await_data          (device_t* device);

/**
 * @brief reset device
 * 
 * @param device device to reset
 */
void kd_reset               (device_t* device);

/**
 * @brief enable device
 * 
 * @param device device to enable
 */
void kd_enable              (device_t* device);

/**
 * @brief disable device
 * 
 * @param device device to disable
 */
void kd_disable             (device_t* device);

/**
 * @brief open device via a path string
 * 
 * @param path device path
 * @return device_descriptor_t* device descriptor if successful, else NULL
 */
device_descriptor_t *kdopen (const char* path);