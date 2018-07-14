#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main ()
{
   stack <string> leStack; 
   string input;
   while(getline(cin,input))
   {
       leStack.push(input);
   }
   cout << "Here are the elements you entered, excluding the empty strings " << endl;
   string leTop = leStack.top();
   while(!leStack.empty())
   {
       if(leTop != "")
         cout << leTop << endl;
       leStack.pop();
       if(!leStack.empty())
           leTop = leStack.top();
   }
}
//stack functionality: last element pushed in is the first element popped out (like stacking
//objects on top of one another and  retrieving the objects from the top of the stack)

//stack functions
//pop() - remove the element at the top of the stack
//top() - returns the element at the top of the stack
//push(x) - adds object (x) into the stack (assuming the object is of the same type as the stack)
//empty() - returns true if there are no elements contained within the stack
//size() - returns the number of elements within the stack