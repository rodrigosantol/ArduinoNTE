#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define col 16 // Serve para definir o numero de colunas do display utilizado
#define lin  2 // Serve para definir o numero de linhas do display utilizado
#define ende  0x27 // Serve para definir o endereço do display.


LiquidCrystal_I2C lcd(ende,col,lin); // Chamada da funcação LiquidCrystal para ser usada com o I2C
dht DHT; // Cria um objeto da classe dht

uint32_t timer = 0; // declara a variável timer

const int RED = 5; // Led RGB vermelho
const int GREEN = 6; // Led RGB verde
const int BLUE = 7; // Led RGB azul

const int pinButton = 2; // Pino do push button

int estado = 1;
int estado_anterior = 1;
int x = 1;

void setup() 
{
  Serial.begin(9600); // Inicializa serial com taxa de transmissão de 9600 bauds
  lcd.init();
  lcd.backlight();
  lcd.clear(); // limpa a tela do display

  DHT.read11(A1); // chama método de leitura da classe dht (leitura inicial)

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  pinMode(pinButton, INPUT_PULLUP);
}

void loop() 
{
  // Executa 1 vez a cada 2 segundos (tempo de resposta do DHT 11)
  if(millis() - timer>= 2000)  {
    
    DHT.read11(A1); // chama método de leitura da classe dht,
                    // com o pino de transmissão de dados ligado no pino A1
 
    // Exibe na serial o valor de umidade
    Serial.print("Umidade = ");
    Serial.print(DHT.humidity);
    Serial.print(" %  ");
 
    // Exibe na serial o valor da temperatura
    Serial.print("Temperatura = ");
    Serial.print(DHT.temperature); 
    Serial.println(" Celsius  ");

    // Chama a função RGb()
    rgb();
    
    timer = millis(); // Atualiza a referência
  }

    // Chama a função print()
    print(x);

    // le o estado pushbutton: ligado (HIGH) ou desligado (LOW)
    estado = digitalRead(pinButton);

    // verifica se o botão (pushbutton) está pressionado
    if ((estado) && (!estado_anterior)) { // Se estado for HIGH e estado_anterio LOW
        // inverte valor da variável x
        x = !x;
        delay(10);
    }
    estado_anterior = estado;
}

void print(int x) {
if (x==1) {
    // Exibe no display LCD o valor da temperatura
    lcd.setCursor(0,0); // Define o cursor na posição de início
    lcd.print("Temp. = ");
    lcd.print(DHT.temperature);
    lcd.write(B11011111); // Imprime o símbolo de grau
    lcd.print("C");    
} else if (x==0) {        
    // Exibe no display LCD o valor da humidade
    lcd.setCursor(0,0); // Define o cursor na posição de início
    lcd.print("Umid. = ");
    lcd.print(DHT.humidity);
    lcd.print("% ");
    }
}

void rgb() {
    if( DHT.temperature < 15) {
        digitalWrite(BLUE, HIGH);
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        Serial.println("COR: AZUL    "); // Escreve texto ” COR:AZUL” na serial
        // Exibe no display LCD o o nome da cor
        lcd.setCursor(5,1); // Define o cursor na posição de início
        lcd.print("AZUL    ");
    }
    else if( DHT.temperature >= 15 && DHT.temperature < 25 )
    {
        digitalWrite(BLUE, LOW);
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH);
        Serial.println("COR: VERDE"); // Escreve texto ” COR:VERDE” na serial
        // Exibe no display LCD o o nome da cor
        lcd.setCursor(5,1); // Define o cursor na posição de início
        lcd.print("VERDE    ");
    }
    else if( DHT.temperature >= 25)
    {
        digitalWrite(BLUE, LOW);
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, LOW);
        Serial.println("COR: VERMELHA"); // Escreve texto ” COR:VERMELHA” na serial
        // Exibe no display LCD o o nome da cor
        lcd.setCursor(5,1); // Define o cursor na posição de início
        lcd.print("VERMELHO");
    }
 

}
