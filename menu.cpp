//
// Created by arina on 21.05.2021.
//

#include "menu.h"
#include "DynamicArray.cpp"
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

int randomInt() {
    return rand() % maxInt;
}

float randomFloat() {
    return (float) randomInt() + (float) randomInt() / (float) randomInt();
}

complex<int> randomComplex() {
    return complex<int>(randomInt(), randomInt());
}

ostream &operator<<(ostream &cout, complex<int> num) {
    if (num.imag() == 0) return cout << num.real();

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
}  //красивый вывод комплексного числа

template<class T>
void printArr(ArraySequence<Vector<T> *> *arr) {
    for (int i = 0; i < arr->GetLength(); i++) {
        cout << i << ": " << *arr->Get(i) << endl;
    }
    cout << endl;
}

void mainMenu() {
    ArraySequence<Vector<int> *> arrInt ;
    ArraySequence<Vector<float> *> arrFloat;
    ArraySequence<Vector<complex<int>> *> arrComplex;
    int item;
    while (true) {
        cout << "Программа имеет следующие возможности: \n"
             << "\t1: Ввести и запомнить вектор\n"
             << "\t2: Выполнить операцию над векторами\n"
             << "\t3: Вывести вектор в консоль\n"
             << "\t4: Удалить или переместить вектор в памяти\n"
             << "\t5: Запустить функцию тестирования вектор\n"
             << "\t6: Закончить выполнение программы\n"
             << "Введите число: ";
        cin >> item;
        if (item < 1 || item > 6) {
            cout << "Ошибка! Нет такого пункта! Повторите попытку\n";
            continue;
        }

        if (item == 6)
            break;

        switch (item) {
            case 1:
                readVector(&arrInt, &arrFloat, &arrComplex);
                break;
            case 2:
                operationWithVector(&arrInt, &arrFloat, &arrComplex);
                break;
            case 3:
                printVector(&arrInt, &arrFloat, &arrComplex);
                break;
            case 4:
                deleteVector(&arrInt, &arrFloat, &arrComplex);
                break;
            case 5:
//                testFunc();
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < arrInt.GetLength(); i++) {
        delete arrInt.Get(i);
    }

    for (int i = 0; i < arrFloat.GetLength(); i++) {
        delete arrFloat.Get(i);
    }

    for (int i = 0; i < arrComplex.GetLength(); i++) {
        delete arrComplex.Get(i);
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

//1
void readVector(ArraySequence<Vector<int> *> *intArr,
                    ArraySequence<Vector<float> *> *floatArr,
                    ArraySequence<Vector<std::complex<int>> *> *complexArr) {

    int count = 0;

    cout << "Введите степень вектора или -1 для выхода\n: ";
    do {
        if (count < 0) {
            cout << "Векторы отрицательной степени не поддерживаются!\n: ";
        }
        cin >> count;

        if (count == -1)
            return;
    } while (count < 0);

    auto item = GetType();
    if (item == 0) return;

    cout << "Сгенерировать вектор автоматически или ввести вручную?:\n"
            "\t0: выход\n"
            "\t1: ввести вектор вручную\n"
            "\t2: сгенерировать вектор\n: ";

    int item2 = GetInt(0, 2);
    if (item2 == 0) return;

    if (item2 == 1) {
        switch (item) {
            case 1:
                readTypeVector<int>(intArr, count);
                break;
            case 2:
                readTypeVector<float>(floatArr, count);
                break;
            case 3:
                readTypeVector<complex<int>>(complexArr, count);
                break;
            default:
                break;
        }
    }

    if (item2 == 2) {
        switch (item) {
            case 1:
                generateRandomVector<int>(intArr, count, randomInt);
                break;
            case 2:
                generateRandomVector<float>(floatArr, count, randomFloat);
                break;
            case 3:
                generateRandomVector<complex<int>>(complexArr, count, randomComplex);
                break;
            default:
                break;
        }
    }

    cout << "Хотите ввести ещё один вектор?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";

    item = GetInt(0, 1);
    if (item) {
        readVector(intArr, floatArr, complexArr);
    }
}

template<class T>
void readTypeVector(ArraySequence<Vector<T> *> *arr, int count) {
    cout << "Введите координаты вектора\n:";
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        T item;
        cin >> item;
        element.Append(item);
    }


    cout << "Вы ввели: " << Vector<T>(element)
         << "\nЗаписать этот вектор? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
    int item;
    cin >> item;

    switch (item) {
        default: break;
        case 0: readTypeVector<T>(arr, count); break;
        case 1:
            auto *res = new Vector<T>(element);
            arr->Append(res);
            break;
    }
}

template<class T>
void generateRandomVector(ArraySequence<Vector<T> *> *arr, int count, T (*func)()) {
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        element.Append(func());
    }
    Vector<T> vec(element);
    cout << "Сгенерирован \"" << vec << "\". Записать или сгенерировать новый?\n"
                                        "\t-1: выход\n"
                                        "\t 0: сгенерировать новый\n"
                                        "\t 1: записать вектор в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomVector(arr, count, func);
            break;
        case 1:
            auto *res = new Vector<T>(element);
            arr->Append(res);
            break;
    }
}

//2
void operationWithVector(ArraySequence<Vector<int> *> *intArr,
                             ArraySequence<Vector<float> *> *floatArr,
                             ArraySequence<Vector<std::complex<int>> *> *complexArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            operationTypeWithVector<int>(intArr);
            break;
        case 2:
            operationTypeWithVector<float>(floatArr);
            break;
        case 3:
            operationTypeWithVector<complex<int>>(complexArr);
            break;
    }
}

