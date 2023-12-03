#ifndef BTree_H
#define BTree_H
#include <iostream>
#include <cmath>
#include <string>
#include "node.h"

using namespace std;

template <typename TK>
class BTree
{
private:
    Node<TK> *root;
    int M; // grado u orden del arbol
    int n; // total de elementos en el arbol

public:
    BTree(int _M) : root(nullptr), M(_M) {}

    bool search(TK key)
    { // indica si se encuentra o no un elemento
        return search(this->root, key);
    }

    void insert(TK key)
    { // inserta un elemento
        // si esta vacio
        if (root == nullptr)
        {
            root = new Node<TK>(M);
            root->keys[0] = key;
            root->count++;
        }
        else
        { // con elementos
            if (root->count == M - 1 && root->leaf)
            { // lleno
                Node<TK> *parent = new Node<TK>(M);
                parent->leaf = false;
                parent->children[0] = root;
                parent->split(0);
                if (key > parent->keys[0])
                    insert(parent->children[1], key);
                else
                    insert(parent->children[0], key);
                root = parent;
            }
            else if (root->leaf)
            {
                int i = root->count - 1;
                while (i >= 0 && root->keys[i] > key)
                {
                    root->keys[i + 1] = root->keys[i];
                    i--;
                }
                root->keys[i + 1] = key;
                root->count++;
            }
            else
            {
                int i = root->count - 1;
                while (i >= 0 && root->keys[i] > key)
                {
                    i--;
                }

                if (root->children[i + 1]->count == M - 1)
                {
                    root->split(i + 1);
                    if (root->keys[i + 1] < key)
                    {
                        i++;
                    }
                }
                insert(root->children[i + 1], key);

                if (root->count == M)
                {
                    Node<TK> *parent = new Node<TK>(M);
                    parent->leaf = false;
                    parent->children[0] = root;

                    Node<TK> *brother = new Node<TK>(M);
                    brother->leaf = false;
                    brother->count = (M - 1) / 2; // 2

                    for (int i = 0; i < brother->count; ++i)
                        brother->keys[i] = root->keys[i + brother->count + 1 + (M + 1) % 2];

                    for (int i = 0; i < brother->count + 1; ++i)
                        brother->children[i] = root->children[i + brother->count + 1 + (M + 1) % 2];

                    root->count = M - 1 - brother->count;
                    parent->children[1] = brother;

                    parent->keys[0] = root->keys[M / 2];
                    parent->count++;

                    root = parent;
                }
            }
        }
    }

    void remove(TK key)
    { // elimina un elemento
        if (!search(key))
            throw("Given key does not exist in the tree");
        else
            remove(this->root, key);
    }

    int height()
    { // altura del arbol. Considerar altura 0 para arbol vacio
        return height(this->root);
    }
    string toString(const string &sep) // recorrido inorder
    {
        auto result = inOrder(this->root, sep);
        if (result != "")
            result.pop_back();
        if (sep.size()>1){
            result = result.substr(0, result.size() - 2);
        }

            
        return result;
    }

    TK minKey() // minimo valor de la llave en el arbol
    {
        return minKey(this->root);
    }
    TK maxKey() // maximo valor de la llave en el arbol
    {
        return maxKey(this->root);
    }

    void clear()
    { // eliminar todos lo elementos del arbol
        clear(this->root);
        this->root = nullptr;
    }

    int size()
    { // retorna el total de elementos insertados
        return size(this->root);
    }

