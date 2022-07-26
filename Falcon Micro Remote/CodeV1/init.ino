void init_ser() {

  Serial.begin(9600);

}

void init_wifi()  {

  const char* ssid = "SUTD_LAB";
  const char* mqttServer = "10.21.131.9";
  const int   mqttPort = 1883;
  const char* mqttUser = "sutd";
  const char* mqttPassword = "sutdmqtt";

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

void init_buttons() {

  // Main Locomotion

  pinMode(F, INPUT);
  pinMode(B, INPUT);
  pinMode(L, INPUT);
  pinMode(R, INPUT);

  // Side levers

  pinMode(R1, INPUT);
  pinMode(R2, INPUT);
  pinMode(RT, INPUT);
  pinMode(L1, INPUT);
  pinMode(L2, INPUT);
  pinMode(LT, INPUT);

}
