//
// Created by Administrator on 11/18/2023.
//
#include <iostream>
#include "Field.h"

Field::Field()
{
    row=3;
    col=3;
    d = 3;

    // array initialization
    pFieldSize = new int*[3];
    for (int i = 0; i < 3; ++i)
    {
        pFieldSize[i] = new int[3];
    }
}

/// Max size is 9x9, min 3x3
/// \param weight
/// \param height
Field::Field(int row, int col)
{
    this->row = row;
    this->col = col;
    d = row;

    // array initialization
    pFieldSize = new int*[row];
    for (int i = 0; i < row; ++i)
    {
        pFieldSize[i] = new int[col];
    }
}

void Field::fillField()
{
    int value = d*d-1;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            pFieldSize[i][j] = value;
            --value;
        }
    }
}

void Field::displayField()
{
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << pFieldSize[i][j] << "\t";
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


