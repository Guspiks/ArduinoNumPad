#include <Arduino.h>
#include <Keypad.h>

int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int led6 = 10;
int led7 = 11;
int led8 = 12;
int led9 = 13;
int bright = 0;
int fade = 5;

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = {3, 2, A5, A4};
byte colPins[COLS] = {A0, A1, A2, A3};

char keys[ROWS][COLS]{
  {'A','3','2','1'},
  {'B','6','5','4'},
  {'C','9','8','7'},
  {'D','#','0','*'}
};

Keypad klawiatura = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  Serial.begin(9600);
}

void ChONE(int led){
  if(digitalRead(led) == HIGH){
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
}

void ChALL(int wart){
  digitalWrite(led1, wart);
  digitalWrite(led2, wart);
  digitalWrite(led3, wart);
  digitalWrite(led4, wart);
  digitalWrite(led5, wart);
  digitalWrite(led6, wart);
  digitalWrite(led7, wart);
  digitalWrite(led8, wart);
  digitalWrite(led9, wart);
}

void loop() {
  char klawisz = klawiatura.getKey();
  if(klawisz){
    Serial.println(klawisz);
  }

  switch (klawisz){
    case '1':
    ChONE(led1);
    break;

    case '2':
    ChONE(led2);
    break;

    case '3':
    ChONE(led3);
    break;

    case '4':
    ChONE(led4);
    break;

    case '5':
    ChONE(led5);
    break;

    case '6':
    ChONE(led6);
    break;

    case '7':
    ChONE(led7);
    break;

    case '8':
    ChONE(led8);
    break;

    case '9':
    ChONE(led9);
    break;

    case 'A':
    ChALL(HIGH);
    break;

    case 'D':
    ChALL(LOW);
    break;

    default:
    break;
  }
}