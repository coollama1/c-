//Marvin Estime
//March 25, 2018

#include "sequence.h"
#include <cstdlib>
#include <assert.h>
#include <iostream>

namespace main_savitch_3
{
    sequence::sequence()
    {
        used = 0; //starting from [0], used = the number of elements that occupy the array

        current_index = 0; //values of the data array can be accessed by data[index] 
                          //where index = current_index - 1
                         //current_index is 1 greater than actual index
    }

    void sequence::start()
    {
        if(used != 0)
            current_index = 1;//first element, [0] index = current_index - 1
    }

    void sequence::advance()
    {
        if(is_item())
        {
            if(current_index < used)
            {
                current_index++;
            }
            else
            {
                current_index = 0;
            }
        }
    }

    void sequence::insert(const value_type& entry)
    {
        if(size() < CAPACITY)
        {
            if(!is_item()) //special case for sequence, otherwise current_index is unchanged
            {             //current_index = 0 -> implies no current element
                current_index = 1; //first element = [0] index = current_index - 1
            }

            for(size_type c = size(); c > current_index - 1; c--) //starting from current_index to the
            {                                                    //final element, all elements are
                data[c] = data[c - 1];                          //shifted to the right by 1 position
            }
                 
                data[current_index - 1] = entry; //new entry is put in the current_index position:
                                                //current_index - 1

            used++; //used is incremented to account for the new element being added
        }
    }

    void sequence::attach(const value_type& entry)
    {
        if(size() < CAPACITY)
        {
            if(!is_item())
            {
                current_index = size(); //given that (current_index = 0) current_index is shifted to the
            }                          //final element

            for(size_type c = size(); c > current_index ; c--) //similar to the insert function
            {                                                        //except the [current_index - 1] element
                data[c] = data[c - 1];                              //is excluded
            }

            used++; 

            advance(); //adjust the current_index to the new position
                 
            data[current_index - 1] = entry; //inserting entry at the (current_index - 1) + 1 position, or
                                            //the (current_index)'th element 

        }
    }

    void sequence::remove_current()
    {
        if(is_item())
        {
            for(size_type c = current_index; c < size(); c++)
            {
                data[c - 1] = data[c];
            }
            if(current_index == size()) //if the current index is at the last position, then there is no
            {                          //longer any current item
                advance();
            }
            used--;
        }
    }

    sequence::size_type sequence::size() const
    {
        return used;
    }
    bool sequence::is_item() const
    {
        if(current_index == 0)
            return false;

        return true;
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return data[current_index - 1];
    }
}
/*
int main()
{
    sequence testing;
    testing.insert(3.5);
    testing.attach(3.6);
    testing.insert(3.55);
    testing.advance();
    testing.attach(3.7);
    testing.attach(3.8);
    testing.start();
    testing.advance();
    testing.advance();
    testing.advance();
    testing.advance();
    testing.advance();
    testing.remove_current();
    testing.start();
    
    while(testing.is_item())
    {
        std::cout << testing.current() << std::endl;
        testing.advance();
    }
    
    testing.start();
    while(testing.is_item())
    {
        testing.remove_current();
    }
    
    testing.start();
    if(!testing.is_item())
        std::cout << "Everything seems to be working fine :)" << std::endl;
    else
        std::cout << "Lol, more errors" << std::endl;

    return 0;
}
*/