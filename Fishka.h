#ifndef PROJECTS_FISHKA_H
#define PROJECTS_FISHKA_H


class Fishka
{
protected:
    int number;
    int posX, posY;

public:
    Fishka();
    Fishka(int number,int x, int y);
    int getFishkaNumber();
    void getPosition();
    ~Fishka();

};


#endif //PROJECTS_FISHKA_H
