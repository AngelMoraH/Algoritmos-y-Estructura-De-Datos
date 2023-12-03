#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
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
                if (next != nullptr) {
                    next->killSelf();
                }
                delete this;     
            }    
        };

    private:
        Node* head;//sentinel
        int nodes; 

    public:
        CircularList() : List<T>() { 
            this->head = new Node();
            this->head->next = head;
            this->head->prev = head;
            this->nodes = 0;
        }

        ~CircularList(){
           // TODO
        }       

        T front(){
            if (is_empty()) {
            throw "List esta vacio";
        }
        return head->next->data;
        }

        T back(){
            if (is_empty()) {
            throw "List esta vacio";
        }
        return head->prev->data;
        }

        void push_front(T data){
            Node* new_node = new Node(data);
            if (is_empty()) {
                new_node->prev=head;
                new_node->next=head;
                head->next=new_node;
                head->prev=new_node;
            } 
            else {
                new_node->prev = head;
                new_node->next = head->next;
                head->next->prev = new_node;
                head->next = new_node;
            }
            nodes++;
        }

        void push_back(T data){
            Node* new_node = new Node(data);
            if (is_empty()) {
                new_node->prev=head;
                new_node->next=head;
                head->next=new_node;
                head->prev=new_node;
            } 
            else {
                new_node->prev = head->prev;
                new_node->next = head;
                head->prev->next = new_node;
                head->prev = new_node;
            }
            nodes++;
        }

        T pop_front(){
            if (is_empty()) {
            throw "List esta vacia";
            }
            Node* temp = head->next;
            T data = temp->data;
            
            if (nodes == 1) {
                head->next = head;
            } 
            else {
                head->next = temp->next;
                head->next->prev = head;
            }
            delete temp;
            temp = nullptr;
            nodes--;
            return data;
        }

        T pop_back() {
            if (is_empty()) {
                throw "List is empty";
            }
            T data = head->prev->data;
            head->prev = head->prev->prev;
            head->prev->next = head;
            nodes--;
            return data;
        }

        T insert(T data, int pos) {
            if (pos < 0 || pos > nodes) {
                throw "Invalid position";
            }
            if (pos == 0) {
                push_front(data);
                return data;
            } else if (pos == nodes) {
                push_back(data);
                return data;
            } else {
                Node* current = head;
                for (int i = 0; i < pos - 1; i++) {
                    current = current->next;
                }
                Node* new_node = new Node(data);
                new_node->next = current->next;
                new_node->prev = current;
                current->next->prev = new_node;
                current->next = new_node;
                nodes++;
                return data;
            }
        }

        bool remove(int pos) {
            if (pos < 0 || pos >= nodes) {
                return false;
            }
            Node* current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next;
            }
            if (nodes == 1) {
                head = nullptr;
            } else {
                if (current == head) {
                    head = current->next;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            nodes--;
            return true;
        }


        bool is_empty(){
            if(nodes==0){return true;}
            else{return false;}
        }

        T& operator[](int pos) {
        if (pos < 0 || pos >= nodes) {
            throw "Invalid position";
        }
        Node* current = head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }

        int size() {
            return nodes;
        }

        void clear() {
            while (nodes>0){
                pop_front();
            }
            
        }

        void sort() {
            if (head->next == head || head->next->next == head) {
                throw "List is empty";
            }
            Node* current = head->next;
            while (current != head) {
                Node* temp = current->next;
                while (temp != head) {
                    if (current->data > temp->data) {
                        T data = current->data;
                        current->data = temp->data;
                        temp->data = data;
                    }
                    temp = temp->next;
                }
                current = current->next;
            }

        }

        bool is_sorted() {
            Node* temp=head->next;
            for(int i=0;i<nodes-1;i++){
                if(temp->data>temp->next->data){
                    return false;
                }
                temp=temp->next;
            }
            return true;
        }

        void reverse() {
            if (nodes > 1) {
                Node* current = head;
                do {
                    Node* temp = current->next;
                    current->next = current->prev;
                    current->prev = temp;
                    current = temp;
                } while (current != head);
                head = head->prev;
            }
        }

        std::string name() {
            return "CircularList";
        }
};

#endif