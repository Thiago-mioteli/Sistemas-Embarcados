const int pinoPot = A0;
const int led = 2;

unsigned long tempoAnterior = 0;
const long intervalo = 500; // piscar a cada 500ms
bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(pinoPot);

  // Converte para tensão (considerando 5V)
  float tensao = valor * (5.0 / 1023.0);

  // Caso 1: abaixo ou igual a 2V
  if (tensao <= 2.0) {
    digitalWrite(led, LOW);
  }

  // Caso 2: entre 2V e 4V
  else if (tensao > 2.0 && tensao < 4.0) {
    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  }

  // Caso 3: acima ou igual a 4V
  else if (tensao >= 4.0) {
    digitalWrite(led, HIGH);
  }
}