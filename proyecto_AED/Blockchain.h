#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <string>
#include "Block.h"
#include "double.h"
#include "hash.h"
#include "MaxHeap.h"

using namespace std;
using namespace std::chrono;

class Blockchain
{
private:
    List<Block *> *chain = new DoubleList<Block *>();
    unsigned int size_chain = 0;

public:
    // Constructor
    Blockchain() {}
    
    //Hash
    Hash<string, string> *hash_amount = new Hash<string, string>();
    Hash<string, string> *hash_timestamp = new Hash<string, string>();
    
    //Max Heap
    MaxHeap<string> *maxheap_amount = new MaxHeap<string>();
    MaxHeap<string> *maxheap_timestamp = new MaxHeap<string>();


    // Metodos public
    void add_to_maxheaps(Block* new_block);
    void add_to_hash(Block* new_block);
    void addBlock(Transaction *data);
    void show_blockchain();
    void test_proof_work(int id);
    void fix_all();

    void Clear()
    {
        cout << "\x1B[2J\x1B[H";
    }

    void calculate_time(time_point<high_resolution_clock> start2, time_point<high_resolution_clock> end2){
        auto duration = duration_cast<milliseconds>(end2 - start2);
        cout << endl << "Time taken by program is : " << duration.count() << " milliseconds.";
        cout << " sec" << endl;
    }

    void ingrese_0_para_salir(){
        int F6;
        do{
            cout<<endl<< "Ingrese 0 para salir: ";
            cin>> F6;
            Clear();
        }while(F6 != 0);
    }


    void igual_a_x(){

        int opcion;
        bool repetir = true;
        do{
            Clear();
            cout << "\n\n        Choose an attribute: " << endl;
            cout << "--------------------"<<endl;
            cout << "1. Amount" << endl;
            cout << "2. tiempo" << endl;
            cout << "0. End" << endl;

            cout << "\nEnter an option: ";
            cin >> opcion;

            while(opcion != 0 and opcion != 1 and opcion != 2){
                cerr << endl << "Enter a valid option";
                cout << "\nEnter an option: ";
                cin >> opcion;
            }
            if (opcion == 0){
                repetir = false;
            } else {
                string x;
                Clear();
                cout << "\n\n        Choose a range: " << endl;
                cout << "--------------------"<<endl;
                cout << "\nEnter X: ";
                cin >> x;
                Clear();
                switch (opcion) {
                    case 1: {
                                auto start1 = chrono::high_resolution_clock::now();
                                bool found = hash_amount->find(x);
                                auto end1 = chrono::high_resolution_clock::now();
                                if(found){
                                    cout << "Bloque emisor: " << hash_amount->get(x) << endl;
                                } else {
                                    cout << "NOT FOUND!" << endl;
                                    return;
                                }
                                calculate_time(start1, end1);
                                ingrese_0_para_salir();
                                break;
                            }
                    case 2: {
                                auto start2 = chrono::high_resolution_clock::now();
                                bool found = this->hash_timestamp->find(x);
                                auto end2 = chrono::high_resolution_clock::now();
                                if(found){
                                   cout << "Bloque emisor: " << hash_amount->get(x) << endl; 
                                } else {
                                    cout << "NOT FOUND!" << endl;
                                    return;
                                }
                                calculate_time(start2, end2);
                                ingrese_0_para_salir();
                                break;
                            }
                    default: {
                                 cout << "opcion invalido." << endl;
                                 ingrese_0_para_salir();
                             }
                }
            }
        } while(repetir);
    }

