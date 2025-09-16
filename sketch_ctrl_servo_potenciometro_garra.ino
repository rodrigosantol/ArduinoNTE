//incluindo biblioteca para controle do servomotor
#include "Servo.h"
  
//Criando um objeto da classe Servo
Servo servoMotorObj1;
Servo servoMotorObj2;  
Servo servoMotorObj3;  
  
//pino analógico onde o potenciômetro está conectado
int const potenciometroPin1 = 0;  
int const potenciometroPin2 = 1;  
int const potenciometroPin3 = 2;  

//pino digital associado ao controle do servomotor
int const servoMotorPin1    = 9;
int const servoMotorPin2    = 10;
int const servoMotorPin3    = 11;  
 
//variável usada para armazenar o valor lido no potenciômetro
int valPotenciometro1;
int valPotenciometro2;
int valPotenciometro3;

void setup() {
  //associando o pino digital ao objeto da classe Servo
  servoMotorObj1.attach(servoMotorPin1);
  servoMotorObj2.attach(servoMotorPin2); 
  servoMotorObj3.attach(servoMotorPin3);  
}

void loop() {
  //lendo o valor do potenciômetro (intervalo entre 0 e 1023)
  valPotenciometro1 = analogRead(potenciometroPin1);
  valPotenciometro2 = analogRead(potenciometroPin2);
  valPotenciometro3 = analogRead(potenciometroPin3); 
 
  //mapeando o valor para a escala do servo (entre 0 e 180)
  valPotenciometro1 = map(valPotenciometro1, 0, 1023, 0, 180);
  valPotenciometro2 = map(valPotenciometro2, 0, 1023, 0, 180);
  valPotenciometro3 = map(valPotenciometro3, 0, 1023, 0, 180); 
 
  //definindo o valor/posição do servomotor
  servoMotorObj1.write(valPotenciometro1);
  servoMotorObj2.write(valPotenciometro2); 
  servoMotorObj3.write(valPotenciometro3);  
  delay(15);

}
