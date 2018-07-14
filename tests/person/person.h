//experimenting with classes
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
#include <vector>
#include <map>
using std::set;
using std::map;
using std::vector; 

//general guidline: class written in header (.h) file with member variables 
//declerations and member function prototypes
//  member functions of the class are imlpemented in a seperate .ccp file
//      calling program, uses items in a namespace

//when declaring member function prototypes within the body of a class
//putting (const) after the arguments ensures that objects created from
//the class will not be altered after the particular member function is activated
// double x() const; <- for example

//classes are usually placed in a seperate header (.h) file
//member function implelmentation (definition of what the member functins do)
//are usually placed in the cpp file
class person
{
private:
    string first_name;
    string last_name;
    int age;
    int grades;
    int iq;
    string major;
    map <string,string> family_members ; 
    set <string> interests;
    vector <string> classes;
public:
    person(string fname = "", string lname = "", int age = 0, int grades = 0, int iq = 0, string major = "None");

    void setFirstName(string fname);
    void setLastName(string lname);
    void setAge(int age);
    void setGrades (int grades);
    void setIq(int iq);
    void setMajor(string major);
    void addFamilyMember(string name, string relation);
    void addInterest (string interest);
    void addClass (string className);

    string getName() const;
    void printStats();
    string getFamilyMember(string relation);
    void printListOfInterests();
    void printListOfFamilyMembers();
    void printListOfClasses();
    void printEVERYTHING();
    bool isTakingClass(string className);

    person operator+(const person& p1) const;
    bool operator==(const person& p1) const;
    bool operator!=(const person& p1) const;
    
};


//constructors, like almost everything else, can be overloaded
//each one accepting different parameters 

//c++ automatically creates a copy constructor for a class that simply
//copies all of the member variables
//ex of a copy constructor: person person_object1(person_object2)

//fun fact about constructors: once one is initialized within the class
//it must be implemented (like the ones below)
//and the default constructor (if used) must then be initialized/implemented
// as well 
//implentations can be empty 

//compliler provides default constructor automatically iff no construtors are
//initialized

//construtors that contain default parameters, like age,grads,iq, and major in
//the person constructor below (where values are assigned in the parameter list),
//must place these values on the right most part of the parameter list
//this prevents values from being overwritten
//  for ex, if person (int age = 0, string fname, string lname)
//activating the constructor person("first_name", "last_name") would assign
//"first_name" to age, and "last_name" to fname
//  IMPORTANT AF: default arguments are provided in the prototype decleration,
//like above, NOT the implementation, like below
//  HOWEVER, the default parameters must still be included in the implementation,
//but not given a value, like age, grades, iq, and major below (and given values
// in the prototype declaration in the class above)

person::person(string fname, string lname, int age, int grades, int iq, string major)
{
    first_name = fname;
    last_name = lname;
    this->age = age;
    this->grades = grades;
    this->iq = iq;
    this->major = major;
}

//once all arguments are declared as default, the constructor can be used
//as a default constructor

//the above constructor requires less than or equal to 6 parameters (0 < n < 6)
//n - numb of parameters

//the minimum amount of parameters needed to activate a constructor is equal to 
//the numb of non-default arguments (found in the prototype in the class)
//ex: person(int age, int grades, string major = "none") - requires at least
//2 parameters, and accepts up to 3 

//actual parameter: parameter provided to a function when it's activated
//formal parameter:parameter used by the function once it's activated
//ex:
/*
f(int x, int y)
{
    ...
}
int main()
{
    f(a,b);
}
a,b - actual parameters
x,y - formal parameters
*/

/*
  - Value parameters: 
    f(int x, int y), x, y, for exmp, create a copy of the values; once activated
    f(a,b) will not change the values of a,b
      - copy constructor is used to create formal parameters
      - variables exist only in the function
  - Reference parameters
    f(int& x, int& y), once f(a,b) is activated , the actual values of a and b
    are used, so the function could change them
  - By reference uses less memeory (no copy created) so it's more efficient
    when dealing with large amounts of data
      - const ref: guarantees that value of the parameter isn't changed
        while still being efficient by not creating a copy of the variable
          - f(const int& c, const int& y)

*/

/*
    - Seems kinda obvious: classes can be returned by functions and accepted
      as arguments
        - f(const person& x, const person& y)
        {
            return person z;
        }
        - return statements use copy constructor to create a temporary copy
          of the return value before returning it

*/

/*
    - In order for binary operators to work on classes, they must be overloaded
      (person + person, person - person)
        - Assignment operator (=) uses copy constructor, therefore the rule
          does not apply
*/




