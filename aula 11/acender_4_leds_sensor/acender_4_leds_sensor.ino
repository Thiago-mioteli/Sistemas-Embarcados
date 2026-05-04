
#include <Ultrasonic.h>


Ultrasonic ultrasonic(12, 13);
int distance;

int led = 6;
int led2 = 7;
int led3 = 8;
int led4 = 9;


int bot = 2;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
 pinMode(bot, INPUT_PULLUP);


  Serial.begin(9600);
}

void loop() {
  if(digitalRead(bot) == LOW){

  }
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(10);
  
  if(distance > 40){
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led2, LOW);

  }
  else if(distance >= 30){
    digitalWrite(led, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

  }
  else if(distance >= 20){
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);

  }
    else if(distance >= 10){
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
}
 else{
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

