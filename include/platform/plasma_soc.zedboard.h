

#pragma once

#include <kernel/device.h>
#include <dev/counter.h>
#include <dev/irc.h>
#include <dev/gpio.h>
#include <dev/uart.h>
#include <dev/display.h>
#include <dev/timer.h>

// 50MHz
#define SYSTEM_CLOCK        (50 * 1000 * 1000)

// 8 KB
#define MEMORY_SIZE         (8 * 1024 * 1024)

// Provide Plasma SoC device addresses
#define IRC_BASE            0x20000000
#define UART0_BASE          0x20000100

#define TIMER0_BASE         0x20000200
#define TIMER1_BASE         (TIMER1_BASE + 0x10)
#define TIMER2_BASE         (TIMER2_BASE + 0x20)
#define TIMER3_BASE         (TIMER3_BASE + 0x30)

#define COUNTER0_BASE       0x20000300
#define COUNTER1_BASE       (COUNTER0_BASE + 0x10)
#define COUNTER2_BASE       (COUNTER0_BASE + 0x20)
#define COUNTER3_BASE       (COUNTER0_BASE + 0x30)

#define GPIO0_BASE          0x20000400
#define GPIO1_BASE          (GPIO0_BASE + 0x10)
#define GPIO2_BASE          (GPIO0_BASE + 0x20)
#define GPIO3_BASE          (GPIO0_BASE + 0x30)

#define SPI_BASE            0x20000500
#define DISPLAY0_BASE	    0x40000000


// Define devices
#define irc0        (kbind_device(irc_t, IRC_BASE))
#define uart0       (kbind_device(uart,  UART0_BASE))

#define timer0      (kbind_device(timer_t, TIMER0_BASE))
#define timer1      (kbind_device(timer_t, TIMER1_BASE))
#define timer2      (kbind_device(timer_t, TIMER2_BASE))
#define timer3      (kbind_device(timer_t, TIMER3_BASE))

#define counter0    (kbind_device(counter_t, COUNTER0_BASE))
#define counter1    (kbind_device(counter_t, COUNTER1_BASE))
#define counter2    (kbind_device(counter_t, COUNTER2_BASE))
#define counter3    (kbind_device(counter_t, COUNTER3_BASE))

#define gpio0       (kbind_device(gpio_t, GPIO0_BASE))
#define gpio1       (kbind_device(gpio_t, GPIO1_BASE))
#define gpio2       (kbind_device(gpio_t, GPIO2_BASE))
#define gpio3       (kbind_device(gpio_t, GPIO3_BASE))

#define display0    (kbind_device(display_t, DISPLAY0_BASE))

// Define interrupt flags
#define IR_UART_READ    (1 << 0)
#define IR_UART_WRITE   (1 << 1)
#define IR_CNT_OVERFLOW (1 << 2)
