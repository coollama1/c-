
#include <iostream>
using namespace std;

int main ()
{
    int count = 0;
    for(int a0 = 0; a0 <= 1; a0++)
    {
        for(int a1 = 0; a1 <= 1; a1++)
        {
            for(int a2 = 0; a2 <= 1; a2++)
            {
                cout << a0 << a1 << a2;
                count = 0;
                for(int b0 = 0; b0 <= 1; b0++)
                {
                    for(int b1 = 0; b1 <= 1; b1++)
                    {
                        for(int b2 = 0; b2 <= 1; b2++)
                        {
                            if(count == 0)
                            {
                                cout << "\t" << b0 << b1 << b2 << endl;
                                count++;
                            }
                            else
                            {
                                cout << "   \t" << b0 << b1 << b2 <<endl;
                            }
                        }
                        
                    }
                    
                }

            }
        }
    }
}