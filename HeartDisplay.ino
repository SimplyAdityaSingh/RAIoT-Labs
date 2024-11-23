byte heart[8] = {
  0b01100110, // Row 0
  0b10011001, // Row 1
  0b10000001, // Row 2
  0b10000001, // Row 3
  0b01000010, // Row 4
  0b00100100, // Row 5
  0b00011000, // Row 6
  0b00000000  // Row 7
};

void loop() {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, heart[row]);
  }
  delay(1000);
  lc.clearDisplay(0);
  delay(500);
}
