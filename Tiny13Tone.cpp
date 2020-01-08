// This is all the Arduino wiring references eg PORTB
// and DDRB and everytthing else to do with AVR chips
#include "Arduino.h"

// The library for delays
#include <util/delay.h>
int ralph;

int main(void) {
	// PB4 are LED OUTPUT pins
	// Data Directon Register "B" (ie INPUT or OUTPUT)
	// Set the bit representing PB4 (pin 3) to Bit Value 1
	DDRB |= _BV(PB4);
	// pinMode(PB4, OUTPUT);

	ralph = 0;

	// This is a do forever LOOP
	while (1) {

		ralph++;

		// LED OFF
		// On port B (the set of pins) set the pin represnting
		// PB4 to the bit value (BV) of 1
		PORTB |= _BV(PB4);
		// digitalWrite(PB4, HIGH);
		// PORTB = 00000010

		// Underlying delay call
		_delay_ms(150);
		// delay(150);

		// On port B (the set of pins) set the pin represnting
		// PB4 to the "NOT" bit value of 1 (so 0)
		PORTB &= ~_BV(PB4);
		// digitalWrite(PB4, LOW);

		// Another longer delay
		_delay_ms(300);
		// delay(300);
	}
}
