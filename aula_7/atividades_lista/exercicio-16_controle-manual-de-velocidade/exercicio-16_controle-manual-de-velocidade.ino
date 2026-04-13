// Pinos
const int botaoMais = 2;
const int botaoMenos = 3;
const int ledPin = 9;

// Controle de velocidade (PWM)
int velocidade = 0;
const int passo = 25;   // quanto aumenta/diminui

const int velMin = 0;
const int velMax = 255;

// Debounce
unsigned long tempoUltimoMais = 0;
unsigned long tempoUltimoMenos = 0;
const long debounceDelay = 200;

void setup() {
  pinMode(botaoMais, INPUT_PULLUP);
  pinMode(botaoMenos, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  unsigned long agora = millis();

  bool estadoMais = !digitalRead(botaoMais);
  bool estadoMenos = !digitalRead(botaoMenos);

  // Botão +
  if (estadoMais && (agora - tempoUltimoMais > debounceDelay)) {
    tempoUltimoMais = agora;

    velocidade += passo;
    if (velocidade > velMax) {
      velocidade = velMax; // evita estouro
    }
  }

  // Botão -
  if (estadoMenos && (agora - tempoUltimoMenos > debounceDelay)) {
    tempoUltimoMenos = agora;

    velocidade -= passo;
    if (velocidade < velMin) {
      velocidade = velMin; // evita valor negativo
    }
  }

  // Aplica PWM
  analogWrite(ledPin, velocidade);

  // Monitoramento
  Serial.print("Velocidade PWM: ");
  Serial.println(velocidade);
}