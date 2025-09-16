//incluindo biblioteca para controle do servomotor
#include "Servo.h"
  
//Criando um objeto da classe Servo
Servo servoMotor1;
Servo servoMotor2;
  
//pino analógico onde o potenciômetro está conectado
int const potenc_H = 0;
int const potenc_V = 1;
 
//pino digital associado ao controle do servomotor
int const servoMotorPin1 = 9;
int const servoMotorPin2 = 10;  
 
//variável usada para armazenar o valor lido no potenciômetro
int valPotenciometro1;
int valPotenciometro2; 
  
void setup() { 
  //associando o pino digital ao objeto da classe Servo
  servoMotor1.attach(servoMotorPin1);
  servoMotor2.attach(servoMotorPin2);
} 
  
void loop() 
{ 
  //lendo o valor do potenciômetro (intervalo entre 0 e 1023)
  valPotenciometro1 = analogRead(potenc_H);
  valPotenciometro2 = analogRead(potenc_V);
 
  //mapeando o valor para a escala do servo (entre 0 e 180)
  valPotenciometro1 = map(valPotenciometro1, 0, 1023, 0, 180);
  valPotenciometro2 = map(valPotenciometro2, 0, 1023, 0, 180);
 
  //definindo o valor/posição do servomotor
  servoMotor1.write(valPotenciometro1); 
  delay(15);
  servoMotor2.write(valPotenciometro2);
  delay(15);
}