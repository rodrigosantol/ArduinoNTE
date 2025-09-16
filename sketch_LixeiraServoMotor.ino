#include <Servo.h>

#define pinoTRIGGER 7
#define pinoECHO 6
#define pinoSERVO 12

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  pinMode(pinoTRIGGER, OUTPUT);
  pinMode(pinoECHO, INPUT);
  
  servoMotor.attach(pinoSERVO);
}

void loop() {
  long duration, distance;
  
  // Dispara o pulso no pino TRIGGER_PIN
  digitalWrite(pinoTRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTRIGGER, LOW);
  
  // Mede a duração do eco no pino ECHO_PIN
  duration = pulseIn(pinoECHO, HIGH);
  
  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Se a distância for menor que 15cm, movimenta o servo em 100 graus
  if (distance < 15) {
    servoMotor.write(50);
    delay(3000); // Ajuste conforme necessário
  } else {
    // Se não, mantém o servo em 0 graus
    servoMotor.write(0);
  }
  
  delay(100); // Aguarda um curto intervalo antes da próxima leitura
}