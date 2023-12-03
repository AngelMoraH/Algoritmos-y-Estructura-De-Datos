#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename TK>
struct Node
{
    // array de keys
    TK *keys;
    // array de punteros a hijos
    Node **children;
    // cantidad de keys
    int count;
    // indicador de nodo hoja
    bool leaf;
    int M;

    Node() : keys(nullptr), children(nullptr), count(0) {}
    Node(int M)
    {
        keys = new TK[M - 1];
        children = new Node<TK> *[M];
        count = 0;
        leaf = true;
        this->M = M;
    }

    void killSelf()
    {
        // TODO
        delete[] this->keys;
        for (int i = 0; i < this->M; ++i)
            delete this->children[i];
        delete[] this->children;
        delete this;
    }

    void split(int child)
    {
        // TODO: dividir el hijo de la posicion "child"
        Node *son = children[child];
        Node *brother = new Node(M);
        brother->leaf = son->leaf;
        brother->count = (M - 1) / 2;

        for (int i = 0; i < brother->count; ++i)
            brother->keys[i] = son->keys[i + brother->count + (M + 1) % 2];

        if (!son->leaf)
            for (int i = 0; i < brother->count + 1; ++i)
                brother->children[i] = son->children[i + brother->count + (M + 1) % 2];

        son->count = M - 1 - brother->count - 1;

        for (int i = count; i >= child + 1; --i)
            children[i + 1] = children[i];

        children[child + 1] = brother;

        for (int i = count - 1; i >= child; --i)
            keys[i + 1] = keys[i];

        keys[child] = son->keys[M / 2 - 1];
        count++;
    }
};

#endif