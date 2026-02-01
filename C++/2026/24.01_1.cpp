#include <iostream>
#include <cmath>
using namespace std;
// Задание 1: Комплексное число
struct Complex {
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    void display() {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << -imag << "i";
    }
};

Complex add(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex subtract(Complex a, Complex b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex multiply(Complex a, Complex b) {
    return Complex(
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    );
}

Complex divide(Complex a, Complex b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    return Complex(
        (a.real * b.real + a.imag * b.imag) / denominator,
        (a.imag * b.real - a.real * b.imag) / denominator
    );
}

// Задание 2: Автомобиль
enum TransmissionType { manual, automatic, robot, variator };

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    TransmissionType transmission;

    Car() : length(0), clearance(0), engineVolume(0), enginePower(0),
        wheelDiameter(0), color("unknown"), transmission(manual) {
    }

    void setValues() {
        cout << "Длина автомобиля (м): ";
        cin >> length;
        cout << "Клиренс (м): ";
        cin >> clearance;
        cout << "Объем двигателя (л): ";
        cin >> engineVolume;
        cout << "Мощность двигателя (л.с.): ";
        cin >> enginePower;
        cout << "Диаметр колес (дюймы): ";
        cin >> wheelDiameter;
        cout << "Цвет: ";
        cin >> color;

        int trans;
        cout << "Тип коробки (0-Механика, 1-Автомат, 2-Робот, 3-Вариатор): ";
        cin >> trans;
        transmission = static_cast<TransmissionType>(trans);
    }

    void display() {
        cout << "\n\tХарактеристики автомобиля\n";
        cout << "Длина: " << length << " м\n";
        cout << "Клиренс: " << clearance << " м\n";
        cout << "Объем двигателя: " << engineVolume << " л\n";
        cout << "Мощность: " << enginePower << " л.с.\n";
        cout << "Диаметр колес: " << wheelDiameter << " дюймов\n";
        cout << "Цвет: " << color << "\n";

        string transStr;
        switch (transmission) {
        case manual: transStr = "Механика"; break;
        case automatic: transStr = "Автомат"; break;
        case robot: transStr = "Робот"; break;
        case variator: transStr = "Вариатор"; break;
        }
        cout << "Коробка передач: " << transStr << "\n";
    }

    void searchByParameter() {
        cout << "\nПоиск по параметру:\n";
        cout << "1 - Мощность двигателя\n";
        cout << "2 - Объем двигателя\n";
        cout << "3 - Цвет\n";
        cout << "4 - Тип коробки\n";
        cout << "Выберите параметр: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Мощность двигателя: " << enginePower << " л.с.\n";
            break;
        case 2:
            cout << "Объем двигателя: " << engineVolume << " л\n";
            break;
        case 3:
            cout << "Цвет: " << color << "\n";
            break;
        case 4: {
            string transStr;
            switch (transmission) {
            case manual: transStr = "Механика"; break;
            case automatic: transStr = "Автомат"; break;
            case robot: transStr = "Робот"; break;
            case variator: transStr = "Вариатор"; break;
            }
            cout << "Тип коробки: " << transStr << "\n";
            break;
        }
        default:
            cout << "Неверный выбор\n";
        }
    }
};

void complexNumbersMenu() {
    Complex a, b;

    cout << "Введите первое комплексное число:\n";
    cout << "Действительная часть: ";
    cin >> a.real;
    cout << "Мнимая часть: ";
    cin >> a.imag;

    cout << "Введите второе комплексное число:\n";
    cout << "Действительная часть: ";
    cin >> b.real;
    cout << "Мнимая часть: ";
    cin >> b.imag;

    while (true) {
        cout << "\n\tОперации с комплексными числами\n";
        cout << "1 Сложение\n";
        cout << "2 Вычитание\n";
        cout << "3 Умножение\n";
        cout << "4 Деление\n";
        cout << "5 Показать числа\n";
        cout << "0 Назад\n";
        cout << "Выбор: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        Complex result;
        switch (choice) {
        case 1:
            result = add(a, b);
            cout << "Результат: ";
            result.display();
            cout << endl;
            break;
        case 2:
            result = subtract(a, b);
            cout << "Результат: ";
            result.display();
            cout << endl;
            break;
        case 3:
            result = multiply(a, b);
            cout << "Результат: ";
            result.display();
            cout << endl;
            break;
        case 4:
            if (b.real == 0 && b.imag == 0) {
                cout << "Ошибка: деление на ноль\n";
            }
            else {
                result = divide(a, b);
                cout << "Результат: ";
                result.display();
                cout << endl;
            }
            break;
        case 5:
            cout << "Первое число: ";
            a.display();
            cout << "\nВторое число: ";
            b.display();
            cout << endl;
            break;
        default:
            cout << "Неверный выбор\n";
        }
    }
}

void carMenu() {
    Car car;
    bool carCreated = false;

    while (true) {
        cout << "\n\tРабота с автомобилем\n";
        cout << "1 Задать характеристики\n";
        cout << "2 Показать характеристики\n";
        cout << "3 Поиск по параметру\n";
        cout << "0 Назад\n";
        cout << "Выбор: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            car.setValues();
            carCreated = true;
            cout << "Характеристики сохранены\n";
            break;
        case 2:
            if (carCreated) {
                car.display();
            }
            else {
                cout << "Сначала задайте характеристики автомобиля\n";
            }
            break;
        case 3:
            if (carCreated) {
                car.searchByParameter();
            }
            else {
                cout << "Сначала задайте характеристики автомобиля\n";
            }
            break;
        default:
            cout << "Неправильно\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    while (true) {
        cout << "\n\tМеню\n";
        cout << "1 Комплексные числа\n";
        cout << "2 Автомобиль\n";
        cout << "0 Выход\n";
        cout << "Выбор: ";

        int choice;
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            complexNumbersMenu();
            break;
        case 2:
            carMenu();
            break;
        default:
            cout << "Неправильно\n";
        }
    }

    return 0;
}