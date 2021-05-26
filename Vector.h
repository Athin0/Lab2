//
// Created by arina on 10.05.2021.
//

#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

#include "DynamicArraySequence.h"
#include <cmath>

template<class T>
class Vector {
private:
    int dimension=0;
    ArraySequence<T> vector_arr;
    size_t type = sizeof(T);
public:
    Vector() {
    }

    explicit Vector(ArraySequence<T> &arraySequence) {
        this->vector_arr = ArraySequence<T>(arraySequence);
        dimension = arraySequence.GetLength();
    }

    Vector(T *array, int dimension) {
        this->dimension = dimension;
        vector_arr = ArraySequence<T>(array, dimension);
    }

    Vector<T> *addVectors(Vector<T> vector) {
        if (type != vector.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = dimension;
        if (dimension >= vector.dimension) {
            arraySequence1 = ArraySequence<T>(vector_arr);
            size = vector.dimension;
        } else {
            arraySequence1 = ArraySequence<T>(vector.vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.Set(vector.vector_arr.Get(i) + vector_arr.Get(i), i);
        }

        auto vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *scalarMultVector(T a) {
        ArraySequence<T> arraySequence1(vector_arr);
        for (int i = 0; i < dimension; ++i) {
            arraySequence1.Set(vector_arr.Get(i) * a, i);
        }
        auto vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *subVectors(Vector<T> vector) { ///Туть ошибка! возвращаешь указатель, а потом используешь как обычный объект
        if (type != vector.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = dimension;
        vector = *(vector.scalarMultVector(-1));
        if (dimension >= vector.dimension) {
            arraySequence1 = ArraySequence<T>(vector_arr);
            size = vector.dimension;
        } else {
            arraySequence1 = ArraySequence<T>(vector.vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.Set(vector_arr.Get(i) + vector.vector_arr.Get(i), i);
        }
        auto vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *multVector(Vector<T> vector) {
        if (type != vector.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = dimension;
        if (dimension >= vector.dimension) {
            arraySequence1 = ArraySequence<T>(vector.vector_arr);
            size = vector.dimension;
        } else {
            arraySequence1 = ArraySequence<T>(vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.Set(vector.vector_arr.Get(i) * vector_arr.Get(i), i);
        }
        auto *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    T GetValue() {
        T res = (T) 0;
        for (int i = 1; i < vector_arr.GetLength(); i++) {
            if (vector_arr[i] == 0)
                continue;
            res += (vector_arr[i]) * (vector_arr[i]);
        }
        return sqrt(res);
    }

    int GetLength(){
        return dimension;
    }


    Vector<T> operator*(Vector<T> vec0) {
        return *Vector<T>(*this).multVector(vec0);
    }

    Vector<T> operator*(T a) {
        return *Vector<T>(*this).scalarMultVector(a);
    }


    Vector<T> operator-(Vector<T> vect1) {
        auto *resPtr = Vector<T>(*this).subVectors(vect1);
        auto res = *resPtr;
        delete resPtr;
        return res;
        //return *Vector<T>(*this).subVectors(vect1);
    }

    Vector<T> operator -= (Vector<T> vect) {
        return *subVectors(vect);
    }


    Vector<T> operator-() {
        return *Vector<T>().subVectors(*this);
    }


    T &operator[](int index) {
        return vector_arr[index];
    }


    Vector<T> operator +(Vector<T> vec0) {
        auto *resPtr = Vector<T>(*this).addVectors(vec0);
        auto res = *resPtr;
        delete resPtr;
        return res;
    }

    Vector<T> operator += (Vector<T> vec0) {
        return addVectors(vec0);
    }


    Vector<T> operator *= (T item) {
        return scalarMult(item);
    }

    int operator == (Vector<T> vec0) {
        if (vector_arr.GetLength() != vec0.vector_arr.GetLength())
            return 0;

        for (int i = 0; i < vector_arr.GetLength(); i++) {
            if (vector_arr[i] != vec0.vector_arr[i])
                return 0;
        }

        return 1;
    }

    int operator != (Vector<T> vec0) {
        return !(*this == vec0);
    }

    int operator == (T value) {
        if (vector_arr.GetLength() == 1 && vector_arr[0] == value)
            return 1;

        if (vector_arr.GetLength() == 0 && value == 0)
            return 1;

        return 0;
    }

    int operator != (T value) {
        return !(*this == value);
    }
    
    Vector<T> &operator = (const Vector<T> &vec0) {
        vector_arr = vec0.vector_arr;
        return *this;
    }
};
template <class T>
std::ostream &operator<<(std::ostream &cout, Vector<T> vector) {
    cout << '{';
    for (int i = 0; i < vector.GetLength(); i++) {
        cout << vector[i];
        if (i != vector.GetLength() - 1) {
            cout << ", ";
        }
    }
    cout << '}';
    return cout;
}

#endif //LAB2_VECTOR_H
