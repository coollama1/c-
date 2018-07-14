#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class foo
{
public:
    static const int x = 5; //static variables can be instantiated within the class
                           //if they are declared as const
    int fancy (int& x) const
    {
        x += x + 5; //program will not run if function attempts to change the 
                   //value of a const reference parameter
                   cout << x << " ";
        return x + 5;
    }//const member functions only preserve the object which they are being activated on
    
    //outside parameters (in the case below, x) are not preserved
    //non-member functions cannot be const: funct(int x) const <- will give errors
};

int main()
{
    foo obj;
    int x = 5;
    cout << "This is your number: " << obj.fancy(x) << endl << "This is also your number: " << foo::x <<endl;
    cout << x << endl;
    //cannot use a temp value as a reference parameter, fancy (int& x); fancy(5);
    //5 is an Rvalue, it is a temporary value and exists only for an instance
    //int x - is an Lvalue, it is a variable or object and exists throughout the program
    //or within a scope
}