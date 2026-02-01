#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int sum(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divi(int a, int b) { return b != 0 ? a / b : 0; }

int compareStrings(const char* a, const char* b) {
    while (*a && *a == *b) { a++; b++; }
    return *(unsigned char*)a - *(unsigned char*)b;
}

bool asc(int a, int b) { return a > b; }
bool desc(int a, int b) { return a < b; }

void bubbleSort(int arr[], int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(arr[j], arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double integrate(double a, double b, int n, double (*func)(double)) {
    double step = (b - a) / n;
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * step;
        result += func(x);
    }
    return result * step;
}

void openFile() { cout << "Открыть файл" << endl; }
void saveFile() { cout << "Сохранить файл" << endl; }
void exitProg() { cout << "Выход" << endl; }

template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

double func1(int x) { return x * 1.5; }
double (*plainRetFunc())(int) { return func1; }
auto altRetFunc() -> double (*)(int) { return func1; }

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    do {
        cout << "\n1. Калькулятор";
        cout << "\n2. Сравнение строк";
        cout << "\n3. Сортировка по возрастанию";
        cout << "\n4. Сортировка по убыванию";
        cout << "\n5. Интеграл sin(x)";
        cout << "\n6. Интеграл x*x";
        cout << "\n7. Меню действий";
        cout << "\n8. Auto для итератора";
        cout << "\n9. decltype и auto";
        cout << "\n10. Хвостовой тип";
        cout << "\n11. Указатель на функцию";
        cout << "\n0. Выход";
        cout << "\nВыберите: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char op;
            int x, y;
            cout << "Введите два числа: ";
            cin >> x >> y;
            cout << "Введите оператор (+, -, *, /): ";
            cin >> op;
            int (*operation)(int, int) = nullptr;
            if (op == '+') operation = sum;
            else if (op == '-') operation = sub;
            else if (op == '*') operation = mul;
            else if (op == '/') operation = divi;
            if (operation) cout << "Результат: " << operation(x, y) << endl;
            break;
        }
        case 2: {
            char s1[100], s2[100];
            cout << "Введите первую строку: ";
            cin >> s1;
            cout << "Введите вторую строку: ";
            cin >> s2;
            int (*cmp)(const char*, const char*) = compareStrings;
            int res = cmp(s1, s2);
            if (res > 0) cout << "Первая больше" << endl;
            else if (res < 0) cout << "Вторая больше" << endl;
            else cout << "Равны" << endl;
            break;
        }
        case 3: {
            int arr[] = { 5, 2, 9, 1, 5 };
            int n = 5;
            bubbleSort(arr, n, asc);
            cout << "Отсортировано по возрастанию: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            break;
        }
        case 4: {
            int arr[] = { 5, 2, 9, 1, 5 };
            int n = 5;
            bubbleSort(arr, n, desc);
            cout << "Отсортировано по убыванию: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            break;
        }
        case 5: {
            double res = integrate(0, 3.14159, 1000, sin);
            cout << "Интеграл sin(x) от 0 до pi: " << res << endl;
            break;
        }
        case 6: {
            auto square = [](double x) { return x * x; };
            double res = integrate(0, 2, 1000, square);
            cout << "Интеграл x*x от 0 до 2: " << res << endl;
            break;
        }
        case 7: {
            void (*menuActions[])() = { openFile, saveFile, exitProg };
            int mchoice;
            cout << "1. Открыть файл\n2. Сохранить файл\n3. Выход\nВыберите: ";
            cin >> mchoice;
            if (mchoice >= 1 && mchoice <= 3) menuActions[mchoice - 1]();
            break;
        }
        case 8: {
            vector<int> vec = { 1, 2, 3, 4, 5 };
            cout << "Элементы вектора: ";
            for (auto it = vec.begin(); it != vec.end(); ++it)
                cout << *it << " ";
            cout << endl;
            break;
        }
        case 9: {
            int a = 5;
            double b = 3.14;
            decltype(a * b) c1 = a * b;
            auto c2 = a * b;
            cout << "decltype результат: " << c1 << ", auto результат: " << c2 << endl;
            break;
        }
        case 10: {
            cout << "add(3, 4.2) = " << add(3, 4.2) << endl;
            break;
        }
        case 11: {
            double (*f1)(int) = plainRetFunc();
            auto f2 = altRetFunc();
            cout << "Обычное объявление: " << f1(2) << ", альтернативное: " << f2(2) << endl;
            break;
        }
        }
    } while (choice != 0);

    return 0;
}