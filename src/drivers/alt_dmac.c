#include <kdev/alt_dmac.h>

#ifndef __kebabos__
#include <ksys/time.h>
#endif

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