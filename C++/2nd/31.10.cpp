#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    srand(time(NULL));
    int a;
    a = 1;
    cout << a << "\n\n";

    int num_1, num_1_1;
    cout << "Введите число: ";
    cin >> num_1;
    num_1_1 = num_1 % 2;
    if (num_1_1 == 0) {
        cout << "Число четное!" << endl;
    }
    else {
        cout << "Число нечетное!" << endl;
    }
    cout << "\n\n";
    int i = 0;
    for (; i <= 10;) {
        cout << i * i * i << " ";
        i++;
    }
    cout << "\n\n";


    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int array[size];

    cout << "Исходный массив:\n";
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    cout << "\n\n";

    // Сортировка пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
    cout << "\n\n";

    const int m = 3;
    const int n = 3;
    int x = 1;
    int mr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mr[i][j] = x;
            x++;
            cout << mr[i][j] << " ";
        }
        cout << "\n\n";
    }
    cout << "\n\n";
    return 0;
}