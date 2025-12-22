#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double f(double x) {
    return sin(x);
}

double leftrect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double rightrect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double midrect(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += f(a + (i + 0.5) * h);
    }
    return sum * h;
}

double trapez(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double simpson(double a, double b, int n) {
    if (n % 2 != 0) n++;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h);
        }
        else {
            sum += 4 * f(a + i * h);
        }
    }
    return sum * h / 3;
}

int main() {
    cout << "\tФормулы Ньютона-Котеля\n";
    cout << "--------------------------------------\n";

    double a, b, eps;
    int n;

    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите n (число отрезков): ";
    cin >> n;
    cout << "Введите точность: ";
    cin >> eps;

    cout << "\n\tРезультаты:\n";
    cout << "1. Левых прямоугольников: " << leftrect(a, b, n) << endl;
    cout << "2. Правых прямоугольников: " << rightrect(a, b, n) << endl;
    cout << "3. Средних прямоугольников: " << midrect(a, b, n) << endl;
    cout << "4. Трапеций: " << trapez(a, b, n) << endl;
    cout << "5. Симпсона (парабол): " << simpson(a, b, n) << endl;

    return 0;
}