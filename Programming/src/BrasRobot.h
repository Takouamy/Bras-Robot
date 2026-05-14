#ifndef BRASROBOT_H
#define BRASROBOT_H

#include <Arduino.h>
#include <Servo.h>
#include "Moteur.h"

#include <LiquidCrystal_I2C.h>
class BrasRobot{
private :
    Moteur base;
    Moteur m1;
    Moteur m2;
    int R;

public :
    BrasRobot(int pinBase, int pinM1, int pinM2, int r);
    void calibre();
    int gotoXY(int x, int y);       //return 0 si (x, y) n'est pas accessible et 1 sionon
    int gotoXYZ(int x, int y, int z);   //return 0 si (x, y, z) n'est pas accessible et 1 sionon
    void testAllMoteur();
};
#endif // BRASROBOT_H
