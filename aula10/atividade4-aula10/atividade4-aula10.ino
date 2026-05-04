
const byte pin[4] {A0, A1, A2, A3};// configuração

unsigned long TempoA = 0;//tempos de debaunce
unsigned long TempoB = 0;

void setup()
{
  Serial.begin(9600);//comunicação serial
}

void loop()
{
  for ( int i = 0; i < 4; i) { //lê quatro valores de potênciometro
    TempoA = millis();
    if (TempoA - TempoB > 1000) {
      TempoB = TempoA;
    Serial.println(analogRead(pin[i]));// Acompanha e mostra o valor em função de i(potenciometro)
     i++;
    }
  }
  
  while (true){// Quebra o código
  
  }
  
}