// C++ code
int ledPins [7] = {2,3,4,5,7,8,6};
int dicePatterns [7][7] =
{
  {0,0,0,0,0,0,1},
  {0,0,1,1,0,0,0},
  {0,0,1,1,0,0,1},
  {1,0,1,1,0,1,0},
  {1,0,1,1,0,1,1},
  {1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0}
};
int switchPin = 9;
int blank = 6;

void setup()
{
  for(int i = 0; i<7; i++){
      pinMode (ledPins[i], OUTPUT);
      digitalWrite(ledPins[i], LOW);
	}
  
  pinMode(switchPin, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop()
{
  if(digitalRead(switchPin)){
    rollTheDice();
  }
  delay(100);
}

void rollTheDice()
{
  int result =0;
  int lenghtOfRoll = random(15,25);
  for (int i = 0; i < lenghtOfRoll; i++){
    result = random (0,6);
    show(result);
    delay(50 + i*10);
  }
  
  for(int j = 0; j < 3; j++){
    show(blank);
    delay(500);
    show(result);
    delay(500);
  }
}

void show(int result)
{
  for (int i=0; i<7; i++)
  {
    digitalWrite(ledPins[i], dicePatterns[result][i]);
  }
}
