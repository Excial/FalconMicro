void halt_climb() {

  if (climbState == 1) {

    for (int j = climbSpeed1; j <= 0; j -= 30) {

      ledcWrite(4, j);
      ledcWrite(5, 0);
      ledcWrite(6, 0);
      ledcWrite(7, 0);
      delay(100);

    }
  }

  else if (climbState == 2) {

    for (int j = climbSpeed1; j <= 0; j -= 30) {

      ledcWrite(4, 0);
      ledcWrite(5, j);
      ledcWrite(6, 0);
      ledcWrite(7, 0);
      delay(100);
    }
  }

  else if (climbState == 3) {

    for (int j = climbSpeed1, i = climbSpeed2; j, i <= 0; j, i -= 30) {

      ledcWrite(4, j);
      ledcWrite(5, 0);
      ledcWrite(6, 0);
      ledcWrite(7, i);
      delay(100);
    }
  }

  else if (climbState == 4) {

    for (int j = climbSpeed2; j <= 0; j -= 30) {

      ledcWrite(4, 0);
      ledcWrite(5, 0);
      ledcWrite(6, j);
      ledcWrite(7, 0);
      delay(100);
    }
  }

  else if (climbState == 5) {

    for (int j = climbSpeed2; j <= 0; j -= 30) {

      ledcWrite(4, 0);
      ledcWrite(5, 0);
      ledcWrite(6, 0);
      ledcWrite(7, j);
      delay(100);
    }
  }

  else if (climbState == 6) {

    for (int j = climbSpeed1, i = climbSpeed2; j <= 0; j -= 30) {

      ledcWrite(4, 0);
      ledcWrite(5, j);
      ledcWrite(6, i);
      ledcWrite(7, 0);
      delay(100);
    }
  }
}


void climber()  {

  if (cmd_cli == "0") {

    ledcWrite(4, 0);
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, 0);

    climbState = 0;
    Serial.println("UP1");
  }


  if (cmd_cli == "1") {

    ledcWrite(4, climbSpeed1);
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, 0);

    climbState = 1;
    Serial.println("UP1");
  }

  else if (cmd_cli == "2") {

    ledcWrite(4, 0);
    ledcWrite(5, climbSpeed1);
    ledcWrite(6, 0);
    ledcWrite(7, 0);

    climbState = 2;
    Serial.println("UP2");
  }

  else if (cmd_cli == "3") {

    ledcWrite(4, climbSpeed1);
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, climbSpeed2);


    climbState = 3;
    Serial.println("UP3");

  }

  if (cmd_cli == "4") {

    ledcWrite(4, 0);
    ledcWrite(5, 0);
    ledcWrite(6, climbSpeed2);
    ledcWrite(7, 0);

    climbState = 4;
    Serial.println("DOWN1");
  }

  if (cmd_cli == "5") {

    ledcWrite(4, 0);
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, climbSpeed2);


    climbState = 5;
    Serial.println("DOWN2");
  }

  if (cmd_cli == "6") {

    ledcWrite(4, 0);
    ledcWrite(5, climbSpeed1);
    ledcWrite(6, climbSpeed2);
    ledcWrite(7, 0);


    climbState = 6;
    Serial.println("DOWN2");
  }
}
