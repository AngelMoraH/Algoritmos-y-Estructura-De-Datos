#include <iostream>
#include "solucion.h"
using namespace std;

void test_sortedInsert(){
    NodeF* head = nullptr;    
    sortedInsert(head, 2);
    sortedInsert(head, 5);
    sortedInsert(head, 1);
    sortedInsert(head, 10);
    sortedInsert(head, 4);
    display(head);//1->2->4->5->10->
}

void test_palindrome(){
    DoubleList* list1 = new DoubleList();
    push_back(list1, 1);
    push_back(list1, 2);
    push_back(list1, 3);
    push_back(list1, 2);
    push_back(list1, 1);
    cout<<"List1 is palindrome: "<<is_palindrome(list1)<<endl; // 1

    DoubleList* list2 = new DoubleList();
    push_back(list2, 1);
    push_back(list2, 2);
    push_back(list2, 3);
    push_back(list2, 3);
    push_back(list2, 2);
    push_back(list2, 1);
    cout<<"List2 is palindrome: "<<is_palindrome(list2)<<endl; // 1

    DoubleList* list3 = new DoubleList();
    push_back(list3, 1);
    push_back(list3, 2);
    push_back(list3, 3);    
    cout<<"List3 is palindrome: "<<is_palindrome(list3)<<endl; // 0
}

void test_merge(){
    DoubleList* list1 = new DoubleList();
    push_back(list1, 1);
    push_back(list1, 4);
    push_back(list1, 8);
    push_back(list1, 9);
    push_back(list1, 11);

    DoubleList* list2 = new DoubleList();
    push_front(list2, 13);
    push_front(list2, 10);
    push_front(list2, 7);
    push_front(list2, 6);
    push_front(list2, 3);

    cout<<"List 1:\n"; display(list1);//1->4->8->9->11
    cout<<"List 2:\n"; display(list2);//3->6->7->10->13
    DoubleList* list3 = merge(list1, list2);//1->3->4->6->7->8->9->10->11->13
    cout<<"List 3:\n"; display(list3);
}

int main() 
{
    cout<<"-- test_sortedInsert --\n";
    test_sortedInsert();
    
    cout<<"-- test_palindrome --\n";
    test_palindrome();

    cout<<"-- test_merge --\n";
    test_merge();
    return 0;
}
