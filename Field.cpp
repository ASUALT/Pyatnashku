#include <iostream>
#include "Field.h"
#include <algorithm>
#include <ctime>

Field::Field()
{
    row=3;
    col=3;
    maxValue = 8;
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
    maxValue = row*col-1;

    // array initialization
    fieldElement = new Fishka*[row];
    for (int i = 0; i < row; ++i)
    {
        fieldElement[i] = new Fishka[col];
    }
}

void Field::fillField()
{
    int tempMaxValue = maxValue; // the max number in the field
    // fill up the field
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            fieldElement[i][j] = Fishka(tempMaxValue,i,j);
            --tempMaxValue;
        }
    }
    shuffleFieldElment();
}

void Field::shuffleFieldElment() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    // shuffle array
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
                int random_row = std::rand() % row;
                int random_col = std::rand() % col;
                std::swap(fieldElement[i][j], fieldElement[random_row][random_col]);
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (fieldElement[i][j].getFishkaNumber() == 0) {
                // placing element with number "0" at the end of the array
                std::swap(fieldElement[i][j], fieldElement[row - 1][col - 1]);
            }
        }
    }

    // replace "1" and "2" fiska
    if( maxValue % 2 == 1 )
    {
        int oneFishkaPosX = getPostionOnField(1)[0];
        int oneFishkaPosY = getPostionOnField(1)[1];

        int twoFishkaPosX = getPostionOnField(2)[0];
        int twoFishkaPosY = getPostionOnField(2)[1];

        std::cout << "(1) " << oneFishkaPosX << " " << oneFishkaPosY << std::endl;
        std::cout << "(2) " << twoFishkaPosX << " " << twoFishkaPosY << std::endl;

        std::swap(fieldElement[oneFishkaPosX][oneFishkaPosY], fieldElement[twoFishkaPosX][twoFishkaPosY]);
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

void Field::Move(int fishkaNumber)
{
    if (validFiska(fishkaNumber) && checkNearZero(fishkaNumber))
    {
        // replacing "0" element to selected fishka
        int fishkaPosX = getPostionOnField(fishkaNumber)[0];
        int fishkaPosY = getPostionOnField(fishkaNumber)[1];

        int zeroFishkaPosX = getPostionOnField(0)[0];
        int zeroFishkaPosY = getPostionOnField(0)[1];

        // replacing "0" element to selected fishka
        std::swap(fieldElement[fishkaPosX][fishkaPosY], fieldElement[zeroFishkaPosX][zeroFishkaPosY]);
        std::cout << "(" << fishkaNumber << ") " <<fishkaPosX << " " << fishkaPosY << std::endl;
        std::cout << "(0) " << zeroFishkaPosX << " " << zeroFishkaPosY << std::endl;
        //std::cout << "Correct" << std::endl;
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
                positionOnField[0] = i;
                positionOnField[1] = j;
                return positionOnField;
            }
        }
    }
}

bool Field::finalCheck() {
    int value = row*col-1; // the max number in the field
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if(fieldElement[i][j].getFishkaNumber() != value) { return false; };
            value--;
        }
    }
    return true;

}

bool Field::checkNearZero(int fishkaNumber) {

    int fishkaPosX = getPostionOnField(fishkaNumber)[0];
    int fishkaPosY = getPostionOnField(fishkaNumber)[1];

    int zeroFishkaPosX = getPostionOnField(0)[0];
    int zeroFishkaPosY = getPostionOnField(0)[1];

    if( zeroFishkaPosY == fishkaPosY )
    {
        if (zeroFishkaPosX  == fishkaPosX + 1 or zeroFishkaPosX  == fishkaPosX - 1) { return  true; }
    }

    else if( zeroFishkaPosX == fishkaPosX )
    {
        if (zeroFishkaPosY  == fishkaPosY + 1 or zeroFishkaPosY  == fishkaPosY - 1) { return  true; }
    }
    else return false;
}

Field::~Field()
{
    for (int i = 0; i < row; ++i) {
        delete[] fieldElement[i];
    }
    delete[] fieldElement;
    std::cout << "Field Destructor" << std::endl;
}





