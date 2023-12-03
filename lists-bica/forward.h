#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        struct Node {
            T data;
            Node* next;

            Node(){ 
                this->next = nullptr;
            }

            Node(T value){
                this->data = value;
                this->next = nullptr;
            }

            void killSelf(){
                // TODO    
                delete next;
                next=nullptr;  
            }    
        };

    private:
        Node* head;
        int nodes;

    public:
        ForwardList() : List<T>() {
            this->head = nullptr;
            this->nodes = 0;
        }

        ~ForwardList(){ 
         	// TODO 
        }

        T front(){
            return this->head->data;
        }

        T back(){
            Node* temp = this->head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            return temp->data;
        }

        void push_front(T data){
            if (this->head == nullptr){
                this->head = new Node(data);
                nodes++;
            }else{
                Node* nodo = new Node(data);
                nodo->next = this->head;
                this->head = nodo;
                nodes++;
            }
            
        }

        void push_back(T data){
            if (this->head == nullptr){
                this->head = new Node(data);
                nodes++;
            }else{
                Node* nodo = new Node(data);
                Node* temp = this->head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = nodo;
                nodes++;
            }
        }

        T pop_front(){
            if (is_empty()) {
                throw "List is empty";
            }
            Node* temp = this->head;
            this->head = this->head->next;
            T res = temp->data;
            delete temp;
            nodes--;
            return res;
        }

        T pop_back(){
            if (is_empty()) {
                throw "List is empty";
            }
            Node* temp = this->head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            T res = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            nodes--;
            return res;
            
        }

        T insert(T data, int pos){
            Node *nodo = new Node(data);
            Node *temp = this->head;
            for (int i = 0; i < pos - 1; i++){
                temp = temp->next;
            }
            nodo->next = temp->next;
            temp->next = nodo;
            nodes++;
            return nodo->data;
        }

        bool remove(int pos){
            Node* temp = this->head;
            for (int i = 0; i < pos - 1; i++){
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            nodes--;
            return true;
        }

        T& operator[](int pos){
            Node* temp = this->head;
            for (int i = 0; i < pos; i++){
                temp = temp->next;
            }
            return temp->data;
        }

        bool is_empty(){
            return nodes==0;
        }

        int size(){
            return this->nodes;
        }

        void clear(){
            while(this->head != nullptr){
                Node* temp = this->head;
                this->head = this->head->next;
                delete temp;
                this->nodes--;
            }
        }
        
        void sort(){
            for (int i = 0; i < this->size(); i++){
                for (int j = 0; j < this->size() - 1; j++){
                    if (this->operator[](j) > this->operator[](j+1)){
                        T temp = this->operator[](j);
                        this->operator[](j) = this->operator[](j+1);
                        this->operator[](j+1) = temp;
                    }
                }
            }
        }

        bool is_sorted(){
            Node *temp = this->head;
            while(temp->next != nullptr){
                if (temp->data > temp->next->data){
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }

        void reverse(){
            T *arr = new T[nodes];
            Node *temp = this->head;
            if(nodes%2==0){
                for (int i = 0; i < nodes/2; i++){
                    arr[i]=this->operator[](nodes-i-1);
                    arr[nodes-i-1] = this->operator[](i);
                }

                for (int i = 0; i <nodes/2; i++){
                    temp->data = arr[i];
                    temp = temp->next;
                }
                for (int i = nodes/2; i <nodes; i++){
                    temp->data = arr[i];
                    temp = temp->next;
                }

            }else{
                for (int i = 0; i < (nodes-1)/2; i++){
                    arr[i]=this->operator[](nodes-i-1);
                    arr[nodes-i-1] = this->operator[](i);
                }
                arr[(nodes-1)/2] = this->operator[]((nodes-1)/2);

                for (int i = 0; i <(nodes-1)/2; i++){
                    temp->data = arr[i];
                    temp = temp->next;
                }
                for (int i = nodes/2; i <nodes; i++){
                    temp->data = arr[i];
                    temp = temp->next;
                }
            }

            delete [] arr;
            delete temp;
            arr=nullptr;
            temp=nullptr;
        }

        std::string name(){
            return "ForwardList";
        }
        
};

#endif