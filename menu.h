//
// Created by arina on 21.05.2021.
//

#ifndef LAB2_MENU_H
#define LAB2_MENU_H
#include <complex>
#include "Vector.h"
#include <iostream>
#include "Tests.h"

void mainMenu();
int getType();

//1
void readVector(ArraySequence<Vector<int>*> *intArr,
ArraySequence<Vector<float>*> *floatArr,
ArraySequence<Vector<std::complex<int>>*> *complexArr);

template<class T>
void readTypeVector(ArraySequence<Vector<T>*> *arr, int count);

template<class T>
void generateRandomVector(ArraySequence<Vector<T>*> *arr, int count, T (*func)());

//2
void operationWithVector(ArraySequence<Vector<int>*> *intArr,
ArraySequence<Vector<float>*> *floatArr,
ArraySequence<Vector<std::complex<int>>*> *complexArr);

template<class T>
void operationTypeWithVector(ArraySequence<Vector<T>*> *arr);

//3
void printVector(ArraySequence<Vector<int>*> *intArr,
                 ArraySequence<Vector<float>*> *floatArr,
                 ArraySequence<Vector<std::complex<int>>*> *complexArr);

template<class T>
void printTypeVector(ArraySequence<Vector<T>*> *arr);


//4
void deleteVector(ArraySequence<Vector<int>*> *intArr,
ArraySequence<Vector<float>*> *floatArr,
ArraySequence<Vector<std::complex<int>>*> *complexArr);

template<class T>
void deleteTypeVector(ArraySequence<Vector<T>*> *arr);

//5
void testFunc();

#endif //LAB2_MENU_H
