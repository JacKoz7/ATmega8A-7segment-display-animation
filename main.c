#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

// Define 7-segment display patterns for "OPEN" and "CLOSED" in program memory
const uint8_t PROGMEM segments[][7] = {
	{0b00111111, 0b01110011, 0b01111001, 0b00110111, 0}, // OPEN
	{0b00111001, 0b00111000, 0b00111111, 0b01101101, 0b01111001, 0b01011110, 0} // CLOSED
};

int main(void) {
	// Configure I/O ports
	DDRD = 0xFF;  // Set PORTD as output for segments
	DDRC |= 0x0F; // Set lower 4 bits of PORTC as output for digit selection
	DDRB &= ~(1 << PB0); // Set PB0 as input for button
	PORTB |= (1 << PB0); // Enable pull-up resistor for PB0

	// Initialize variables
	uint8_t i = 0, state = 0, last_button = 0, button_pressed = 0;
	
	while (1) {
		// Read button state (active low)
		uint8_t button = !(PINB & (1 << PB0));
		
		// Button press detection with debouncing
		if (button && !last_button) {
			_delay_ms(10); // Debounce 
			button_pressed = 1;
			} else if (!button && last_button) {
			_delay_ms(10); // Debounce delay for button release
			if (button_pressed) {
				state ^= 1; // Toggle state between OPEN and CLOSED
				i = 0;      // Reset display index
				button_pressed = 0;
			}
		}
		last_button = button;

		// Display loop
		for (uint8_t k = 0; k < 50; k++) {
			for (uint8_t j = 0; j < 4; j++) {
				PORTD = 0x00; // Turn off all segments
				PORTC = ~(1 << j); // Select digit (active low)
				// Display appropriate segment pattern
				PORTD = pgm_read_byte(&segments[state][(i + j) % (state ? 0x7 : 0x5)]);
				_delay_ms(1);
			}
		}
		
		// Move to next character in the sequence
		i = (i + 1) % (state ? 0x7 : 0x5);
	}
}