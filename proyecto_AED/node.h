#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node()
    {
        // data;
        next = nullptr;
        prev = nullptr;
    }

    Node(T value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    void killSelf()
    {
        delete this;
    }
};
