// --------------------------------------------------------------------------------
// -- TITLE:  Altera DMA controller IP Core device
// -- AUTHOR: Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
// --------------------------------------------------------------------------------
// -- Altera DMA CONTROLLER (See Embedded Peripherals IP User Guide, Page 269)
// ----------------|-----------|-------|-------------------------------------------
// -- REGISTER     | address   | mode  | description
// ----------------|-----------|-------|-------------------------------------------
// -- status       | 0x00      | r/w   | Status register
// -- readaddress  | 0x04      | r/w   | Read master start address
// -- writeaddress | 0x08      | r/w   | Write master start address
// -- length       | 0x0C      | r/w   | DMA transaction length (in bytes)
// --              | 0x10      |       | Reserved
// --              | 0x14      |       | Reserved
// -- control      | 0x18      | r/w   | Control register
// --              | 0x1C      |       | Reserved
// ----------------|-----------|-------|-------------------------------------------

#pragma once

#include <kernel/kernel.h>
#include <kernel/device.h>
#include <ksys/types.h>

#ifndef __kebabos__
#include <sys/time.h>
#endif

// Status reg flags
#define ALT_DMAC_STAT_LEN   (1 << 4)
#define ALT_DMAC_STAT_WEOP  (1 << 3)
#define ALT_DMAC_STAT_REOP  (1 << 2)
#define ALT_DMAC_STAT_BUSY  (1 << 1)
#define ALT_DMAC_STAT_DONE  (1 << 0)

// Control reg flags
#define ALT_DMAC_CTL_SWRESET    (1 << 12)
#define ALT_DMAC_CTL_QWORD      (1 << 11)
#define ALT_DMAC_CTL_DWORD      (1 << 10)
#define ALT_DMAC_CTL_WCON       (1 << 9)
#define ALT_DMAC_CTL_RCON       (1 << 8)
#define ALT_DMAC_CTL_LEEN       (1 << 7)
#define ALT_DMAC_CTL_WEEN       (1 << 6)
#define ALT_DMAC_CTL_REEN       (1 << 5)
#define ALT_DMAC_CTL_I_EN       (1 << 4)
#define ALT_DMAC_CTL_GO         (1 << 3)
#define ALT_DMAC_CTL_WORD       (1 << 2)
#define ALT_DMAC_CTL_HW         (1 << 1)
#define ALT_DMAC_CTL_BYTE       (1 << 0)

typedef struct alt_dmac_t
{
    reg32_t status;
    reg32_t readaddress;
    reg32_t writeaddress;
    reg32_t length;

    reg32_t reserved0;
    reg32_t reserved1;

    reg32_t control;
    reg32_t reserved2;
} alt_dmac_t;


void alt_dmac_reset(alt_dmac_t* dmac);
void alt_dmac_await(alt_dmac_t* dmac);
void alt_dmac_stop (alt_dmac_t* dmac);

void alt_dmac_reset(alt_dmac_t* dmac)
{
    dmac->status = 0;
}

void alt_dmac_await(alt_dmac_t* dmac)
{
    while(dmac->status & ALT_DMAC_STAT_BUSY)
    {
        #ifndef __kebabos__
        struct timespec s;
		s.tv_sec = 0;
		s.tv_nsec = 1000000L;

		nanosleep(&s, NULL);
        #endif 
    }
}

void alt_dmac_stop (alt_dmac_t* dmac)
{
    dmac->control = 0;
}
