int leds[] = {8, 9, 10, 11};
int ledAtual = 0;

unsigned long tempoAnterior = 0;
unsigned long intervalo = 200; // 200 ms

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // apaga todos os LEDs
    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }

    // liga o LED atual
    digitalWrite(leds[ledAtual], HIGH);

    // avança para o próximo LED
    ledAtual++;

    if (ledAtual > 3) {
      ledAtual = 0; // reinicia a sequência
    }
  }
}