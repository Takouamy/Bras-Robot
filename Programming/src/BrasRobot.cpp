#include<Arduino.h>
#include<Servo.h>
#include<math.h>
#include "BrasRobot.h"
#include "Moteur.h"

float convertRad_Deg(float rad)
{
    return rad*180/PI;
}

BrasRobot::BrasRobot(int pinBase, int pinM1, int pinM2, int r):base(pinBase), m1(pinM1), m2(pinM2)
{
    R=r;
}

void BrasRobot::calibre()
{
    base.calibre();
    m1.calibre();
    m2.calibre();
}

int BrasRobot::gotoXY(int x, int y)
{
    float deg, degX;
    if(x*x + y*y > 4*R*R)
    {
        Serial.println("hors de porte du bras");
        return 0;    //hors de porte du bras
    }
    else
    {
        Serial.println("goto(x, y)");
        if(x == 0)
        {
            deg=0.5 * PI;   //90 degree en radian
        }
        else
        {
            deg = atan2(y, x);  //deg est en radians
        }
        degX = acos(x/(2*R*cos(deg)));      //cos prends des valeurs en radians et acos retourne une valeurs en radians
        //conversion
        deg = convertRad_Deg(deg);
        degX= convertRad_Deg(degX);
        Serial.println(deg);
        Serial.println(degX);
        //Mouvement
        
        m1.tourne(deg + degX);
        m2.tourne(deg - degX + 90);
        
        Serial.print("theta_1 = ");
        Serial.println(deg + degX);
        Serial.print("theta_2 = ");
        Serial.println(deg - degX + 90);
        return 1;
    }
}

int BrasRobot::gotoXYZ(int x, int y, int z)
{
    float degY, u;
    if(x*x + y*y + z*z > 4*R*R)
    {
        Serial.println("hors de porte du bras");
        return 0;
    }
    else
    {
        Serial.println("A la porte du bras");
        if(x == 0 && y!=0)
        {
            degY = 90;
        }
        else if(x ==0 && y ==0)
        {
            degY = 0;
        }
        else if( x != 0)
        {
            degY = atan2(y, x)*180/PI;  //car atan2 et atan retourne en radians et non en degree
        }
        u = sqrt(x*x + y*y);
        Serial.print("phi = ");
        Serial.println(degY);
        Serial.println(u);
        //Mouvement
        base.tourne(degY);
        gotoXY(u, z);

        return 1;
    }

}

void testMoteur(Moteur m)
{
  m.tourne(90);
  m.tourne(45);
  m.tourne(180);
  m.calibre();
}

void BrasRobot::testAllMoteur()
{
  testMoteur(base);
  testMoteur(m1);
  testMoteur(m2);
}