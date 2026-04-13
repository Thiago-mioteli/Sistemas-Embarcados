// Pinos
const int sensorPin = A0;

const int ledBaixo = 10;   // vermelho
const int ledMedio = 9;    // amarelo
const int ledAlto = 8;     // verde

// Limites de nível (ajustáveis)
int nivelBaixo = 300;
int nivelAlto = 700;

// Controle de tempo (piscar sem delay)
unsigned long tempoAnterior = 0;
const long intervaloPisca = 500;
bool estadoPisca = false;

void setup() {
  pinMode(ledBaixo, OUTPUT);
  pinMode(ledMedio, OUTPUT);
  pinMode(ledAlto, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorPin);

  Serial.print("Nivel: ");
  Serial.println(leitura);

  unsigned long agora = millis();

  // Atualiza estado do pisca
  if (agora - tempoAnterior >= intervaloPisca) {
    tempoAnterior = agora;
    estadoPisca = !estadoPisca;
  }

  // Desliga todos primeiro
  digitalWrite(ledBaixo, LOW);
  digitalWrite(ledMedio, LOW);
  digitalWrite(ledAlto, LOW);

  // Classificação de nível
  if (leitura < nivelBaixo) {
    // 🔴 CRÍTICO BAIXO (pisca)
    digitalWrite(ledBaixo, estadoPisca);

  } else if (leitura >= nivelBaixo && leitura <= nivelAlto) {
    // 🟡 MÉDIO
    digitalWrite(ledMedio, HIGH);

  } else if (leitura > nivelAlto && leitura < 900) {
    // 🟢 ALTO
    digitalWrite(ledAlto, HIGH);

  } else {
    // 🔴 CRÍTICO ALTO (pisca)
    digitalWrite(ledAlto, estadoPisca);
  }
}
