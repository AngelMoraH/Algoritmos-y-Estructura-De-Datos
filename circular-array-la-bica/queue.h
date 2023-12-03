#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T>{

public:
    QueueArray(int);
    void enqueue(T);
    void dequeue();
    ~QueueArray();
    
};

template <typename T>
QueueArray<T>::QueueArray(int _capacity=8) : CircularArray<T>(_capacity){}

template <typename T>
void QueueArray<T>::enqueue(T data){
    CircularArray<T>::push_back(data);
}

template <typename T>
void QueueArray<T>::dequeue(){
    CircularArray<T>::pop_front();
}

template <class T>
QueueArray<T>::~QueueArray(){
    delete[] this->array;
}