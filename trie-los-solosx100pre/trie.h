#pragma once
#include <string>
using namespace std;

const unsigned ALPHA_SIZE = 26; // tamanio del alfabeto: letras minusculas

class Trie
{
public:
    virtual void insert(string key) = 0;
    virtual bool search(string key) = 0;
    virtual void remove(string key) = 0;        
    
    //imprime ordenado
    virtual string toString(string sep=",") = 0;
};
