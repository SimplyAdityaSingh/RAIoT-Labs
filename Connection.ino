#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid = "xShadowRock";       // Your WiFi SSID
const char* password = "xshadowrock"; // Your WiFi Password

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi network
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your main code goes here
}