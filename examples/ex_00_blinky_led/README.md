# GPIO Control on the Raspberry Pi Pico

This document outlines how to control GPIO pins, specifically GPIO 25 (the onboard LED), on the Raspberry Pi Pico using direct register manipulation.

## Memory Map and Register Information

The USER IO Bank, which manages the GPIO pins, starts at the memory address `0x40014000`. Each GPIO pin is allocated 4 bytes (32 bits) in this memory space.

| Offset (Hex) | Register Name | Description |
|--------------|---------------|-------------|
| 0x000        | GPIO_0_STATUS | Status register for GPIO pin 0 (bits 0-15). |
| 0x004        | GPIO_0_CTRL   | Control register for GPIO pin 0 (bits 16-31). |
| 0x008        | GPIO_1_STATUS | Status register for GPIO pin 1 (bits 0-15). |
| 0x00C        | GPIO_1_CTRL   | Control register for GPIO pin 1 (bits 16-31). |
| ...          | ...           | ...         |
| 0x064        | GPIO_25_STATUS| Status register for GPIO pin 25 (bits 0-15). |
| 0x068        | GPIO_25_CTRL  | Control register for GPIO pin 25 (bits 16-31). |
| ...          | ...           | ...         |

**Note:** Each GPIO pin's registers are located at an offset of `0x008` from the previous pin. For example, GPIO 25 is located at `0x40014000 + (25 * 0x008)`.

## Controlling GPIO 25 (Onboard LED)

The onboard LED on the Raspberry Pi Pico is connected to GPIO pin 25. To control the LED, we need to modify the `GPIO_25_CTRL` register.

### Steps to Blink the LED:

1.  **Calculate the Control Register Address:**
    * The base address of the USER IO Bank is `0x40014000`.
    * The offset for GPIO 25 is `25 * 0x008 = 0x068`.
    * Therefore, the address of `GPIO_25_CTRL` is `0x40014000 + 0x068 = 0x40014068`.

2.  **Configure the Pin as Output:**
    * Write the appropriate value to the control register to configure the pin as an output. Refer to the Raspberry Pi Pico datasheet for the specific bit fields and values.

3.  **Set the Pin High (Logic 1):**
    * Write the appropriate value to the control register to set the pin high, turning the LED on.

4.  **Set the Pin Low (Logic 0):**
    * Write the appropriate value to the control register to set the pin low, turning the LED off.

5.  **Repeat Steps 3 and 4:**
    * By repeatedly toggling the pin between high and low, you can make the LED blink.
