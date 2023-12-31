#pragma once
#include "../encriptacion/SHA256.h"
#include "../estructuras/Listas_enlazadas/forward.h"
#include "Transaction.h"
#include <iostream>
#include <string>


using namespace std;

class Block{
public:

    int prev_index = 1;
    bool valid = true;
    int index{};
    size_t nonce{};
    string hash_code;
    string* prev_hash_code{};
    ForwardList<Transaction> transactions;

    void display_transactions(){
        cout << "   str1 | str2 | number | tiempo" << endl;
        for(int i = 1 ; i <= transactions.size() ; i++){
            cout << i << ") ";
            transactions[i].short_display();
        }
    }

    Block() = default;

    Block(int index, const ForwardList<Transaction>& transactions, string* prev_hash_code){
        this->index = index;
        this->transactions = transactions;
        this->prev_hash_code = prev_hash_code;
        this->hash_code = generate_hash_code();
        this->valid = true;
    }

    void insert_transactions(ForwardList<Transaction>& trans){
        for(int i = 1 ; i <= trans.size() ; i++){
            this->transactions.push_back(trans[i]);
        }
    }

    string generate_hash_code(){
        string transact;
        SHA256 crpto;
        for(int i=1; i<=transactions.size();i++){
            transact += transactions[i].get_data_as_string();
        }
        hash_code = crpto.generate_hash(to_string(this->index) + to_string(this->nonce) + transact + *(this->prev_hash_code)); 
        return hash_code;
    }

    string* get_hash_code(){
        return &(hash_code);
    }

    void update_(){
        string former_hash_code = this->hash_code;
        string new_hash_code = this->generate_hash_code();

        if(former_hash_code != new_hash_code)
            this->valid = false;
        this->hash_code = new_hash_code;
    }

    void update(const Block& new_block){
        string former_hash_code = this->hash_code;

        this->index = new_block.index;
        this->nonce = new_block.nonce;
        this->hash_code = new_block.hash_code;
        this->prev_hash_code = new_block.prev_hash_code;
        this->transactions = new_block.transactions;
        string new_hash_code = this->generate_hash_code();

        if(former_hash_code != new_hash_code)
            this->valid = false;
        this->hash_code = new_hash_code;
    }

    void set_nonce(size_t nonce_){
        this->nonce = nonce_;
    }

    bool proof_of_work(int difficulty) { // method: HashCash
        switch(difficulty){
            case 1:{
                return (this->generate_hash_code().substr(0, 1) == "0");
                break;
            }
            case 2:{
                return (this->generate_hash_code().substr(0, 2) == "00");
                break;
            }
            case 3:{
                return (this->generate_hash_code().substr(0, 3) == "000");
                break;
            }
            case 4:{
                return (this->generate_hash_code().substr(0, 4) == "0000");
                break;
            }
            default:{
                cout << "ERROR" << endl;
                return false;
            }
        }
    }

    void short_display(){
        cout << "       Index:              " << index << endl;
        cout << "       Transactions:       " << transactions.size() << endl;
        cout << "       Nonce:              " << nonce << endl;
        cout << "       Hash code:          " << hash_code << endl;
        cout << "       Prev. hash code:    " << *prev_hash_code << endl;
        cout << "       valid:              " << int(valid) << endl;
    }
};