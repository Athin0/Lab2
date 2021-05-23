//
// Created by arina on 10.05.2021.
//

#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

#include "DynamicArraySequence.h"

template<class T>
class Vector {
private:
    int dimension;
    ArraySequence<T> vector_arr;
    size_t type = sizeof(T);
public:
    Vector() {
    }

    explicit Vector(ArraySequence <T> &arraySequence) {
        this->vector_arr = ArraySequence<T>(arraySequence);
        dimension = arraySequence.GetLength();
    }

    Vector(T *array, int dimension) {
        this->dimension = dimension;
        vector_arr = ArraySequence<T>(array, dimension);
    }

    Vector<T> *addVectors(Vector<T> vector) {
        if (type != vector.type) return nullptr;
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

        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *subVectors(Vector<T> vector) {
        if (type != vector.type) return nullptr;
        ArraySequence<T> arraySequence1;
        int size = dimension;
        if (dimension >= vector.dimension) {
            arraySequence1 = ArraySequence<T>(vector_arr);
            size = vector.dimension;
        } else {
            arraySequence1 = ArraySequence<T>(vector.vector_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.Set(vector_arr.Get(i) - vector.vector_arr.Get(i), i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *multVector(Vector<T> vector) {
        if (type != vector.type) return nullptr;
        ArraySequence <T> arraySequence1;
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

    T GetValue(T item) {
        T res = vector_arr[0];
        for (int i = 1; i < vector_arr.GetLength(); i++) {
            if (vector_arr[i] == 0) continue;
            T val = item;
            for (int j = 1; j < i; j++)
                val *= item;

            res += val * vector_arr[i];
        }

        return res;
    }

    Vector<T> *scalarMultVector(T a) {
        ArraySequence <T> arraySequence1(vector_arr);
        for (int i = 0; i < dimension; ++i) {
            arraySequence1.Set(vector_arr.Get(i) * a, i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }


    friend std::ostream &operator<<(std::ostream &cout, const Vector<T> &vector) {
        cout << '{';
        for (int i = 0; i < vector.dimension; i++) {
            cout << vector.vector_arr.Get(i);
            if (i != vector.dimension - 1) {
                cout << ", ";
            }
        }
        cout << '}';
        return cout;
    }

    Vector<T> add(Vector<T> vec0) {
        ArraySequence <T> *arrRes;
        for (int i = 0; i < vector_arr.GetLength() && i < vec0.vector_arr.GetLength(); i++) {
            arrRes->Append(vector_arr[i] + vec0[i]);
        }


        for (int i = arrRes->GetLength(); i < vector_arr.GetLength(); i++) {
            arrRes->Append(vector_arr[i]);
        }

        for (int i = arrRes->GetLength(); i < vec0.vector_arr.GetLength(); i++) {
            arrRes->Append(vec0.vector_arr[i]);
        }

        vector_arr = *arrRes;
        delete arrRes;

        return *this;
    }

    Vector<T> operator+(Vector<T> vec0) {
        return Vector<T>(*this).add(vec0);
    }


};


#endif //LAB2_VECTOR_H
