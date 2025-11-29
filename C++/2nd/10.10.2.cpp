#include <iostream>
using namespace std;

int main() {
    //Задание 1:
    //Пользователь вводит число. Определить количество цифр
    //в этом числе, посчитать их сумму и среднее арифметическое.
    //Определить количество нулей в этом числе. Общение с пользователем организовать через меню.
    long long number;
    cout << "Введите число: ";
    cin >> number;
    int choice;
    bool running = true;

    while (running) {
        cout << "\nМеню:\n";
        cout << "1. Определить количество цифр\n";
        cout << "2. Посчитать сумму цифр\n";
        cout << "3. Найти среднее арифметическое цифр\n";
        cout << "4. Определить количество нулей\n";
        cout << "5. Ввести новое число\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            long long temp = number;
            int count = 0;

            if (temp == 0) count = 1;
            for (; temp > 0; temp /= 10) {
                count++;
            }

            cout << "Количество цифр: " << count << endl;
            break;
        }

        case 2: {
            long long temp = number;
            int sum = 0;

            for (; temp > 0; temp /= 10) {
                sum += temp % 10;
            }

            cout << "Сумма цифр: " << sum << endl;
            break;
        }

        case 3: {
            long long temp = number;
            int sum = 0, count = 0;

            if (temp == 0) { sum = 0; count = 1; }
            for (; temp > 0; temp /= 10) {
                sum += temp % 10;
                count++;
            }

            double avg = static_cast<double>(sum) / count;
            cout << "Среднее арифметическое цифр: " << avg << endl;
            break;
        }

        case 4: {
            long long temp = number;
            int zeros = 0;

            if (temp == 0) zeros = 1;
            for (; temp > 0; temp /= 10) {
                if (temp % 10 == 0) zeros++;
            }

            cout << "Количество нулей: " << zeros << endl;
            break;
        }

        case 5: {
            cout << "Введите новое число: ";
            cin >> number;
            if (number < 0) number = -number;
            break;
        }

        case 0:
            running = false;
            cout << "Выход из программы.\n";
            break;

        default:
            cout << "Неверный выбор!\n";
        }
    }

    cout << endl;
    cout << endl;

    //Задание 2:
    //Написать программу, которая выводит на экран шахматную
    //доску с заданным размером клеточки. 
    int size;
    cout << "Введите размер клеточки: ";
    cin >> size;

    int boardSize = 8;
    int boardSize_2 = 2;

    for (int row = 0; row < boardSize_2; row++) {
        for (int subRow = 0; subRow < size; subRow++) {
            for (int col = 0; col < boardSize; col++) {
                if ((row + col) % 2 == 0) {
                    for (int i = 0; i < size; i++) cout << '*';
                }
                else {
                    for (int i = 0; i < size; i++) cout << '-';
                }
            }
            cout << endl;
        }
    }
    return 0;
}