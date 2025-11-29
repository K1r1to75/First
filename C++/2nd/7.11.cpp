#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
    // 1:
    srand(time(NULL));
    const int size = 10;
    int ar[size]{};
    int sr = 0;
    for (int i = 0; i < size; i++)
    {
        ar[i] = rand() % 100;
        sr += ar[i];
        cout << ar[i] << " ";
    }
    int average = sr / size;
    cout << "\nСреднее арифметическое: " << average << endl;
    cout << "\n\n";

    // 3:
    const int size_2 = 20;
    double ar_2[size_2]{};
    cout << "Исходный массив: " << endl;
    for (int i = 0; i < size_2; i++)
    {
        ar_2[i] = rand() % 2001 - 1000 / 1000.0;
        cout << ar_2[i] << " ";
    }
    cout << endl;
    // Сортировка пузырьком
    for (int i = 0; i < size_2 - 1; i++) {
        for (int j = 0; j < size_2 - i - 1; j++) {
            if (ar_2[j] < ar_2[j + 1]) {
                int temp = ar_2[j];
                ar_2[j] = ar_2[j + 1];
                ar_2[j + 1] = temp;
            }
        }
    }
    cout << "Отсортированный массив:\n";
    for (int i = 0; i < size_2; i++) {
        cout << ar_2[i] << " ";
    }
    cout << "\n\n";

    // 4:
    const int size_3 = 20;
    int ar_3[size_3]{};
    int even_ar_3[0];
    int even_count = 0;
    cout << "Исходный массив: " << endl;
    for (int i = 0; i < size_3; i++)
    {
        ar_3[i] = rand() % 50;
        cout << ar_3[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size_3; i++)
    {
        if (ar_3[i] % 2 == 0) {
            even_ar_3[even_count++] = ar_3[i];
        }
    }

    cout << "Массив только с четными числами:" << endl;
    for (int i = 0; i < even_count; i++)
    {
        cout << even_ar_3[i] << " ";
    }
    cout << "\n\n";

    // Многомерные массивы
    // 1
    const int size_6 = 5;
    int ar_6[size_6][size_6];
    for (int i = 0; i < size_6; i++)
    {
        cout << "\n";
        for (int j = 0; j < size_6; j++)
        {
            ar_6[i][j] = rand() % 9 + 1;
            cout << ar_6[i][j] << " ";
        }
    }
    cout << endl;
    cout << "Главная диагональ:\n";
    for (int i = 0; i < size; i++)
    {
        cout << ar_6[i][i];
        if (i < size_6 - 1) cout << " - ";
    }
    cout << "\n\n";

    // 2
    const int size_7 = 4;
    int ar_7[size_7][size_7];
    for (int i = 0; i < size_7; i++)
    {
        cout << "\n";
        for (int j = 0; j < size_7; j++)
        {
            ar_7[i][j] = rand() % 100;
            cout << ar_7[i][j] << " ";
        }
    }
    cout << endl;
    int sum = 0;
    for (int i = 0; i < size_7; i++)
    {
        sum += ar_7[0][i];
    }
    cout << "\nСумма элементов первой строки: " << sum;
    cout << "\n\n";


    // 4
    const int size_8 = 6;
    int ar_8[size_8][size_8];
    for (int i = 0; i < size_8; i++)
    {
        cout << "\n";
        for (int j = 0; j < size_8; j++)
        {
            int z = rand() % 19 + 1;
            ar_8[i][j] = z;
            ar_8[j][i] = z;
        }
    }
    cout << "Симметричная матрица" << endl;
    for (int i = 0; i < size_8; i++)
    {
        cout << " ";
        for (int j = 0; j < size_8; j++)
        {
            cout << ar_8[i][j] << " ";
        }
        cout << " " << endl;

    }
    cout << "\n\n";


    // 5
    const int size_9 = 3;
    int ar_9[size_9][size_9];
    for (int i = 0; i < size_9; i++)
    {
        cout << "\n";
        for (int j = 0; j < size_9; j++)
        {
            ar_9[i][j] = rand() % 9 + 1;
            cout << ar_9[i][j] << " ";
        }
    }
    int min_value = ar_9[0][0];
    int m_v = 0;
    int m_g = 0;
    for (int i = 0; i < size_9; i++)
    {
        for (int j = 0; j < size_9; j++)
        {
            if (ar_9[i][j] < min_value) {
                min_value = ar_9[i][j];
                m_v = i;
                m_g = j;
            }
        }
    }
    cout << "\nМинимальный элемент: " << min_value << endl;
    cout << "Координаты: столбец " << m_v + 1 << ", строка " << m_g + 1 << endl;

}