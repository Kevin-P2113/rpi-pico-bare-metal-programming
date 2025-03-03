#include "examples_defines.h"
#include "example_selection.h"

example_ptr example_pointer;

void build_examples(void)
{

#ifdef TEST_BLINKY_LED
    extern int blinky_led(void);
    example_pointer = blinky_led;
#endif
}