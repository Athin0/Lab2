//
// Created by arina on 23.05.2021.
//

#ifndef LAB2_LINFORM_H
#define LAB2_LINFORM_H
#include "DynamicArraySequence.h"

template<class T>
class LinForm {
private:
    int dimension;
    ArraySequence<T> linForm_arr;
    size_t type = sizeof(T);
public:
    LinForm() {
    }

    explicit LinForm(ArraySequence <T> &arraySequence) {
        this->linForm_arr = ArraySequence<T>(arraySequence);
        dimension = arraySequence.GetLength();
    }

    LinForm(T *array, int dimension) {
        this->dimension = dimension;
        linForm_arr = ArraySequence<T>(array, dimension);
    }

    LinForm<T> *addLinForms(LinForm<T> linform) {
        if (type != linform.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = dimension;
        if (dimension >= linform.dimension) {
            arraySequence1 = ArraySequence<T>(linForm_arr);
            size = linform.dimension;
        } else {
            arraySequence1 = ArraySequence<T>(linform.linForm_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.Set(linform.linForm_arr.Get(i) + linForm_arr.Get(i), i);
        }

        LinForm<T> *linform1 = new LinForm<T>(arraySequence1);
        return linform1;
    }

    LinForm<T> *scalarMultLinForm(T a) {
        ArraySequence <T> arraySequence1(linForm_arr);
        for (int i = 0; i < dimension; ++i) {
            arraySequence1.Set(linForm_arr.Get(i) * a, i);
        }
        LinForm<T> *linform1 = new LinForm<T>(arraySequence1);
        return linform1;
    }

    LinForm<T> *subLinForms(LinForm<T> linform) {
        if (type != linform.type)
            return nullptr;
        ArraySequence<T> arraySequence1;
        int size = dimension;
        linform= *(linform.scalarMultLinForm(-1));
        if (dimension >= linform.dimension) {
            arraySequence1 = ArraySequence<T>(linForm_arr);
            size = linform.dimension;
        } else {
            arraySequence1 = ArraySequence<T>(linform.linForm_arr);
        }
        for (int i = 0; i < size; i++) {
            arraySequence1.Set(linForm_arr.Get(i) + linform.linForm_arr.Get(i), i);
        }
        LinForm<T> *linform1 = new LinForm<T>(arraySequence1);
        return linform1;
    }

    T GetValue(ArraySequence<T> &arr) {
        T res = (T) 0;
        for (int i = 0; i < arr.GetLength(); i++) {
            res += linForm_arr.Get(i) * arr.Get(i);
        }
        return res;
    }

    int GetLength() {
        return dimension;
    }


    friend std::ostream &operator<<(std::ostream &cout, const LinForm<T> &linform) {
        cout << '{';
        for (int i = 0; i < linform.dimension; i++) {
            cout << linform.linForm_arr.Get(i);
            if (i != linform.dimension - 1) {
                cout << "x["<<i<<"]+";
            }
        }
        cout <<"x[" <<linform.dimension-1<<"]}";
        return cout;
    }


    LinForm<T> operator+(LinForm<T> linform0) {
        return LinForm<T>(*this).addLinForms(linform0);
    }

    LinForm<T> &operator=(const LinForm<T> &linform0) {
        linForm_arr = linform0.linForm_arr;
        return *this;
    }


    LinForm<T> operator-(LinForm<T> linform0) {
        return LinForm<T>(*this).subLinForms(linform0);
    }

    LinForm<T> operator*(LinForm<T> linform0) {
        return LinForm<T>(*this).multLinForm(linform0);
    }

    LinForm<T> operator*(T a) {
        return LinForm<T>(*this).scalarMultLinForm(a);
    }

    int operator==(LinForm<T> linform0) {
        if (linForm_arr.GetLength() != linform0.linForm_arr.GetLength())
            return 0;
        for (int i = 0; i < linForm_arr.GetLength(); i++) {
            if (linForm_arr[i] != linform0.linForm_arr[i])
                return 0;
        }
        return 1;
    }
    int operator!=(LinForm<T> linform0) {
        return !(*this == linform0);
    }

};

#endif //LAB2_LINFORM_H
