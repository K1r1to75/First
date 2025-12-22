#include <iostream>
#include <cmath>

double f(double x) {
    return sin(x);
}

double trapez(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
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
        double x = a + i * h;
        if (i % 2 == 0) sum += 2 * f(x);
        else sum += 4 * f(x);
    }
    return sum * h / 3;
}

int main() {
    double a = 0.0, b = 3.14159;
    int n = 100;
    std::cout << "Трапеции: " << trapez(a, b, n) << std::endl;
    std::cout << "Симпсона: " << simpson(a, b, n) << std::endl;
    return 0;
}