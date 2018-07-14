#include "bag.h"
#include <algorithm>

using namespace std;

namespace anthony_bravo {
    const bag::size_type bag::DEFAULT_CAPACITY;
    
    //constructor
    bag::bag(size_type initial_capacity) {
        data = new value_type[initial_capacity];
        used = 0;
        capacity = initial_capacity;
    }
    
    //copy constructor
    bag::bag(const bag& source) {
        data = new value_type[source.capacity];
        used = source.used;
        capacity = source.capacity;
    }
    
    //Destructor (deletes the whole array)
    bag::~bag() {
        delete [] data;
    }
    
    //Reserve Capacity Member Functions
    void bag::reserve(size_type new_capacity) {
        if(new_capacity == capacity) {
            return;
        }
        if(new_capacity < used) { //You cant shrink the array smaller than what you are using
            new_capacity = used;
        }
        value_type* new_data = new value_type[new_capacity];
        copy(data,data+used,new_data);
        delete [] data; //deletes array data was pointing to
        data = new_data;
        capacity = new_capacity;
    }
    
    //Insert Member Function
    void bag::insert(const value_type& entry) {
        if(used==capacity) {
            reserve(used+1);
        }
        data[used] = entry;
        used++;
    }
    
    //Erase One member Function
    bool bag::erase_one(const value_type& target) {
        size_t index;
        for(index = 0;index<used;index++) {
            if(data[index] == target) {
                break;
            }
        }
        if(index == used) { //We searched the whole array
            return false;
        }
        used--;
        data[index] = data[used]; //Move last element to the index found
        return true;
    }
    
    //Erase Member Function
    bag::size_type bag::erase(const value_type& target) {
        size_t times = count(target);
        for(int i=0;i<times;i++){
            erase_one(target);
        }
        return times;
    }
    
    //Overload operator +=
    void bag::operator+=(const bag& source) {
        if(used+source.used > capacity) {
            reserve(used+source.used); //Note: we could use reserved
        }
        copy(source.data,source.data+used,data+used);
        used += source.used;
    }
    
    //Overoad operator =
    void bag::operator=(const bag& source) {
        if(this == &source) { //pointer to object = adress of object
            return;
        }
        if(capacity!=source.capacity) { //Note: we cant use reserved
            value_type* temp = new value_type[source.capacity];
            delete []data;
            data = temp;
            capacity = source.capacity;
        }
        copy(source.data,source.data+used,data);
        used = source.used;
    }
    
    //Size Function
    bag::size_type bag::size()const {
        return used;
    }
    
    //Count Function
    bag::size_type bag::count(const value_type& target)const {
        size_t answer = 0;
        size_t index = 0;
        for(index = 0;index<used;index++) {
            if(data[index]==target) {
                answer++;
            }
        }
        return answer;
    }
    
    //Non-Member Function
    bag operator+(const bag& b1, const bag& b2) {
        bag b3(b1.size()+b2.size());
        b3 += b1;
        b3 += b2;
        return b3;
    }
    
}
