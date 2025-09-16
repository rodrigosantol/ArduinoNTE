void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);

  analogWrite(11, 0);
  analogWrite(9, 102);
  analogWrite(10, 0);
}

void loop() {
// put your main code here, to run repeatedly:
if (digitalRead(2) == HIGH) {
    analogWrite(11, 204);
    analogWrite(9, 0);
    analogWrite(10, 0);
  }
if (digitalRead(4) == HIGH) {
    analogWrite(11, 0);
    analogWrite(9, 102);
    analogWrite(10, 0);
  }
  delay(10);
}
