// Pinos
const int botao1Pin = 2;
const int botao2Pin = 3;
const int ledPin = 8;

// Janela de simultaneidade (ms)
const unsigned long janela = 200;

// Controle de tempo
unsigned long tempoBotao1 = 0;
unsigned long tempoBotao2 = 0;

void setup() {
  pinMode(botao1Pin, INPUT_PULLUP);
  pinMode(botao2Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  bool botao1 = !digitalRead(botao1Pin); // invertido (pull-up)
  bool botao2 = !digitalRead(botao2Pin);

  unsigned long agora = millis();

  // Detecta pressionamento do botão 1
  if (botao1) {
    tempoBotao1 = agora;
  }

  // Detecta pressionamento do botão 2
  if (botao2) {
    tempoBotao2 = agora;
  }

  // Verifica simultaneidade
  if ((agora - tempoBotao1 <= janela) &&
      (agora - tempoBotao2 <= janela)) {
    
    digitalWrite(ledPin, HIGH); // máquina ligada
    Serial.println("MAQUINA LIGADA");
    
  } else {
    digitalWrite(ledPin, LOW); // máquina desligada
  }
}