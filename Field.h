#ifndef PROJECTS_FIELD_H
#define PROJECTS_FIELD_H

#include "Fishka.h"

class Field : private Fishka
{
private:
    int row, col, d;
    Fishka ** pFieldSize;
public:
    Field();
    Field(int weight,int height);
    void fillField();
    void displayField();
    void getFishkaPos();
    ~Field();
};


#endif //PROJECTS_FIELD_H
