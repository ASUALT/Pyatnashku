#include <iostream>
#include "Field.h"

Field::Field()
{
    row=3;
    col=3;
    d = 3;

    // array initialization
    pFieldSize = new Fishka *[3];
    for (int i = 0; i < 3; ++i)
    {
        pFieldSize[i] = new Fishka[3];
    }
}

/// Max size is 9x9, min 3x3
Field::Field(int row, int col)
{
    this->row = row;
    this->col = col;
    d = row;

    // array initialization
    pFieldSize = new Fishka*[row];
    for (int i = 0; i < row; ++i)
    {
        pFieldSize[i] = new Fishka[col];
    }
}

void Field::fillField()
{
    int value = d*d-1; // the max number in the field
    // fill up the field
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            pFieldSize[i][j] = Fishka(value,i,j);
            --value;
        }
    }
}

void Field::displayField()
{
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << pFieldSize[i][j].getFishkaNumber() << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;

}

Field::~Field()
{
    for (int i = 0; i < row; ++i) {
        delete[] pFieldSize[i];
    }
    delete[] pFieldSize;
    std::cout << "Field Destructor" << std::endl;
}




