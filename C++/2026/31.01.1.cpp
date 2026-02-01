#include <iostream>
using namespace std;

// Макросы
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))
#define POWER(base, exp) ({ \
    int result = 1; \
    for(int i = 0; i < (exp); i++) { \
        result *= (base); \
    } \
    result; \
})

// Макрос для проверки числа на четность
#define IS_EVEN(num) ((num) % 2 == 0)

// Макрос для проверки числа на нечетность
#define IS_ODD(num) ((num) % 2 != 0)

int main() {
    int choice;
    int a, b;

    do {
        cout << "\tМеню" << endl;
        cout << "1. Нахождение меньшего из двух чисел" << endl;
        cout << "2. Нахождение большего из двух чисел" << endl;
        cout << "3. Возведение числа в квадрат" << endl;
        cout << "4. Возведение числа в степень" << endl;
        cout << "5. Проверка числа на четность" << endl;
        cout << "6. Проверка числа на нечетность" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите два числа: ";
            cin >> a >> b;
            cout << "Минимальное: " << MIN(a, b) << endl;
            break;

        case 2:
            cout << "Введите два числа: ";
            cin >> a >> b;
            cout << "Максимальное: " << MAX(a, b) << endl;
            break;

        case 3:
            cout << "Введите число: ";
            cin >> a;
            cout << "Квадрат числа: " << SQUARE(a) << endl;
            break;

        case 4:
            cout << "Введите основание и степень (целое положительное число): ";
            cin >> a >> b;
            cout << a << " в степени " << b << " = " << POWER(a, b) << endl;
            break;

        case 5:
            cout << "Введите число: ";
            cin >> a;
            if (IS_EVEN(a))
                cout << "Число " << a << " четное" << endl;
            else
                cout << "Число " << a << " нечетное" << endl;
            break;

        case 6:
            cout << "Введите число: ";
            cin >> a;
            if (IS_ODD(a))
                cout << "Число " << a << " нечетное" << endl;
            else
                cout << "Число " << a << " четное" << endl;
            break;

        case 0:
            cout << "Выход из программы" << endl;
            break;

        default:
            cout << "Неправильно" << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}