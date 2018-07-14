#include<cstdlib>
#include"complex.h"


#ifndef bag_h
#define bag_h

namespace anthony_bravo {

    class bag {
    public:
        //Type defs and static
        typedef int value_type;
        typedef size_t size_type;
        const static size_type DEFAULT_CAPACITY = 30;
        
        //Cosntructor and Destructor
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag();
        
        //Modification Member Fucntions
        void reserve(size_type new_capacity);
        void insert(const value_type& entry);
        bool erase_one(const value_type& target);
        size_type erase(const value_type& target);
        void operator+=(const bag& source);
        void operator=(const bag&source);
        
        //Constant Member Functions
        size_type size() const;
        size_type count(const value_type& target) const;
        
    private:
        value_type* data;
        size_type used;
        size_type capacity;
        
    };
    //Non-Member Functions
    bag operator+(const bag& b1,const bag& b2);
    
}


#endif
