#define SensorBoia 10
#define LedVermelho 6
#define LedVerde 5

int leituraSensor ;

void setup() {
  Serial.begin(9600);
  pinMode(SensorBoia, INPUT);
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedVerde, OUTPUT);
}

void loop() {
  leituraSensor = digitalRead(SensorBoia);
  Serial.print("Leitura do sensor: ");
  Serial.print(leituraSensor);

  if (leituraSensor == HIGH){
    Serial.print("Nível de água alto");
    digitalWrite(LedVermelho, LOW);
    digitalWrite(LedVerde, HIGH);
  }
  else{
    Serial.print("Nível de água alto");
    digitalWrite(LedVermelho, HIGH);
    digitalWrite(LedVerde, LOW);
  }
 delay(300);
}
