//
// Created by arina on 24.05.2021.
//

#include "test.h"
#include "Vector.h"
#include "LinkedListSequence.h"

#define maxSizeDA 100000  // *Максимальный размер динамического массива
#define maxSizeAS 1000    // *Максимальный размер последовательности массива
#define maxSizeLL 2000    // *Максимальный размер связного списка
#define maxSizeLS 2000    // *Максимальный размер последовательности списка
#define maxSizeP 200      // *Максимальная степень многочлена
#define maxItemP 10000    // *Максильманый элемент многочлена

void printDone(int count, int done, int print) {
    if (print)
        if (done == count)
            std::cout << "\tТест пройден (\"" << count << "\" итераций).\n\n";
        else
            std::cout << "\tТест не пройден (провалено \"" << count - done << "\", пройдено \"" << done << "\" тестов).\n\n";
    else if (done != count)
        throw testFault(done, count - done);
}

int getLen(int max) {
    int len;
    do {
        len = rand()%max;
    } while (len == 0);
    return len;
}

int getIndex(int max){
    if (max == 0) return 0;
    return rand()%max;
}

void testAll(int count, int print) {
    dynamicArrTest(count, print);
      ArraySequenceTest(count, print);
      LinkedListTest(count, print);
      LinkedListSequenceTest(count, print);
      VectorTest(count, print);
      LinFormTest(count,print);
}

void dynamicArrTest(int count, int print) {
    srand(count);
    if (print)
        std::cout << "Тестирование динамического массива:\n";
    dynamicArrTestResize(count, print);
    dynamicArrTestGetItem(count, print);
    dynamicArrTestReverse(count,print);
}

void dynamicArrTestResize(int count, int print) {
    int done = 0;
    if (print)
        std::cout <<"\tТест изменения размера массива:\n";

    for (int i = 0; i < count; i++) {
          DynamicArray<int> array;
        int len = getLen(maxSizeDA);
        array.Resize(len);
        if (array.GetLength() == len) {
            done++;
        }
    }

    printDone(count, done, print);
}

void dynamicArrTestGetItem(int count, int print) {
    int done = 0;
    int actions = 10;
    if (print)
        std::cout << "\tТест чтение элементов массива:\n";

    for (int i = 0; i < count; i+=actions) {
          DynamicArray<int> array;
        int len = getLen(maxSizeDA);
        array.Resize(len);
        for (int j = 0; j < actions; j++) {
            if (i + j >= count) break;
            int index = getIndex(maxSizeDA);
            try {
                array[index];
                if (index < len)
                    done++;
            }
            catch (  DynamicArray<int>::IndexOutOfRange err) {
                if (index >= len)
                    done++;
            }
        }
    }

    printDone(count, done, print);
}

void dynamicArrTestReverse(int count, int print) {
    int done = 0;
    int maxElement = 100000;
    if (print) std::cout << "\tТест разворота массива:\n";
    for (int i = 0; i < count; i++) {
          DynamicArray<int> array;
        int len = getLen(maxSizeDA);
        array.Resize(len);
        for (int j = 0; j < len; j++) {
            array[j] = rand();
        }
        auto arrayNew = array;
        arrayNew.Reverse();
        int ok = 1;
        for (int j = 0; j < len; j++) {
            if (array[j] != arrayNew[len - 1 - j]) {
                ok = 0;
                break;
            }
        }
        done += ok;
    }

    printDone(count, done, print);
}



void   ArraySequenceTest(int count, int print) {
    srand(count);
    if (print)
        std::cout << "Тестирование последовательности массива:\n";
      ArraySequenceTestResize(count, print);
      ArraySequenceTestGetItem(count, print);
      ArraySequenceTestReverse(count, print);
}

void   ArraySequenceTestResize(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование изменения размера последовательности:\n";
    for (int j = 0; j < count; j++) {
          ArraySequence<int> sequence;
        int len = getLen(maxSizeAS / 3);
        for (int i = 0; i < len; i++) {
            sequence.Append(i);
        }
        if (sequence.GetLength() != len)
            continue;

        for (int i = 0; i < len; i++) {
            sequence.Prepend(i);
        }

        if (sequence.GetLength() != len*2)
            continue;

        for (int i = 0; i < len; i++) {
            sequence.Insert(i, getIndex(sequence.GetLength()));
        }

        if (sequence.GetLength() != len*3)
            continue;

        for (int i = 0; i < len*3; i++) {
            sequence.Pop();
        }

        if (sequence.GetLength() != 0)
            continue;

        done++;
    }

    printDone(count, done, print);
}

