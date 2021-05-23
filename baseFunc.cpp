//
// Created by arina on 23.05.2021.
//

#include <iostream>
#include "baseFunc.h"
#include "random"
#define maxInt 10000
using namespace std;

int GetInt() {
    int k;
    cin >> k;
    return k;
}

int GetInt(int up) {
    int k;
    cin >> k;
    if (k > up) {
        cout << "Число вне диапозона. Повторите попытку\n";
        return GetInt(up);
    }
    return k;
}

int GetInt(int down, int up) {
    int k;
    cin >> k;
    if (k > up || k < down) {
        cout << "Число вне диапозона. Повторите попытку\n";
        return GetInt(down, up);
    }
    return k;
}

float randomFloat() {
    return (float) randomInt() + (float) randomInt() / (float) randomInt();
}

int randomInt() {
    return rand() % maxInt;
}

complex<int> randomComplex() {
    return complex<int>(randomInt(), randomInt());
}

ostream &operator<<(ostream &cout, complex<int> num) {
    if (num.imag() == 0)
        return cout << num.real();

    if (num.real() != 0) {
        cout << num.real();
    }

    if (num.imag() > 0) {
        if (num.real() != 0)
            cout << '+';
        if (num.imag() != 1)
            cout << num.imag();
        return cout << 'i';
    } else {
        if (num.imag() == -1)
            return cout << "-i";
        return cout << num.imag() << 'i';
    }
}

int GetType() {
    cout << "Введите число для работы со следующим типом данных: \n"
         << "\t1: int\n"
         << "\t2: float\n"
         << "\t3: complex<int>\n"
         << "\t0: Выйти из функции\n"
         << ": ";
    return GetInt(0, 3);
}
