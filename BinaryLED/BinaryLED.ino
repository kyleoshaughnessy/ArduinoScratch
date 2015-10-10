
void setup() { 
  for (int i = 0; i<5; i++) {
    pinMode(i, OUTPUT);
  }  
}

void loop() {
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j<5; j++) {
      if((1<<j) & i) {
        digitalWrite(j, HIGH);
      }
      else {
        digitalWrite(j, LOW);
      }
    }
    delay(1000);
  }
}



