#include <iostream>
using namespace std;

int i = 6;

void complexicate(int& i)
{
    i++;
}
namespace fancy
{
    static int i = 50;
}

//CLASS
class foo
{
    public: 
    static int i;
    int j;
    foo(int i = 0);
    int increment ();

    //static functions are only allowed to access static variables 
    static void printMessage() //function cannot access j
    {                         //because it is non-static
        int j = 0; //the functon can, however, declare its own local
                  //static or non-nonstatic variables
        static int i = 0;
        cout << i << ": wow, things are going well :) " << foo::i <<  endl;
        i++;
        
    }//static varibles of the function exist within the life-span of the
    //entire program
};

int foo::i = 0; //giving a value to the static memeber variable

//CONSTRUCTOR
foo::foo(int i)
{
    (*this).i = i; //same as this->i = i;
}

//MEMBER FUNCTIONS
int foo::increment()
{
    i++;
}

//MAIN
int main()
{
    int i = 3; //local i within main
    cout << i;
    i += 6; //appending local i
    cout << " " << i;
    complexicate(i); //incrementing local i
    cout << " " << i << endl;
    cout << ::i << " "; //global i (initialized outside of main)
    ::i+= 6; //appending global i
    cout << ::i << endl; 
    foo obj(i); //static member variable i
    cout << obj.i;
    obj.increment(); //incrementing static member variable i
    cout << " " << obj.i << endl;
    foo doo;
    cout << doo.i << " ";
    doo.increment();
    cout << foo::i << endl; //static variables belong to the class (in this case
    cout << obj.i << endl; // foo, foo::i), NOT the individual objects. They can, 
                          //however still be accessed through objects (obj.i)
    foo::printMessage();
    foo::printMessage();
    cout << fancy::i << endl; //printing i in the scope of the namespace fancy
               
}

//static functions can be called without objects (foo::printMessage())

//when a variable/function/class is declared as static, it exists for the
//entire run-time of the program

//:: - scope operator, used to access variables and functions in 
// namespaces/classes/outside of main (global variables)