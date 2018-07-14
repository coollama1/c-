#include <iostream>
using std::cout;
using std::endl;

void sort(int a [], int size)
{
    int temp;
    for(int c = 0; c < size; c++)
    {
        for(int d = c + 1; d < size; d++)
        {
            if(a[c] > a[d])
            {
                temp = a[c];
                a[c] = a[d];
                a[d] = temp;
            }
        }
    }
}

void do_job(int length_of_job)
{
    for(int c = 0; c < length_of_job; c++)
    {
        cout << "0 ";
    }
    cout << endl;
}

int main()
{
    int list_of_jobs [] = {7, 3, 10, 5};
    sort(list_of_jobs, 4);
    for(int c = 0; c < 4; c++)
    {
        do_job(list_of_jobs[c]);
    }
}