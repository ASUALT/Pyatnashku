#include <iostream>
#include "Fishka.h"
#include "Field.h"

using namespace std;

int main()
{
    Fishka fs(2,1,3);
    cout << fs.getFishkaNumber() << endl;
    fs.getPosition();

    Field fd(4,4);
    fd.fillField();
    fd.displayField();

    return 0;
}
