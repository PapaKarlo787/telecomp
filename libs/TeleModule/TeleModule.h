#ifndef PCD8544_H
#define PCD8544_H

#include <Arduino.h>

class TeleModule : public Print {
public:
	TeleModule();
	
	void begin();
	
	void send(uint8_t type, uint8_t data);
	
	virtual size_t write(uint8_t chr);
	
	void setCursor(uint8_t x, uint8_t y);
	
	bool set_point(uint8_t x, uint8_t y);
	
	void draw_circle(int8_t X1, int8_t Y1, uint8_t y);
	
	void draw_line(int8_t x0, int8_t y0, int8_t x1, int8_t y1);
	
	void clear();
	
	void reverse(uint16_t from, uint16_t to);
		
	void setColor(uint8_t c);
	
	bool draw_bmp(int8_t x, int8_t y, uint8_t (*reader) ());
	
	void Play(uint32_t num);
	
	void sendTone(uint32_t tone);
	
	void noPlay();

private:
	const uint8_t pins[8] PROGMEM = {4, 5, 6, 8, A2, A3, A4, A5};
};
#endif
