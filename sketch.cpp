/*
 * Based on Tone Generator by Lukasz Marcin Podkalicki
 * for the ATtiny13
 */

// Compiles to 150 bytes
#include <avr/io.h>

// Prevents the expectation of a fixed value delay
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

// Physical pin 5 (or 6, one of the OC0 pins)
#define	BUZZER_PIN	PB0

// Forward declaration
static void tone(uint8_t note);
static void stop(void);

int main(void) {
	// set Data Direction Register BUZZER pin as OUTPUT
	DDRB = 0b00000001;

	// Set Buzzer PB0 LOW
	PORTB &= ~_BV(BUZZER_PIN);

	//Timer/Counter Control Register TCCR0A
	TCCR0A |= (1 << WGM01); // set timer mode to Fast PWM
	TCCR0A |= (1 << COM0A0); // connect PWM pin to Channel A of Timer0

	// Door opening sound
	for (auto j = 24; j > 17; j--) {
		tone(j);
		_delay_ms(30);
	}

	stop();

	// Uses 18 bytes
	_delay_ms(500);

	// Door closing sound
	for (auto j = 17; j < 25; j++) {
		tone(j);
		_delay_ms(30);
	}
	stop();
}

static void tone(uint8_t note) {
	// Fixed octave
	TCCR0B = (TCCR0B & ~((1 << CS02) | (1 << CS01) | (1 << CS00))) | _BV(CS01);

	// Use notes from 24 to 18 (highest)
	OCR0A = note - 1; // set the Output Compare Register 0A
}

static void stop(void) {
	TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00)); // stop the timer
}
