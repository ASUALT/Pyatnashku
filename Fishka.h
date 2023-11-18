#ifndef PROJECTS_FISHKA_H
#define PROJECTS_FISHKA_H


class Fishka
{
protected:
    int number;
    // first element is X coordinate, second is Y coordinate
    int position[2];

public:
    Fishka();
    Fishka(int number,int x, int y);
    int getFishkaNumber();
    int * getFishkaPosition(int fishkaNumber);
    void setFishkaNumber(int fishkaNumber);
    ~Fishka();

};


#endif //PROJECTS_FISHKA_H
