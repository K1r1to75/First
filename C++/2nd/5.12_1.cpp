#include <iostream>
using namespace std;

// Задание 1: Максимальное число
void max(int a, int b) {
    int* pa = &a;
    int* pb = &b;

    // Сравнение
    if (*pa > *pb) {
        cout << "Наибольшее число: " << *pa << endl;
    }
    else if (*pb > *pa) {
        cout << "Наибольшее число: " << *pb << endl;
    }
    else {
        cout << "Числа равны" << endl;
    }
}

// Задание 2: Знак числа
void number(int a) {
    int* pa = &a;

    // Проверка числа
    if (*pa > 0) {
        cout << "Число " << *pa << " Положительное" << endl;
    }
    else if (*pa < 0) {
        cout << "Число " << *pa << " Отрицательное" << endl;
    }
    else {
        cout << "Число равно 0" << endl;
    }
}

// Задание 3: Обмен местами
void exchange(int a, int b) {
    // Переменная для временного хванения
    int c;
    int* pa = &a;
    int* pb = &b;
    // Обмен
    c = *pa;
    *pa = *pb;
    *pb = c;
    cout << "Числа поменяны местами: " << *pa << " " << *pb << endl;
}

//
void calcul(double a, double b, char c) {
    double res;
    double* pa = &a;
    double* pb = &b;
    double* pres = &res;
    char* pc = &c;

    switch (*pc) {
    case '+':
        *pres = *pa + *pb;
        break;
    case '-':
        *pres = *pa - *pb;
        break;
    case '*':
        *pres = *pa * *pb;
        break;
    case '/':
        *pres = *pa / *pb;
        break;
    default:
        cout << "Неверный оператор!" << endl;
        return;
    }
    cout << "\n" << *pa << " " << *pc << " " << *pb << " = " << *pres << endl;

}
int main() {
    setlocale(LC_ALL, "ru");
    int a, b, a2, a3, b3, a4, b4;
    char c4;
    cout << "Введите числа: ";
    cin >> a >> b;
    max(a, b);

    cout << "Введите число: ";
    cin >> a2;
    number(a2);

    cout << "Введите числа: ";
    cin >> a3 >> b3;
    exchange(a3, b3);

    cout << "Введите числа: ";
    cin >> a4 >> b4;
    cout << "Введите оператор (+,-,*,/): ";
    cin >> c4;
    calcul(a4, b4, c4);
}