#include "TeleModule.h"

TeleModule::TeleModule() {
	for (auto e : pins) {
		pinMode(e, OUTPUT);
	}
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
}

void TeleModule::begin() {
	
}

void TeleModule::send(uint8_t type, uint8_t data) {
	for (uint8_t i = 0; i < 8; i++) {
		digitalWrite(pins[i], (data >> i) & 1);
	}
	if (type) cursor++;
	digitalWrite(A1, type);
	digitalWrite(A0, 1);
	delayMicroseconds(10);
	digitalWrite(A0, 0);
}

size_t TeleModule::write(uint8_t chr) {
	send(1, chr);
	return 1;
}

void TeleModule::setCursor(uint8_t x, uint8_t y) {
	send(0, 0);
	send(0, x & 127);
	send(0, y & 15);
}

bool TeleModule::set_point(uint8_t x, uint8_t y) {
	send(0, 1);
	send(0, x & 127);
	send(0, y & 127);
	return 0;
}

void TeleModule::draw_circle(int8_t X1, int8_t Y1, uint8_t y) {
	send(0, 2);
	send(0, X1);
	send(0, Y1);
	send(0, y);
}

void TeleModule::draw_line(int8_t x0, int8_t y0, int8_t x1, int8_t y1) {
	send(0, 3);
	send(0, x0);
	send(0, y0);
	send(0, x1);
	send(0, y1);
}

void TeleModule::clear() {
	send(0, 4);
}

void TeleModule::reverse(uint16_t from, uint16_t to) {
	send(0, 5);
	send(0, from & 0xff);
	send(0, from >> 8);
	send(0, to & 0xff);
	send(0, to >> 8);
}
	
void TeleModule::setColor(uint8_t c) {
	send(0, 6);
	send(0, c);
}

void TeleModule::Play(uint32_t num) {
	send(0, 7);
	for (uint8_t i = 0; i < 4; i++) {
		send(0, num & 255);
		num >>= 8;
	}
}

void TeleModule::sendTone(uint32_t tone) {
	for (uint8_t i = 0; i < 4; i++) {
		send(0, tone & 255);
		tone >>= 8;
	}
}

void TeleModule::noPlay() {
	send(0, 8);
}

bool TeleModule::draw_bmp(int8_t x, int8_t y, uint8_t (*reader) ()) {
	send(0, 9);
	send(0, x);
	send(0, y);
	x = reader();
	y = reader();
	send(0, x);
	send(0, y);
	for (uint16_t t = 0; t < x * y; t++)
		send(0, reader());
};
