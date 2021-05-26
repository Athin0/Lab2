

#include "menuLinForm.h"
#include "DynamicArray.cpp"
#include "random"
#include "baseFunc.h"
#include "test.h"
#include "menuVector.h"

#define maxInt 10000

using namespace std;

template<class T>
void printArr(ArraySequence<LinForm<T> *> *arr) {
    for (int i = 0; i < arr->GetLength(); i++) {
        cout << i << ": " << *arr->Get(i) << endl;
    }
    cout << endl;
}

void mainMenuLinForm() {
    ArraySequence<LinForm<int> *> arrInt ;
    ArraySequence<LinForm<float> *> arrFloat;
    ArraySequence<LinForm<complex<int>> *> arrComplex;
    int item;
    while (true) {
        cout << "Программа имеет следующие возможности: \n"
             << "\t1: Ввести и запомнить линейную форму\n"
             << "\t2: Выполнить операцию над линейными формами\n"
             << "\t3: Вывести линейную форму в консоль\n"
             << "\t4: Удалить или переместить линейную форму в памяти\n"
             << "\t5: Запустить функцию тестирования линейной формы\n"
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
                readLinForm(&arrInt, &arrFloat, &arrComplex);
                break;
            case 2:
                operationWithLinForm(&arrInt, &arrFloat, &arrComplex);
                break;
            case 3:
                printLinForm(&arrInt, &arrFloat, &arrComplex);
                break;
            case 4:
                deleteLinForm(&arrInt, &arrFloat, &arrComplex);
                break;
            case 5:
                testFunc();
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


//1
void readLinForm(ArraySequence<LinForm<int> *> *intArr,
                ArraySequence<LinForm<float> *> *floatArr,
                ArraySequence<LinForm<std::complex<int>> *> *complexArr) {

    int count = 0;

    cout << "Введите степень линейной формы или -1 для выхода\n: ";
    do {
        if (count < 0) {
            cout << "Ллинейные формы отрицательной степени не поддерживаются!\n: ";
        }
        cin >> count;

        if (count == -1)
            return;
    } while (count < 0);

    auto item = GetType();
    if (item == 0) return;

    cout << "Сгенерировать линейную форму автоматически или ввести вручную?:\n"
            "\t0: выход\n"
            "\t1: ввести линейную форму вручную\n"
            "\t2: сгенерировать линейную форму\n: ";

    int item2 = GetInt(0, 2);
    if (item2 == 0) return;

    if (item2 == 1) {
        switch (item) {
            case 1:
                readTypeLinForm<int>(intArr, count);
                break;
            case 2:
                readTypeLinForm<float>(floatArr, count);
                break;
            case 3:
                readTypeLinForm<complex<int>>(complexArr, count);
                break;
            default:
                break;
        }
    }

    if (item2 == 2) {
        switch (item) {
            case 1:
                generateRandomLinForm<int>(intArr, count, randomInt);
                break;
            case 2:
                generateRandomLinForm<float>(floatArr, count, randomFloat);
                break;
            case 3:
                generateRandomLinForm<complex<int>>(complexArr, count, randomComplex);
                break;
            default:
                break;
        }
    }

    cout << "Хотите ввести ещё одну линейную форму?\n"
            "\t0 - нет\n"
            "\t1 - да\n: ";

    item = GetInt(0, 1);
    if (item) {
        readLinForm(intArr, floatArr, complexArr);
    }
}

template<class T>
void readTypeLinForm(ArraySequence<LinForm<T> *> *arr, int count) {
    cout << "Введите коэффициенты линейную формы\n:";
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        T item;
        cin >> item;
        element.Append(item);
    }


    cout << "Вы ввели: " << LinForm<T>(element)
         << "\nЗаписать эту линейную форму? (1 - да, 0 - повторить попытку ввода, "
         << "другое число приведёт к выходу их функции)\n:";
    int item;
    cin >> item;

    switch (item) {
        default: break;
        case 0: readTypeLinForm<T>(arr, count); break;
        case 1:
            auto *res = new LinForm<T>(element);
            arr->Append(res);
            break;
    }
}

template<class T>
void generateRandomLinForm(ArraySequence<LinForm<T> *> *arr, int count, T (*func)()) {
    ArraySequence<T> element;
    for (int i = 0; i < count; i++) {
        element.Append(func());
    }
    LinForm<T> linf(element);
    cout << "Сгенерирована \"" << linf << "\". Записать или сгенерировать новую?\n"
                                        "\t-1: выход\n"
                                        "\t 0: сгенерировать новую\n"
                                        "\t 1: записать линейную форму в память\n: ";
    int item = GetInt(-1, 1);
    switch (item) {
        default:
            break;
        case 0:
            generateRandomLinForm(arr, count, func);
            break;
        case 1:
            auto *res = new LinForm<T>(element);
            arr->Append(res);
            break;
    }
}

//2
void operationWithLinForm(ArraySequence<LinForm<int> *> *intArr,
                         ArraySequence<LinForm<float> *> *floatArr,
                         ArraySequence<LinForm<std::complex<int>> *> *complexArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            operationTypeWithLinForm<int>(intArr);
            break;
        case 2:
            operationTypeWithLinForm<float>(floatArr);
            break;
        case 3:
            operationTypeWithLinForm<complex<int>>(complexArr);
            break;
    }
}

