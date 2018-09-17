// --------------------------------------------------------------------------------
// -- TITLE:  Display controller device
// -- AUTHOR: Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
// --------------------------------------------------------------------------------
// -- DISPLAY CONTROLLER
// ----------------|-----------|-------|-------------------------------------------
// -- REGISTER     | address   | mode  | description
// ----------------|-----------|-------|-------------------------------------------
// -- control      | 0x0       | r/w   | control register
// -- status       | 0x4       | r     | status register
// -- data         | 0x8       | w     | vram data window
// ----------------|-----------|-------|-------------------------------------------
// -- CONTROL      |           |       | 
// ----------------|-----------|-------|-------------------------------------------
// -- reset        | 0         | r/w   | reset device
// -- enable       | 1         | r/w   | enable device
// -- immediate    | 2         | r/w   | immediate mode (immediate SPI commands)
// -- textmode     | 3         | r/w   | text mode (interpret vram as ASCII)
// -- flush        | 4         | r/w   | flush vram to screen
// -- burst        | 5         | r/w   | burst transfer (auto increment address)
// ----------------|-----------|-------|-------------------------------------------
// -- STATUS       |           |       | 
// ----------------|-----------|-------|-------------------------------------------
// -- ready        | 0         | r     | display ready
// ----------------|-----------|-------|-------------------------------------------

#pragma once

#include <kernel/kernel.h>
#include <kernel/device.h>
#include <ksys/types.h>

// control register bits
#define DISPLAY_CONTROL_IMMEDIATE           0x04
#define DISPLAY_CONTROL_TEXTMODE            0x08
#define DISPLAY_CONTROL_FLUSH               0x10
#define DISPLAY_CONTROL_CLEAR               0x20


typedef struct kos_display_t
{
    device_t    device;
} kos_display_t;


void display_reset              (kos_display_t* display);
void display_enable             (kos_display_t* display);
void display_disable            (kos_display_t* display);

void display_set_textmode       (kos_display_t* display);
void display_set_graphicmode    (kos_display_t* display);
void display_flush              (kos_display_t* display);
void display_clear              (kos_display_t* display);