#include <iostream>
#include <forward_list>
#include <functional>

using namespace std;

const float maxFillFactor = 0.4;
const int maxColision = 3;

template<typename TK, typename TV>
class ChainHash
{
public:    
    struct Entry{
        TK key;
        TV value; 
        Entry(TK k, TV v){
            this->key = k;
            this->value = v;
        }  
    };
private:    
    forward_list<Entry>* array; 
    int capacity;//tamanio del array
    int size;//cantidad total de elementos
    hash<TK> hasher;

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        array = new forward_list<Entry>[this->capacity];
    }

    
    
    void insert(TK key, TV value){        
        if(fillFactor() >= maxFillFactor) rehashing();
        int hashcode = hasher(key);
        int index = hashcode % capacity;        
        //TODO: validar repetidos
        array[index].push_front(Entry(key, value));
    }double fillFactor(){
        return this->size / (this->capacity * maxColision * 1.0);
    }

    TV find(TK key){
        //TODO
        int hashcode = hasher(key);
        int index = hashcode % capacity;
        for(auto it = array[index].begin(); it != array[index].end(); ++it){
            if((*it).key == key) return (*it).value;
        }
        throw "No existe";
    }

    void remove(TK key){
        //TODO
        int hashcode = hasher(key);
        int index = hashcode % capacity;
        for(auto it = array[index].begin(); it != array[index].end(); ++it){
            if((*it).key == key) {
                array[index].erase_after(it);
                return;
            }
        }
    }

    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return distance(array[i].begin(), array[i].end());
    }

    typename forward_list<Entry>::iterator begin(int i){
        return array[i].begin();
    }

    typename forward_list<Entry>::iterator end(int i){
        return array[i].end();
    }

    ~ChainHash(){
        //TODO
    }

private:
    void rehashing(){
         //TODO
    }

};