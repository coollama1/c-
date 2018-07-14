
#include <iostream>
#include <limits>
using namespace std;

int exponent_on_two(double n) //PRECONDITION: n is a positive number >= 1 
{                            //POSTCOND: returns the smallest exponenent on 2
    if(n == 1)              //that will be greater than or equal to n
    {                      
        return 0;
    }
    else if(n > 1 && n < 2)
    {
        return 1;
    }
    return 1 + exponent_on_two(n/2.0);
}

int main ()
{
    int max = numeric_limits<int>::max();
    int min = numeric_limits<int>::min();
    cout << "The max value: " << max << endl;
    cout << "The min value: " << min << endl;
    cout << "This must be a " << exponent_on_two(max) + 1 << "-bit system" << endl;
    bool data [5];
    cout << data[0] << endl;
    // exponent_on_two(max) + 1; <- Because 1 bit is reserved for sign
}