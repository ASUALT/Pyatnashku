#include <iostream>
#include "Fishka.h"
#include "Field.h"

using namespace std;

int main()
{
    Field fd(4,4);
    fd.fillField();
    //fd.displayField();
    //fd.Move(2);
    int number;
    do
    {
        fd.displayField();
        cout << "Enter fishka number: ";
        cin >> number;
        fd.Move(number);
        cout << "============================" << endl;
    } while (!fd.finalCheck());
    cout << "Completed!" << endl;



}
