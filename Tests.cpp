//
// Created by arina on 10.05.2021.

#include "Tests.h"

void LinkedListSequenceSet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    l.Set(4, 11111);
    cout << l << endl;
}

void Tests() {
    // DynamicArrayTests();
    LinkedListTests();
    //LinkedListSequenceTests();
    // ArraySequenceTests();
}

void ArraySequenceTests() {
    ArraySequenceCreate();
    ArraySequenceGet();
    ArraySequenceGetFirst();
    ArraySequenceGetLast();
    ArraySequenceGetSubList();
    ArraySequenceGetLength();
    ArraySequenceSet();
    ArraySequenceAppend();
    ArraySequencePrepend();
    ArraySequenceInsertAt();
    ArraySequenceConcat();
}

void ArraySequenceConcat() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    ArraySequence<int> *l2 = l.GetSubSequence(2, 5);
    l.Concat(l2);
    cout << l << endl;

}

void ArraySequenceInsertAt() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    l.Insert(11111, 2);
    cout << l << endl;
}

void ArraySequencePrepend() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    l.Prepend(11111);
    cout << l << endl;
}

void ArraySequenceAppend() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    l.Append(11111);
    cout << l << endl;
}

void ArraySequenceSet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    l.Set(4, 11111);
    cout << l << endl;
}

void ArraySequenceGetLength() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    cout << l.GetLength() << endl;

}

void ArraySequenceGet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    cout << l.Get(0) << " " << l.Get(l.GetLength() - 1) << endl;

}

void ArraySequenceGetSubList() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);

    ArraySequence<int> *l2 = l.GetSubSequence(2, 7);
    cout << *l2 << endl;
}

void ArraySequenceGetLast() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    cout << l.GetLast() << endl;
}

void ArraySequenceGetFirst() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ArraySequence<int> l = ArraySequence<int>(ar, 10);
    cout << l.GetFirst() << endl;
}

void ArraySequenceCreate() {
    ArraySequence<int> l1 = ArraySequence<int>();
    cout << l1 << endl;
    int ar[] = {1, 2};
    ArraySequence<int> l2(ar, 2);
    cout << l2 << endl;
    ArraySequence<int> l3(l2);
    cout << l3 << endl;
}

void LinkedListSequenceTests() {
    LinkedListSequenceCreate();
    LinkedListSequenceGet();
    LinkedListSequenceGetFirst();
    LinkedListSequenceGetLast();
    LinkedListSequenceGetSubList();
    LinkedListSequenceGetLength();
    LinkedListSequenceSet();
    LinkedListSequenceAppend();
    LinkedListSequencePrepend();
    LinkedListSequenceInsertAt();
    LinkedListSequenceConcat();

}

void LinkedListSequenceConcat() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    LinkedListSequence<int> *l2 = l.GetSubSequence(2, 5);
    l.Concat(l2);
    cout << l << endl;

}

void LinkedListSequenceInsertAt() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    l.Insert(11111, 2);
    cout << l << endl;
}

void LinkedListSequencePrepend() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    l.Prepend(11111);
    cout << l << endl;
}

void LinkedListSequenceAppend() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    l.Append(11111);
    cout << l << endl;
}

void LinkedListSequenceGetLength() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    cout << l.GetLength() << endl;

}

void LinkedListSequenceGet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    cout << l.Get(0) << " " << l.Get(l.GetLength() - 1) << endl;

}

void LinkedListSequenceGetSubList() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);

    LinkedListSequence<int> *l2 = l.GetSubSequence(2, 7);
    cout << *l2 << endl;
}

void LinkedListSequenceGetLast() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    cout << l.GetLast() << endl;
}

void LinkedListSequenceGetFirst() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedListSequence<int> l = LinkedListSequence<int>(ar, 10);
    cout << l.GetFirst() << endl;
}

void LinkedListSequenceCreate() {
    LinkedListSequence<int> l1 = LinkedListSequence<int>();
    cout << l1 << endl;
    int ar[] = {1, 2};
    LinkedListSequence<int> l2(ar, 2);
    cout << l2 << endl;
    LinkedListSequence<int> l3(l2);
    cout << l3 << endl;
}

void LinkedListTests() {
    LinkedListCreate();
    LinkedListGet();
    LinkedListGetFirst();
    LinkedListGetLast();
    LinkedListGetSubList();
    LinkedListGetLength();
    LinkedListSet();
    LinkedListAppend();
    LinkedListPrepend();
    LinkedListInsertAt();
    LinkedListConcat();

}

void LinkedListConcat() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    LinkedList<int> *l2 = l.GetSubList(2, 5);
    l.Concat(l2);
    cout << l << endl;

}

void LinkedListInsertAt() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    l.Insert(11111, 2);
    cout << l << endl;
}

void LinkedListPrepend() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    l.Prepend(11111);
    cout << l << endl;
}

void LinkedListAppend() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    l.Append(11111);
    cout << l << endl;
}

void LinkedListSet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    l.Set(4, 11111);
    cout << l << endl;
}

void LinkedListGetLength() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    cout << (l.GetLength()==10) << endl;

}

void LinkedListGet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    cout << (l.Get(5) == ar[5])<<  endl;

}

void LinkedListGetSubList() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);

    LinkedList<int> *l2 = l.GetSubList(2, 7);
    cout << *l2 << endl;
}

void LinkedListGetLast() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    cout << (l.GetLast()==ar[9]) << endl;
}

void LinkedListGetFirst() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList<int> l = LinkedList<int>(ar, 10);
    cout << (l.GetFirst()==ar[0]) << endl;
}

void LinkedListCreate() {
    LinkedList<int> l1 = LinkedList<int>();
    cout << l1 << endl;
    int ar[] = {1, 2};
    LinkedList<int> l2(ar, 2);
    cout << l2 << endl;
    LinkedList<int> l3(l2);
    cout << l3 << endl;
}

void DynamicArrayTests() {
    DynamicArrayCreate();
    DynamicArrayGet();
    DynamicArrayGetLength();
    DynamicArraySet();
    DynamicArrayResize();
}

void DynamicArrayResize() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    DynamicArray<int> l = DynamicArray<int>(ar, 10);
    l.Resize(4);
    cout << l << endl;
    l.Resize(11);
    cout << l << endl;
}

void DynamicArraySet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    DynamicArray<int> l = DynamicArray<int>(ar, 10);
    l.Set(4, 11111);
    cout << l << endl;
}

void DynamicArrayGetLength() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    DynamicArray<int> l = DynamicArray<int>(ar, 10);
    cout << l.GetLength() << endl;

}

void DynamicArrayGet() {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    DynamicArray<int> l = DynamicArray<int>(ar, 10);
    cout << l.Get(0) << " " << l.Get(l.GetLength() - 1) << endl;

}

void DynamicArrayCreate() {
    DynamicArray<int> l1 = DynamicArray<int>();
    cout << l1 << endl;
    int ar[] = {1, 2};
    DynamicArray<int> l2(ar, 2);
    cout << l2 << endl;
    DynamicArray<int> l3(l2);
    cout << l3 << endl;
}
