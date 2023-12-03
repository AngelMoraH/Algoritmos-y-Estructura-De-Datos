#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;

public:
    CircularArray(int _capacity = 10); // listo
    virtual ~CircularArray();          // listo
    void push_front(T data);           // listo
    void push_back(T data);            // listo
    void insert(T data, int pos);
    T pop_front();      // listo
    T pop_back();       // listo
    bool is_full();     // listo
    bool is_empty();    // listo
    int size();         // listo
    void clear();       // listo
    T &operator[](int); // listo
    void sort();
    bool is_sorted();                   // listo
    T reverse();                        // listo
    string to_string(string sep = " "); // listo
    T MAX();
    void print();
private:
    int next(int); // listo
    int prev(int); // listo
};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1; // empty
}

template <class T>
int CircularArray<T>::next(int pos)
{
    return (pos + 1) % this->capacity;
}

template <class T>
int CircularArray<T>::prev(int pos)
{
    return (pos - 1 + this->capacity) % this->capacity;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return (this->back == -1 && this->front == -1) ? true : false;
}

template <class T>
bool CircularArray<T>::is_full()
{

    return this->next(this->back) == this->front && this->front != -1 ? true : false;
}

template <class T>
int CircularArray<T>::size()
{
    if (this->is_empty())
    {
        return 0;
    }
    if (this->front == this->back && this->front == 0)
    {
        return 1;
    }
    return (this->front < this->back) ? this->back - this->front + 1 : (this->capacity - this->front) + (this->back + 1);
}

template <class T>
void CircularArray<T>::push_back(T data)
{
    this->back = this->next(this->back);
    if (this->front == -1)
    {
        this->front = this->back;
    }
    this->array[this->back] = data;
}

template <class T>
void CircularArray<T>::push_front(T data)
{
    this->front = this->prev(this->front);
    this->array[this->front] = data;
}
template <class T>
T CircularArray<T>::pop_front()
{
    if (is_empty()) {
        throw "CircularArray esta vacio";
    }
    T data = array[front];
    if (front == back)
    {
        front = back = -1;
    }
    else
    {
        front = next(front);
    }
    return data;
}
template <class T>
T CircularArray<T>::pop_back()
{
    if (is_empty()) {
        throw "CircularArray esta vacio";
    }
    T data = array[back];
    if (front == back)
    {
        front = back = -1;
    }
    else
    {
        back = prev(back);
    }
    return data;
}

template <class T>
T &CircularArray<T>::operator[](int pos)
{
    if (pos < 0 || pos >= size()) {
        throw "posicion fuera de rango";
    }
    int idx = (front + pos) % capacity;
    return array[idx];
}


template <class T>
T CircularArray<T>::MAX()
{
    T max = array[front];
    int temp=this->front;
    while (temp != this->back){
        if(array[temp] > max){
            max = array[temp];
        }
        temp = this->next(temp);
    }
    
    return max;
}

template <class T>
void CircularArray<T>::sort()
{
    int temp = front;
    T arr_num[capacity];
    T arr_count[this->MAX()+1];

    for (int i = 0; i < this->MAX()+1; i++){
        arr_count[i] = 0;
    }

    while (temp != this->back){
        arr_count[this->array[temp]] ++;
        temp = next(temp);
    }
    arr_count[array[temp]]++;
    temp = front;
    
    for (int i = 1; i < this->MAX()+1; i++){
        arr_count[i] += arr_count[i - 1];
    }
    
    for(int i=temp; i<=this->capacity-1;i++){
        arr_num[arr_count[this->array[i]]-1] = this->array[i];
        arr_count[this->array[i]] --;
    }
    for(int i=0;i<=this->back;i++){
        arr_num[arr_count[this->array[i]]-1] = this->array[i];
        arr_count[this->array[i]] --;
    }
    for(int i=0;i<this->capacity;i++){
        this->array[temp] = arr_num[i];
        temp = next(temp);
    }
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string output = "";

    for (int i = this->front; i <= this->capacity - 1; i++)
    {
        output += std::to_string(this->array[i]) + sep;
    }
    for (int i = 0; i <= this->back; i++)
    {
        output += std::to_string(this->array[i]) + sep;
    }

    return output;
}

template <class T>
T CircularArray<T>::reverse()
{
    T output[this->capacity];
    int temp= this->back;
    int j = 0;

    while (temp != this->front){
        output[j] = this->array[temp];
        temp = this->prev(temp);
        j++;
    }
    output[j] = this->array[temp];
    temp = this->front;
    for(int i=0;i<this->capacity;i++){
        this->array[temp] = output[i];
        temp = this->next(temp);
    }
    return *output;
}
template <class T>
void CircularArray<T>::insert(T data, int pos)
{
    if (is_full()) {
        int new_capacity = capacity * 2;
        T *new_array = new T[new_capacity];

        // Copio el viejo array al nuevo
        int j = 0;
        for (int i = front; i != back; i = next(i)) {
            new_array[j++] = array[i];
        }
        new_array[j++] = array[back];
        //actualizo el fron y back
        front = 0;
        back = j - 1;

        //libero el antiguo array y lo actualizo el puntero 
        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }
     // Mueve los elementos para hacer espacio para el nuevo elemento.
    if (is_empty()) {
        front = back = 0;
    } 
    else if (pos <= 0) {
        front = prev(front);
    } 
    else if (pos >= size()) {
        back = next(back);
    } 
    else {
        if (pos < size() / 2) {
            front = prev(front);
            for (int i = 0; i < pos - 1; i++) {
                array[prev(front)] = array[prev(prev(front))];
            }
        } else {
            back = next(back);
            for (int i = 0; i < size() - pos; i++) {
                array[next(back)] = array[next(next(back))];
            }
        }
    }

    array[pos] = data;
}
template <class T>
bool CircularArray<T>::is_sorted()
{
    for (int i = 0; i < this->size() - 1; i++)
    {
        if (this->array[i] > this->array[i + 1])
        {
            return false;
        }
    }
    return true;
}

template <class T>
void CircularArray<T>::clear()
{
    this->front = this->back = -1;
}
template <class T>
void CircularArray<T>::print() {
  for (int i = 0; i < size(); i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] this->array;
}