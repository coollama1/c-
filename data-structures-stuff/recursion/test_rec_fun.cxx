#include <iostream>
#include "rec_fun.h"
using namespace std;

int main ()
{
    //triangle(...) test
    int m, n;
    cout << "Gimme the m and n values, and I'll make a triangle" << endl;
    cin >> m >> n;
    cout << endl;
    triangle(cout, m, n);
    cout << endl;
    
    //numbers(...) test
    string prefix = "so done with this class";
    int levels;
    cout << "Tell me how many levels of repetition you want :)" << endl;
    cin >> levels;
    cout << endl;
    numbers(cout, prefix, levels);
    cout << endl;

    //bears(...) test
    int numberOfBears;
    cout << "Tell me how many bears you have and I'll tell you if you can win the game" << endl;
    cin >> numberOfBears;
    cout << endl;
    if(bears(numberOfBears))
    {
        cout << "It's possible for you to win" << endl << endl;
    }
    else
    {
        cout << "It's not possible for you to win" << endl << endl;
    }

    //pattern(...) test
    int powerOnTwo;
    cout << "Tell me the size (power on two) of the fractal you would like to make" << endl;
    cin >> powerOnTwo;
    cout << endl;
    pattern(cout, powerOnTwo, 0);
}