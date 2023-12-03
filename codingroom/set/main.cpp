#include <iostream>
#include "set.h"
#include "person.h"
using namespace std;

void test1(){
    Set<int> myset;
    myset.Insert(10);
    myset.Insert(5);
    myset.Insert(4);
    myset.Insert(8);
    myset.Insert(5);
    myset.Insert(10);
    myset.Insert(12);    
    myset.display();//4,5,8,10,12
    cout<<"Contains(4): "
        <<myset.Contains(4)<<endl;//Contains(4): 1
    cout<<"Contains(14): "
        <<myset.Contains(14)<<endl;//Contains(14): 0
    myset.Remove(5);
    myset.display();//4,8,10,12
}

void test2(){
    Set<Person> myset;
    myset.Insert(Person("juan", 20));
    myset.Insert(Person("bruno", 18));
    myset.Insert(Person("angelica", 19));
    myset.Insert(Person("pedro", 21));
    myset.Insert(Person("bruno", 25));
    myset.Insert(Person("maria", 22));
    myset.Insert(Person("terry", 23));    
    //myset.display();
    //(angelica, 19) (bruno, 18) (juan, 20) (pedro, 21) (terry, 23)
    cout<<"Contains(bruno): " <<myset.Contains(Person("bruno"))<<endl;//Contains(bruno): 1
    cout<<"Contains(heider): " <<myset.Contains(Person("heider"))<<endl;//Contains(heider): 0
    myset.Remove(Person("juan"));
    //myset.display();
    //(angelica, 19) (bruno, 18) (pedro, 21) (terry, 23)
}

int main(){
   test1();
   test2();
}