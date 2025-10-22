#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // ЗАДАНИЕ 1
    cout << "Проверка допуска к экзамену\n";

    int s1, s2, s3, s4, s5;
    double av;

    cout << "5 оценок: ";
    cin >> s1 >> s2 >> s3 >> s4 >> s5;

    av = (s1 + s2 + s3 + s4 + s5) / 5.0;

    if (av >= 4) {
        cout << "Студент допущен\n";
        cout << "Средний балл: " << av << endl;
    }
    else {
        cout << "Студент не допущен ,\n";
        cout << "Средний балл: " << av << endl;
    }

    cout << "\n";

    // ЗАДАНИЕ 2
    cout << "Проверка четности числа\n";

    int num;
    double res;

    cout << "Введите число: ";
    cin >> num;

    if (num % 2 == 0) {
        res = num * 3;
        cout << "Число четное. Умножаем на 3: " << res << endl;
    }
    else {
        res = num / 2.0;
        cout << "Число нечетное. Делим на 2: " << res << endl;
    }

    cout << "\n";

    // ЗАДАНИЕ 3
    cout << "ЗАДАНИЕ 3: Калькулятор\n";

    double num1, num2;
    char operation;
    double c_res;

    cout << "Введите первое число: ";
    cin >> num1;

    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Выберите операцию (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        c_res = num1 + num2;
        cout << "Результат: " << num1 << " + " << num2 << " = " << c_res << endl;
    }
    else if (operation == '-') {
        c_res = num1 - num2;
        cout << "Результат: " << num1 << " - " << num2 << " = " << c_res << endl;
    }
    else if (operation == '*') {
        c_res = num1 * num2;
        cout << "Результат: " << num1 << " * " << num2 << " = " << c_res << endl;
    }
    else if (operation == '/') {
        if (num2 != 0) {
            c_res = num1 / num2;
            cout << "Результат: " << num1 << " / " << num2 << " = " << c_res << endl;
        }
        else {
            cout << "деление на ноль" << endl;
        }
    }
    return 0;
}