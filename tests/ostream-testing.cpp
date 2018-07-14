#include <iostream>
using namespace std;

class foo
{
public:
    int a;
    int b;
    foo(int a, int b);
    
};

foo::foo(int a, int b)
{
    this->a = a;
    this->b = b;
}

ostream & operator<< (ostream & o, foo & z)
{
    o << "We have " << z.a << ", but we also have " << z.b;
    return o;
}

int main()
{
    int a, b;
    cout << "Gimme two numbers" << endl;
    cin >> a >> b;
    foo bar(a,b);
    cout << bar << endl;
}