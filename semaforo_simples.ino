#define ledVermelho 8
#define ledAmarelo 9
#define ledVerde 5

void setup()
{
  pinMode(ledVerde, OUTPUT); //verde
  pinMode(ledAmarelo, OUTPUT); //vermelho
  pinMode(ledVermelho, OUTPUT); //amarelo
}

void loop()
{
  digitalWrite(ledVerde, HIGH);
  delay(10000); // Wait for 1000 millisecond(s)
  digitalWrite(ledVerde, LOW);
  
digitalWrite(ledAmarelo, HIGH);
  delay(5000); // Wait for 1000 millisecond(s)
  digitalWrite(ledAmarelo, LOW);
   // Wait for 1000 millisecond(s)

digitalWrite(ledVermelho, HIGH);
  delay(10000); // Wait for 1000 millisecond(s)
  digitalWrite(ledVermelho, LOW);
 
}