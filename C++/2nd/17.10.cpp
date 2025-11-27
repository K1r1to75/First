#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // Задача 1: Делители чисел
    int A, B;
    cout << "Задача 1: Делители чисел в диапазоне" << endl;
    cout << "Введите диапазон A и B: ";
    cin >> A >> B;

    cout << "Число\tДелители\tКоличество" << endl;
    cout << "--------------------------------" << endl;

    for (int num = A; num <= B; num++) {
        vector<int> divisors;
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {
                divisors.push_back(i);
            }
        }

        cout << num << "\t";
        for (int div : divisors) {
            cout << div << " ";
        }
        cout << "\t\t" << divisors.size() << endl;
    }

    cout << "\n\n";

    // Задача 2: Простые числа
    cout << "Задача 2: Простые числа от 2 до 1000:" << endl;

    for (int num = 2; num <= 1000; num++) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl << "\n\n";

    // Задача 3: Фигура
    cout << "Задача 3: Вывод фигуры" << endl;
    int size;
    cout << "Введите положительное нечетное число: ";
    cin >> size;

    if (size % 2 == 0 || size <= 0) {
        cout << "Ошибка! Число должно быть положительным и нечетным." << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j == 0 || j == i || i == size - 1) {
                    cout << "* ";
                }
                else {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }

    cout << "\n\n";

    // Задача 4: Комбинации чемодана
    cout << "Задача 4: Комбинации кода чемодана" << endl;
    cout << "Все возможные комбинации трехзначного кода без повторяющихся цифр:" << endl;
    int count = 0;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (i != j && i != k && j != k) {
                    cout << i << j << k << " ";
                    count++;
                    if (count % 10 == 0) cout << endl;
                }
            }
        }
    }

    cout << "\n\nВсего комбинаций: " << count << endl;
    int totalTime = count * 3;
    cout << "Время для перебора всех комбинаций: " << totalTime << " секунд ("
        << totalTime / 60 << " минут " << totalTime % 60 << " секунд)" << endl;

    cout << "\n\n";

    // Задача 5: Зарплата
    cout << "Задача 5: Зарплата сотрудников" << endl;
    const int EMPLOYEES = 12;
    const int MONTHS = 3;
    string monthNames[MONTHS] = { "Март", "Апрель", "Май" };

    int salary[EMPLOYEES][MONTHS];
    int quarterlyTotal = 0;

    // Ввод данных
    for (int i = 0; i < EMPLOYEES; i++) {
        cout << "\nСотрудник " << (i + 1) << ":" << endl;
        for (int j = 0; j < MONTHS; j++) {
            cout << "Зарплата за " << monthNames[j] << ": ";
            cin >> salary[i][j];
        }
    }

    // Вывод результатов
    cout << "\n\nОТЧЕТ ПО ЗАРАБОТНОЙ ПЛАТЕ" << endl;
    cout << "==========================" << endl;
    cout << setw(10) << "Сотрудник" << setw(10) << "Март" << setw(10) << "Апрель"
        << setw(10) << "Май" << setw(15) << "За квартал" << endl;
    cout << "----------------------------------------------------" << endl;

    for (int i = 0; i < EMPLOYEES; i++) {
        int employeeTotal = 0;
        cout << setw(10) << (i + 1);

        for (int j = 0; j < MONTHS; j++) {
            cout << setw(10) << salary[i][j];
            employeeTotal += salary[i][j];
        }

        cout << setw(15) << employeeTotal << endl;
        quarterlyTotal += employeeTotal;
    }

    cout << "----------------------------------------------------" << endl;
    cout << "Общая выплата за квартал: " << setw(25) << quarterlyTotal << endl;

    return 0;
}