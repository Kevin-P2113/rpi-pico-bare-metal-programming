#include "pico/stdlib.h"
#include "example_selection.h"
#include <stdint.h>

#ifdef TEST_BLINKY_LED

void blinky_led()
{
    /* address of gpio25*/
    volatile uint32_t *pin25 = (volatile uint32_t *)(0x40014000 + 0x0cc);

    /* make the pin high */
    *pin25 = 0;
    *pin25 |= (3 << 12);
    *pin25 |= (3 << 8);

    /* wait for sometime */
    sleep_ms(250);

    /* make the led low */
    *pin25 = 0;

    /* wait for sometime */
    sleep_ms(250);
}

#endif