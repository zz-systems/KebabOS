#include <kdev/display.h>

void display_reset(kos_display_t* display)
{
    kd_reset(&display->device);
}

void display_enable(kos_display_t* display)
{
    kd_enable(&display->device);
}

void display_disable(kos_display_t* display)
{
    kd_disable(&display->device);
}

void display_set_textmode(kos_display_t* display)
{
    display->device.control |= DISPLAY_CONTROL_TEXTMODE;
}

void display_set_graphicmode(kos_display_t* display)
{
    display->device.control &= ~DISPLAY_CONTROL_TEXTMODE;
}

void display_flush(kos_display_t* display)
{
    display->device.control |= DISPLAY_CONTROL_FLUSH;
    display->device.control &= ~DISPLAY_CONTROL_FLUSH;
}

void display_clear(kos_display_t* display)
{
    display->device.control |= DISPLAY_CONTROL_CLEAR;
    display->device.control &= ~DISPLAY_CONTROL_CLEAR;
}