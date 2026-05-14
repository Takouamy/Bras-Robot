#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include "Moteur.h"
#include "BrasRobot.h"
#include "ScreenManager.h"
#define motor_base 13
#define motor_1 8
#define motor_2 7
#define pinPotentiometer A0
#define selec 2
#define ES 3    //Emergency Stop

LiquidCrystal_I2C lcd(0x27, 16, 2);       //Screen
int motor[] = {13, 8, 7};
void setup() {
  // put your setup code here, to run once:
  pinMode(selec, INPUT);
  pinMode(ES, INPUT);
  pinMode(pinPotentiometer, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(selec), parcour, FALLING);
  attachInterrupt(digitalPinToInterrupt(ES), selecPressed, FALLING);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int t=MainMenu(lcd);
  if(t==0)
  {

  }else if(t==1)
  {
    int t1=manualControlMenu(lcd);
    if(t1!=3)
    {
      int x =motor[t1];
      Moteur m(x);
      do
      {
        m.calibre();
        //int t = analogRead(pinPotentiometer);
        //int angle = map(pinPotentiometer, 0, 1023, 0, 180);
        //m.tourne(180);
        //m.tourne(0);
      }while(clicked() == false);
    }
  }
}




