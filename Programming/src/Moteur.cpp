#include "Moteur.h"
#include <Arduino.h>
#include <Servo.h>

Moteur::Moteur(int p)
{
    pin=p;
}

void Moteur::tourne(int deg)
{
    moteur.write(deg);
    delay(2000);
}

void Moteur::calibre()
{
    moteur.attach(pin);
    moteur.write(0);
    delay(2000);
}

void controleUnMoteur(Moteur M, int pinPotentiometer)
{
    /**/
    M.tourne(35);
    M.tourne(180);
    M.tourne(0);
}