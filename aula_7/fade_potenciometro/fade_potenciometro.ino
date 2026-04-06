const int valor_sensor = A0;
int LED = 9;

void setup() {
}

void loop() {
 int valor_analogico = analogRead(valor_sensor);
 int valor = (valor_analogico / 4);
 analogWrite(LED, valor);
}