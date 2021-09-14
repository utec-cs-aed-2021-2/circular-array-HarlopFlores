#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
    
    StackArray(){
        StackArray(0);
    }
    StackArray(int capacity){
        this->array = new T[capacity];
        this->capacity = capacity;

        this->size = 0;
    }

    void Stackpush(T data){

        push_back(data);
    }

    void Stackpop(){

        pop_back();
    }
    
    
};
