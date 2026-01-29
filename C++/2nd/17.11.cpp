
#include <iostream>
using namespace std;


// 1
void degree(double a, int b) {
    double result = 1.0;
    if (b < 0) {
        a = 1.0 / a;
        b = -b;
    }
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    cout << a << "^" << b << " = " << result << endl;
}


// 2
void suminrange(int a, int b) {
    int start, end;
    if (a < b) {
        start = a;
        end = b;
    }
    else {
        start = b;
        end = a;
    }
    int sum = 0;
    for (int i = start + 1; i < end; i++) {
        sum += i;
    }
    cout << "Сумма чисел между " << a << " и " << b << " = " << sum << endl;
}


// 3
void perfectnumbers(int a, int b) {
    cout << "Совершенные числа в диапазоне от " << a << " до " << b << ":" << endl;
    bool found = false;
    for (int num = a; num <= b; num++) {
        int sum = 0;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        if (sum == num && num != 0) {
            cout << num << " ";
            found = true;
        }
    }

    cout << endl;
}


// 5
void luckynumber(int number) {
    if (number < 100000 || number > 999999) {
        cout << number << " - не шестизначное число!" << endl;
        return;
    }

    int digit1 = number / 100000;
    int digit2 = (number / 10000) % 10;
    int digit3 = (number / 1000) % 10;
    int digit4 = (number / 100) % 10;
    int digit5 = (number / 10) % 10;
    int digit6 = number % 10;

    int sum1 = digit1 + digit2 + digit3;
    int sum2 = digit4 + digit5 + digit6;

    if (sum1 == sum2) {
        cout << "Это число Счастливое! :)" << endl;
    }
    else {
        cout << "Это число не счастливое :(" << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int z_1, z_1_2, z_2, z_2_2, z_3, z_3_2, z_4;
    cout << "Введите основание степени: ";
    cin >> z_1;
    cout << "Введите показатель степени: ";
    cin >> z_1_2;
    degree(z_1, z_1_2);
    cout << "Введите число1: ";
    cin >> z_2;
    cout << "Введите число2: ";
    cin >> z_2_2;
    suminrange(z_2, z_2_2);
    cout << "Введите начало интервала: ";
    cin >> z_3;
    cout << "Введите конец интервала: ";
    cin >> z_3_2;
    perfectnumbers(z_3, z_3_2);
    cout << "Введите число: ";
    cin >> z_4;
    luckynumber(z_4);
}