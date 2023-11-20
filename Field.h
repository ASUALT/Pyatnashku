#ifndef PROJECTS_FIELD_H
#define PROJECTS_FIELD_H

#include "Fishka.h"

class Field : private Fishka
{
private:
    int row, col, maxValue;
    Fishka ** fieldElement;
    int positionOnField[2];

    bool validFiska(int fishkaNumber);
    int * getPostionOnField(int fishkaNumber);
    void shuffleFieldElment();
    bool checkNearZero(int fishkaNumber);

public:
    Field();
    Field(int weight,int height);
    void fillField();
    void displayField();
    void Move(int chooseFishka);
    bool finalCheck();
    ~Field();
};


#endif //PROJECTS_FIELD_H
