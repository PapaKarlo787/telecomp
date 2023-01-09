#include "functions.h"

const uint8_t pins[8] PROGMEM = {4, 5, 6, 8, A2, A3, A4, A5};
uint16_t cursor = 0;


void setup() {
	TV.begin(NTSC, 128, 128);
    TV.selectFont(font8x8);
	for (auto e : pins) {
		pinMode(e, INPUT);
	}
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);
}

void loop() {
	while (!digitalRead(A0));
	uint8_t	num = 0;
	for (uint8_t i = 0; i < 8; i++) {
		num |= digitalRead(pins[i]) << i;
	}
	if (digitalRead(A1)) {
		
	} else {
		void (*f) (void) = pgm_read_word(&funcs[num]);
		while (digitalRead(A0));
		(*f)();
	}
}
