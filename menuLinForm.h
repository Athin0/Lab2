

#ifndef LAB2_MENULINFORM_H
#define LAB2_MENULINFORM_H

#include <complex>
#include "LinForm.h"
#include <iostream>
#include "Lab2/Tests.h"


void mainMenuLinForm();
int getType();

//1
void readLinForm(ArraySequence<LinForm<int>*> *intArr,
ArraySequence<LinForm<float>*> *floatArr,
ArraySequence<LinForm<std::complex<int>>*> *complexArr);

template<class T>
void readTypeLinForm(ArraySequence<LinForm<T>*> *arr, int count);

template<class T>
void generateRandomLinForm(ArraySequence<LinForm<T>*> *arr, int count, T (*func)());

//2
void operationWithLinForm(ArraySequence<LinForm<int>*> *intArr,
ArraySequence<LinForm<float>*> *floatArr,
ArraySequence<LinForm<std::complex<int>>*> *complexArr);

template<class T>
void operationTypeWithLinForm(ArraySequence<LinForm<T>*> *arr);

//3
void printLinForm(ArraySequence<LinForm<int>*> *intArr,
ArraySequence<LinForm<float>*> *floatArr,
ArraySequence<LinForm<std::complex<int>>*> *complexArr);

template<class T>
void printTypeLinForm(ArraySequence<LinForm<T>*> *arr);


//4
void deleteLinForm(ArraySequence<LinForm<int>*> *intArr,
ArraySequence<LinForm<float>*> *floatArr,
ArraySequence<LinForm<std::complex<int>>*> *complexArr);

template<class T>
void deleteTypeLinForm(ArraySequence<LinForm<T>*> *arr);


#endif //LAB2_MENULINFORM_H
