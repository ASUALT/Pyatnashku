#ifndef PROJECTS_FIELD_H
#define PROJECTS_FIELD_H

#include "Fishka.h"

class Field : private Fishka
{
private:
    int row, col, d;
    Fishka ** fieldElement;

    bool validFiska(int fishkaNumber);
    int * getPostionOnField(int fishkaNumber);

public:
    Field();
    Field(int weight,int height);
    void fillField();
    void displayField();
    void Move(int chooseFishka);
    ~Field();
};


#endif //PROJECTS_FIELD_H
