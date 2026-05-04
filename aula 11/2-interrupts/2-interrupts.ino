const int led = 9;

const int interruptPin = 2;
const int interruptPin2 = 3;

bool state = LOW;



void setup() {
pinMode(led, OUTPUT);
pinMode(interruptPin, INPUT_PULLUP);
pinMode(interruptPin2, INPUT_PULLUP);


attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
attachInterrupt(digitalPinToInterrupt(interruptPin2), blink2, FALLING);


}

void loop() {
digitalWrite(led, state);

}
void blink(){
  state = 1;
}
void blink2(){
  state = 0;
}
