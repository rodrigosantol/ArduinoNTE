#include <Ultrasonic.h>
#include <Servo.h>

float distancia = 0;
int sorteio = 0;
const int pinTrig = 7;                     // pino usado para disparar os pulsos do sensor
const int pinEcho = 6;                     // pino usado para ler a saida do sensor

Servo servo_4;
Servo servo_3;
Servo servo_2;
Ultrasonic ultrasonic(pinTrig, pinEcho); // inicializa o senor HC-SR04

void setup()
{
  Serial.begin(9600);
  servo_4.attach(4);
  servo_3.attach(3);
  servo_2.attach(2);
  pinMode(5, OUTPUT);
}

void loop()
{
  servo_2.write(0);
  servo_3.write(0);
  servo_4.write(0);

  distancia = ultrasonic.read();

  // Verifique distância ao sensor  
  if (distancia < 10) {
    digitalWrite(LED_BUILTIN, HIGH);
    // Se menor 10cm sortear um número entre 1 e 30
    sorteio = random(1, 30 + 1);
    // Escreva o numero sorteado no monitor serial
    Serial.println(distancia);
    Serial.print("Sorteio =");
    Serial.println(sorteio);
    
    // Escreva o numero no monitor serial
    if (sorteio < 10) {
      // Se sorteio < 10, mover servo "pedra"
      servo_4.write(60);
      Serial.println("Pedra");
    }
    if (sorteio >= 10 && sorteio < 20) {
      // Se sorteio > 10 e < 20, mover servo "papel"
      servo_3.write(60);
      Serial.println("Papel");
    }
    if (sorteio >= 20) {
      // Se sorteio > 20, mover servo "tesoura"
      servo_2.write(60);
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
  else{
    servo_2.write(0);
    servo_3.write(0);
    servo_4.write(0);
    digitalWrite(LED_BUILTIN, LOW);
  }
}