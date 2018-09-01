#pragma once

#include <plasma_soc.h>

#ifndef __linux__
#define __kebabos
#endif


/**
 * @brief read raw data at address
 */
#define kmread(address) (*(volatile unsigned int*)(address))

/**
 * @brief write raw data at address
 */
#define kmwrite(address, value) (*(volatile unsigned int*)(address)=(value))