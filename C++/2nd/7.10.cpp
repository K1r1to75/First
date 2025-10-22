#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // 1
    int a;
    cout << "a: ";
    cin >> a;

    int sum = 0;
    for (int i = a; i <= 500; i++) {
        sum += i;
    }
    cout << "Сумма: " << sum << endl << endl;

    // 2
    int x, y;
    cout << "x и y: ";
    cin >> x >> y;

    int xy = 1;
    for (int i = 0; i < y; i++) {
        xy *= x;
    }
    cout << x << "^" << y << " = " << xy << endl << endl;

    // 3
    int total = 0;
    for (int i = 1; i <= 1000; i++) {
        total += i;
    }
    cout << "Среднее 1-1000: " << total / 1000.0 << endl << endl;

    // 4
    int a4;
    cout << "1-20: ";
    cin >> a4;

    long an4 = 1;
    for (int i = a4; i <= 20; i++) {
        an4 *= i;
    }
    cout << "Произведение: " << an4 << endl << endl;

    // 5
    int k;
    cout << "k: ";
    cin >> k;

    cout << "Таблица умножения на " << k << ":\n";
    for (int i = 1; i <= 10; i++) {
        cout << k << " * " << i << " = " << k * i << endl;
    }

    return 0;
}