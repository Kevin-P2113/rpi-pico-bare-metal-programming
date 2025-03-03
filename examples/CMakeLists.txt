project(examples)

add_library(examples
    examples_info/example_info.c
    ex_00_blinky_led/blinky_led.c
)

target_include_directories(examples PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    examples_info
)

target_link_libraries(examples
pico_stdlib
)