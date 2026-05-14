#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <LiquidCrystal_I2C.h>

void selecPressed();
void parcour();

int MainMenu(LiquidCrystal_I2C lcd);
int manualControlMenu(LiquidCrystal_I2C lcd);
bool clicked();
#endif // SCREENMANAGER_H