void   ArraySequenceTestGetItem(int count, int print) {
    int done = 0;
    int actions = 100;
    if (print)
        std::cout << "\tТестирование чтения элеметов последовательности:\n";
    for (int i = 0; i < count; i+=actions) {
          ArraySequence<int> sequence;
        int len = getLen(maxSizeAS);
        for (int j = 0; j < len; j++) {
            sequence.Append(j);
        }
        for (int j = 0; j < actions; j++) {
            if (i + j >= count) break;
            int index = getIndex(maxSizeAS);
            try {
                if (sequence[index] == index)
                    done++;
            }
             catch (  ArraySequence<int>::IndexOutOfRange err) {
                 if (index >= len)
                     done++;
             }
        }
    }

    printDone(count, done, print);
}

void   ArraySequenceTestReverse(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование разворота последовательности:\n";
    for (int i = 0; i < count; i++) {
          ArraySequence<int> sequence;
        int len = getLen(maxSizeAS);
        for (int j = 0; j < len; j++) {
            sequence.Append(j);
        }
        auto sequenceRev = sequence;
        sequenceRev.Reverse();
        int res = 1;
        for (int j = 0; j < len; j++) {
            if (sequence[j] != sequenceRev[len - j - 1]) {
                res = 0;
                break;
            }
        }
        done += res;
    }

    printDone(count, done, print);
}


void   LinkedListTest(int count, int print) {
    srand(count);
    if (print)
        std::cout << "Тестирование связного списка:\n";
      LinkedListTestGetItem(count, print);
}


void   LinkedListTestGetItem(int count, int print) {
    int done = 0;
    int actions = 10;
    if (print)
        std::cout << "\tТестирование чтения элементов списка:\n";
    for (int i = 0; i < count; i++) {
          LinkedList<int> linkedList;
        int len = getLen(maxSizeLL);
        for (int j = 0; j < len; j++) {
            linkedList.Append(j);
        }
        int Done = 0;
        for (int j = 0; j < actions; j++) {
            //if (j + i >= count) break;
            int index = getIndex(len);
            if (linkedList[index] == index)
                Done++;
        }
        done += Done == actions;
    }

    printDone(count, done, print);
}


void   LinkedListSequenceTest(int count, int print) {
    if (print)
        std::cout << "Тестирование последовательности связного списка:\n";
      LinkedListSequenceTestResize(count, print);
      LinkedListSequenceTestGetItem(count, print);
}

void   LinkedListSequenceTestResize(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование изменения размера последовательности:\n";
    for (int i = 0; i < count; i++) {
          LinkedListSequence<int> LinkedListSequence;
        int len = getLen(maxSizeLS/3);
        for (int j = 0; j < len; j++) {
            LinkedListSequence.Append(j);
        }
        if (LinkedListSequence.GetLength() != len) continue;

        for (int j = 0; j < len; j++) {
            LinkedListSequence.Prepend(j);
        }
        if (LinkedListSequence.GetLength() != len * 2) continue;

        for (int j = 0; j < len; j++) {
            LinkedListSequence.Insert(j, getIndex(LinkedListSequence.GetLength()));
        }
        if (LinkedListSequence.GetLength() != len * 3) continue;

        done++;
    }

    printDone(count, done, print);
}

void   LinkedListSequenceTestGetItem(int count, int print) {
    int done = 0;
    int actions = 10;
    if (print)
        std::cout << "\tТестирование чтения элементов последовательности:\n";
    for (int i = 0; i < count; i+=actions) {
          LinkedListSequence<int> LinkedListSequence;
        int len = getLen(maxSizeLS);
        for (int j = 0; j < len; j++) {
            LinkedListSequence.Append(j);
        }
        for (int j = 0; j < actions; j++) {
            int index = getIndex(len);
            if (LinkedListSequence[index] == index)
                done++;
        }
    }

    printDone(count, done, print);
}



void   VectorTest(int count, int print) {
    if (print)
        std::cout << "Тестирование многочленов:\n";
      VectorTestSum(count, print);
      VectorTestSub(count, print);
      VectorTestMult(count, print);
      VectorTestScalar(count, print);
}

