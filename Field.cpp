#include <iostream>
#include "Field.h"

Field::Field()
{
    row=3;
    col=3;
    d = 3;

    // array initialization
    fieldElement = new Fishka *[3];
    for (int i = 0; i < 3; ++i)
    {
        fieldElement[i] = new Fishka[3];
    }
}

/// Max size is 9x9, min 3x3
Field::Field(int row, int col)
{
    this->row = row;
    this->col = col;
    d = row;

    // array initialization
    fieldElement = new Fishka*[row];
    for (int i = 0; i < row; ++i)
    {
        fieldElement[i] = new Fishka[col];
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
            fieldElement[i][j] = Fishka(value,i,j);
            --value;
        }
    }
}

void Field::displayField()
{
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << fieldElement[i][j].getFishkaNumber() << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;

}

Field::~Field()
{
    for (int i = 0; i < row; ++i) {
        delete[] fieldElement[i];
    }
    delete[] fieldElement;
    std::cout << "Field Destructor" << std::endl;
}

void Field::Move(int fishkaNumber)
{
    if (validFiska(fishkaNumber))
    {
        fieldElement[getPostionOnField(fishkaNumber)[0]] [getPostionOnField(fishkaNumber)[1]]
        .setFishkaNumber(fishkaNumber);
        //std::cout << getPostionOnField(fishkaNumber)[0] << " " << getPostionOnField(fishkaNumber)[1] << std::endl;
        std::cout << "Correct" << std::endl;
    }
    else std::cout << "Incorrect" << std::endl;
}

bool Field::validFiska(int fishkaNumber) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if ( fieldElement[i][j].getFishkaNumber() == fishkaNumber) { return true; }
        }
    }
    return false;
}

int *Field::getPostionOnField(int fishkaNumber) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if ( fieldElement[i][j].getFishkaNumber() == fishkaNumber)
            {
                postionField[0] = i;
                postionField[1] = j;
                return postionField;
            }
        }
    }
}




