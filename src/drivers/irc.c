
#include <kdev/irc.h>
#include <kernel/io.h>

int irc_is_set(kos_irc_t *irc, int irq_number)
{
    return kdc_read(irc) & (1 << irq_number);
}

void irc_clear(kos_irc_t *irc, int irq_number)
{
    // set
    irc->clear |=  (1 << irq_number);

    // clear
    irc->clear &= ~(1 << irq_number);
}

void irc_set_mask(kos_irc_t *irc, int irq_number, int value)
{
    // clear
    irc->mask &= ~(1      << irq_number);

    // set
    irc->mask |=  ((value & 1) << irq_number);
}

void irc_set_pol(kos_irc_t *irc, int irq_number, int value)
{
    // clear
    irc->invert &= ~(1      << irq_number);

    // set
    irc->invert |=  ((value & 1) << irq_number);
}

void irc_set_edge(kos_irc_t *irc, int irq_number, int value)
{
    // clear
    irc->edge &= ~(1      << irq_number);

    // set
    irc->edge |=  ((value & 1) << irq_number);
}