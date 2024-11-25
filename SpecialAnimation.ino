#include <LedControl.h>

// Initialize the LedControl object
LedControl lc = LedControl(8, 10, 9, 1); // DIN=8, CLK=10, CS=9, 1 device

// Define patterns for the animation
byte sunrise[4][8] = {
  {0b00000000, 0b00000000, 0b00000000, 0b00011000, 0b00011000, 0b00000000, 0b00000000, 0b00000000}, // Rising Sun 1
  {0b00000000, 0b00000000, 0b00011000, 0b00111100, 0b00111100, 0b00011000, 0b00000000, 0b00000000}, // Rising Sun 2
  {0b00000000, 0b00011000, 0b00111100, 0b01111110, 0b01111110, 0b00111100, 0b00011000, 0b00000000}, // Rising Sun 3
  {0b00011000, 0b00111100, 0b01111110, 0b11111111, 0b11111111, 0b01111110, 0b00111100, 0b00011000}  // Full Sun
};

byte sparkle[3][8] = {
  {0b00001000, 0b00000000, 0b00100000, 0b00000000, 0b00010000, 0b00000000, 0b01000000, 0b00000000}, // Sparkle 1
  {0b00000000, 0b00010000, 0b00000000, 0b01000000, 0b00000000, 0b00100000, 0b00000000, 0b10000000}, // Sparkle 2
  {0b00000000, 0b01000000, 0b00000000, 0b00100000, 0b00000000, 0b00010000, 0b00000000, 0b00001000}  // Sparkle 3
};

byte thankYou[8] = {
  0b00000000, 0b11110111, 0b10111010, 0b10111010, 0b11110111, 0b10100010, 0b10100010, 0b11110111  // THANK YOU!
};

void setup() {
  lc.shutdown(0, false);    // Wake up MAX7219
  lc.setIntensity(0, 8);    // Set brightness (0–15)
  lc.clearDisplay(0);       // Clear the display
}

void loop() {
  playSunrise();     // Show sunrise animation
  delay(1000);       // Pause
  playSparkle();     // Show sparkle animation
  delay(1000);       // Pause
  displayThankYou(); // Show "THANK YOU!" text
  delay(3000);       // Pause before repeating
}

// Function to play sunrise animation
void playSunrise() {
  for (int i = 0; i < 4; i++) {
    displayPattern(sunrise[i]);
    delay(500);
    lc.clearDisplay(0);
    delay(100);
  }
}

// Function to play sparkle animation
void playSparkle() {
  for (int i = 0; i < 6; i++) {         // Loop sparkle effect 6 times
    displayPattern(sparkle[i % 3]);    // Alternate between sparkle frames
    delay(200);
    lc.clearDisplay(0);
    delay(50);
  }
}

// Function to display "THANK YOU!"
void displayThankYou() {
  displayPattern(thankYou);            // Show "THANK YOU!"
}

// Function to display a single 8x8 pattern
void displayPattern(byte pattern[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);   // Set each row of the display
  }
}
