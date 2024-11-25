#include <LedControl.h>

// Initialize the LedControl object
LedControl lc = LedControl(8, 10, 9, 1); // DIN=8, CLK=10, CS=9, 1 device

// Font data: Each digit is 8x8 pixels
byte digits[10][8] = {
  {0b00111100, 0b01000010, 0b10000101, 0b10000101, 0b10000101, 0b10000101, 0b01000010, 0b00111100}, // 0
  {0b00001000, 0b00011000, 0b00101000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b01111110}, // 1
  {0b00111100, 0b01000010, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01111110}, // 2
  {0b00111100, 0b01000010, 0b00000010, 0b00011100, 0b00000010, 0b00000010, 0b01000010, 0b00111100}, // 3
  {0b00000100, 0b00001100, 0b00010100, 0b00100100, 0b01000100, 0b01111110, 0b00000100, 0b00000100}, // 4
  {0b01111110, 0b01000000, 0b01000000, 0b01111100, 0b00000010, 0b00000010, 0b01000010, 0b00111100}, // 5
  {0b00111100, 0b01000010, 0b10000000, 0b10111100, 0b11000010, 0b10000010, 0b01000010, 0b00111100}, // 6
  {0b01111110, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b00100000, 0b00100000}, // 7
  {0b00111100, 0b01000010, 0b01000010, 0b00111100, 0b01000010, 0b01000010, 0b01000010, 0b00111100}, // 8
  {0b00111100, 0b01000010, 0b01000010, 0b00111110, 0b00000010, 0b00000010, 0b01000010, 0b00111100}  // 9
};

void setup() {
  lc.shutdown(0, false);    // Wake up MAX7219
  lc.setIntensity(0, 8);    // Set brightness (0–15)
  lc.clearDisplay(0);       // Clear the display
}

void loop() {
  countdown(9); // Start the countdown from 9
}

// Function to display a countdown
void countdown(int start) {
  for (int i = start; i >= 0; i--) {
    displayDigit(i);       // Display the current digit
    delay(1000);           // Wait for 1 second
    lc.clearDisplay(0);    // Clear display for transition
    delay(100);            // Brief pause before next digit
  }
}

// Function to display a single digit
void displayDigit(int digit) {
  if (digit < 0 || digit > 9) return; // Skip invalid digits
  byte* pattern = digits[digit];      // Get the digit's pattern
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);  // Set each row of the display
  }
}
