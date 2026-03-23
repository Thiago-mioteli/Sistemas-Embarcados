/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Aluno: Thiago Mioteli

Programa: Seleção simples

Autor: Thiago Mioteli
Data: 23/03/2026
Versão: 1.1
************************************************************************ */

const int led_vermelho = 5;  // costante
const int led_verde = 6;     //
const int led_amarelo = 7;   //
char led;                    // variavel

void setup() {
  pinMode(led_vermelho, OUTPUT);  //
  pinMode(led_verde, OUTPUT);     //
  pinMode(led_amarelo, OUTPUT);   //
  Serial.begin(115200);           // Definição da velocide de transmissão em 115200 bps
}

void loop() {
  if (Serial.available()) {              //
    led = Serial.read();                 //
    if (led == 'R') {                    // Led vermelho - red
      digitalWrite(led_vermelho, HIGH);  // Acende led
    }

    else if (led == 'r') {
      digitalWrite(led_vermelho, LOW);
    }

    if (led == 'G') {                 // Led verde - green
      digitalWrite(led_verde, HIGH);  // Acende led
    }

    else if (led == 'g') {
      digitalWrite(led_verde, LOW);
    }
    if (led == 'Y') {                   // Led amarelo - yellow
      digitalWrite(led_amarelo, HIGH);  // Acende led
    }

    else if (led == 'y') {
      digitalWrite(led_amarelo, LOW);
    }
    if (led == 'T') {
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_amarelo, HIGH);
    } else if (led == 't') {
      digitalWrite(led_vermelho, LOW);
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarelo, LOW);
    }
  }
}