    ~BTree() // liberar memoria
    {
        root->killSelf();
    }

private:
    void insert(Node<TK> *node, TK key)
    {
        if (node->leaf)
        { // es hoja
            int i = node->count - 1;
            while (i >= 0 && node->keys[i] > key)
            {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->count++;
        }

        else
        { // es interno
            int i = node->count - 1;
            while (i >= 0 && node->keys[i] > key)
                i--;
            if (node->children[i + 1]->count == M - 1)
            {
                node->split(i + 1);
                if (key > node->keys[i + 1])
                    i++;
            }
            insert(node->children[i + 1], key);
        }
    }
    void remove(Node<TK> *&node, TK key)
    {
        int i = 0;
        while (i < node->count && key > node->keys[i])
            i++;
        if (i < node->count && node->keys[i] == key){
            if (node->leaf){
                if (node->count > ceil(M / 2) - 1){
                    for (int j = i + 1; j < node->count; j++){
                        node->keys[j - 1] = node->keys[j];
                    }
                    node->count--;
                }
                else{
                    return;
                }
            }
            else{
                Node<TK> *pred = node->children[i];
                Node<TK> *succ = node->children[i + 1];

                if (pred->count >= ceil(M / 2)){
                    TK predKey = pred->keys[pred->count - 1];
                    remove(pred, predKey);
                    node->keys[i] = predKey;
                }
                else if (succ->count >= ceil(M / 2)){
                    TK succKey = succ->keys[0];
                    remove(succ, succKey);
                    node->keys[i] = succKey;
                }
                else{
                    pred->keys[pred->count] = key;
                    for (int j = 0; j < succ->count; j++){
                        pred->keys[pred->count + j + 1] = succ->keys[j];
                    }
                    for (int j = 0; j < succ->count + 1; j++){
                        pred->children[pred->count + j + 1] = succ->children[j];
                    }
                    pred->count += succ->count + 1;
                    node->count--;
                    for (int j = i + 1; j < node->count + 1; j++){
                        node->keys[j - 1] = node->keys[j];
                    }
                    for (int j = i + 2; j < node->count + 2; j++){
                        node->children[j - 1] = node->children[j];
                    }
                    remove(pred, key);
                }
            }
        }
        else{
            if (node->leaf){
                throw("Given key does not exist in the tree");
            }

            bool flag = (i == node->count);

            if (node->children[i]->count < ceil(M / 2)){
                if (i > 0 && node->children[i - 1]->count >= ceil(M / 2)){
                    Node<TK> *child = node->children[i];
                    Node<TK> *sibling = node->children[i - 1];
                    for (int j = child->count - 1; j >= 0; j--){
                        child->keys[j + 1] = child->keys[j];
                    }
                    if (!child->leaf){
                        for (int j = child->count; j >= 0; j--){
                            child->children[j + 1] = child->children[j];
                        }
                    }
                    child->keys[0] = node->keys[i - 1];
                    node->keys[i - 1] = sibling->keys[sibling->count - 1];
                    if (!child->leaf){
                        child->children[0] = sibling->children[sibling->count];
                    }

                    child->count++;
                    sibling->count--;
                }
                else if (i < node->count && node->children[i + 1]->count >= ceil(M / 2)){
                    Node<TK> *child = node->children[i];
                    Node<TK> *sibling = node->children[i + 1];
                    child->keys[child->count] = node->keys[i];
                    node->keys[i] = sibling->keys[0];
                    for (int j = 1; j < sibling->count; j++){
                        sibling->keys[j - 1] = sibling->keys[j];
                    }
                    if (!sibling->leaf){
                        for (int j = 1; j <= sibling->count; j++){
                            sibling->children[j - 1] = sibling->children[j];
                        }
                    }

                    child->count++;
                    sibling->count--;
                }
                else{
                    if (i > 0){
                        Node<TK> *child = node->children[i];
                        Node<TK> *sibling = node->children[i - 1];
                        sibling->keys[sibling->count] = node->keys[i - 1];
                        for (int j = 0; j < child->count; j++){
                            sibling->keys[sibling->count + j + 1] = child->keys[j];
                        }

                        if (!child->leaf){
                            for (int j = 0; j <= child->count; j++){
                                sibling->children[sibling->count + j + 1] = child->children[j];
                            }
                        }

                        sibling->count += child->count + 1;
                        for (int j = i; j < node->count - 1; j++){
                            node->keys[j - 1] = node->keys[j];
                        }
                        for (int j = i + 1; j < node->count; j++){
                            node->children[j - 1] = node->children[j];
                        }
                        node->count--;
                        delete child;
                    } else{
                        Node<TK> *child = node->children[i];
                        Node<TK> *sibling = node->children[i + 1];
                        child->keys[child->count] = node->keys[i];
                        for (int j = 0; j < sibling->count; j++){
                            child->keys[child->count + j + 1] = sibling->keys[j];
                        }
                        if (!child->leaf){
                            for (int j = 0; j <= sibling->count; j++){
                                child->children[child->count + j + 1] = sibling->children[j];
                            }
                        }

                        child->count += sibling->count + 1;
                        for (int j = i + 1; j < node->count - 1; j++){
                            node->keys[j - 1] = node->keys[j];
                        }

                        for (int j = i + 2; j < node->count; j++){
                            node->children[j - 1] = node->children[j];
                        }

                        node->count--;
                        delete sibling;
                    }
                }
            }
            remove(node->children[i], key);
        }
    }


    int height(Node<TK> *node)
    {
        if (node->leaf)
        {
            return 0;
        }
        else
        {
            return 1 + height(node->children[0]);
        }
    }

    bool search(Node<TK> *node, TK key)
    {

        bool flag = false;

        if (!node->leaf)
        {
            for (int i = 0; i < node->count; i++)
            {
                if (node->keys[i] == key)
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                int i = 0;

                for (; i < node->count; ++i)
                {
                    if (node->keys[i] > key)
                    {
                        flag = search(node->children[i], key);
                        break;
                    }
                }

                if (key > node->keys[i - 1])
                    flag = search(node->children[i], key);
            }
        }
        else
        {
            for (int i = 0; i < node->count; i++)
            {
                if (node->keys[i] == key)
                {
                    flag = true;
                    break;
                }
            }
        }

        return flag;
    }

    TK minKey(Node<TK> *node)
    {
        auto temp = node;

        while (!temp->leaf)
            temp = temp->children[0];

        return temp->keys[0];
    }

    TK maxKey(Node<TK> *node)
    {
        auto temp = node;

        while (!temp->leaf)
            temp = temp->children[temp->count];

        return temp->keys[temp->count - 1];
    }

    void clear(Node<TK> *node)
    {
        if (node->leaf)
            node->killSelf();
        else
        {
            for (int i = 0; i <= node->count; ++i)
                clear(node->children[i]);

            node->killSelf();
        }
    }

    int size(Node<TK> *node)
    {
        int result = 0;
        if (node->leaf)
            result += node->count;
        else
        {
            for (int i = 0; i <= node->count; ++i)
                result += size(node->children[i]);
            result += node->count;
        }

        return result;
    }

    string inOrder(Node<TK> *node, const string &sep)
    {
        string str = "";
        int i = 0;
        for (; i < node->count; ++i)
        {
            if (!node->leaf)
                str += inOrder(node->children[i], sep);
            str += to_string(node->keys[i]) + sep;
        }

        if (!node->leaf)
            str += inOrder(node->children[i], sep);

        return str;
    }
};

#endif
