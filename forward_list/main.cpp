#include <iostream>
#include "list.h"
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int size(Node* &head){
    Node* temporal=head;
    int resultado=0;
    while(temporal!=nullptr){
        temporal=temporal->next;
        resultado++;
    }
    return resultado;  
    
    
}
void push_front(Node* &head,int data){
    Node* nodo=new Node;
    nodo->data=data;
    nodo->next=head;
    head=nodo;
}
void push_back(Node* &head,int data){
    Node* nodo=new Node;
    nodo->data=data;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=nodo;
    nodo->next=NULL;
    
    
}
void display(Node* head){
    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
void reverse(Node* &head){
        Node *current = head; 
        Node *prev = nullptr;
        Node*next = nullptr; 
        while (current != nullptr) 
        { 
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        } 
        head = prev; 
}


Node* union_lists(Node* head1, Node* head2){//O(n)
    Node* nodo=new Node;
    while(head1!=nullptr && head2!=nullptr){//O(N)
        int temp1=head1->data;
        cout<<"Temp 1: "<<temp1<<endl;
        int temp2=head2->data;
        cout<<"Temp 2: "<<temp2<<endl;

        if(temp1>temp2){
            if(head2->next!=nullptr){
                if((head1)->data > (head2->next)->data){
                push_front(nodo, head2->data);
                head2=head2->next;
                }
                else{
                    push_front(nodo, head2->data);
                    push_front(nodo, head1->data);
                    head1=head1->next;
                    head2=head2->next;
                }     
            }
            else{
                push_front(nodo, head2->data);
                push_front(nodo, head1->data);
                head1=head1->next;
                head2=head2->next;  
            }  
      
        }
        else{
            push_front(nodo,temp1);
            push_front(nodo, temp2);
            head1=head1->next;
            head2=head2->next;
        }
    }
    reverse(nodo);//O(N)
    return nodo;
}



int main()
{
    Node* head1 = nullptr;
    push_front(head1, 15);
    push_front(head1, 10);
    push_front(head1, 8);
    push_front(head1, 3);
    //display(head1);
    //cout<<"Size de head 1: "<<size(head1)<<endl;
    Node* head2 = nullptr;
    push_front(head2, 13);
    push_front(head2, 11);
    push_front(head2, 7);
    push_front(head2, 2);
    push_front(head2, 1);
    print(head1);
    //cout<<"Size de head 2: "<<size(head2)<<endl;

    //display(head2);



    //Node* head3 = union_lists(head1, head2);//O(n)
    //display(head3);//1->2->3->7->8->10->11->13->15

    //return 0;
}


