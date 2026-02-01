#include <iostream>
using namespace std;

int main() {
    //1 1
    int a, b;
    cout << "Введите два целых числа: ";
    cin >> a >> b;
    cout << a << " + " << b << " = " << a + b << endl;
    // 1 2
    double celsius;
    cout << "Введите температуру в градусах Цельсия: ";
    cin >> celsius;
    double fahrenheit = celsius * 9.0 / 5.0 + 32;
    cout << celsius << "°C = " << fahrenheit << "°F" << endl;
    // 2 1
    int num;
    cout << "Введите число: ";
    cin >> num;
    if (num % 2 == 0) {
        cout << num << " - четное число." << endl;
    }
    else {
        cout << num << " - нечетное число." << endl;
    }
    // 2 2
    int year;
    cout << "Введите год: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " - високосный год." << endl;
    }
    else {
        cout << year << " - не високосный год." << endl;
    }
    // 3 1
    int N, sum = 0;
    cout << "Введите N: ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << "Сумма чисел от 1 до " << N << " равна " << sum << "." << endl;
    //3 2
    int N;
    cout << "Введите число N: ";
    cin >> N;
    for (int i = 1; i <= 10; i++) {
        cout << N << " x " << i << " = " << N * i << endl;
    }
    // 4 1
    const int size = 10;
    int arr[size];
    cout << "Введите " << size << " целых чисел: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "Минимальный элемент: " << min << endl;
    //4 2
    const int rows = 3, cols = 3;
    int matrix[rows][cols];
    cout << "Введите матрицу 3x3:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Сумма строки " << i + 1 << ": " << rowSum << endl;
    }

