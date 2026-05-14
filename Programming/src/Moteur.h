#ifndef MOTEUR_H
#define MOTEUR_H

#include<Arduino.h>
#include<Servo.h>

class Moteur{
private :
    Servo moteur;
    int pin;

public :
    Moteur(int p);
    void tourne(int deg);
    void calibre();

};
void controleUnMoteur(Moteur M, int pinPotentiometer);

#endif // MOTEUR_H
