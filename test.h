//
// Created by arina on 24.05.2021.
//

#ifndef LAB2_TEST_H
#define LAB2_TEST_H


#include "DynamicArray.cpp"
#include "DynamicArraySequence.h"
#include "LinkedList.cpp"
#include "LinkedListSequence.h"
#include "LinForm.h"

#include "iostream"
#include "random"

class testFault{
public:
    int done;
    int fault;
    testFault(): done(0), fault(0) {}
    testFault(int done, int fault): done(done), fault(fault) {}
};

void testAll(int count, int print);


void dynamicArrTest(int count, int print);

void dynamicArrTestResize(int count, int print);
void dynamicArrTestGetItem(int count, int print);
void dynamicArrTestReverse(int count, int print);


void  ArraySequenceTest(int count, int print);

void  ArraySequenceTestResize(int count, int print);
void  ArraySequenceTestGetItem(int count, int print);
void  ArraySequenceTestReverse(int count, int print);

void  LinkedListTest(int count, int print);
void  LinkedListTestGetItem(int count, int print);


void  LinkedListSequenceTest(int count, int print);

void  LinkedListSequenceTestResize(int count, int print);
void  LinkedListSequenceTestGetItem(int count, int print);


void  VectorTest(int count, int print);

void  VectorTestSum(int count, int print);
void  VectorTestSub(int count, int print);
void  VectorTestMult(int count, int print);
void  VectorTestScalar(int count, int print);



void  LinFormTest(int count, int print);

void  LinFormTestSum(int count, int print);
void  LinFormTestSub(int count, int print);
void  LinFormTestScalar(int count, int print);
void  LinFormTestGetValue(int count, int print);

#endif //LAB2_TEST_H
