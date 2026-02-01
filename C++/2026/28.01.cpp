#include <iostream>
#include <cmath>
using namespace std;
// Задание 1: Структура для прямоугольника
struct Rectangle {
    double x, y;
    double width;
    double height;
};

// Функции для прямоугольника
void moveRectangle(Rectangle& rect, double dx, double dy) {
    rect.x += dx;
    rect.y += dy;
}

void resizeRectangle(Rectangle& rect, double newWidth, double newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}

void printRectangle(const Rectangle& rect) {
    cout << "Прямоугольник: (" << rect.x << ", " << rect.y
        << "), ширина: " << rect.width << ", высота: " << rect.height << endl;
}

// Задание 2: Структура для точки
struct Point {
    double x, y;
};

// Функция вычисления расстояния между точками
double distanceBetweenPoints(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Задание 3: Структура для дроби
struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "Ошибка: знаменатель не может быть 0! Установлен 1." << endl;
            denominator = 1;
        }
        else {
            denominator = denom;
        }
        numerator = num;
        simplify();
    }

    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Функция упрощения дроби
    void simplify() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int divisor = gcd(numerator, denominator);
        if (divisor != 0) {
            numerator /= divisor;
            denominator /= divisor;
        }
    }

    void toProperFraction() {
        // Дробь уже хранится в правильном формате
        // Эта функция нужна если мы хотим выделить целую часть
    }

    // Печать дроби
    void print() const {
        if (denominator == 1) {
            cout << numerator;
        }
        else {
            cout << numerator << "/" << denominator;
        }
    }
};

// Арифметические операции с дробями
Fraction addFractions(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction subtractFractions(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction multiplyFractions(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int denom = f1.denominator * f2.denominator;
    return Fraction(num, denom);
}

Fraction divideFractions(const Fraction& f1, const Fraction& f2) {
    if (f2.numerator == 0) {
        cout << "Ошибка: деление на 0! Возвращена дробь 0/1." << endl;
        return Fraction(0, 1);
    }
    int num = f1.numerator * f2.denominator;
    int denom = f1.denominator * f2.numerator;
    return Fraction(num, denom);
}

// Меню
void showMenu() {
    cout << "\n\tМеню\n";
    cout << "1. Работа с прямоугольником\n";
    cout << "2. Вычисление расстояния между точками\n";
    cout << "3. Работа с дробями\n";
    cout << "4. Выход\n";
    cout << "Выберите опцию: ";
}

void rectangleMenu() {
    Rectangle rect = { 0, 0, 10, 5 };
    int choice;
    double dx, dy, width, height;

    do {
        cout << "\n\tРабота с прямоугольником\n";
        printRectangle(rect);
        cout << "\n1. Переместить прямоугольник\n";
        cout << "2. Изменить размер прямоугольника\n";
        cout << "3. Назад в главное меню\n";
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите смещение по X: ";
            cin >> dx;
            cout << "Введите смещение по Y: ";
            cin >> dy;
            moveRectangle(rect, dx, dy);
            cout << "Прямоугольник перемещен.\n";
            break;
        case 2:
            cout << "Введите новую ширину: ";
            cin >> width;
            cout << "Введите новую высоту: ";
            cin >> height;
            if (width > 0 && height > 0) {
                resizeRectangle(rect, width, height);
                cout << "Размер изменен.\n";
            }
            else {
                cout << "Ошибка: размеры должны быть положительными!\n";
            }
            break;
        }
    } while (choice != 3);
}

void pointsMenu() {
    Point p1, p2;

    cout << "\n\tВычисление растояния между точками\n";
    cout << "Введите координаты первой точки:\n";
    cout << "X1: ";
    cin >> p1.x;
    cout << "Y1: ";
    cin >> p1.y;

    cout << "Введите координаты второй точки:\n";
    cout << "X2: ";
    cin >> p2.x;
    cout << "Y2: ";
    cin >> p2.y;

    double dist = distanceBetweenPoints(p1, p2);
    cout << "Расстояние между точками: " << dist << endl;
}

void fractionsMenu() {
    Fraction f1, f2;
    int num, denom;
    int choice;

    cout << "\nВведите первую дробь:\n";
    cout << "Числитель: ";
    cin >> num;
    cout << "Знаменатель: ";
    cin >> denom;
    f1 = Fraction(num, denom);

    cout << "Введите вторую дробь:\n";
    cout << "Числитель: ";
    cin >> num;
    cout << "Знаменатель: ";
    cin >> denom;
    f2 = Fraction(num, denom);

    do {
        cout << "\n\tРабота с дробями\n";
        cout << "Дробь 1: ";
        f1.print();
        cout << "\nДробь 2: ";
        f2.print();
        cout << "\n\n1. Сложение\n";
        cout << "2. Вычитание\n";
        cout << "3. Умножение\n";
        cout << "4. Деление\n";
        cout << "5. Ввести новые дроби\n";
        cout << "6. Назад в главное меню\n";
        cout << "Выберите опцию: ";
        cin >> choice;

        Fraction result;

        switch (choice) {
        case 1:
            result = addFractions(f1, f2);
            cout << "Результат сложения: ";
            f1.print();
            cout << " + ";
            f2.print();
            cout << " = ";
            result.print();
            cout << endl;
            break;
        case 2:
            result = subtractFractions(f1, f2);
            cout << "Результат вычитания: ";
            f1.print();
            cout << " - ";
            f2.print();
            cout << " = ";
            result.print();
            cout << endl;
            break;
        case 3:
            result = multiplyFractions(f1, f2);
            cout << "Результат умножения: ";
            f1.print();
            cout << " * ";
            f2.print();
            cout << " = ";
            result.print();
            cout << endl;
            break;
        case 4:
            result = divideFractions(f1, f2);
            cout << "Результат деления: ";
            f1.print();
            cout << " / ";
            f2.print();
            cout << " = ";
            result.print();
            cout << endl;
            break;
        case 5:
            cout << "Введите первую дробь:\n";
            cout << "Числитель: ";
            cin >> num;
            cout << "Знаменатель: ";
            cin >> denom;
            f1 = Fraction(num, denom);

            cout << "Введите вторую дробь:\n";
            cout << "Числитель: ";
            cin >> num;
            cout << "Знаменатель: ";
            cin >> denom;
            f2 = Fraction(num, denom);
            break;
        }
    } while (choice != 6);
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            rectangleMenu();
            break;
        case 2:
            pointsMenu();
            break;
        case 3:
            fractionsMenu();
            break;
        case 4:
            cout << "Выход\n";
            break;
        default:
            cout << "Неправильно\n";
        }
    } while (choice != 4);

    return 0;
}