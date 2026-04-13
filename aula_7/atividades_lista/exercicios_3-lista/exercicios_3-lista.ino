int leds[] = {8, 9, 10, 11};
int pot = A0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  int valor = analogRead(pot); // 0 a 1023
  float porcentagem = (valor / 1023.0) * 100;

  // apaga todos primeiro
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
  }

  if (porcentagem >= 25 && porcentagem < 50) {
    digitalWrite(leds[0], HIGH);
  }
  else if (porcentagem >= 50 && porcentagem < 75) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
  }
  else if (porcentagem >= 75 && porcentagem < 90) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
  }
  else if (porcentagem >= 90) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
  }
}