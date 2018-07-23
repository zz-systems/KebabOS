#include <dev/display.h>

void display_reset(display_t* display)
{
    kd_reset(&display->device);
}

void display_enable(display_t* display)
{
    kd_enable(&display->device);
}

void display_disable(display_t* display)
{
    kd_disable(&display->device);
}

void display_set_textmode(display_t* display)
{
    display->device.control |= DISPLAY_CONTROL_TEXTMODE;
}

void display_set_graphicmode(display_t* display)
{
    display->device.control &= ~DISPLAY_CONTROL_TEXTMODE;
}

void display_flush(display_t* display)
{
    display->device.control |= DISPLAY_CONTROL_FLUSH;
    display->device.control &= ~DISPLAY_CONTROL_FLUSH;
}

void display_clear(display_t* display)
{
    display->device.control |= DISPLAY_CONTROL_CLEAR;
    display->device.control &= ~DISPLAY_CONTROL_CLEAR;
}