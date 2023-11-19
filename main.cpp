#include <iostream>
#include "Fishka.h"
#include "Field.h"

using namespace std;

int main()
{
    Field fd(4,4);
    fd.fillField();
    fd.displayField();
    fd.Move(4);
    fd.displayField();


    return 0;
}
