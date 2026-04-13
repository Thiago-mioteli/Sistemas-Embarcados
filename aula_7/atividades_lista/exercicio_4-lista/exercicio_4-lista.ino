int led = 8;
int botao1 = 2;
int botao3 = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
}

void loop() {
  int estado1 = digitalRead(botao1);
  int estado3 = digitalRead(botao3);

  // ambos pressionados
  if (estado1 == LOW && estado3 == LOW) {
    digitalWrite(led, HIGH); // liga LED
  } else {
    digitalWrite(led, LOW);  // desliga imediatamente
  }
}