void bms() {

  if (cmd_vel == "7")  {

    const int x = 1;
    int v = analogRead(23);
    float vbat = 0.000; //  BAT V LEVEL
    float vin = 0.000;  //  ESP Input
    float Res = 21.120; //  (R1 + R2)/1000
    float vin_total = 0.000;
    float vbat_total = 0.000;


    vbat = (float(v) * Res) / 1000;
    Serial.println("VBAT: " + String(vbat));

    vin = vbat * (1 / Res);
    Serial.println("VIN: " + String(vin));


    for (int i = 0; i < 5; i += 1)  {
      vin_total = vin_total + vin;
      vbat_total = vbat_total + vbat;

    }

    vin_total = vin_total / 5;
    vbat_total = vbat_total / 5;

    Serial.println("BAT LEVEL: " + String(((vbat_total - vin_total) / vbat_total) * 100) + "%");

    if (vbat_total < 6.3) {
      Serial.println("Please Charge");

    }
  }
}
