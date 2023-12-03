#ifndef CRYPTOCHAIN_SIMPLETRIE_H
#define CRYPTOCHAIN_SIMPLETRIE_H

#include <iostream>
#include "../Listas_enlazadas/forward.h"
using namespace std;


const unsigned ALPHA_SIZE = 128; // ASCII

class TrieSimple
{
private:
    struct TrieNode
    {
        int index; 
        TrieNode **children;
        bool endWord; 

        TrieNode()
        {
            this->children = new TrieNode *[ALPHA_SIZE];
            for (int i = 0; i < ALPHA_SIZE; ++i)
                this->children[i] = nullptr;
            this->endWord = false;
        }
        void killSelf()
        {
            for (int i = 0; i < ALPHA_SIZE; ++i)
                delete this->children[i];
            delete[] this->children;
            delete this;
        }
    };

    TrieNode *root;

public:
    TrieSimple() : root(nullptr) {}

    void insert(int indice, string key)
    {
        if (this->root == nullptr)
            this->root = new TrieNode();
      
        TrieNode *node = this->root;
        int index;
      
        for (int i = 0; i < key.size(); i++)
        {
            
            index = key[i];
            if (node->children[index] == nullptr)
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->endWord = true;
        node->index = indice;
    }

    bool search(string key)
    {
        auto iter = this->root;
        int index = 0;
        for (int i = 0; i < key.size(); i++)
        {
            index = key[i] - 'a';
            if (iter->children[index] != nullptr && iter->children[index]->endWord)
                return true;
            iter = iter->children[index];
        }

        return false;
    }

    ForwardList<int> contained_in(string x){
        ForwardList<int> indices;
        ForwardList<string> strings;
        string estr;
        char str[20];
        display(strings, estr, root, str, 0);
        for(int i = 1 ; i <= strings.size() ; i++){
            if(match(x, strings[i])){
                indices.push_back(i);
            }
        }
      return indices;
    }

    bool match(string x, string y){
        int counter1 = 0;
        for(int i = 0 ; i < x.size() ; i++){
            while(y[counter1] == x[i]){
                if(counter1 == y.size() - 1){
                    return true;
                }
                counter1++;
            }
            counter1 = 0;
        }
        return true;
    }

    int* buildPositions(string patron){
        int* positions = new int[256];
        for(int i=0;i<256;i++) positions[i] = -1;
        for(int i=0;i<(int)patron.size();i++)
            positions[(int)patron[i]] = i;
        return positions;
    }


    void remove(string key)
    {
        if (!search(key))
            throw("Key doesn't exit in trie");
        remove(this->root, key, 0);
    }


    string toString(string sep)
    {
        return toString(this->root, sep, "");
    }

    void display(ForwardList<string>& strings, string& estr, TrieNode* root, char str[], int level)
    {
        if (root->endWord)
        {
            strings.push_back(estr);
            estr.clear();
        }
        for (int i = 0; i < ALPHA_SIZE; i++)
        {
            if (root->children[i])
            {
                str[level] = i;
                estr += i;
                display(strings, estr, root->children[i], str, level + 1);
            }
        }
    }

    ForwardList<int> starts_with(string str){
        ForwardList<int> rslt;

        auto iter = this->root;
        int index = 0;
        for (int i = 0; i < str.size(); i++)
        {
            index = str[i];
            if(iter->children[index] != nullptr)
                iter = iter->children[index];
        }
        diving(iter, rslt);
        return rslt;
    }

    void diving(TrieNode* iter, ForwardList<int>& result){
        if(iter->endWord){
            result.push_back(iter->index);
        }
        for (int i = 0; i < ALPHA_SIZE; i++)
        {
            if (iter->children[i] != nullptr)
                diving(iter->children[i], result);
        }
    }

private:

    string toString(TrieNode *node, string sep, string prefix)
    {
        if (node == nullptr)
            return "";
        string result = "";

        if (node->endWord)
            result += prefix + sep;

        for (int i = 0; i < ALPHA_SIZE; i++)
        {
            if (node->children[i] != nullptr)
                result += toString(node->children[i], sep,
                                   prefix + char('a' + i));
        }
        return result;
    }

    bool hasChildren(TrieNode *node)
    {
        if (node == nullptr)
            return false;
        for (int i = 0; i < ALPHA_SIZE; i++)
        {
            if (node->children[i] != nullptr)
                return true;
        }

        return false;
    }

    void remove(TrieNode *node, string key, int i)
    {
        if (i < key.size())
        {
            int index = key[i] - 'a';
            i++;
            remove(node->children[index], key, i);
        }

        if (node->endWord && i >= key.size())
        {
            node->endWord = false;

            if (!hasChildren(node))
            {
                node->killSelf();
                node = nullptr;
            }
        }
        else
        {
            if (!hasChildren(node))
            {
                node->killSelf();
                node = nullptr;
            }
        }
    }
};

#endif //CRYPTOCHAIN_SIMPLETRIE_H
