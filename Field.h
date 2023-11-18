//
// Created by Administrator on 11/18/2023.
//

#ifndef PROJECTS_FIELD_H
#define PROJECTS_FIELD_H


class Field
{
private:
    int row, col, d;
    int ** pFieldSize;
public:
    Field();
    Field(int weight,int height);
    void fillField();
    void displayField();
    ~Field();
};


#endif //PROJECTS_FIELD_H
