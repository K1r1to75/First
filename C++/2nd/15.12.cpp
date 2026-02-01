
#include <iostream>
using namespace std;

bool contains(double* arr, int size, double value) {
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) == value) return true;
    }
    return false;
}

// Задача 1
void task1() {
    int M, N;
    cout << "Введите M и N: ";
    cin >> M >> N;

    double* A = new double[M];
    double* B = new double[N];

    cout << "Введите массив A (" << M << " элементов): ";
    for (int i = 0; i < M; ++i) cin >> *(A + i);

    cout << "Введите массив B (" << N << " элементов): ";
    for (int i = 0; i < N; ++i) cin >> *(B + i);

    // Разности множеств A \ B
    double* temp = new double[M];
    int tempSize = 0;

    for (int i = 0; i < M; ++i) {
        double val = *(A + i);
        if (!contains(B, N, val) && !contains(temp, tempSize, val)) {
            *(temp + tempSize) = val;
            ++tempSize;
        }
    }
    // Разности множеств B \ A
    double* C = new double[tempSize];
    for (int i = 0; i < tempSize; ++i) *(C + i) = *(temp + i);

    cout << "Результат (элементы A, которых нет в B): ";
    for (int i = 0; i < tempSize; ++i) cout << *(C + i) << " ";
    cout << endl;

}
// Задача 2
void task2() {
    int M, N;
    cout << "Введите M и N: ";
    cin >> M >> N;

    double* A = new double[M];
    double* B = new double[N];

    cout << "Введите массив A (" << M << " элементов): ";
    for (int i = 0; i < M; ++i) cin >> *(A + i);

    cout << "Введите массив B (" << N << " элементов): ";
    for (int i = 0; i < N; ++i) cin >> *(B + i);

    // Симметрическая разность множеств A и B
    double* temp = new double[M + N];
    int tempSize = 0;

    for (int i = 0; i < M; ++i) {
        double val = *(A + i);
        if (!contains(B, N, val) && !contains(temp, tempSize, val)) {
            *(temp + tempSize) = val;
            ++tempSize;
        }
    }

    for (int i = 0; i < N; ++i) {
        double val = *(B + i);
        if (!contains(A, M, val) && !contains(temp, tempSize, val)) {
            *(temp + tempSize) = val;
            ++tempSize;
        }
    }

    double* C = new double[tempSize];
    for (int i = 0; i < tempSize; ++i) *(C + i) = *(temp + i);

    cout << "Результат (симметрическая разность A и B): ";
    for (int i = 0; i < tempSize; ++i) cout << *(C + i) << " ";
    cout << endl;
}

int main() {
    cout << "\tЗадача 1" << endl;
    task1();

    cout << "\n\tЗадача 2" << endl;
    task2();

    return 0;
}
