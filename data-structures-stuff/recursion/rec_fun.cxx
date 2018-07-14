#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>
using namespace std;

string asteriks(unsigned int n) 
{
    if(n <= 0)
    {
        return "";
    }
    else
    {
        return "*" + asteriks(n - 1);
    }
}

string spaces(unsigned int n)
{
    if(n == 0)
    {
        return "";
    }
    else
    {
        return " " + spaces(n - 1);
    }
}

void triangle(ostream& outs, unsigned int m, unsigned int n)
{
    if(m == n)
    {
        outs << asteriks(m) << "\n" << asteriks(m) << "\n";
    }
    else
    {
        outs << asteriks(m) << "\n";
        triangle(outs, m + 1, n);
        outs << asteriks(m) << "\n";
    }
}

void numbers(ostream& outs, const string& prefix, unsigned int levels)
{
    if(levels == 0)
    {
        outs << prefix  << endl;
    }
    else
    {  
        for(char c = '1'; c <= '9'; c++)
        {
            string s = prefix + c + ".";
            numbers(outs, s, levels - 1);
        }
    }
}

bool bears(int n)
{
    bool first = false, second = false, third = false; //conditions
    if(n == 42)
    {
        return true;
    }
    else if (n < 42)
    {
        return false;   
    }
    if(n % 2 == 0)
    {
        first = bears(n/2);
    }
    if(n % 4 == 0 || n % 3 == 0)
    {
        int last, beforeLast;
        last = n % 10;
        beforeLast = (n / 10) % 10;
        int productOfLastTwo = last * beforeLast;
        if(productOfLastTwo != 0)
            second = bears(n - (productOfLastTwo));
    }
    if(n % 5 == 0)
    {
        third = bears(n - 42);
    }
    return (first || second || third);
}

void pattern(ostream& outs, unsigned int n, unsigned int i)
{
    assert(n >= 0);

    if(n == 0)
    {
        outs << spaces(i) << asteriks(1) << endl;
    }
    else
    {
        pattern(outs, n - 1, i);
        outs << spaces(i) << asteriks(pow(2,n)) << endl;
        pattern(outs, n - 1, i + pow(2,n) / 2);
    }
}
