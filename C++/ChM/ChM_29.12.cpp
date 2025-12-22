#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
    return x * x + y * y;
}

// Метод Эйлера
void euler(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    for (int i = 0; i < n; i++) {
        y += h * f(x, y);
        x += h;
        cout << "x = " << x << ", y = " << y << endl;
    }
}

// Метод Эйлера-Коши
void euler_c(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    for (int i = 0; i < n; i++) {
        double k1 = f(x, y);
        double y_t = y + h * k1;
        double k2 = f(x + h, y_t);
        y += h * (k1 + k2) / 2.0;
        x += h;
        cout << "x = " << x << ", y = " << y << endl;
    }
}

// Метод Рунге-Кутта
void runge_kutta(double x0, double y0, double h, int n) {
    double x = x0, y = y0;
    for (int i = 0; i < n; i++) {
        double k1 = f(x, y);
        double k2 = f(x + h / 2, y + h * k1 / 2);
        double k3 = f(x + h / 2, y + h * k2 / 2);
        double k4 = f(x + h, y + h * k3);
        y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x += h;
        cout << "x = " << x << ", y = " << y << endl;
    }
}

int main() {
    int choice;
    double x0, y0, h;
    int n;

    cout << "Введите x0, y0, h, n: ";
    cin >> x0 >> y0 >> h >> n;

    cout << "Выберите метод:\n1 - Эйлер\n2 - Эйлер-Коши\n3 - Рунге-Кутта 4\n";
    cin >> choice;

    switch (choice) {
    case 1: euler(x0, y0, h, n); break;
    case 2: euler_c(x0, y0, h, n); break;
    case 3: runge_kutta(x0, y0, h, n); break;
    default: cout << "Неверный выбор";
    }

    return 0;
}