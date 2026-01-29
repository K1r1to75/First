#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//1
int degree(int base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) return 0;
    return base * degree(base, exponent - 1);
}

//2
void printStars(int n) {
    if (n <= 0) return;
    cout << "*";
    printStars(n - 1);
}

//3
int sumRange(int a, int b) {
    if (a > b) return 0;
    return a + sumRange(a + 1, b);
}

//4
int findminsumposition(int arr[], int size, int sequencelength = 10, int currentpos = 0) {
    if (currentpos > size - sequencelength) return -1;

    int currentsum = 0;
    for (int i = 0; i < sequencelength; i++) {
        currentsum += arr[currentpos + i];
    }

    int nextpos = findminsumposition(arr, size, sequencelength, currentpos + 1);
    if (nextpos == -1) return currentpos;

    int nextsum = 0;
    for (int i = 0; i < sequencelength; i++) {
        nextsum += arr[nextpos + i];
    }

    if (currentsum <= nextsum) {
        return currentpos;
    }
    else {
        return nextpos;
    }
}

//5

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) {
    return findMax(findMax(a, b), c);
}

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMax(int arr[][5], int rows, int cols) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

int findMax(int arr[][3][4], int dim1, int dim2, int dim3) {
    int maxVal = arr[0][0][0];
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                if (arr[i][j][k] > maxVal) {
                    maxVal = arr[i][j][k];
                }
            }
        }
    }
    return maxVal;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    cout << "\tЗадание 1: Степень числа" << endl;
    cout << "2^5 = " << degree(2, 5) << endl;
    cout << "3^4 = " << degree(3, 4) << endl;
    cout << "5^(-2) = " << degree(5, -2) << endl;

    cout << "\n\tЗадание 2: Звезды в ряд" << endl;
    int starscount;
    cout << "Введите количество звезд: ";
    cin >> starscount;
    cout << "Результат: ";
    printStars(starscount);
    cout << endl;

    cout << "\n\tЗадание 3: Сумма в диапазоне" << endl;
    int a, b;
    cout << "Введите начало диапазона a: ";
    cin >> a;
    cout << "Введите конец диапазона b: ";
    cin >> b;
    cout << "Сумма чисел от " << a << " до " << b << " = " << sumRange(a, b) << endl;

    cout << "\n\tЗадание 4: Поиск позиции с минимальной суммой" << endl;
    const int array_size = 100;
    int arr[array_size];

    for (int i = 0; i < array_size; i++) {
        arr[i] = rand() % 100;
    }

    int position = findminsumposition(arr, array_size);

    cout << "Позиция с минимальной суммой 10 чисел: " << position << endl;
    cout << "Элементы с этой позиции: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[position + i] << " ";
    }
    cout << endl;

    cout << "\n\tЗадание 5: Перегруженные функции максимума" << endl;

    cout << "Максимум из 5 и 10: " << findMax(5, 10) << endl;
    cout << "Максимум из 3, 7 и 2: " << findMax(3, 7, 2) << endl;

    int oneDimArray[] = { 3, 7, 2, 9, 1, 8 };
    int oneDimSize = sizeof(oneDimArray) / sizeof(oneDimArray[0]);
    cout << "Максимум в одномерном массиве: " << findMax(oneDimArray, oneDimSize) << endl;

    int twoDimArray[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };
    cout << "Максимум в двумерном массиве: " << findMax(twoDimArray, 3, 5) << endl;

    int threeDimArray[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    cout << "Максимум в трехмерном массиве: " << findMax(threeDimArray, 2, 3, 4) << endl;

    return 0;
}