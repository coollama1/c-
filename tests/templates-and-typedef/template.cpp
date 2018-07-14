#include <iostream>
#include "min-and-max.template"
//using namespace std; // cannot be used when importing a template

//templates are used for functions, as eiher parameters or return types
//templates CANNOT be used whithin (int main()), however, template functions can be
//ex: (assuming: template <class thing>; is declared beforehand)
//valid:
/*
    int main()
    {
        thing<int>(a,b);
    }
*/
//invalid:
/*
    int main()
    {
        thing a, b;
    }
*/
//when using a template function, f<data_type>(a,b);, the data type included in (< >) 
//(in this case, data_type) replaces every occurence of the template (in other case, (thing))
//contents can be found in the (min-and-max.template) file

typedef int data_type;

int main()
{
    data_type a, b;
    std::cout << "Give me two integers and I will compare them" << std::endl;
    std::cin >> a >> b;
    std::cout << "The maximum is: " << max<data_type>(a,b) << " and the minimum is: " << min<data_type>(a,b) << std::endl;    
    print<data_type>(a,b);
}