#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); // Инициализация генератора случайных чисел

    // 1
    const int ROWS = 3, COLS = 4;
    int arr1[ROWS][COLS] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    // Вывод массива
    cout << "Массив:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    // Подсчет статистики
    int sum = 0, min = arr1[0][0], max = arr1[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += arr1[i][j];
            if (arr1[i][j] < min) min = arr1[i][j];
            if (arr1[i][j] > max) max = arr1[i][j];
        }
    }
    double average = (double)sum / (ROWS * COLS);

    cout << "Сумма всех элементов: " << sum << endl;
    cout << "Среднее арифметическое: " << average << endl;
    cout << "Минимальный элемент: " << min << endl;
    cout << "Максимальный элемент: " << max << endl;

    // 2
    int rowSums[ROWS] = { 0 };
    int colSums[COLS] = { 0 };
    int totalSum = 0;

    // Вычисление сумм по строкам и столбцам
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rowSums[i] += arr1[i][j];
            colSums[j] += arr1[i][j];
        }
        totalSum += rowSums[i];
    }

    // Вывод в требуемом формате
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << "| " << rowSums[i] << endl;
    }

    // Разделительная линия
    for (int i = 0; i < COLS * 2 + 3; i++) {
        cout << "-";
    }
    cout << endl;

    // Суммы по столбцам и общая сумма
    for (int j = 0; j < COLS; j++) {
        cout << colSums[j] << " ";
    }
    cout << "| " << totalSum << endl;

    // 3
    const int ROWS1 = 5, COLS1 = 10;
    const int ROWS2 = 5, COLS2 = 5;

    int array1[ROWS1][COLS1];
    int array2[ROWS2][COLS2];

    // Заполнение первого массива случайными числами
    cout << "Первый массив (5x10):" << endl;
    for (int i = 0; i < ROWS1; i++) {
        for (int j = 0; j < COLS1; j++) {
            array1[i][j] = rand() % 51; // числа от 0 до 50
            cout << array1[i][j] << "\t";
        }
        cout << endl;
    }

    // Заполнение второго массива по правилу
    cout << "\nВторой массив (5x5):" << endl;
    for (int i = 0; i < ROWS2; i++) {
        for (int j = 0; j < COLS2; j++) {
            int index = j * 2; // индекс в первом массиве
            array2[i][j] = array1[i][index] + array1[i][index + 1];
            cout << array2[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}