const int pin_botao = 2;
bool botao = false;

void setup() {
  // put your setup code here, to run once:
 pinMode(pin_botao, INPUT_PULLUP);
 Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  botao = digitalRead(pin_botao);
  if (botao == LOW) {
    Serial.println("Botao precionado!!!"); 
  }

}
