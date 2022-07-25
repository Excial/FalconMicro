void motion() {

  if (cmd_vel == "0") {

    halt();
    halt_climb();

    while (cmd_vel == "0") {

      ledcWrite(0, 0);
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      ledcWrite(3, 0);
      motorState = 0;

      climber();
      
      Serial.println("HALT");
      client.loop();
    }
  }

  else if (cmd_vel == "1") {

    halt();

    for (int j = 0; j <= motorSpeed; j += 50)  {

      ledcWrite(0, j);
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      ledcWrite(3, j);
      delay(100);
    }

    while (cmd_vel == "1") {

      ledcWrite(0, motorSpeed);
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      ledcWrite(3, motorSpeed);
      
      motorState = 1;
      
      climber();
      
      Serial.println("FRONT");
      client.loop();
    }
  }

  else if (cmd_vel == "2") {

    halt();

    for (int j = 0; j <= motorSpeed; j += 50)  {

      ledcWrite(0, 0);
      ledcWrite(1, j);
      ledcWrite(2, j);
      ledcWrite(3, 0);
      delay(100);

    }

    while (cmd_vel == "2") {

      ledcWrite(0, 0);
      ledcWrite(1, motorSpeed);
      ledcWrite(2, motorSpeed);
      ledcWrite(3, 0);

      motorState = 2;
     
      Serial.println("BACK");
      client.loop();
    }
  }

  else if (cmd_vel == "3") {

    halt();

    for (int j = 0; j <= motorSpeed; j += 51)  {

      ledcWrite(0, 0);
      ledcWrite(1, j);
      ledcWrite(2, 0);
      ledcWrite(3, j);
      delay(100);

    }

    while (cmd_vel == "3") {

      ledcWrite(0, 0);
      ledcWrite(1, motorSpeed);
      ledcWrite(2, 0);
      ledcWrite(3, motorSpeed);
      
      motorState = 3;

      Serial.println("RIGHT");
      client.loop();

    }
  }

  else if (cmd_vel == "4")  {

    halt();

    for (int j = 0; j <= motorSpeed; j += 51)  {

      ledcWrite(0, j);
      ledcWrite(1, 0);
      ledcWrite(2, j);
      ledcWrite(3, 0);
      delay(100);

    }

    while (cmd_vel == "4") {

      ledcWrite(0, motorSpeed);
      ledcWrite(1, 0);
      ledcWrite(2, motorSpeed);
      ledcWrite(3, 0);

      motorState = 4;

      Serial.println("LEFT");
      client.loop();

    }
  }
}

//BREAK

void halt() {

  if (motorState == 1) {

    for (int j = motorSpeed; j <= 0; j -= 51) {

      ledcWrite(0, j);
      ledcWrite(1, 0);
      ledcWrite(2, 0);
      ledcWrite(3, j);
      delay(100);

    }
  }

  else if (motorState == 2) {

    for (int j = motorSpeed; j <= 0; j -= 51) {

      ledcWrite(0, 0);
      ledcWrite(1, j);
      ledcWrite(2, j);
      ledcWrite(3, 0);
      delay(100);
    }
  }

  else if (motorState == 3) {

    for (int j = motorSpeed; j <= 0; j -= 51) {

      ledcWrite(0, 0);
      ledcWrite(1, j);
      ledcWrite(2, 0);
      ledcWrite(3, j);
      delay(100);
    }
  }

  else if (motorState == 4) {

    for (int j = motorSpeed; j <= 0; j -= 51) {

      ledcWrite(0, j);
      ledcWrite(1, 0);
      ledcWrite(2, j);
      ledcWrite(3, 0);
      delay(100);
    }
  }
}
