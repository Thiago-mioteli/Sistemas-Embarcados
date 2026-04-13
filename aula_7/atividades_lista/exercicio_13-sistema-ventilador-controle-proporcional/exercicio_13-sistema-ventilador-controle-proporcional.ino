// Pinos
const int sensorPin = A0;
const int ledPin = 9;

// Faixa de operação (ajustável)
int tempMin = 300;  // "frio"
int tempMax = 700;  // "quente"

// Controle de tempo (sem delay)
unsigned long tempoAnterior = 0;
const long intervalo = 100;

// Filtro (suavização)
float leituraFiltrada = 0;
const float alpha = 0.1; // quanto menor, mais suave

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long agora = millis();

  if (agora - tempoAnterior >= intervalo) {
    tempoAnterior = agora;

    // Leitura do sensor
    int leituraBruta = analogRead(sensorPin);

    // Filtro simples (média exponencial)
    leituraFiltrada = (alpha * leituraBruta) + ((1 - alpha) * leituraFiltrada);

    // Mapeamento para PWM (0–255)
    int pwm = map(leituraFiltrada, tempMin, tempMax, 0, 255);

    // Limites de segurança
    pwm = constrain(pwm, 0, 255);

    // Saída PWM (controle do "ventilador")
    analogWrite(ledPin, pwm);

    // Monitoramento
    Serial.print("Leitura: ");
    Serial.print(leituraFiltrada);
    Serial.print(" | PWM: ");
    Serial.println(pwm);
  }
}