#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "sequence.cpp"
using namespace std;

class foo
{

public:
    int testing_things(int x) const;
    int testing_even_more_things(int x);
    
private:
    int x;
};

int foo::testing_things(int x) const
{
    assert(x > 0); //assert stops the entire program and produces an error
    return x++;
}

int foo::testing_even_more_things(int x)
{
    this->x = x;
    return x;
}

int main ()
{
    typedef int something;
    something data[30]; //an array declared like this holds 30 elements [0 - 29]
    size_t interesting;
    cout << interesting << endl;
    for(size_t c = 0; c < 30; c++)
    {
        data[c] = c;
    }
    for (size_t c = 0; c < 30; c++)
    cout << data[c] << endl; 

    foo bar;
    cout << bar.testing_things(5) << endl;
    cout << -5 << endl;

}