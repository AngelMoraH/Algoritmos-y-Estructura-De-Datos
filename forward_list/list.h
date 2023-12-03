#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

void push_front(Node* &head, int data){
    Node* nodo=new Node;
    nodo->data=data;
    nodo->next=head;
    head=nodo;
}


void push_back(Node* &head, int data){
    Node* nodo=new Node;
    nodo->data=data;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=nodo;
    nodo->next=NULL;
}

void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}

void union_lists(Node* &head1, Node* &head2){
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=nullptr&&temp2!=nullptr){
        
    }
}