template<class T>
void operationTypeWithLinForm(ArraySequence<LinForm<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких линейных форм нет!\n";
        return;
    }
    int item;

    while (true) {
        auto len = arr->GetLength();
        cout << "В памяти находится \"" << len << "\" линейных форм, введите:\n"
                                                  "\t- индекс линейной формы, для выбора\n"
                                                  "\t- число, больше чем число элементов, для вывода всех линейных форм\n "
                                                  "\t- число меньше нуля для выхода\n: ";

        item = GetInt();
        if (item < 0) break;

        if (item >= len) {
            printArr(arr);
            continue;
        }

        cout << "Вы выбрали: " << *arr->Get(item) << endl;

        cout << "Какую операцию необходимо выполнить:\n"
                "\t0: выбрать другую линейную форму\n"
                "\t1: сложить линейные формы\n"
                "\t2: вычесть линейные формы\n"
                "\t3: умножить линейную форму на скаляр\n"
                "\t4: вычислить значение для данной линейной формы\n: ";

        int item2 = GetInt(0, 4);

        if (item2 == 0) continue;

        auto *linf1 = arr->Get(item);
        LinForm<T> *linf2, *linf3;

        if (item2 == 4) {
            ArraySequence<T> arr;
            for (int i = 0; i < linf1->GetLength(); i++) {
                cout<< "Введите элемент["<<i<<"] :";
                T item;
                cin >> item;
                arr.Append(item);
            }
            T res = linf1->GetValue(arr);
            cout << "Полученное значение: " << res << endl << endl;
            continue;
        }

        if (item2 == 3) {
            T elem;
            cout << "Введите скаляр\n: ";
            cin >> elem;
            linf3 = new LinForm<T>;
            linf3 = (linf1->scalarMultLinForm(elem));
        } else {
            cout << "Введите:\n"
                    "\t-1: для выбора другой линейной формы\n"
                    "\t- индекс линейной формы для выполнения данной операции\n: ";

            int item3 = GetInt(-1, len - 1);
            if (item3 == -1) {
                continue;
            }

            linf2 = arr->Get(item3);
            linf3 = new LinForm<T>;
            T res;
            switch (item2) {
                default:
                    break;
                case 1:
                    linf3 = linf1->addLinForms(*linf2);
                    break;
                case 2:
                    linf3 = linf1->subLinForms(*linf2);
                    break;
            }
        }

        cout << "Был получен: \"" << *linf3 <<
             "\". Запомнить его под индексом \"" << len << "\" ?:\n"
                                                           "\t0 - нет\n"
                                                           "\t1 - да\n: ";

        item = GetInt(0, 1);
        if (item == 1) {
            arr->Append(linf3);
        } else {
            delete linf3;
        }
    }
}

//3
void printLinForm(ArraySequence<LinForm<int> *> *intArr,
                 ArraySequence<LinForm<float> *> *floatArr,
                 ArraySequence<LinForm<std::complex<int>> *> *complexArr) {
    int type = GetType();

    switch (type) {
        default:
            break;
        case 1:
            printTypeLinForm<int>(intArr);
            break;
        case 2:
            printTypeLinForm<float>(floatArr);
            break;
        case 3:
            printTypeLinForm<complex<int>>(complexArr);
            break;
    }
}


template<class T>
void printTypeLinForm(ArraySequence<LinForm<T> *> *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких линейных форм нет!";
        return;
    }
    int item;
    do {
        cout << "В памяти находится \"" << arr->GetLength() << "\" линейных форм этого типа, введите:\n"
                                                               "\t- Индекс элемента для его вывода в консоль\n"
                                                               "\t- Число, больше чем количество линейных форм для вывода всех линейных форм "
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
void deleteLinForm(ArraySequence<LinForm<int> *> *intArr,
                  ArraySequence<LinForm<float> *> *floatArr,
                  ArraySequence<LinForm<std::complex<int>> *> *complexArr) {

    auto item = GetType();
    if (item == 0) return;

    switch (item) {
        case 1:
            deleteTypeLinForm(intArr);
            break;
        case 2:
            deleteTypeLinForm(floatArr);
            break;
        case 3:
            deleteTypeLinForm(complexArr);
            break;
        default:
            break;
    }
}


template<class T>
void deleteTypeLinForm(ArraySequence<LinForm<T>* > *arr) {
    if (arr->GetLength() == 0) {
        cout << "Таких линейных форм нет!\n";
        return;
    }
    int item;

    while (true) {
        int len = arr->GetLength();
        if (len == 0) {
            cout << "Больше не осталось линейных форм этого типа! Автоматический выход из функции\n";
            break;
        }
        cout << "В памяти находится \"" << len << "\" линейных форм, введите:\n"
                                                  "\t- Число меньше нуля для выхода из функции\n"
                                                  "\t- Индекс элемента, для его выбора\n"
                                                  "\t- Число, больше длины массива, для вывода линейных форм в консоль\n: ";

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

        cout << "Введите номер линейной формы, с которой надо поменять \""
             << item << "\" линейную форму\n: ";

        item2 = GetInt(0, len - 1);
        if (item != item2) {
            LinForm<T> *LinForm = arr->Get(item);
            arr->Set(arr->Get(item2), item);
            arr->Set(LinForm, item2);
        }
    }
}
