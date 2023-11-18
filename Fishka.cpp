//
// Created by Administrator on 11/17/2023.
//
#include <iostream>
#include "Fishka.h"


Fishka::Fishka()
{
    number = 0;
    posX = 0;
    posY = 0;
}

Fishka::Fishka(int number, int x, int y)
{
    this->number = number;
    posX = x;
    posY = y;
}

int Fishka::getFishkaNumber() { return number; }

void Fishka::getPosition() {
    std::cout << posX << " " << posY << std::endl;
}

Fishka::~Fishka() { std::cout << "Fishka Destructor" << std::endl;}
