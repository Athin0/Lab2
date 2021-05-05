#include <iostream>
#include "LinkedListSequence.h"
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    int ar[]={1,2,3};

    LinkedListSequence<int> l(ar,2);

    cout<< l.linkedlist << "itog1";
    l.Append(3);
cout<< l.linkedlist << "add 3";
/*
    LinkedList<int>l2(ar,2);
LinkedList<int> l1 = LinkedList<int>(l2);//(ar,3);
cout<< l1;
l1.Append(3);
cout<< l1;
 /**/
    return 0;
}
