#include <stdio.h>
#include "pico/stdlib.h"
#include "examples_defines.h"

extern example_ptr example_pointer;

int main()
{
    stdio_init_all();
    build_examples();

    while (true)
    {
        example_pointer();
    }
}