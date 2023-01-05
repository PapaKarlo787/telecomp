void play() {
	uint32_t poi = readNum();
	uint32_t size = readNum(poi);
	lcd.Play(size);
	for (; size > 0; size--) {
		poi += 4;
		lcd.sendTone(readNum(poi));
	}
}

void nplay(){
	lcd.noPlay();
}
