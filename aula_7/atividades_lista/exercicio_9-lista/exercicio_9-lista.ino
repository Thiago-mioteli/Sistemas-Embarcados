const int potPin = A0;
const int led = 9;

const int numLeituras = 10;
int leituras[numLeituras];

int indice = 0;
long soma = 0;

unsigned long tempoAnterior = 0;
const int intervalo = 50; // pequeno intervalo entre leituras (50 ms)

void setup() {
  pinMode(led, OUTPUT);

  // Inicializa o array com zeros
  for (int i = 0; i < numLeituras; i++) {
    leituras[i] = 0;
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // Remove valor antigo da soma
    soma -= leituras[indice];

    // Lê novo valor
    leituras[indice] = analogRead(potPin);

    // Adiciona na soma
    soma += leituras[indice];

    // Avança índice (circular)
    indice++;
    if (indice >= numLeituras) {
      indice = 0;
    }

    // Calcula média
    int media = soma / numLeituras;

    // Controle do LED
    if (media > 700) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
}