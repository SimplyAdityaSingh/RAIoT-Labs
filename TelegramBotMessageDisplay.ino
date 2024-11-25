#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <TimeLib.h>    // Time library for handling time
#include <NTPClient.h>  // Library for getting time from NTP server
#include <WiFiUdp.h>    // UDP library for NTP communication

const char* ssid = "SSID_name";
const char* password = "SSID_password";

#define BOTtoken "Your_bot_token"//take from bot father in telegram
#define CHAT_ID "Your_chat_id"//take from id bot in telegram

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // 19800 = 5 hours 30 mins offset for IST

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

bool messageSent = false; // Flag to ensure message is sent only once

void setup() {
  Serial.begin(115200);
  client.setInsecure();

  // Connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize NTP client
  timeClient.begin();
  Serial.println("Synchronizing time...");
  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }
  Serial.println("Time synchronized!");
}

void loop() {
  timeClient.update(); // Keep the time updated

  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();

  // Check if it's 11:15 PM IST
  if (currentHour == 18 && currentMinute == 45 && !messageSent) {
    if (bot.sendMessage(CHAT_ID, "Hello! Ye message Bot se Bheja hai.", "")&& bot.sendPhoto(CHAT_ID, "https://i.kym-cdn.com/entries/icons/original/000/045/436/doggy_suit.jpg")) {
      Serial.println("Message sent successfully!");
    } else {
      Serial.println("Failed to send message.");
    }
    messageSent = true; // Prevent further messages for the same minute
  }

  // Reset the flag after the minute changes
  if (currentMinute != 45) {
    messageSent = false;
  }

  delay(1000); // Check every second
}