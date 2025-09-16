#include <Servo.h>

#define pinoServo 2
#define chuvaDigital 4
#define chuvaAnalogico A5
#define ledVerm 12
#define ledAmarelo 11
#define ledVerde 10

Servo servoMotor;

int valorAnalogico;
int valorDigital;
int intensidadeChuva;

void setup() {
 Serial.begin(9600);
 pinMode (ledVerm, OUTPUT);
 pinMode (ledAmarelo, OUTPUT);
 pinMode (ledVerde, OUTPUT);
 pinMode (chuvaAnalogico, INPUT);
 pinMode (chuvaDigital, INPUT);
 
 servoMotor.attach(pinoServo);
}

void loop() {
  valorAnalogico = analogRead(chuvaAnalogico);
  intensidadeChuva = map(valorAnalogico, 1023, 0, 0, 100);
  Serial.print("Intensidade Chuva: ");
  Serial.print(intensidadeChuva);

valorDigital = digitalRead(chuvaDigital); //Realiza a leitura digital do sensor e armazena em valorDigital
  if (valorDigital == 0) {                  //Se esse valor for igual a 0, será mostrado no monitor serial que a chuva foi detectada e o led verde se acende
    Serial.println("Status: Chuva detectada");
    servoMotor.write(90);                   //Em "90", o varal estará recolhido
  }
  else { // se esse valor for igual a 1, será mostrado no monitor serial que o solo está seco e o led vermelho se acende
    Serial.println("Status: Chuva não detectada");
    servoMotor.write(0);                   //Em "ZERO", o varal estará exposto
  }

  if (intensidadeChuva == 0){
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } else if (intensidadeChuva <= 30){
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  } else if (intensidadeChuva <= 70){
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
  } else {
    digitalWrite(ledVerm, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  }
  delay(500); //Atraso de 500ms
  
  

}
