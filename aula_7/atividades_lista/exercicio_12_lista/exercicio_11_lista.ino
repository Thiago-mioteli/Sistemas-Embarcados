const int ledPins[] = {8, 9, 10, 11};
const int botao1 = 2;
const int botao2 = 3;

unsigned long tempoAnterior = 0;
const long intervalo = 1000;

int etapa = 0;
bool sequenciaAtiva = false;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  // Botão 1 inicia sequência
  if (digitalRead(botao1) == LOW) {
    sequenciaAtiva = true;
    etapa = 0;
    tempoAnterior = millis();
  }

  // Botão 2 reseta tudo
  if (digitalRead(botao2) == LOW) {
    sequenciaAtiva = false;
    etapa = 0;
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Controle da sequência sem delay
  if (sequenciaAtiva) {
    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;

      if (etapa < 4) {
        digitalWrite(ledPins[etapa], HIGH);
        etapa++;
      } else {
        sequenciaAtiva = false; // terminou a sequência
      }
    }
  }
}