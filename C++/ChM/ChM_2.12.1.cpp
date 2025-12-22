#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Исходная функция: 5*sin(2x) - sqrt(1-x) = 0
double f(double x) {
    return 5 * sin(2 * x) - sqrt(1 - x);
}

// Производная функции
double df(double x) {
    return 10 * cos(2 * x) + 0.5 / sqrt(1 - x);
}

// Метод Ньютона (касательных)
double newton(double a, double b, double eps) {
    // Выбор начального приближения: где f(x)*f''(x) > 0
    double x0 = (f(a) * df(a) > 0) ? a : b;
    double x = x0;
    int iterations = 0;

    cout << "Начальное приближение: " << x0 << endl;

    do {
        x0 = x;
        x = x0 - f(x0) / df(x0);
        iterations++;
        cout << "Итерация " << iterations << ": x = " << x << ", f(x) = " << f(x) << endl;
    } while (fabs(x - x0) > eps && iterations < 100);

    cout << "Метод Ньютона: итераций = " << iterations << endl;
    return x;
}

// Метод хорд
double chord(double a, double b, double eps) {
    double fa = f(a), fb = f(b);
    double x;
    int iterations = 0;

    // Проверка сходимости
    if (fa * fb > 0) {
        cout << "На отрезке нет корня или несколько корней!" << endl;
        return NAN;
    }

    do {
        x = (a * fb - b * fa) / (fb - fa);
        double fx = f(x);

        if (fa * fx < 0) {
            b = x;
            fb = fx;
        }
        else {
            a = x;
            fa = fx;
        }
        iterations++;
        cout << "Итерация " << iterations << ": x = " << x << ", f(x) = " << fx << endl;
    } while (fabs(b - a) > eps && iterations < 100);

    cout << "Метод хорд: итераций = " << iterations << endl;
    return x;
}

// Комбинированный метод хорд и касательных
double combined(double a, double b, double eps) {
    double x_chord, x_newton;
    int iterations = 0;

    do {
        // Метод хорд
        x_chord = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Метод Ньютона (выбираем конец с f(x)*f''(x) > 0)
        double x0_newton = (f(a) * df(a) > 0) ? a : b;
        x_newton = x0_newton - f(x0_newton) / df(x0_newton);

        // Обновляем границы
        a = min(x_chord, x_newton);
        b = max(x_chord, x_newton);

        iterations++;
        cout << "Итерация " << iterations << ": [" << a << ", " << b << "], длина = " << b - a << endl;
    } while (fabs(b - a) > eps && iterations < 100);

    cout << "Комбинированный метод: итераций = " << iterations << endl;
    return (a + b) / 2;
}

int main() {
    double a = -3.0, b = -2.9;
    double eps = 1e-6;

    cout << fixed << setprecision(8);
    cout << "Уравнение: 5*sin(2x) = sqrt(1-x)" << endl;
    cout << "Промежуток: [" << a << ", " << b << "]" << endl;
    cout << "Точность: " << eps << endl << endl;

    // Проверка наличия корня
    cout << "f(" << a << ") = " << f(a) << endl;
    cout << "f(" << b << ") = " << f(b) << endl;
    cout << "f(a)*f(b) = " << f(a) * f(b) << endl << endl;

    // Метод Ньютона
    cout << "\tМетод ньютона (касательных)" << endl;
    double root1 = newton(a, b, eps);
    cout << "Корень: " << root1 << endl;
    cout << "Проверка: f(" << root1 << ") = " << f(root1) << endl << endl;

    // Метод хорд
    cout << "\tМетод Хорд" << endl;
    double root2 = chord(a, b, 1e-3);  // Точность 10^-3 по заданию
    cout << "Корень: " << root2 << endl;
    cout << "Проверка: f(" << root2 << ") = " << f(root2) << endl << endl;

    // Комбинированный метод
    cout << "\tКомбинированный метод" << endl;
    double root3 = combined(a, b, eps);
    cout << "Корень: " << root3 << endl;
    cout << "Проверка: f(" << root3 << ") = " << f(root3) << endl << endl;

    // Сравнение с ожидаемым результатом из таблицы
    cout << "Ожидаемый результат из таблицы: -2.937543" << endl;
    cout << "Отклонение: " << fabs(root3 - (-2.937543)) << endl;

    return 0;
}