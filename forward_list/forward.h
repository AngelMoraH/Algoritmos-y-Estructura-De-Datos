#include <iostream>
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
        cout<<"->"<<head->data;
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
