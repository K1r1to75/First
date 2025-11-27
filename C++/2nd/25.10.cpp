#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // 1
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }

    // 2
    int N;
    cout << "Введите число N: ";
    cin >> N;

    cout << "Простые числа до " << N << ": ";
    for (int num = 2; num <= N; num++) {
        bool prostoe = true;
        for (int delitel = 2; delitel < num; delitel++) {
            if (num % delitel == 0) {
                prostoe = false;
                break;
            }
        }
        if (prostoe) {
            cout << num << " ";
        }
    }
    cout << endl;

    // 3
    int M, K;
    cout << "Введите M и N: ";
    cin >> M >> K;

    int chislo = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cout << chislo << " ";
            chislo++;
        }
        cout << endl;
    }

    // 4
    int P;
    cout << "Введите N для перестановок (не больше 3): ";
    cin >> P;

    if (P == 1) {
        cout << "1" << endl;
    }
    else if (P == 2) {
        cout << "1 2" << endl;
        cout << "2 1" << endl;
    }
    else if (P == 3) {
        cout << "1 2 3" << endl;
        cout << "1 3 2" << endl;
        cout << "2 1 3" << endl;
        cout << "2 3 1" << endl;
        cout << "3 1 2" << endl;
        cout << "3 2 1" << endl;
    }
    else {
        cout << "Слишком сложно для новичка " << endl;
    }

    return 0;
}