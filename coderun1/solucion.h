#include <iostream>
using namespace std;

struct NodeF{
    int data;
    NodeF* next;
};

void display(NodeF* head){
    while (head != nullptr){
        cout<< head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

void sortedInsert(NodeF* &head, int value){
    if(head == nullptr){
        head = new NodeF();
        head->data = value;
        head->next = nullptr;
    }else{
        NodeF* temp = head;
        NodeF* nuevo = new NodeF();
        nuevo->data = value;
        while (temp!=nullptr) {
            if(temp->data>nuevo->data){
                nuevo->next=temp;
                head = nuevo;
                break;
            }else if(nuevo->data>temp->data && temp->next==nullptr){
                temp->next = nuevo;
                nuevo->next = nullptr;
                break;
            }else if(nuevo->data>temp->data && nuevo->data<temp->next->data){
                nuevo->next = temp->next;
                temp->next = nuevo;
                break;
            }
            temp= temp->next;
        }
        
    }
}

struct NodeD
{
    int data;
    NodeD* next;
    NodeD* prev;
};

struct DoubleList{
    NodeD* head;
    NodeD* tail;
};


void push_back(DoubleList* &list, int value){
    if(list->head == nullptr){        
        list->head = new NodeD();
        list->head->data = value;
        list->head->next = nullptr;
        list->head->prev = nullptr;
        list->tail = list->head;
    }else{
        NodeD* temp = list->tail;
        NodeD* nuevo = new NodeD();
        nuevo->data = value;
        nuevo->next = nullptr;
        nuevo->prev = temp;
        temp->next = nuevo;
        list->tail = nuevo;
    }
}

void push_front(DoubleList* &list, int value){
    if(list->head == nullptr){  
        list->tail = list->head;      
        list->head = new NodeD();
        list->head->data = value;
        list->head->next = nullptr;
        list->head->prev = nullptr;
    }else{
        NodeD* temp = list->head;
        NodeD* nuevo = new NodeD();
        nuevo->data = value;
        nuevo->next = temp;
        nuevo->prev = nullptr;
        temp->prev = nuevo;
        list->head = nuevo;
    }
}

bool is_palindrome(DoubleList* list){
    while (list->head!=nullptr) {
        if(list->head->data!=list->tail->data){
            return false;
        }
        list->head = list->head->next;
        list->tail = list->tail->prev;
    }

    return true;

}

DoubleList* merge(DoubleList* l1, DoubleList* l2){
    DoubleList* list = new DoubleList();
    while (l1->head!=nullptr && l2->head!=nullptr) {
        if(l1->head->data<l2->head->data){
            push_back(list, l1->head->data);
            l1->head = l1->head->next;
        }else{
            push_back(list, l2->head->data);
            l2->head = l2->head->next;
        }
    }
    while (l1->head!=nullptr) {
        push_back(list, l1->head->data);
        l1->head = l1->head->next;
    }
    while (l2->head!=nullptr) {
        push_back(list, l2->head->data);
        l2->head = l2->head->next;
    }
    return list;
}

void display(DoubleList* list){
    NodeD* temp = list->head;
    while (temp != nullptr){
        cout<< temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}




