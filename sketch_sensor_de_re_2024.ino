#include <Ultrasonic.h>

Ultrasonic ultrasonic(7,8);
int distancia; 
int buzzer = 4;

void setup() {
  Serial.begin(9600);
  ultrasonic.setTimeout(40000UL);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  distancia = ultrasonic.read();
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  delay(1000);

  if (distancia <= 10){
    tone(buzzer, 1500);
    delay(50);
    noTone(buzzer);
    delay(5);
  }
  else if  (distancia <= 20){
    tone(buzzer, 1500);
    delay(50);
    noTone(buzzer);
    delay(10);
  }
  else if (distancia <= 30){
    tone(buzzer, 1500);
    delay(50);
    noTone(buzzer);
    delay(15);
  }
  else {
    tone(buzzer, 1500);
    delay(50);
    noTone(buzzer);
    delay(20);
  }
} 



