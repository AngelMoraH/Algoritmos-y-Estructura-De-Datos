#ifndef MAX_HEAP
#define MAX_HEAP

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class MaxHeap
{

private:
    vector<T> elements;
    int n;

public:

    MaxHeap()
    {
        n = 0;
    }

    ~MaxHeap()
    {
    }

    int size()
    {
        return n;
    }

    bool is_empty()
    {
        return (n == 0);
    }

    void push(T value)
    {
        n++;
        elements.push_back(value);

        heapify_up(size() - 1);
    }

    void pop()
    {
        if (is_empty())
        {
            return;
        }

        elements[0] = elements[size() - 1];

        elements.pop_back();
        n--;

        heapify_down(0);
    }

    T top()
    {
        return elements[0];
    }

private:
    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    int Left(int i)
    {
        return (2 * i + 1);
    }

    int Right(int i)
    {
        return (2 * i + 2);
    }

    void heapify_down(int i)
    {
      T mayor = i;
      T izquierdo = Left(i);
      T derecho = Right(i);

      if (izquierdo < size() && (elements[izquierdo]) > (elements[mayor]))
      {
          mayor = izquierdo;
      }
      if (derecho < size() && (elements[derecho]) > (elements[mayor]))
      {
          mayor = derecho;
      }

      if (mayor != i)
      {
          swap(elements[i], elements[mayor]);
          heapify_down(mayor);
      }
    }

    void heapify_up(int i)
    {
      T menor = i;
      T padre = Parent(i);

      if (padre >= 0 && elements[i] > elements[padre])
      {
          menor = padre;
      }

      if (menor != i)
      {
          swap(elements[i], elements[padre]);
          heapify_up(menor);
      }
    }
};

#endif
