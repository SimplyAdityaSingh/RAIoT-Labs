#include <LedControl.h>

// Initialize the LedControl object
LedControl lc = LedControl(8, 10, 9, 1); // DIN=8, CLK=10, CS=9, 1 device

// Emoji patterns (8x8 bitmaps)
byte emojis[6][8] = {
  {0b00000000, 0b01100110, 0b01100110, 0b00000000, 0b00000000, 0b01100110, 0b01100110, 0b00000000}, // Smiley Face
  {0b00111100, 0b01000010, 0b10100101, 0b10000001, 0b10000001, 0b10100101, 0b01000010, 0b00111100}, // Heart
  {0b00011000, 0b00111100, 0b01111110, 0b11111111, 0b01111110, 0b00111100, 0b00011000, 0b00000000}, // Arrow Up
  {0b00011000, 0b00111100, 0b01011010, 0b11111111, 0b11111111, 0b01011010, 0b00111100, 0b00011000}, // Star
  {0b00111100, 0b01111110, 0b11011011, 0b11111111, 0b11111111, 0b11000011, 0b01111110, 0b00111100}, // Laughing Face
  {0b00000000, 0b00111100, 0b01000010, 0b10100101, 0b10000001, 0b01011010, 0b00111100, 0b00000000}  // Surprised Face
};

void setup() {
  lc.shutdown(0, false);    // Wake up MAX7219
  lc.setIntensity(0, 8);    // Set brightness (0–15)
  lc.clearDisplay(0);       // Clear the display
}

void loop() {
  displayEmojis(); // Show the emojis sequentially
}

// Function to display emojis
void displayEmojis() {
  for (int i = 0; i < 6; i++) {       // Loop through each emoji
    displayPattern(emojis[i]);        // Display the current emoji
    delay(1000);                      // Wait for 1 second
    lc.clearDisplay(0);               // Clear display for transition
    delay(100);                       // Brief pause before next emoji
  }
}

// Function to display a single 8x8 pattern
void displayPattern(byte pattern[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);  // Set each row of the display
  }
}
