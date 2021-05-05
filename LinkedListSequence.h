//
// Created by arina on 04.05.2021.
//

#ifndef LAB2_LINKEDLISTSEQUENCE_H
#define LAB2_LINKEDLISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.cpp"

template<class T>
class LinkedListSequence : Sequence<T> {
//private:
public:
    LinkedList<T> linkedlist;
public:
    class IndexOutOfRange {
    public:
        int lenght;
        int index;

        IndexOutOfRange(int lenght, int index) : lenght(lenght), index(index) {};

        IndexOutOfRange() : lenght(-1), index(-1) {};
    };

    LinkedListSequence() {
        linkedlist = LinkedList<T>();
    }

    LinkedListSequence(T *items, int count) {
        linkedlist= LinkedList<T>(items, count);
        cout<< linkedlist <<"its just init\n \n";


        LinkedList<T>l(items, count);
        linkedlist =l;
        cout<<linkedlist<<"Its init with dop T \n \n";
    }

//проверить
    LinkedListSequence(const LinkedList<T> &list) {
        linkedlist = LinkedList<T>(list);
    }

    T GetFirst() {
        if (linkedlist.GetLength() == 0) throw IndexOutOfRange(0, 0);
        return linkedlist.GetFirst();
    }

    T GetLast() {
        if (linkedlist.GetLength() == 0) throw IndexOutOfRange(0, 0);
        return linkedlist.GetLast();
    }

    T Get(int index) {
        if (index < 0 || index >= linkedlist.GetLength()) throw IndexOutOfRange(linkedlist.GetLength(), index);
        return linkedlist.Get(index);
    }

    void Set(T item, int index) {
        if (index < 0 || index >= linkedlist.GetLength()) throw IndexOutOfRange(linkedlist.GetLength(), index);
        return linkedlist.Set(item, index);
    }

    T &operator[](int index) {
        if (index < 0 || index >= linkedlist.GetLength()) throw IndexOutOfRange(linkedlist.GetLength(), index);
        return linkedlist[index];
    }

    Sequence<T> *GetSubSequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= linkedlist.GetLength())
            throw IndexOutOfRange(linkedlist.GetLength(), startIndex);
        if (endIndex < 0 || endIndex >= linkedlist.GetLength()) throw IndexOutOfRange(linkedlist.GetLength(), endIndex);
        auto *res = new LinkedListSequence<T>(linkedlist.GetSubList(startIndex, endIndex));
        return res;
    }

    int GetLength() {
        return linkedlist.GetLength();
    }

    void Append(T item) {
        linkedlist.Append(item);
    }

    void Prepend(T item) {
        linkedlist.Prepend(item);
    }

    void Insert(T item, int index) {
        if (index < 0 || index >= linkedlist.GetLength()) throw IndexOutOfRange(linkedlist.GetLength(), index);
        linkedlist.Insert(item, index);
    }

    //проверить
    Sequence<T> *Concat(Sequence<T> *list) {
        for (int i = 0; i < list->GetLength(); i++) {
            Append(list->Get(i));
        }
        return this;
    }
};

#endif //LAB2_LINKEDLISTSEQUENCE_H
