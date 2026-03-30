const int led1 = 8;
unsigned long intervalo = 1000;
unsigned long tempo_anterior = 0;
bool estado = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(11520); 
pinMode(led1, OUTPUT);


}

void loop() {
  unsigned long tempo_atual = millis(); 
  if (tempo_atual  - tempo_anterior >= intervalo) {
    estado = !estado; 
  
  digitalWrite(led1, estado);
  tempo_anterior = tempo_atual;
  Serial.println("1 segundo"); 
  
  }

}
