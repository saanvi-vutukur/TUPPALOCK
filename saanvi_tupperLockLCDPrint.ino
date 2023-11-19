#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h"

int solenoid_pin = 2;
int input_pin = 4;
int input;

void setup()
{
  pinMode(solenoid_pin, OUTPUT);
  pinMode(input_pin, INPUT);
  Serial.begin(9600);

  Config_Init();
  LCD_Init();
  LCD_Clear(0xffff);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_Clear(WHITE);
}

void loop()
{

  input = 1;
  Serial.println(input);

  // if command == lock 
  // - make voltage high 
  // - print "locked" to LCD
  // else if command == unlocked 
  // - make voltage low 
  // - print "unlocked" to LCD
  // else --> return; (nothing)

  // figure out that it can read based on input 

  if (input == 1) { 
    digitalWrite(solenoid_pin, HIGH); // voltage high 
    Paint_DrawString_EN(100, 110, "UNLOCKED", &Font24, WHITE, BLACK);
    Serial.println("Solenoid activated");
    // the voltage is high 
  }
  else if (input == 0) {
    digitalWrite(solenoid_pin, LOW);
    Paint_DrawString_EN(100, 110, "LOCKED", &Font24, WHITE, BLACK);
    Serial.println("Solenoid deactivated");
    // the voltage is low 
  }
  else {
        Paint_DrawString_EN(100, 110, "UNLOCKED", &Font24, WHITE, BLACK);
        Serial.println("Solenoid deactivated");
  }
}


/*

int solenoid_pin = 2;
int input_pin = 8;
int input;
void setup() {
  // put your setup code here, to run once:
  pinMode(solenoid_pin, OUTPUT);
  pinMode(input_pin, INPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  input = digitalRead(input_pin);
  if(input == 1){
    digitalWrite(solenoid_pin, HIGH);
    Serial.println("Solenoid activated");
  } else if (input == 0){
    digitalWrite(solenoid_pin, LOW);
    Serial.println("Solenoid deactivated");
  }
}

*/



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
