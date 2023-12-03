#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"


// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
        struct Node {
            T data;
            Node* next;
            Node* prev;

            Node(){ 
                this->data = 0;
                this->next = nullptr;
                this->prev = nullptr;
            }

            Node(T value){
                this->data = value;
                this->next = nullptr;
                this->prev = nullptr;
            }

            void killSelf(){
                // TODO      
            }    
        };

    private:
        Node* head;
        Node* tail;
        int nodes;

    public:
        DoubleList() : List<T>() {
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes = 0;
        }

        ~DoubleList(){ 
         	// TODO            
        }

         T front(){
            return this->head -> data;
        }

        T back(){
            return this->tail->data;
        }

        void push_front(T data){
            Node* nodo =new Node(data);
            nodo->prev=nullptr;
            nodo->next=nullptr;

            
            if(is_empty()){
                head=nodo;
                tail=head;
            }else{

                nodo->next=head;
                head->prev=nodo;
                head=nodo;
            }
            nodes++;
        }

        void push_back(T data){
            Node* nodo = new Node(data);
            Node* temp = head;
            nodo->prev=nullptr;
            nodo->next=nullptr;

            if(is_empty()){
                tail=head;
                head=nodo;   
            }else{
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nodo;

                nodo->next=nullptr;
                nodo->prev=tail;
                tail=nodo;
                
            }
            nodes++;
        }

        T pop_front(){
            if(head!=nullptr){
                Node* temp=head;
                head=head->next;
                if(head!=nullptr){
                    head->prev=nullptr;
                }
                nodes--;
                return temp->data;
            }

            return 0;
        }

        T pop_back(){
            if(tail!= nullptr){
                Node* temp=tail;
                tail=tail->prev;
                if(tail != nullptr) {
                    tail->next=nullptr;
                }

                nodes--;
                return temp->data;
            }

            return 0;
        }

        T insert(T data, int pos){
            Node* nodo = new Node(data);
            
            nodo->next = nullptr;
            nodo->prev = nullptr;
        
            if (pos == 1) {
                nodo->next = head;
                head->prev = nodo;
                head = nodo;
            }
            else {
                Node* temp = head;
                for (int i=0; i<pos-1; i++) {
                    if (temp != nullptr) {
                        temp = temp->next;
                    }
                }

                if (temp != nullptr) {
                    nodo->next = temp->next;
                    nodo->prev = temp;
                    temp->next = nodo;
                    if (nodo->next != nullptr) {
                        nodo->next->prev = nodo;
                    }
                }
                
            }
            nodes++;
            return 0 ;
        }

        bool remove(int pos){
            throw ("sin definir");
        }
 
        T& operator[](int pos){
            Node* temp = this->head ;

            for(int i = 0 ; i < pos ; i++){
                temp = temp -> next;
            }
            return temp -> data;
        }

        bool is_empty(){
            if (nodes==0){
                return true;
            }else{
                return false;
            }
        }

        int size(){
            return this->nodes;
        }

        void clear(){
            while(nodes!=0){
                pop_front();
            }
        }
        
        void sort(){
            Node* temp1 = head;
            Node* compnext = head;
            Node* compprev = head;
            Node* orgprev = head;
            Node* orgnext = head;
            Node* actComp = head;

            for(int i = 0; i < size(); i++){
                Node* temp2 = head;
                for(int k = 0; k < i; k++){
                    temp2 = temp2->next;
                }
                for(int j = i; j < size() - 1; j++){
                    if(j == size()-1){
                        actComp = temp2;
                    }
                    else{
                        if(temp2->next==nullptr){
                            actComp = temp2;
                        } else {
                            actComp = temp2->next;
                        }
                    }
                    if(actComp->data < temp1->data){
                        if(j == size()-1){compnext = nullptr;}
                        else {
                            if(temp2->next==nullptr){
                                compnext = nullptr;
                            } else {
                                compnext = temp2->next->next;
                            }
                        }
                        if(j != size()-1) compprev = temp2;
                        orgnext  = temp1->next;
                        if(compnext == nullptr){
                            if(temp1->next == actComp){
                                orgprev->next = actComp;
                                actComp->next = temp1;
                                temp1->next = nullptr;
                            } else {
                                if(temp2->next==nullptr){
                                    orgprev->next = actComp;
                                    actComp->next = orgnext;
                                    orgnext->next = temp1;
                                    temp1->next = nullptr;
                                } else {
                                    orgprev->next = actComp;
                                    actComp->next = orgnext;
                                    compprev->next = temp1;
                                    temp1->next = nullptr;
                                }
                            }
                        } else {
                            if(temp1->next == actComp){
                                if(actComp->next == nullptr){
                                }
                                orgprev->next = actComp;
                                actComp->next  = temp1;
                                temp1->next = compnext;
                            } else {
                                compprev->next = temp1;
                                temp1->next  = compnext;
                                orgprev->next = actComp;
                                actComp->next = orgnext;
                            }
                        }
                        temp1 = actComp;
                    }
                    compprev = temp2;
                    if(j != size()-1)temp2 = temp2->next;
                }
                orgprev = temp1;
                if(i + 1 != size()) {temp1 = temp1->next;}
            }
        }

        bool is_sorted(){
            Node* temp = head;

            while(temp->next!= nullptr){
                if(temp->data > (temp->next)->data){
                        return false;
                }
                temp=temp->next;
            }
            return true;
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "DoubleListt";
        }
        
};
#endif