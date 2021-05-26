
#include "menuLinForm.h"
#include "menuVector.h"

using namespace std;

int main() {
    int tupe;
    cout << "Выберите тип:\n 1-Линейная форма \n 2-Вектор\n";
    cin >> tupe;
    if (tupe == 1) {
        mainMenuLinForm();
    } else {
        mainMenuVector();
    }
    return 0;
}

