#include "ScreenManager.h"
#include <Arduino.h>
#define selec 2
#define ES 3    //Emergency Stop
int cpt=0;
int t=0;

bool click = false;
bool emergencyStop = false;

String mainMenu[] = {"Auto Control", "Manual"};
String manualMenu[] = {"Moteur_Base", "Moteur_Axe1", "Moteur_Axe2", "Back"};

//----Interrupts--------------
void selecPressed()
{
    click = true;
}
void parcour()
{
    cpt++;
}
//----------------------------

int MainMenu(LiquidCrystal_I2C lcd)
{
    click=false;
    cpt=0;
    bool stop = false;
    do
    {
        lcd.clear();
        if(cpt%2 == 0)
        {
            lcd.setCursor(0, 0);
            lcd.print(">");
            lcd.setCursor(0, 1);
            lcd.print(" ");
        }
        if(cpt%2 == 1)
        {
            lcd.setCursor(0, 0);
            lcd.print(" ");
            lcd.setCursor(0, 1);
            lcd.print(">");
        }
        lcd.setCursor(1, 0);
        lcd.print(mainMenu[0]);
        lcd.setCursor(1, 1);
        lcd.print(mainMenu[1]);
        delay(500);
        if(click == true)
        {
            click = false;
            stop=true;
        }
    }
    while(stop == false  && emergencyStop == false);

    return cpt%2;
}

int manualControlMenu(LiquidCrystal_I2C lcd)
{
    click=false;
    cpt=0;
    bool stop = false;
    int step = 0;
    do
    {
        lcd.clear();
        if(cpt%4<=1)
        {
            step = 0;
        }
        else
        {
            step = 2;
        }
        if(cpt%2 == 0)
        {
            lcd.setCursor(0, 0);
            lcd.print(">");
            lcd.setCursor(0, 1);
            lcd.print(" ");
        }
        if(cpt%2 == 1)
        {
            lcd.setCursor(0, 0);
            lcd.print(" ");
            lcd.setCursor(0, 1);
            lcd.print(">");
        }
        lcd.setCursor(1, 0);
        lcd.print(manualMenu[step]);
        lcd.setCursor(1, 1);
        lcd.print(manualMenu[(step + 1)]);
        delay(500);

        if(click == true)
        {
            click = false;
            stop =true;
        }

    }
    while(stop==false && emergencyStop == false);

    return cpt%4;
}

bool clicked()
{
    return click;
}