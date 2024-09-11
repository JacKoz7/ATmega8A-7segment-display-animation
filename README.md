# ATmega8A Interactive Display Project

## Project Description

This project showcases an interactive status display using an ATmega8A microcontroller. It features animated text on a 4-digit 7-segment display, toggling between "OPEN" and "CLOSED" states with smooth scrolling animations.

![IMG_0333](https://github.com/JacKoz7/7-segment-display/assets/126762316/8a292c57-a935-4f3b-9d99-37b1e3c9ebb6)

## Features

- Animated display of "OPEN" and "CLOSED" states
- Smooth left-scrolling text animation
- Button-activated state toggle
- Efficient multiplexed display driving
- Debounced button input

## Hardware

- Microcontroller: ATmega8A
- Display: 4-digit, 7-segment (common cathode)
- Status toggle button: connected to PB0
- Programmer: USBasp

## Software

The project is written in C and uses AVR-GCC for compilation. Key software features include:

- Efficient use of PROGMEM for storing display patterns
- Interrupt-driven display multiplexing
- Software debouncing for reliable button operation

## Animations

- "OPEN": Text scrolls one position to the left in an infinite loop (OPEN -> PEN  -> EN O -> N OP -> etc.)
- "CLOSED": Displays the sequence CLOS -> LOSE -> OSED -> etc.

https://github.com/JacKoz7/7-segment-display/assets/126762316/d057253d-35fd-4350-9f73-168d1be03dd2

## Usage

- Upon powering on, the device defaults to displaying the "OPEN" animation.
- To change the state to "CLOSED", press the button connected to PB0.
- Press the button again to revert to the "OPEN" state.

## Customization

You can easily modify the display patterns or add new states:

- Edit the segments array in the source code to change display patterns.
- Adjust the animation logic in the main loop to add new states or modify existing ones.

## Author

Jacek Kozłowski
