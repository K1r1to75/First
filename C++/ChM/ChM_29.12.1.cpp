#include <iostream>
#include <cmath>
using namespace std;

double f1(double x, double y, double z) {
    return z;
}

double f2(double x, double y, double z) {
    return -y;
}

// Метод Рунге-Кутта
void runge_kutta(double x0, double y0, double z0, double h, int n) {
    double x = x0, y = y0, z = z0;
    for (int i = 0; i < n; i++) {
        double k1 = f1(x, y, z);
        double l1 = f2(x, y, z);

        double k2 = f1(x + h / 2, y + h * k1 / 2, z + h * l1 / 2);
        double l2 = f2(x + h / 2, y + h * k1 / 2, z + h * l1 / 2);

        double k3 = f1(x + h / 2, y + h * k2 / 2, z + h * l2 / 2);
        double l3 = f2(x + h / 2, y + h * k2 / 2, z + h * l2 / 2);

        double k4 = f1(x + h, y + h * k3, z + h * l3);
        double l4 = f2(x + h, y + h * k3, z + h * l3);

        y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        z += h * (l1 + 2 * l2 + 2 * l3 + l4) / 6.0;
        x += h;

        cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    }
}

int main() {
    double x0, y0, z0, h;
    int n;

    cout << "Введите x0, y0, z0, h, n: ";
    cin >> x0 >> y0 >> z0 >> h >> n;

    runge_kutta(x0, y0, z0, h, n);

    return 0;
}