template<class T>
void operationTypeWithVector(ArraySequence<Vector<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких векторов нет!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "В памяти находится \"" << len << "\" векторов, введите:\n"
                                                  "\t- индекс вектора, для его выбора\n"
                                                  "\t- число, больше чем число элементов, для вывода всех векторов\n "
                                                  "\t- число меньше нуля для выхода\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "Вы выбрали: " << *arr->Get(item) << endl;

        cout << "Какую операцию необходимо выполнить:\n"
                "\t0: выбрать другой вектор\n"
                "\t1: сложить векторы\n"
                "\t2: вычесть векторы\n"
                "\t3: умножить вектор на скаляр\n"
                "\t4: умножить векторы\n"
                "\t5: вычислить значение для данного значения аргумента\n"
                "\t6: выполнить композицию\n: ";

        int item2 = GetInt(0, 6);

        if (item2 == 0) continue;

        auto *vect1 = arr->Get(item);
        Vector<T> *vect2, *vect3;
        
        if (item2 == 3 || item2 == 5) {
            T elem;
            cout << "Введите скаляр\n: ";
            cin >> elem;
            if (item2 == 5) {
                cout << "Полученное значение: " << vect1->GetValue(elem) << endl << endl;
                continue;
            }
            vect3 = new Vector<T>;
            vect3 = (vect1->scalarMultVector(elem));
        } else {
            cout << "Введите:\n"
                    "\t-1: для выбора другого вектора\n"
                    "\t- индекс вектора для выполнения данной операции\n: ";

            int item3 = GetInt(-1, len - 1);
            if (item3 == -1) {
                continue;
            }

            vect2 = arr->Get(item3);
            vect3 = new Vector<T>;
            T res;
            switch (item2) {
                default:
                    break;
                case 1:
                    vect3 = vect1->addVectors(*vect2);
                    break;
                case 2:
                    vect3 = vect1->subVectors(*vect2);
                    break;
                case 4:
                    vect3 = vect1->multVector(*vect2);
                    break;
                case 6:
//                    res = vect1->GetValue(*vect2);
                    break;
            }
        }

        cout << "Был получен: \"" << *vect3 <<
             "\". Запомнить его под индексом \"" << len << "\" ?:\n"
                                                           "\t0 - нет\n"
                                                           "\t1 - да\n: ";

        item = GetInt(0, 1);
        if (item == 1) {
            arr->Append(vect3);
        } else {
            delete vect3;
        }
    }
}

//3
void printVector(ArraySequence<Vector<int> *> *intArr,
                 ArraySequence<Vector<float> *> *floatArr,
                 ArraySequence<Vector<std::complex<int>> *> *complexArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            printTypeVector<int>(intArr);
            break;
        case 2:
            printTypeVector<float>(floatArr);
            break;
        case 3:
            printTypeVector<complex<int>>(complexArr);
            break;
    }
}


template<class T>
void printTypeVector(ArraySequence<Vector<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких векторов нет!";
        return;
    }
    int item;
    do {
        cout << "В памяти находится \"" << arr->GetLength() << "\" векторов этого типа, введите:\n"
                                                               "\t- Индекс элемента для его вывода в консоль\n"
                                                               "\t- Число, больше чем количество векторов для вывода всех векторов "
                                                               "этого типа\n"
                                                               "\t- Число меньше нуля для выхода из функции\n:";
        item = GetInt();

        if (item < 0) break;

        if (item < arr->GetLength()) {
            cout << item << ": " << *arr->Get(item) << endl;
        }

        if (item >= arr->GetLength())
            printArr(arr);
        cout << endl;
    } while (item >= 0);
}

//4
void deleteVector(ArraySequence<Vector<int> *> *intArr,
                      ArraySequence<Vector<float> *> *floatArr,
                      ArraySequence<Vector<std::complex<int>> *> *complexArr) {

    auto item = GetType();
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeVector(intArr);
            break;
        case 2:
            deleteTypeVector(floatArr);
            break;
        case 3:
            deleteTypeVector(complexArr);
            break;
        default:
            break;
    }
}

template<class T>
void deleteTypeVector(ArraySequence<Vector<T>* > *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких векторов нет!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "Больше не осталось векторов этого типа! Автоматический выход из функции\n";
            break;
        }
        cout << "В памяти находится \"" << len << "\" векторов, введите:\n"
                                                  "\t- Число меньше нуля для выхода из функции\n"
                                                  "\t- Индекс элемента, для его выбора\n"
                                                  "\t- Число, больше длины массива, для вывода векторов в консоль\n: ";

        item = GetInt();

        if (item < 0) break;

        if (item >= arr->GetLength()) {
            printArr(arr);
            continue;
        }

        cout << "Выберите операцию:"
                "\t-1: вернуться к выбору индекса\n"
                "\t 0: для удаления элемента\n"
                "\t 1: для перемещения элемента на другое место\n: ";
        int item2 = GetInt(-1, 1);

        if (item2 == -1) continue;

        if (item2 == 0) {
            cout << "Вы действительно хотите удалить \"" << *arr->Get(item) << "\" ?\n"
                                                                               "\t0 - нет\n"
                                                                               "\t1 - да\n: ";
            item2 = GetInt(0, 1);
            if (item2 == 1) {
                arr->Pop(item);
            }
            continue;
        }

        cout << "Введите номер вектора, с которым надо поменять \""
             << item << "\" вектор\n: ";

        item2 = GetInt(0, len - 1);
        if (item != item2) {
            Vector<T> *vector = arr->Get(item);
            arr->Set(arr->Get(item2), item);
            arr->Set(vector, item2);
        }
    }
}
