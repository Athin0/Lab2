

#ifndef LAB2_POLYNOMIAL_H
#define LAB2_POLYNOMIAL_H

#include <iostream>
#include "DynamicArraySequence.h"

template<class T>
class Polynomial {
private:
    ArraySequence<T> elements;

    static T pow(int x, T value) {
        T result = 1;
        for (int i = 0; i < x; i ++){
            result = result * value;
        }
        return result;
    }
public:
    class IndexOutOfRange{
    public:
        IndexOutOfRange() {};
    };

    Polynomial<T> &operator = (const Polynomial<T> &polynomial) {
        elements = polynomial.elements;

        return *this;
    }

    Polynomial<T> &operator = (Polynomial<T> *polynomial) {
        elements = polynomial->elements;
        return *this;
    }

    Polynomial(){
        elements = ArraySequence<T>();
    }

    Polynomial(const Polynomial<T> &polynomial) {
        elements = polynomial.elements;
    }

    void Set(T item,int index) {
        if (index < 0 || index >= elements.GetLength())
            throw IndexOutOfRange(GetLength(), index);
        elements.Set(item,index);
    }

    T Get(int index) {
        if (index < 0 || index >= elements.GetLength())
            throw IndexOutOfRange(GetLength(), index);
        return elements.Get(index);
    }

    int GetLength() {
        return this->elements.GetLength();
    }

    Polynomial<T> *addPol(Polynomial<T> *pol) {
        if (pol->GetLength() <= 0)
            throw IndexOutOfRange();
        int q = -1;
        int max_len;
        int min_len;
        if (this->GetLength() > pol->GetLength()) {
            max_len = this->GetLength();
            q = 1;
            min_len = pol->GetLength();
        }
        else {
            max_len = pol->GetLength();
            q = 0;
            min_len = this->GetLength();
        }
        auto NewPol = Polynomial<T>();
        for (int i = 0; i < min_len; i++){
            NewPol.elements.Append(this->elements.Get(i) + pol->elements.Get(i));
        }
        for ( int i = min_len; i < max_len; i++) {
            if (q == 0) {
                NewPol.elements.Append(pol->elements.Get(i));
            } else {
                NewPol.elements.Append(this->elements.Get(i));
            }
        }
        elements = NewPol.elements;
        return this;
    }

    Polynomial<T> *subPol(Polynomial<T> *pol) {
        if (pol->GetLength() <= 0)
            throw IndexOutOfRange();
        int q = -1;
        int max_len;
        int min_len;
        if (this->GetLength() > pol->GetLength()) {
            max_len = this->GetLength();
            q = 1;
            min_len = pol->GetLength();
        }
        else{
            max_len = pol->GetLength();
            q = 0;
            min_len = this->GetLength();
        }
        Polynomial<T> NewPol;
        for (int i = 0; i < min_len; i++){
            NewPol.elements.Append((this->elements.Get(i) - pol->elements.Get(i)));
        }
        for ( int i = min_len; i < max_len; i++){
            if (q == 0){
                NewPol.elements.Append(pol->elements.Get(i));
            }
            else {
                NewPol.elements.Append(this->elements.Get(i));
            }
        }
        elements = NewPol.elements;
        return this;
    }


    Polynomial<T> *Scalar(T scalar){
        Polynomial<T> NewPol;
        for (int i = 0; i < this->GetLength(); i++){
            NewPol.elements.Append(this->elements.Get(i) * scalar);
        }
        this->elements = NewPol.elements;
        return this;
    }



    T GetValue(T symbol) {
        T value = this->elements.Get(0);
        if (this->GetLength() == 0) {
            return value;
        }
        else {
            for (int i = 1; i < this->GetLength(); i++){
                value += this->elements.Get(i) * pow(i, symbol);
            }

            return value;
        }
    }

    Polynomial<T> *multPol(Polynomial<T> *pol) {
        if (pol->GetLength() <= 0)
            throw IndexOutOfRange();

        Polynomial<T> NewPol;

        for (int i = 0; i < this->GetLength(); i++)
            for (int j = 0; j < pol->GetLength(); j++){
                NewPol.elements.Append(this->elements.Get(i) + pol->elements.Get(j));
            }
        this->elements = NewPol.elements;
        return this;
    }

    Polynomial<T> &operator + (Polynomial<T> pol){
        return *Polynomial<T>(*this).addPol(&pol);
    }

    Polynomial<T> &operator +=(Polynomial<T> pol){
        addPol(&pol);
        return *this;
    }

    Polynomial<T> &operator -(Polynomial<T> pol){
        return *Polynomial<T>(*this).subPol(&pol);
    }

    Polynomial<T> &operator -=(Polynomial<T> pol){
        subPol(&pol);
        return *this;
    }

    Polynomial<T> &operator *(Polynomial<T> pol){
        return *Polynomial<T>(*this).multPol(&pol);

    }

    Polynomial<T> &operator *(T a){
        return *Polynomial<T>(*this).Scalar(a);

    }

    Polynomial<T> &operator *=(Polynomial<T> pol){
        multPol(&pol);
        return *this;
    }
};



#endif //LAB2_POLYNOMIAL_H
