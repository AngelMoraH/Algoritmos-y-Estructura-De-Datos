#include <iostream>

#include <chrono>
#include <ctime>
#include <random>

#include <cstdlib>
#include <algorithm>
#include <unistd.h>

#include <vector>
#include <unordered_set>

#include "simpletrie.h"
#include "patriciatrie.h"
#include "tester.h"

using namespace std;


string generateRandomWord(int length) {
    static random_device rd;
    static mt19937 generator(rd());

    string word;
    static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    uniform_int_distribution<int> distribution(0, alphabet.size() - 1);

    for (int i = 0; i < length; ++i) {
        char letter = alphabet[distribution(generator)];
        word += letter;
    }

    return word;
}

/*void testTrie(Trie *trie, vector<string> diccionario)
{
    for (string word : diccionario)
        trie->insert(word);
    ASSERT(trie->toString(" ") == "amiga amor amorcito amorfo rata roma romano romario rosario ", "The function insert is not working");
    ASSERT(trie->search("amor") == true, "The function search is not working");
    ASSERT(trie->search("rosa") == false, "The function search is not working");
    trie->remove("roma");
    trie->remove("amorfo");
    ASSERT(trie->toString(" ") == "amiga amor amorcito rata romano romario rosario ", "The function remove is not working");

}*/


void testTrie(Trie *trie, vector<string> diccionario, vector<string>& randomPicks)
{
    int res=0;
    for (string word : diccionario)
        trie->insert(word);
    cout << diccionario.size() << endl;

    for(int i=0;i<randomPicks.size();i++)
    {
        auto start = chrono::steady_clock::now();
        ASSERT(trie->search(randomPicks[i]) == true, "The function search is not working");
        auto end = chrono::steady_clock::now();

        cout << "Test numero " << i+1 << " en microsegundos : "
            << chrono::duration_cast<chrono::microseconds>(end - start).count()
            << "ms" << endl;
        
        cout << "-----------------------------------------------" << endl;
        res += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    cout << "Tiempo promedio de busqueda : " << res/randomPicks.size() << " microsegundos" << endl;
}


int main(){
    vector<string> diccionario;
    unordered_set<string> uniqueWords;
    vector<string> randomPicks;
    //Trie* patricia = new TriePatricia();

    static random_device rd;
    static mt19937 generator(rd());
    
    int numWords = 100000000;
    
    if(numWords != 100000000)
    {
        while(diccionario.size() < numWords)
        {
            int randLength = rand() % (4 - 14 + 1) + 4;
            string word = generateRandomWord(randLength);
        
            if(uniqueWords.insert(word).second) 
            {
                diccionario.push_back(word);
            }
        }
    }
    else
    {
        for(int i;i<numWords;i++){
            int randLength = rand () % (4 - 14 + 1) + 4;
            diccionario.push_back(generateRandomWord(randLength));
        }
    }
         
    vector<int> indices(diccionario.size());
    
    for(int i=0;i<indices.size();i++)
    {
        indices[i] = i;
    }

    shuffle(indices.begin(), indices.end(), generator);

    for(int i=0;i<5;i++)
    {
        randomPicks.push_back(diccionario[indices[i]]);
    }
    cout << "test simple : " << endl;
    testTrie(new TrieSimple(),diccionario, randomPicks);
    cout << "test patricia : " << endl; 
    //testTrie(patricia, diccionario, randomPicks);
    //delete patricia; 
    return 0;
}



/*
int main()
{
    vector<string> diccionario = {"romano", "roma", "romario", "rosario", "rata", "amor", "amorfo", "amorcito", "amiga"};

    testTrie(new TrieSimple(), diccionario);
    testTrie(new TriePatricia(), diccionario);
    return 0;
}*/

