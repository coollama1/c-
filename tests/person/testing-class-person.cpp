#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "person.h" //<-usually, the class uses the include to import
                   //the implementation 


//for some freaking reason, the body of member functions pertaining to a class
//usually appear in the .cpp file instead of the .h file
//#programmer logic

void person::setFirstName(string fname)
{
    first_name = fname;
}
void person::setLastName(string lname)
{
    last_name = lname;
}
void person::setAge(int age)
{
    this->age = age;
}
void person::setGrades(int grades)
{
    this->grades = grades;
}
void person::setIq(int iq)
{
    this->iq = iq;
}
void person::setMajor(string major)
{
    this->major = major;
}
void person::addFamilyMember(string name, string relation)
{
    family_members[relation] = name;
}
void person::addInterest(string interest)
{
    interests.insert(interest);
}
void person::addClass(string className)
{
    classes.push_back(className);
}
/*
string first_name;
    string last_name;
    int age;
    int grades;
    int iq;
    string major;
    map <string,string> family_members ; 
    set <string> interests;
    vector <string> classes;
*/
string person::getName()const
{
    return first_name + " " + last_name;
}

void person::printStats() //srew it, we'll print them isntead
{
    cout << "Age: " << age << endl << "Grades: " << grades << "/100\nIQ: " << iq << "\nMajor: " << major << endl;
}
string person::getFamilyMember(string relation)
{
    return family_members[relation];
}
void person::printListOfFamilyMembers()
{
    for(map<string, string>::iterator i = family_members.begin(); i != family_members.end(); i++)
    {
        cout << (*i).first << ": " << (*i).second << endl;
    }
}
void person::printListOfInterests()
{
    for(set<string>::iterator i = interests.begin(); i != interests.end(); i++)
    {
        cout << *i << ", ";
    }
    cout << endl;   
}
bool person::isTakingClass(string className)
{
    for(size_t c = 0; c < classes.size(); c++)
    {
        if(classes[c] == className)
            return true;
    }
    return false;
}
void person::printListOfClasses()
{
    cout << "Classes: ";
    for(size_t c = 0; c < classes.size(); c++)
    {
        cout << classes[c] << ", ";
    }
    cout << endl;
}
void person::printEVERYTHING()
{
    cout << "Full name: " << getName() << endl;
    printStats();
    printListOfFamilyMembers();
    printListOfInterests();
    printListOfClasses();
}

//dumb but i guess important: activating a member function of a class
//object_name.memberFunction(parameter1, parameter2); parameters are also
//called arguments of the member function 

/*
ic:
    void setFirstName(string fname);
    void setLastName(string lname);
    void setAge(int age);
    void setGrades (int grades);
    void setIq(int iq);
    void setMajor(string major);
    void addFamilyMember(string name, string relation);
    void addInterest (string interest);
    void addClass (string className);

    string getName();
    void printStats();
    string getFamilyMember(string relation);
    void printListOfInterests();
    void printListOfFamilyMembers();
    void printListOfClasses();
    void printEVERYTHING();
    bool isTakingClass(string className);
    */

//two ways of overloading an operator (non member functions)
//method1
/*
person operator+(const person& p1, const person& p2)
{
    person p3;
    p3.setFirstName(p1.getName() + " and");
    p3.setLastName(p2.getName());
    return p3;
}
*/
//method 2 (after the end of this comment)

/*
   - Variables declared in ( int main() { ... } ) are considered to be local
   - Variables declared outside of (int main () { ... }), usually before it,
     considered to be global
        - For ex:
            int i = 1; //global
            int main()
            {
                int i = 6; //local
                cout << i << endl;
            }

*/
person person::operator+(const person& p1) const
{
    person p2;
    p2.first_name = this->first_name;
    p2.last_name = p1.last_name;
    p2.age = p1.age + this->age;
    p2.grades = p1.grades + this->grades;
    p2.iq = p1.iq + this->iq;
    p2.major = p1.major + " and " + this->major;
    return p2;
}
bool person::operator==(const person& p1) const
{
    if(this->first_name == p1.first_name)
    {
        if(this->last_name == p1.last_name)
        {
            return true;
        }
    }
    return false;
    
}
//overloaded operators, like member functions, can utilize previosly
//implemented overloaded operators
bool person::operator!=(const person& p1) const
{
    if(*this == p1)
    {
        return false;
    }
    return true;
}
//Kinda important: (this) is a pointer

//IMPORTANT AF: when using constant parameters, the functions called must
//ALSO be const (for person, getName() had to be const for the const
//parameter p1 object to use the getName() function)
//ex: can be found in the method1 operator+ 

//ALSO IMPORTANT AF: const functions are not allowed to make modificiations
//to the object they are being called on 

int main()
{
    person idol;
    idol.setFirstName("Super");
    idol.setLastName("Guy");
    idol.setAge(69);
    idol.setGrades(100);
    idol.setIq(100000);
    idol.setMajor("Computer Science");
    idol.addClass("Intro to Russian Hacking");
    idol.addClass("Discrete Fapping");
    idol.addClass("Brute Force Programming");
    idol.addClass("Watching Mr.Robot");
    idol.addFamilyMember("Marie Estime", "Mum");
    idol.addFamilyMember("Douchy Fuckface", "Dad");
    idol.addFamilyMember("Lord Dork", "Little Brother");
    idol.addFamilyMember("Karnovsky", "Older Brother");
    idol.addInterest("Figure Skating");
    idol.addInterest("Scuba Diving");
    idol.addInterest("Being an absolute legend");
    idol.printEVERYTHING();

    //person(string fname, string lname, int age, int grades, int iq, string major)
    person peasant("Common", "Begger", 20, 6, 20, "Homelessness");
    cout << endl << "Full Name: " << peasant.getName() << endl;
    peasant.printStats();

    person noone("No", "One");
    cout << endl << "Full Name: " << noone.getName() << endl;
    noone.printStats();

    //when activating default constructor, DO NOT INCLUDE PARENTHESES, like the
    //nobody object below
    person nobody;
    nobody.setFirstName("Nobody");
    cout << endl << "Full Name: " << nobody.getName() << endl;
    nobody.printStats();

    person mystery = noone + nobody;
    cout << endl << "Full Name: " << mystery.getName() << endl;
    mystery.printStats();

    person newPerson = idol + peasant;
    cout << endl << newPerson.getName() << endl;
    newPerson.printStats();

    cout << endl << "Is idol equal to idol + peasant?"<< endl;
    if(peasant == (idol + peasant))
    {
        cout << "Yep :)" << endl;
    }
    else
    {
        cout << "Nope :(" << endl;
    }

    cout << endl << "Is idol NOT equal to idol + peasant?" << endl;
    if(idol != idol + peasant)
    {
        cout << "Yep :)" << endl;    
    }
    else
    {
        cout << "Nope :(" << endl;
    }
    //idol and peasant are objects of the person class (should be obv at this 
    //point)
}