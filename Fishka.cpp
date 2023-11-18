#include <iostream>
#include "Fishka.h"


Fishka::Fishka()
{
    number = 0;
    position[0] = 0;
    position[1] = 0;
}

Fishka::Fishka(int number, int x, int y)
{
    this->number = number;
    position[0] = x;
    position[1] = y;
}

int Fishka::getFishkaNumber() { return number; }

int * Fishka::getFishkaPosition(int fishkaNumber) {
    return position;
}

Fishka::~Fishka() {}

void Fishka::setFishkaNumber(int fishkaNumber) {
    number = fishkaNumber;
}
