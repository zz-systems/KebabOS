#pragma once

#include <kernel/device.h>

/**
 * @brief read data from device
 * 
 * @param device source device
 * @return uint32_t read data word
 */
uint32_t kd_read(device_t* device);

/**
 * @brief wirte data to device
 * 
 * @param device target device
 * @param data source data word
 */
void kd_write(device_t* device, uint32_t data);

/**
 * @brief put char to device
 * 
 * @param device target device
 * @param character source character
 * @return int written bytes
 */
int kd_putc(device_t* device, uint8_t character);

/**
 * @brief get character from device
 * 
 * @param device source device
 * @return int read char
 */
uint8_t kd_getc(device_t* device);

/**
 * @brief put string to device
 * 
 * @param device target device
 * @param string source string
 * @return int written bytes
 */
int kd_puts(device_t* device, const char *string);

/**
 * @brief read data from device control register
 * 
 */
#define kdc_read(dev)           (dev->device.control)

/**
 * @brief test flags in device control register
 * 
 */
#define kdc_test(dev, flags)    (dev->device.control & flags)

/**
 * @brief write data to device control register
 * 
 */
#define kdc_write(dev, data)    (dev->device.control = (data))

/**
 * @brief set flags in device control register
 * 
 */
#define kdc_set(dev, flags)     (dev->device.control |= flags)

/**
 * @brief unset flags in device control register
 */
#define kdc_unset(dev, flags)   (dev->device.control &= ~flags)

/**
 * @brief read data from device status register
 */
#define kds_read(dev)           (dev->device.status)

/**
 * @brief test flags in device status register
 */
#define kds_test(dev, flags)    (dev->device.status & flags)

/**
 * @brief read data from device data register 
 */
#define kdd_read(dev)           (dev->device.data)

/**
 * @brief write data to device register
 */
#define kdd_write(dev, data)    (dev->device.data = (data))