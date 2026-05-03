int led = 8;

unsigned long tempoAnterior = 0;
const long intervalo = 500; 

int contador = 0;
bool estadoLed = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  if (contador < 40) { 
    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;

      estadoLed = !estadoLed;              
      digitalWrite(led, estadoLed);       

      contador++; 
    }
  }
}