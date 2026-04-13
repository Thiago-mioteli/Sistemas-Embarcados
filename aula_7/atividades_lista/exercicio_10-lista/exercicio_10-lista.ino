const int botaoA = 2;
const int led1 = 4;
const int led2 = 5;

unsigned long tempoPressionado = 0;

bool estadoAnterior = HIGH;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  bool estadoAtual = digitalRead(botaoA);

  // Detecta quando o botão é pressionado
  if (estadoAnterior == HIGH && estadoAtual == LOW) {
    tempoPressionado = millis();
  }

  // Detecta quando o botão é solto
  if (estadoAnterior == LOW && estadoAtual == HIGH) {
    unsigned long duracao = millis() - tempoPressionado;

    // Apaga os LEDs antes de decidir
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);

    if (duracao < 1000) {
      // Pulso curto (< 1s)
      digitalWrite(led1, HIGH);
    }
    else if (duracao > 2000) {
      // Pulso longo (> 2s)
      digitalWrite(led2, HIGH);
    }
  }

  estadoAnterior = estadoAtual;
}