void init_ser() {

  Serial.begin(9600);
  Serial.println("SERIAL DONE");

}

void init_vbat()  {

  pinMode(23, INPUT);
  Serial.println("VBAT DONE");
}

void init_wifi()  {

  WiFi.begin(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  while (!client.connected()) {

    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {

      client.subscribe("falcon/micro1");
      client.subscribe("falcon/imu1");

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }
}

void init_led() {

  strip.begin();
  strip.setBrightness(BRIGHTNESS);

  strip.setPixelColor(0, 0, 0, 120);
  strip.setPixelColor(1, 0, 0, 120);
  strip.show();

}

void init_md()  {

  //Initialise all Motor drivers
  //In case the MDs cannot start

  ledcSetup(0, freq, resolution);
  ledcSetup(1, freq, resolution);
  ledcSetup(2, freq, resolution);
  ledcSetup(3, freq, resolution);
  ledcSetup(4, freq, resolution);
  ledcSetup(5, freq, resolution);
  ledcSetup(6, freq, resolution);
  ledcSetup(7, freq, resolution);

  ledcAttachPin(M1A, 0);
  ledcAttachPin(M1B, 1);
  ledcAttachPin(M2A, 2);
  ledcAttachPin(M2B, 3);
  ledcAttachPin(M3A, 4);
  ledcAttachPin(M3B, 5);
  ledcAttachPin(M4A, 6);
  ledcAttachPin(M4B, 7);

}
