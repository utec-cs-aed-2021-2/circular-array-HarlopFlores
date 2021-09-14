#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:

    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();

    void push_front(T data){
    if(is_empty()) 
    front = back = 0;
    else
    front = prev(front);
    array[front] = data;
    }

    void push_back(T data){
    if(is_empty())
    front = back = 0;
    else
    back = next(back);
    array[back] = data;
    }

    void insert(T data, int pos);


    T pop_front(){
    T &temporal = array[front];
    if(back == front){
        front = back = -1;
        return temporal;
        }
    front = next(front);
    return temporal;
    }


    T pop_back(){
    T &temporal = array[back];
    if(back == front){
        front = back = -1;
        return temporal;
    }
    back = prev(back);
    return temporal;
    }


    bool is_full(){
        return front == next(back) && !is_empty();
    }
    bool is_empty(){
        return front == -1;
    }
    int size(){
        if(is_empty()) return 0;
    else
    return((capacity - front + back ) % capacity) +1;
    }
    void clear();


    T &operator[](int index){

    int temporal = front;
    for (int i=0; i<index; i++){
        temporal = next(temporal);
    }
    return array[temporal];
    }


    void sort(){
        
        T* tmp = new T[capacity];
        for (int i = 0; i < capacity; i++){
            tmp[i] = array[i];
        }
        
         delete[] array;
        array = tmp;

     int n = sizeof(tmp) / sizeof(tmp[0]);

        std::sort(tmp, tmp+n);


    }
    bool is_sorted(){

    bool sorted = true;
    for(int i=0; i<size(); i++){
        if(array[i] >= array[i+1]) sorted = false;
    }
    return sorted;
  }

    
    void reverse(){}
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
