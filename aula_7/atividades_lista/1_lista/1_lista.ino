int led = 9;
int botaoA = 2;
int botaoB = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
}

void loop() {
  int estadoA = digitalRead(botaoA);
  int estadoB = digitalRead(botaoB);

  // ambos pressionados (LOW por causa do pull-up)
  if (estadoA == LOW && estadoB == LOW) {
    digitalWrite(led, HIGH); // liga LED
  } else {
    digitalWrite(led, LOW);  // desliga LED
  }
}