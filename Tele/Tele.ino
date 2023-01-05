uint8_t pins[8] = {4, 5, 6, 8, A2, A3, A4, A5};

void setup() {
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
		num |= digitalRead(pins[i]) ;
	}
	if (digitalRead(A1))
		;
	else
		;
}
