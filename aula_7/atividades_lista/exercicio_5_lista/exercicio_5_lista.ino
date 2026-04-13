const int pinoNTC = A0;
const int led = 9;

// Controle de tempo
unsigned long tempoAnterior = 0;
const int intervalo = 100; // 100 ms

bool estadoLED = false;

// Parâmetros do NTC
const float BETA = 3950;
const float R0 = 10000;
const float T0 = 298.15;
const float Rfixo = 10000;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoNTC);

  // Converter para temperatura
  float V = leitura * (5.0 / 1023.0);
  float Rntc = (Rfixo * V) / (5.0 - V);
  float temperaturaK = 1 / ((1/T0) + (1/BETA) * log(Rntc / R0));
  float temperaturaC = temperaturaK - 273.15;

  Serial.println(temperaturaC);

  // Se passou de 40°C → piscar
  if (temperaturaC >= 40.0) {
    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;

      estadoLED = !estadoLED; // alterna estado
      digitalWrite(led, estadoLED);
    }
  } else {
    digitalWrite(led, LOW);
    estadoLED = false;
  }
}