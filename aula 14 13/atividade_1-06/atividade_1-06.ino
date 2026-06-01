const int botao_start = 2;
const int botao_stop = 3;

int sensor3 = 9, sensor4 = 10;
int sensor1 = 11;
int sensor2 = 12;

int estado = 0;
unsigned long tempo_ant = 0, tempo_atual = 0;

const int motorAH = 6;
const int motorH = 7;

int caixa_alta = 0;
int caixa_baixa = 0;

void setup() {
pinMode(botao_start, INPUT_PULLUP);
pinMode(botao_stop, INPUT_PULLUP);

pinMode(motorAH, OUTPUT);
pinMode(motorH, OUTPUT);

}

void loop() {

bool stop = digitalRead(botao_stop);
if (stop == 0){
  estado = 0;
}
switch (estado){
  case 0:

  bool start = digitalRead(botao_start);
  if (start == 0) {
    estado = 1;
    tempo_ant = millis();
  }

  break;

  case 1:

  tempo_atual = millis();
  if (tempo_atual - tempo_ant > 2000){
    estado = 2;
  }

  break;
  
  case 2:

  if (digitalRead(sensor3 == 1 && sensor4 == 1)){
    estado = 3;
  }
  if(digitalRead(sensor3 == 0 || sensor4 == 0)){
  estado = 4;
  }
  break;

  case 3: 
  
  digitalWrite(motorAH, 1);
  if(digitalRead(sensor1 == 1)){
  estado = 5;
  }
  break;

case 4:
digitalWrite(motorH, 1);


if(digitalRead(sensor2 == 1)){
  estado = 6;
}
break;

case 5:
caixa_alta ++;
digitalWrite(motorAH, 0);
break;

case 6:

digitalWrite(motorH, 0);
caixa_baixa ++;
tempo_ant = millis();
  }
}
