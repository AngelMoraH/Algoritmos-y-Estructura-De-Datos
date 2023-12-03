#include "circulararray.h"

template <class T>
class Stack : public CircularArray<T>
{
public:
    Stack(int _capacity = 8) : CircularArray<T>(_capacity) {}
    virtual ~Stack() {}

    void push(T data) { this->push_back(data); }
    T pop() { return this->pop_back(); }
    T& display() { return (*this)[this->size() - 1]; }
};