#include <iostream>

using namespace std;

class Pila{
    private:
        int top;
        int size;
        string *pila;
    public:
        Pila(int size);
        ~Pila();
        string push(string value);
        string pop();
        string peek();
        bool isEmpty();
        bool isFull();
        void print();
};

Pila::Pila(int size){
    this->size = size;
    this->top = -1;
    this->pila = new string[this->size];
}

Pila::~Pila(){
    delete[] this->pila;
}

string Pila::push(string value){
    if(!this->isFull()){
        this->top++;
        this->pila[this->top] = value;
        return this->pila[this->top];
    }
    return "";
}

string Pila::pop(){
    if(!this->isEmpty()){
        string value = this->pila[this->top];
        this->top--;
        return value;
    }
    return "";
}

string Pila::peek(){
    if(!this->isEmpty()){
        return this->pila[this->top];
    }
    return "";
}

bool Pila::isEmpty(){
    return this->top == -1;
}

bool Pila::isFull(){
    return this->top == this->size - 1;
}

void Pila::print(){
    for(int i=0; i<=this->top; i++){
        cout << this->pila[i] << " ";
    }
    cout << endl;
}