    void max_valor()
    {
        int opcion;
        bool repetir = true;
        do
        {
            Clear();
            cout << "\n\n        Choose an attribute: " << endl;
            cout << "--------------------" << endl;
            cout << "1. amount" << endl;
            cout << "2. tiempo" << endl;
            cout << "0. End" << endl;

            cout << "\nEnter an option: ";
            cin >> opcion;

            while (opcion != 0 and opcion != 1 and opcion != 2)
            {
                cerr << endl
                     << "Enter a valid option";
                cout << "\nEnter an option: ";
                cin >> opcion;
            }

            if (opcion == 0)
            {
                repetir = false;
            }
            else
            {
                Clear();
                switch (opcion)
                {
                    case 1:
                    {
                        auto start1 = chrono::high_resolution_clock::now();
                        cout << this->maxheap_amount->get_value() << endl;
                        auto end1 = chrono::high_resolution_clock::now();
                        // Calculating total time taken by the program.
                        calculate_time(start1, end1);
                        ingrese_0_para_salir();
                        break;
                    }
                    case 2:
                    {
                        auto start1 = chrono::high_resolution_clock::now();
                        cout << this->maxheap_timestamp->get_value() << endl;
                        auto end1 = chrono::high_resolution_clock::now();
                        // Calculating total time taken by the program.
                        calculate_time(start1, end1);
                        ingrese_0_para_salir();
                        break;
                    }
                    default:
                        cout << "error in opcion " << endl;
                        ingrese_0_para_salir();
                        break;
                }
            }
        } while (repetir);
    }


};

void Blockchain::add_to_maxheaps(Block* new_block){
    maxheap_amount->push(new_block->get_amount());
    maxheap_timestamp->push(new_block->get_timestamp());
}

void Blockchain::add_to_hash(Block* new_block){
    hash_amount->insert(new_block->get_amount(),new_block->get_sender_key());
    hash_timestamp->insert(new_block->get_timestamp(),new_block->get_sender_key());
}

void Blockchain::addBlock(Transaction *data)
{
    if (this->chain->back() != nullptr)
    {
        Block *prev_block = this->chain->back();
        Block *new_block = new Block(data);
        string prev_hash = prev_block->get_hash();
        new_block->set_id(this->size_chain + 1, prev_hash);
        new_block->mine();
        this->chain->push_back(new_block);
        this->size_chain = this->chain->size();

        add_to_hash(new_block);
        add_to_maxheaps(new_block);
    }
    else
    {
        Block *new_block = new Block(data);
        new_block->set_id(this->size_chain + 1, "");
        new_block->mine();
        this->chain->push_back(new_block);
        this->size_chain = this->chain->size();

        add_to_hash(new_block);
        add_to_maxheaps(new_block);
    }
}

void Blockchain::show_blockchain()
{
    ListIterator<Block *> it;
    for (it = this->chain->begin(); it != this->chain->end(); ++it)
    {
        Block *currentBlock = *it;
        currentBlock->show_block_info();
    }
}

void Blockchain::test_proof_work(int id)
{
    int cont = 1;
    ListIterator<Block *> it;
    string hash_tmp;
    bool flag1 = false;
    bool flag2 = false;
    for (it = this->chain->begin(); it != this->chain->end(); ++it)
    {
        Block *currentBlock = *it;
        if (flag2 == true)
        {
            currentBlock->set_hash_prev(hash_tmp);
            currentBlock->mine();
        }
        if (flag1 == true)
        {
            currentBlock->set_hash_prev(hash_tmp);
        }
        if (cont == id)
        {
            string new_name;
            cout << endl
                 << "Ingrese nombre para el nuevo emisor: ";
            cin >> new_name;
            currentBlock->modify(new_name);
            cout << endl
                 << "Desea arreglar el blockChain? (0 o 1): ";
            bool fix;
            cin >> fix;
            if (fix == false)
            {
                flag1 = true;
            }
            else
            {
                currentBlock->mine();
                flag2 = true;
            }
        }
        hash_tmp = currentBlock->get_hash();
        cont++;
    }
}

void Blockchain::fix_all()
{
    ListIterator<Block *> it;
    string hash_tmp;
    for (it = this->chain->begin(); it != this->chain->end(); ++it)
    {
        Block *currentBlock = *it;
        if (currentBlock->get_validation() == false)
        {
            currentBlock->set_hash_prev(hash_tmp);
            currentBlock->mine();
        }
        hash_tmp = currentBlock->get_hash();
    }
}


#endif
