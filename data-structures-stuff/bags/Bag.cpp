#include "Bag.h"
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

namespace anthony_Bravo {
    
    const Bag::size_type Bag::CAPACITY;
    
    //constructor
    Bag::Bag() {
        used = 0;
    }
    
    //Insert Fucntion
    void Bag::insert(const value_type& input) {
        assert(used<CAPACITY);
        data[used] = input;
        used++;
    }
    
    //Erase One Function
    bool Bag::eraseOne(const value_type& target) {
        size_t index;
        for(index=0;index<used;index++) {
            if(data[index] == target) {
                break;
            }
        }
        if(index == used){
            return false;
        }
        used--;
        data[index] = data[used];
        return true;
    }
    
    //Erase Function
    Bag::size_type Bag::erase(const value_type& targert) {
        size_type times = count(targert);
        if(times==0) return 0;
        size_t index;
        for(index=0;index<times;index++) {
            eraseOne(targert);
        }
        return times;
    }
    
    //Operator += overload
    void Bag::operator+=(const Bag& addend) {
        assert(size()+addend.size() <= CAPACITY);
        copy(addend.data,addend.data + addend.used, data+used);
        used += addend.used;
    }
    
    //Size Function
    Bag::size_type Bag::size()const {
        return used;
    }
    
    //Count Function
    Bag::size_type Bag::count(const value_type& target)const {
        size_type answer = 0;
        for(int i=0;i<size();i++) {
            if(data[i] == target) {
                answer++;
            }
        }
        return answer;
    }
    
    //Non-Member operator+
    Bag operator+(const Bag& b1, const Bag& b2) {
        assert(b1.size()+b2.size() <= Bag::CAPACITY);
        Bag b3;
        b3 += b1;
        b3 += b2;
        return b3;
    }
    
    //Friend Function operator-
    Bag operator-(const Bag& b1, const Bag& b2) {
        Bag b3(b1);
        for(size_t i=0;i<b2.size();i++) {
            if(b3.count(b2.data[i]) !=0 ) {
                b3.eraseOne(b2.data[i]);
            }
        }
        return b3;
    }
}
