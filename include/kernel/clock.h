// -----------------------------------------------------------------------------
// -- TITLE:  kernel clock definitions
// -- AUTHOR: Sergej Zuyev (sergej.zuyev - at - zz-systems.net)
// -----------------------------------------------------------------------------

#pragma once

#ifdef SYSTEM_CLOCK

    // Derive tick/time ratios from clock
    #define TICKS_PER_S       (SYSTEM_CLOCK)
    #define TICKS_PER_MS      (TICKS_PER_S / 1000)
    #define TICKS_PER_US      (TICKS_PER_MS / 1000)
    #define TICKS_PER_NS      (TICKS_PER_NS / 1000)
    #define TICKS_PER_TICK    (1)

#endif