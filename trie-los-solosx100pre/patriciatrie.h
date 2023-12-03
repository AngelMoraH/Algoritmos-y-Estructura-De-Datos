#pragma once
#include <iostream>
#include <list>
#include <map>
#include "trie.h"
using namespace std;

class TriePatricia : public Trie
{
private:
    struct TrieNode
    {
        // opcion 1:   TrieNode **children;
        // opcion 2:   list<pair<char, TrieNode*>> children;
        // opcion 3:   map<pair<char, TrieNode*>> children;
        TrieNode **children;
        string preffix;
        bool endWord; // indica si es final de una palabra

        TrieNode();
        ~TrieNode();
    };
    TrieNode *root;

public:
    TriePatricia() : root(nullptr) {}

    void insert(string key);
    bool search(string key);
    void remove(string key);

    // imprime ordenado
    string toString(string sep);
};
