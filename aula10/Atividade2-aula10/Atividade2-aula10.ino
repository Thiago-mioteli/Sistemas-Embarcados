int botao = 2;
int led = 8;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  while (digitalRead(botao) == HIGH) {
    digitalWrite(led, LOW); 
  }

  digitalWrite(led, HIGH); 
}