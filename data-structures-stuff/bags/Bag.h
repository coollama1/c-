#include<cstdlib>


#ifndef Bag_h
#define Bag_h

namespace anthony_Bravo {
    
    class Bag {
        
    public:
        typedef int value_type;
        typedef size_t size_type;
        static const size_t CAPACITY = 20;
    
        //Modifications
        Bag();
        void insert(const value_type& input);
        bool eraseOne(const value_type& target);
        size_type erase(const value_type& target);
        void operator+=(const Bag& addend);
        
        //Cosntant member functions
        size_type size()const;
        size_type count(const value_type& target)const;
        
        //Friend Function
        friend Bag operator-(const Bag& b1,const Bag& b2);
    
    private:
        value_type data[CAPACITY];
        size_type used;
    };
    
    //Non-Member Functions
    Bag operator+(const Bag& b1, const Bag& b2);
    
}

#endif