void   VectorTestSum(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование суммирования:\n";
    for (int i = 0; i < count; i++) {
        int len1 = getLen(maxSizeP);
        int len2 = getLen(maxSizeP);
        if (len1 < len2) {
            int d = len1;
            len1 = len2;
            len2 = d;
        }
          ArraySequence<int> arraySequence1;
          ArraySequence<int> arraySequence2;
        for (int j = 0; j < len1; j++) {
            arraySequence1.Append(getIndex(maxItemP) + 1);
        }

        for (int j = 0; j < len2; j++) {
            arraySequence2.Append(getIndex(maxItemP) + 1);
        }
          Vector<int> vec1(arraySequence1);
          Vector<int> vec2(arraySequence2);
        auto res1 = vec1 + vec2;
        auto res2 = vec2 + vec1;
        if (res1 != res2) continue;
        int res = 1;
        for (int j = 0; j < len2 && res == 1; j++) {
            if (vec1[j] + vec2[j] != res1[j])
                res = 0;
        }

        for (int j = len2; j < len1 && res == 1; j++) {
            if (vec1[j] != res1[j])
                res = 0;
        }

        done += res;
    }

    printDone(count, done, print);
}

void   VectorTestSub(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование вычитания:\n";
    for (int i = 0; i < count; i++) {
        int len1 = getLen(maxSizeP);
        int len2 = getLen(maxSizeP);
        if (len1 < len2) {
            int d = len1;
            len1 = len2;
            len2 = d;
        }
          ArraySequence<int> arraySequence1;
          ArraySequence<int> arraySequence2;
        for (int j = 0; j < len1; j++) {
            arraySequence1.Append(getIndex(maxItemP) + 1);
        }

        for (int j = 0; j < len2; j++) {
            arraySequence2.Append(getIndex(maxItemP) + 1);
        }
          Vector<int> vector1(arraySequence1);
          Vector<int> vector2(arraySequence2);
        auto res1 = vector1 - vector2;
        auto res2 = vector2 - vector1;
        if (res1 != -res2) continue;
        int res = 1;
        for (int j = 0; j < len2 && res == 1; j++) {
            if (vector1[j] - vector2[j] != res1[j])
                res = 0;
        }

        for (int j = len2; j < len1 && res == 1; j++) {
            if (vector1[j] != res1[j])
                res = 0;
        }

        done += res;
    }

    printDone(count, done, print);
}

void   VectorTestMult(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование умножения:\n";
    for (int i = 0; i < count; i++) {
        int len1 = getLen(maxSizeP/4);
        int len2 = getLen(maxSizeP/4);
        if (len1 < len2) {
            int d = len1;
            len1 = len2;
            len2 = d;
        }
          ArraySequence<int> arraySequence1;
          ArraySequence<int> arraySequence2;
        for (int j = 0; j < len1; j++) {
            arraySequence1.Append(getIndex(maxItemP) + 1);
        }

        for (int j = 0; j < len2; j++) {
            arraySequence2.Append(getIndex(maxItemP) + 1);
        }
          Vector<int> vector1(arraySequence1);
          Vector<int> vector2(arraySequence2);
        auto res1 = vector1 * vector2;
        auto res2 = vector2 * vector1;
        if (res1 != res2) continue;
        int res = 1;
          ArraySequence<int> resultArr;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                int elem = arraySequence1[i] * arraySequence2[j];
                int index = i + j;
                if (resultArr.GetLength() <= index) {
                    resultArr.Append(elem);
                    continue;
                }
                resultArr[index] += elem;
            }
        }
          Vector<int> result(resultArr);
        if (result != res1) continue;
        done += res;
    }

    printDone(count, done, print);
}

void   VectorTestScalar(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование скалярного умножения:\n";
    for (int i = 0; i < count; i++) {
          ArraySequence<int> array;
        int len = getLen(maxSizeP);
        for (int j = 0; j < len; j++) {
            array.Append(getIndex(maxItemP));
        }
        int scalar = getIndex(maxItemP);
          Vector<int> vector(array);
        auto res = vector * scalar;
        if (scalar == 0 && res.GetLength() == 1) {
            done++;
            continue;
        }
        if (res.GetLength() != vector.GetLength()) {
            continue;
        }
        int Done = 1;
        for (int j = 0; j < vector.GetLength() && Done == 1; j++) {
            if (res[j] != vector[j] * scalar)
                Done = 0;
        }

        done+=Done;
        if (!Done) {
            std::cout << res << std::endl;
        }
    }

    printDone(count, done, print);
}



