
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x * sin(x) - 1;
}

double phi(double x) {
    return x - 0.4 * (x * sin(x) - 1);
}

// Метод половинного деления
double bisection(double a, double b, double eps) {
    if (f(a) * f(b) > 0) {
        cout << "На отрезке нет корня!" << endl;
        return NAN;
    }

    double c;
    while (fabs(b - a) > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2;
}

// Метод простых итераций
double iteration(double x0, double eps) {
    double x1 = phi(x0);
    while (fabs(x1 - x0) > eps) {
        x0 = x1;
        x1 = phi(x0);
    }
    return x1;
}

// Функция для расчета количества итераций..
int calculateIterations(double a, double b, double eps) {
    return ceil(log2((b - a) / eps));
}

int main() {
    double a = 1.1, b = 1.2;
    double eps1 = 1e-4, eps2 = 1e-5;

    cout << fixed << setprecision(6);

    // Задание 1: Метод половинного деления с точностью 1e-4
    cout << "Метод половинного деления (1e-4): " << bisection(a, b, eps1) << endl;

    // Задание 3: С расчетом количества итераций
    int n = calculateIterations(a, b, eps1);
    cout << "Количество итераций: " << n << endl;

    // Задание 4: Метод простых итераций с точностью 1e-5
    cout << "Метод простых итераций (1e-5): " << iteration(1.15, eps2) << endl;

    return 0;
}
