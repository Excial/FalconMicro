#include <WiFi.h>               // WiFi Communication Library
#include <PubSubClient.h>       // MQTT Communication Library

// Network Settings--------------------------------------------------

bool callback_status = false;
WiFiClient espClient;
PubSubClient client(espClient);

// Variables --------------------------------------------------
// Each definition is referenced to 1 pin which can detect a Digital Output
// Buttons for Remote output.
const int F = 16;
const int B = 17;
const int L = 18;
const int R = 19;

const int R1 = 21;
const int R2 = 22;
const int RT = 23;

const int L1 = 25;
const int L2 = 26;
const int LT = 27;

// Program --------------------------------------------------

void setup() {

  init_ser();
  init_wifi();

}

void loop() {

  remote();
  delay(500);

}
