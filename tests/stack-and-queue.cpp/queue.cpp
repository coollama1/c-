#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue <int> order;
    int input;
    cout << "Enter some numbers and I will keep track of them for you" << endl;
    while(cin >> input)
    {
        order.push(input);
    }

    cout << "These are the stats of your queue:\nFront: " << order.front();
    cout << "\tBack: " << order.back() << "\nSize: " << order.size();
    cout << "\t\tEmpty: "; 
    if(order.empty())
    {
        cout << "True" << endl;
    } 
    else
    {
        cout << "False" << endl;
    }

    cout << "Now I will regurgitate the elements back to you" << endl;
    while(!order.empty())
    {
        cout << order.front() << endl;
        order.pop();
    }
}
//queue functionality: first element pushed in is the first element poped out

//queue functions are similar to stack, except:
//front() - returns the first element pushed into the queue
//back() - returns the last element pushed into the queue
//pop() - removes the first element at the front of the queue