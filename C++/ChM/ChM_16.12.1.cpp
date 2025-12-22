#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

// Основная функция интерполяции Лагранжа
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double point) {
    double result = 0.0;
    int n = x.size();

    for (int i = 0; i < n; i++) {
        double term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (point - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

// Вывод полинома Лагранжа в явном виде
void printLagrangePolynomial(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    cout << "\nПолином Лагранжа:\n";
    cout << "L(x) = ";

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " + ";
        cout << y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                cout << " * (x - " << x[j] << ")/(" << x[i] << " - " << x[j] << ")";
            }
        }
    }
    cout << endl;
}

// Демонстрация метода Лагранжа
void demoLagrange() {
    vector<double> x1 = { 1, 2, 3, 4, 5 };
    vector<double> y1 = { 1, 4, 9, 16, 25 }; // y = x^2

    cout << "Пример 1: y = x^2\n";
    cout << "Точки: ";
    for (size_t i = 0; i < x1.size(); i++) {
        cout << "(" << x1[i] << "," << y1[i] << ") ";
    }
    cout << endl;

    double point = 2.5;
    double result = lagrangeInterpolation(x1, y1, point);
    cout << fixed << setprecision(4);
    cout << "L(" << point << ") = " << result << endl;
    cout << "Ожидаемое: " << point * point << endl;
    cout << "Разница: " << fabs(result - point * point) << endl;

    cout << "\nПример 2: y = sin(x)\n";
    vector<double> x2 = { 0, M_PI / 6, M_PI / 4, M_PI / 3, M_PI / 2 };
    vector<double> y2;
    for (double val : x2) {
        y2.push_back(sin(val));
    }

    cout << "Точки: ";
    for (size_t i = 0; i < x2.size(); i++) {
        cout << "(" << x2[i] << "," << y2[i] << ") ";
    }
    cout << endl;

    point = M_PI / 5;
    result = lagrangeInterpolation(x2, y2, point);
    cout << "L(" << point << ") = " << result << endl;
    cout << "Ожидаемое sin(" << point << ") = " << sin(point) << endl;
    cout << "Разница: " << fabs(result - sin(point)) << endl;
}

