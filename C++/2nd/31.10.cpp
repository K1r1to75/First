#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    // 1
    const int ROWS = 3, COLS = 4;
    int arr[ROWS][COLS] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    // Выводим исходный массив
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Вычисляем статистику
    int sum = 0;
    int min = arr[0][0];
    int max = arr[0][0];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += arr[i][j];
            if (arr[i][j] < min) min = arr[i][j];
            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    double average = (double)sum / (ROWS * COLS);

    cout << "Сумма всех элементов: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Минимальный элемент: " << min << endl;
    cout << "Максимальный элемент: " << max << endl;

    // 2
    int rowSum[ROWS] = { 0 };
    int colSum[COLS] = { 0 };
    int total = 0;

    // Вычисляем суммы по строкам и столбцам
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
        total += rowSum[i];
    }

    // Выводим в требуемом формате
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << "| " << rowSum[i] << endl;
    }

    // Разделительная линия
    for (int i = 0; i < COLS; i++) {
        cout << "---\t";
    }
    cout << "------" << endl;

    // Суммы по столбцам и общая сумма
    for (int j = 0; j < COLS; j++) {
        cout << colSum[j] << "\t";
    }
    cout << "| " << total << endl;

    // 3
    const int ROWS1 = 5, COLS1 = 10;
    const int ROWS2 = 5, COLS2 = 5;
    int arr1[ROWS1][COLS1];
    int arr2[ROWS2][COLS2];

    // Заполняем первый массив случайными числами
    cout << "Первый массив (5x10):" << endl;
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            arr1[i][j] = rand() % 51; // 0-50
            cout << arr1[i][j] << "\t";
        }
        cout << endl;
    }

    // Заполняем второй массив по правилу
    cout << "\nВторой массив (5x5):" << endl;
    for (int i = 0; i < ROWS2; i++) {
        for (int j = 0; j < COLS2; j++) {
            // Суммируем пары элементов из первого массива
            int index1 = j * 2;      // первый элемент пары
            int index2 = j * 2 + 1;  // второй элемент пары
            arr2[i][j] = arr1[i][index1] + arr1[i][index2];
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}