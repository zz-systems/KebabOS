

#pragma once

#include <kernel/device.h>
#include <kdev/counter.h>
#include <kdev/irc.h>
#include <kdev/gpio.h>
#include <kdev/uart.h>
#include <kdev/display.h>
#include <kdev/timer.h>

#ifndef PLATFORM
    #define PLATFORM de1_soc
#endif

#define PLATFORM_H <platform/plasma_soc.PLATFORM.h>

#include PLATFORM_H
