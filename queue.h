#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
    
     public:
        QueueArray(){
            QueueArray(0);
        }
        QueueArray(int capacity){
            this->array = new T[capacity];
            this->capacity = capacity;
            this->size = 0;
        }
        void enqueue(T data){

            push_back(data);

        }
        void dequeue(){

            pop_front();
        }
    
};
