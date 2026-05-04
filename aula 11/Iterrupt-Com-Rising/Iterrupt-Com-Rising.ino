const int led = 9;
const int interruptPin = 2;
bool state = LOW;

void setup() {
pinMode(led, OUTPUT);
pinMode(interruptPin, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
digitalWrite(led, state);

}
void blink(){
  state = !state;
}
