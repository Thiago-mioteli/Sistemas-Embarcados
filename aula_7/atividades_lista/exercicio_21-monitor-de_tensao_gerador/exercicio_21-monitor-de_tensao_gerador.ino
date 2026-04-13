const int sensorPin = A0;

const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;
const int ledChave = 11; // chave geral

float tensao = 0;
int leitura = 0;

unsigned long tempoForaFaixa = 0;
bool foraFaixa = false;
bool chaveLigada = true;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledChave, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(sensorPin);

  // Converte para tensão (0 a 250V)
  tensao = (leitura / 1023.0) * 250.0;

  Serial.print("Tensao: ");
  Serial.println(tensao);

  // 🔹 LEDs de status
  digitalWrite(ledVerde, (tensao >= 210 && tensao <= 230));
  digitalWrite(ledAmarelo, (tensao < 210));
  digitalWrite(ledVermelho, (tensao > 230));

  unsigned long tempoAtual = millis();

  // 🔹 Verifica faixa crítica
  if (tensao < 180 || tensao > 240) {

    if (!foraFaixa) {
      foraFaixa = true;
      tempoForaFaixa = tempoAtual; // começa a contar
    }

    // Se passou 2 segundos fora da faixa
    if (tempoAtual - tempoForaFaixa >= 2000) {
      chaveLigada = false;
    }

  } else {
    // Voltou ao normal
    foraFaixa = false;
    chaveLigada = true;
  }

  // 🔹 Estado da chave geral
  digitalWrite(ledChave, chaveLigada);
}