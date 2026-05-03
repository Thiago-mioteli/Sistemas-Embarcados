int leds[5] = {8, 9, 10, 11, 12};

unsigned long tempoAnterior = 0;
const long intervalo = 500;

int indice = 0;

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // apaga todos os LEDs
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], LOW);
    }

    // acende o LED atual
    digitalWrite(leds[indice], HIGH);

    // vai para o próximo LED
    indice++;

    // se chegar no final, volta para o início
    if (indice >= 5) {
      indice = 0;
    }
  }
}