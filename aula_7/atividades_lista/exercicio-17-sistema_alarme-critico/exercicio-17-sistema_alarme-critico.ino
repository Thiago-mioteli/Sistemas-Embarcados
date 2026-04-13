// Pinos
const int sensorPin = A0;
const int led1 = 8;
const int led2 = 9;

// Limite crítico (ajustável)
int limiteCritico = 700;

// Controle de tempo (piscar rápido)
unsigned long tempoAnterior = 0;
const long intervaloPisca = 100; // alta frequência

bool estadoPisca = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(sensorPin);
  unsigned long agora = millis();

  Serial.print("Leitura: ");
  Serial.println(leitura);

  // Verifica estado de alerta
  if (leitura > limiteCritico) {
    
    // Pisca rápido (sem delay)
    if (agora - tempoAnterior >= intervaloPisca) {
      tempoAnterior = agora;
      estadoPisca = !estadoPisca;
    }

    digitalWrite(led1, estadoPisca);
    digitalWrite(led2, !estadoPisca); // alternado (mais visível)

  } else {
    // Estado normal (estável)
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}