// Вычисление разделенных разностей
vector<vector<double>> calculateDividedDifferences(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<vector<double>> diffTable(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = (diffTable[i + 1][j - 1] - diffTable[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    return diffTable;
}

// Интерполяция Ньютона
double newtonInterpolation(const vector<double>& x, const vector<double>& y, double point) {
    int n = x.size();
    vector<vector<double>> diffTable = calculateDividedDifferences(x, y);

    double result = diffTable[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++) {
        term *= (point - x[i - 1]);
        result += diffTable[0][i] * term;
    }

    return result;
}

// Вывод полинома Ньютона
void printNewtonPolynomial(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<vector<double>> diffTable = calculateDividedDifferences(x, y);

    cout << "\nПолином Ньютона:\n";
    cout << "N(x) = " << diffTable[0][0];

    for (int i = 1; i < n; i++) {
        cout << " + " << diffTable[0][i];
        for (int j = 0; j < i; j++) {
            cout << "(x - " << x[j] << ")";
        }
    }
    cout << endl;
}

// Демонстрация метода Ньютона
void demoNewton() {
    vector<double> x1 = { 0, 1, 2, 3, 4 };
    vector<double> y1 = { 1, 2, 4, 8, 16 };

    cout << "Пример 1: y ≈ 2^x\n";
    cout << "Точки: ";
    for (size_t i = 0; i < x1.size(); i++) {
        cout << "(" << x1[i] << "," << y1[i] << ") ";
    }
    cout << endl;

    // Вывод таблицы разделенных разностей
    vector<vector<double>> diffTable = calculateDividedDifferences(x1, y1);
    cout << "\nТаблица разделенных разностей:\n";
    cout << fixed << setprecision(4);
    for (size_t i = 0; i < x1.size(); i++) {
        cout << "x=" << x1[i] << ": ";
        for (size_t j = 0; j < x1.size() - i; j++) {
            cout << setw(10) << diffTable[i][j] << " ";
        }
        cout << endl;
    }

    double point = 1.5;
    double result = newtonInterpolation(x1, y1, point);
    cout << "\nN(" << point << ") = " << result << endl;

    cout << "\nПример 2: y = x^2 + 2x + 1\n";
    vector<double> x2 = { -2, -1, 0, 1, 2 };
    vector<double> y2;
    for (double val : x2) {
        y2.push_back(val * val + 2 * val + 1);
    }

    cout << "Точки: ";
    for (size_t i = 0; i < x2.size(); i++) {
        cout << "(" << x2[i] << "," << y2[i] << ") ";
    }
    cout << endl;

    point = 0.5;
    result = newtonInterpolation(x2, y2, point);
    double expected = point * point + 2 * point + 1;
    cout << "N(" << point << ") = " << result << endl;
    cout << "Ожидаемое: " << expected << endl;
    cout << "Разница: " << fabs(result - expected) << endl;
}

// Упрощенная версия Ньютона (более эффективная)
double newtonSimple(const vector<double>& x, const vector<double>& y, double point) {
    int n = x.size();
    vector<double> coeff(n);

    for (int i = 0; i < n; i++) {
        coeff[i] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coeff[i] = (coeff[i] - coeff[i - 1]) / (x[i] - x[i - j]);
        }
    }

    double result = coeff[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = result * (point - x[i]) + coeff[i];
    }

    return result;
}

// Сравнение методов
void compareMethods(const vector<double>& x, const vector<double>& y, double point) {
    double lagrangeResult = lagrangeInterpolation(x, y, point);
    double newtonResult = newtonInterpolation(x, y, point);
    double newtonSimpleResult = newtonSimple(x, y, point);

    cout << fixed << setprecision(10);
    cout << "Метод Лагранжа:   " << lagrangeResult << endl;
    cout << "Метод Ньютона:    " << newtonResult << endl;
    cout << "Ньютон (упрощ.):  " << newtonSimpleResult << endl;

    cout << "\nРазницы:\n";
    cout << "Лагранж - Ньютон: " << fabs(lagrangeResult - newtonResult) << endl;
    cout << "Лагранж - Ньютон(у): " << fabs(lagrangeResult - newtonSimpleResult) << endl;
    cout << "Ньютон - Ньютон(у): " << fabs(newtonResult - newtonSimpleResult) << endl;
}

// Основное меню
void runInteractiveMode() {
    int n;
    cout << "Введите количество точек: ";
    cin >> n;

    if (n < 2) {
        cout << "Нужно хотя бы 2 точки!\n";
        return;
    }

    vector<double> x(n), y(n);
    cout << "\nВведите точки (x y):\n";
    for (int i = 0; i < n; i++) {
        cout << "Точка " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    cout << "\nВведенные точки:\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << x[i] << ", " << y[i] << ")\n";
    }

    // Проверка на уникальность x
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (x[i] == x[j]) {
                cout << "Ошибка: значения x должны быть уникальными!\n";
                return;
            }
        }
    }

    double point;
    cout << "\nВведите точку для интерполяции: ";
    cin >> point;

    int choice;
    cout << "\nВыберите метод:\n";
    cout << "1. Только Лагранж\n";
    cout << "2. Только Ньютон\n";
    cout << "3. Оба метода с сравнением\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    cout << fixed << setprecision(6);

    switch (choice) {
    case 1: {
        double result = lagrangeInterpolation(x, y, point);
        cout << "\nРезультат (Лагранж): f(" << point << ") = " << result << endl;
        break;
    }
    case 2: {
        double result = newtonInterpolation(x, y, point);
        cout << "\nРезультат (Ньютон): f(" << point << ") = " << result << endl;
        printNewtonPolynomial(x, y);
        break;
    }
    case 3: {
        compareMethods(x, y, point);
        break;
    }
    default:
        cout << "Неверный выбор!\n";
    }

    // Проверка в узлах
    cout << "\nПроверка в узлах интерполяции:\n";
    for (int i = 0; i < n; i++) {
        double lagrangeVal = lagrangeInterpolation(x, y, x[i]);
        double newtonVal = newtonInterpolation(x, y, x[i]);
        cout << "x = " << x[i] << ": ";
        cout << "Лагранж = " << lagrangeVal << " (ожидается " << y[i] << ") ";
        cout << "Ньютон = " << newtonVal << " (ожидается " << y[i] << ")\n";
    }
}

// Главное меню программы
int main() {

    int choice;

    do {
        cout << "\n=========================================";
        cout << "\n\t\tГЛАВНОЕ МЕНЮ";
        cout << "\n=========================================\n";
        cout << "1. Демонстрация метода Лагранжа\n";
        cout << "2. Демонстрация метода Ньютона\n";
        cout << "3. Сравнение методов на примерах\n";
        cout << "4. Интерактивный режим\n";
        cout << "5. Тест на точность\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";

        cin >> choice;

        switch (choice) {
        case 1:
            demoLagrange();
            break;
        case 2:
            demoNewton();
            break;
        case 3: {
            // Сравнение на примере
            vector<double> x = { 0, 1, 2, 3, 4 };
            vector<double> y = { 1, 3, 7, 13, 21 }; // y = x^2 + x + 1
            compareMethods(x, y, 2.5);
            break;
        }
        case 4:
            runInteractiveMode();
            break;
        case 5: {
            // Тест на точность
            cout << "\nТЕСТ НА ТОЧНОСТЬ:\n";
            cout << "================\n";

            // Точная функция: sin(x)
            vector<double> x_test;
            vector<double> y_test;

            // Создаем 5 точек от 0 до π/2
            for (int i = 0; i < 5; i++) {
                double xi = i * M_PI / 8;
                x_test.push_back(xi);
                y_test.push_back(sin(xi));
            }

            double test_point = M_PI / 5;
            double exact = sin(test_point);
            double lagrange_test = lagrangeInterpolation(x_test, y_test, test_point);
            double newton_test = newtonInterpolation(x_test, y_test, test_point);

            cout << fixed << setprecision(10);
            cout << "Точное значение sin(" << test_point << ") = " << exact << endl;
            cout << "Лагранж: " << lagrange_test << ", ошибка: " << fabs(lagrange_test - exact) << endl;
            cout << "Ньютон:  " << newton_test << ", ошибка: " << fabs(newton_test - exact) << endl;
            break;
        }
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }

        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}