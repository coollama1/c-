#include <iostream>
#include <string>
using namespace std;

int main()
{
    typedef string new_data_type; //every occurence of new_data_type is replaced with (string)
                                 //or any other data-type provided
                                //ex: typedef int new_data_type; //all occurences of
                               //new_data_type are replaced with (int)
    
    new_data_type i;
    extremely_new_data_type j;
    cout << "Enter something" << endl;
    getline(cin,i);
    cout << "The object you entered is: " << i << endl;
}