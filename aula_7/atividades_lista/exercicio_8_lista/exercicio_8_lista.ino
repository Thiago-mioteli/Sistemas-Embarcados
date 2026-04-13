const int botaoA = 2;
const int botaoB = 3;
const int led = 8;

unsigned long tempoInicio = 0;
const unsigned long duracao = 5000; // 5 segundos

bool temporizadorAtivo = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  // Leitura dos botões (LOW = pressionado)
  bool pressionadoA = (digitalRead(botaoA) == LOW);
  bool pressionadoB = (digitalRead(botaoB) == LOW);

  // Inicia o temporizador
  if (pressionadoA && !temporizadorAtivo) {
    temporizadorAtivo = true;
    tempoInicio = millis();
    digitalWrite(led, HIGH);
  }

  // Cancela se botão B for pressionado
  if (pressionadoB && temporizadorAtivo) {
    temporizadorAtivo = false;
    digitalWrite(led, LOW);
  }

  // Verifica se o tempo acabou
  if (temporizadorAtivo && (millis() - tempoInicio >= duracao)) {
    temporizadorAtivo = false;
    digitalWrite(led, LOW);
  }
}