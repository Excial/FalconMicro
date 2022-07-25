void remote() {

  // Pinouts for ESP32

  char m1;
  char r1;

  if (digitalRead(F) > 0) {

    m1 = '1';
    r1 = remoteRot();

  }
  else if (digitalRead(B) > 0) {

    m1 = '2';
    r1 = remoteRot();

  }
  else if (digitalRead(L) > 0) {

    m1 = '3';
    r1 = remoteRot();

  }

  else if (digitalRead(R) > 0) {

    m1 = '4';
    r1 = remoteRot();

  }

  msgSend(m1, r1);

}


char remoteRot()  {

  if (digitalRead(R1) > 0) {

    char r1 = '1';
    return r1;

  }

  else if (digitalRead(R2) > 0) {

    char r1 = '2';
    return r1;

  }

  else if (digitalRead(RT) > 0) {

    char r1 = '3';
    return r1;

  }

  else if (digitalRead(L1) > 0) {

    char r1 = '4';
    return r1;

  }

  else if (digitalRead(L2) > 0) {

    char r1 = '5';
    return r1;

  }

  else if (digitalRead(LT) > 0) {

    char r1 = '6';
    return r1;

  }

  else  {
    char r1 = '0';
    return r1;
  }
}
