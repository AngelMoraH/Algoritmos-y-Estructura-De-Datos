#pragma once
#include <iostream>
#include "trie.h"
using namespace std;

class TrieSimple : public Trie
{
private:
    struct TrieNode
    {
        TrieNode **children;
        bool endWord; // indica si es final de una palabra

        TrieNode()
        {
            children = new TrieNode *[ALPHA_SIZE]; // Se reserva memoria para un arreglo de 26 punteros a TrieNode
            for (int i = 0; i < ALPHA_SIZE; ++i)
            {
                children[i] = nullptr; // Inicializar todos los punteros a nullptr
            }
            endWord = false;
        }

        ~TrieNode()
        {
            for (int i = 0; i < ALPHA_SIZE; ++i)
            {
                if (children[i])
                {
                    delete children[i]; // Liberar la memoria de los nodos hijos
                    children[i] = nullptr;
                }
            }
            delete[] children; // Liberar la memoria del arreglo de punteros
        }
    };

    TrieNode *root;

public:
    TrieSimple() : root(nullptr) {}

    void insert(string key) override
    {
        if (root == nullptr)
            root = new TrieNode();

        TrieNode *curr = root;

        for (char ch : key)
        {
            int index = ch - 'a'; // Encuentra la pocision donde colocar el caracter
            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->endWord = true;
    }

    bool search(string key) override
    {
        TrieNode *curr = root;
        for (char ch : key)
        {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
                return false;
            curr = curr->children[index];
        }

        if (curr->endWord)
            return true;

        return false;
    }

    void remove(string key) override
    {
        if (root == nullptr)
            return;

        TrieNode *curr = root;
        for (char ch : key)
        {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
                return;
            curr = curr->children[index];
        }
        curr->endWord = false;
    }

    // Imprime ordenado
    string toString(string sep) override
    {
        string result;
        toStringHelper(root, "", sep, result);
        return result;
    }

private:
    void toStringHelper(TrieNode *node, string currWord, string sep, string &result)
    {
        if (node == nullptr)
            return;

        if (node->endWord)
            result += currWord + sep;

        for (int i = 0; i < ALPHA_SIZE; ++i)
        {
            if (node->children[i] != nullptr)
            {
                char ch = 'a' + i;
                toStringHelper(node->children[i], currWord + ch, sep, result);
            }
        }
    }
};