void   LinFormTest(int count, int print) {
    if (print)
        std::cout << "Тестирование многочленов:\n";
    LinFormTestSum(count, print);
    LinFormTestSub(count, print);
    LinFormTestGetValue(count, print);
    LinFormTestScalar(count, print);
}

void   LinFormTestSum(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование суммирования:\n";
    for (int i = 0; i < count; i++) {
        int len1 = getLen(maxSizeP);
        int len2 = getLen(maxSizeP);
        if (len1 < len2) {
            int d = len1;
            len1 = len2;
            len2 = d;
        }
        ArraySequence<int> arraySequence1;
        ArraySequence<int> arraySequence2;
        for (int j = 0; j < len1; j++) {
            arraySequence1.Append(getIndex(maxItemP) + 1);
        }

        for (int j = 0; j < len2; j++) {
            arraySequence2.Append(getIndex(maxItemP) + 1);
        }
        LinForm<int> linform1(arraySequence1);
        LinForm<int> linform2(arraySequence2);
        auto res1 = linform1 + linform2;
        auto res2 = linform2 + linform1;
        if (res1 != res2) continue;
        int res = 1;
        for (int j = 0; j < len2 && res == 1; j++) {
            if (linform1[j] + linform2[j] != res1[j])
                res = 0;
        }

        for (int j = len2; j < len1 && res == 1; j++) {
            if (linform1[j] != res1[j])
                res = 0;
        }

        done += res;
    }

    printDone(count, done, print);
}

void   LinFormTestSub(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование вычитания:\n";
    for (int i = 0; i < count; i++) {
        int len1 = getLen(maxSizeP);
        int len2 = getLen(maxSizeP);
        if (len1 < len2) {
            int d = len1;
            len1 = len2;
            len2 = d;
        }
        ArraySequence<int> arraySequence1;
        ArraySequence<int> arraySequence2;
        for (int j = 0; j < len1; j++) {
            arraySequence1.Append(getIndex(maxItemP) + 1);
        }

        for (int j = 0; j < len2; j++) {
            arraySequence2.Append(getIndex(maxItemP) + 1);
        }
        LinForm<int> LinForm1(arraySequence1);
        LinForm<int> LinForm2(arraySequence2);
        auto res1 = LinForm1 - LinForm2;
        auto res2 = LinForm2 - LinForm1;
        if (res1 != -res2) continue;
        int res = 1;
        for (int j = 0; j < len2 && res == 1; j++) {
            if (LinForm1[j] - LinForm2[j] != res1[j])
                res = 0;
        }

        for (int j = len2; j < len1 && res == 1; j++) {
            if (LinForm1[j] != res1[j])
                res = 0;
        }

        done += res;
    }

    printDone(count, done, print);
}


void   LinFormTestScalar(int count, int print) {
    int done = 0;
    if (print)
        std::cout << "\tТестирование скалярного умножения:\n";
    for (int i = 0; i < count; i++) {
        ArraySequence<int> array;
        int len = getLen(maxSizeP);
        for (int j = 0; j < len; j++) {
            array.Append(getIndex(maxItemP));
        }
        int scalar = getIndex(maxItemP);
        LinForm<int> LinForm(array);
        auto res = LinForm * scalar;
        if (scalar == 0 && res.GetLength() == 1) {
            done++;
            continue;
        }
        if (res.GetLength() != LinForm.GetLength()) {
            continue;
        }
        int Done = 1;
        for (int j = 0; j < LinForm.GetLength() && Done == 1; j++) {
            if (res[j] != LinForm[j] * scalar)
                Done = 0;
        }

        done+=Done;
        if (!Done) {
            std::cout << res << std::endl;
        }
    }

    printDone(count, done, print);
}


void   LinFormTestGetValue(int count, int print) {
        int done = 0;
        if (print)
            std::cout << "\tТестирование получения значения :\n";
        for (int i = 0; i < count; i++) {
            int len1 = getLen(maxSizeP);

            ArraySequence<int> arraySequence1;
            for (int j = 0; j < len1; j++) {
                arraySequence1.Append(getIndex(maxItemP) + 1);
            }

            LinForm<int> LinForm1(arraySequence1);
            auto res1 = LinForm1.GetValue(arraySequence1);
            int res = 1;
            int res2= 0;
            for (int i=0;i<len1;i++){
                res2+=arraySequence1[i];
            }
            if (res1 != res2)
                res = 0;

            done += res;
        }

        printDone(count, done, print);
    }