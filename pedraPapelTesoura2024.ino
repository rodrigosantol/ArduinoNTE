#include <Servo.h>

int distancia = 0;

int sorteio = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_4;

Servo servo_3;

Servo servo_2;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  servo_4.attach(4, 500, 2500);
  servo_3.attach(3, 500, 2500);
  servo_2.attach(2, 500, 2500);
  pinMode(5, OUTPUT);
}

void loop()
{
  // Verifique distância ao sensor
  distancia = 0.01723 * readUltrasonicDistance(7, 6);
  if (distancia < 40) {
    digitalWrite(LED_BUILTIN, HIGH);
    // Se menor 10cm sortear um número entre 1 e 30
    sorteio = random(1, 30 + 1);
    // Escreva o numero sorteado no monitor serial
    Serial.print("Sorteio =");
    Serial.println(sorteio);
    // Escreva o numero no monitor serial
    if (sorteio < 10) {
      // Se sorteio < 10, mover servo "pedra"
      servo_4.write(90);
      Serial.println("Pedra");
    }
    if (sorteio >= 10 && sorteio < 20) {
      // Se sorteio > 10 e < 20, mover servo "papel"
      servo_3.write(90);
      Serial.println("Papel");
    }
    if (sorteio >= 20) {
      // Se sorteio > 20, mover servo "tesoura"
      servo_2.write(90);
      Serial.println("Tesoura");
    }
    // Emita um som no buzzer
    tone(5, 1783720093981, 500); // play tone 440 (G#36 = 1783720093981 Hz)
    // Aguarde 5s para nova jogada
    delay(5000); // Wait for 5000 millisecond(s)
    // Retorne os 3 servos para a posição inicial
    servo_2.write(0);
    servo_3.write(0);
    servo_4.write(0);
    digitalWrite(LED_BUILTIN, LOW);
  }
}