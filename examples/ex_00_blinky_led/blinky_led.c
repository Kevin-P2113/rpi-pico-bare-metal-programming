#include "pico/stdlib.h"
#include "example_selection.h"
#include <stdint.h>

#ifdef TEST_BLINKY_LED

void blinky_led()
{
    /* 1. deassert the reset of the IOBANK0 peripheral */
    volatile uint32_t *reset_reg = (volatile uint32_t *)0x4000f000; // 0x4000c000 + 0x3000 (atomic bitmask clear on write)
    *reset_reg = 32U;

    /* 2. check if peripheral can now be used  */
    volatile uint32_t *reset_done_reg = (volatile uint32_t *)0x4000c008;
    while (1)
    {
        if ((*reset_done_reg & 32) != 0)
        {
            /* reset done */
            break;
        }
    }

    /* 3. selecting SIO function on gpio pin 25 (led pin) */
    volatile uint32_t *gpio_25_control_reg = (volatile uint32_t *)(0x40014000 + 0x0cc);
    *gpio_25_control_reg = 5U;

    /* 4. perform an atomic bit set on the GPIO_OE_ENABLE regsiter by writing to the set register */
    volatile uint32_t *gpio_oe_enable_set_reg = (volatile uint32_t *)(0xd0000000 + 0x24);
    *gpio_oe_enable_set_reg = 1 << 25;

    while (1)
    {
        /* 5. make the pin high */
        volatile uint32_t *gpio_out_set_reg = (volatile uint32_t *)(0xd0000000 + 0x14);
        *gpio_out_set_reg = 1 << 25;

        /* delay */
        for (volatile int i = 0; i < 10000000; i++)
        {
            // NOP
        }

        /* 6. make the pin low */
        volatile uint32_t *gpio_out_clear_reg = (volatile uint32_t *)(0xd0000000 + 0x18);
        *gpio_out_clear_reg = (1 << 25);

        /* delay */
        for (volatile int i = 0; i < 10000000; i++)
        {
            // NOP
        }
    }
}

#endif