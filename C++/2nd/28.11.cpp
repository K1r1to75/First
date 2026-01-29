#include <iostream>
using namespace std;
//      Задание 1: Телефонный справочник

// Функция ввода
void input(long long* mobile, long long* home, int num) {
    cout << "Введите " << num << " номеров мобильных телефонов:" << endl;
    for (int i = 0; i < num; i++) {
        cout << "Мобильный " << i + 1 << ": ";
        cin >> mobile[i];
    }

    cout << "\nВведите " << num << " домашних номеров телефонов:" << endl;
    for (int i = 0; i < num; i++) {
        cout << "Домашний " << i + 1 << ": ";
        cin >> home[i];
    }
}

// Функция вывода
void print(long long* mobile, long long* home, int num) {
    cout << "\n\tТелефонный справочник" << endl;
    cout << "№\tМобильный\tДомашний" << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < num; i++) {
        cout << i + 1 << "\t" << mobile[i] << "\t" << home[i] << endl;
    }
    cout << endl;
}

// Функция сортировки пузырьком
void sort1(long long* mobile, long long* home, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mobile[j] > mobile[j + 1]) {
                long long temp = mobile[j];
                mobile[j] = mobile[j + 1];
                mobile[j + 1] = temp;
                long long temp2 = home[j];
                home[j] = home[j + 1];
                home[j + 1] = temp2;
            }
        }
    }
    cout << "Сортировка по мобильным номерам завершена!" << endl;
}

void sort2(long long* mobile, long long* home, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (home[j] > home[j + 1]) {
                long long tempHome = home[j];
                home[j] = home[j + 1];
                home[j + 1] = tempHome;
                long long tempMobile = mobile[j];
                mobile[j] = mobile[j + 1];
                mobile[j + 1] = tempMobile;
            }
        }
    }
    cout << "Сортировка по домашним номерам завершена!" << endl;
}

// Функция меню
void menu() {
    cout << "\n\tМеню" << endl;
    cout << "1. Отсортировать по номерам мобильных" << endl;
    cout << "2. Отсортировать по домашним номерам телефонов" << endl;
    cout << "3. Вывести пользовательские данные" << endl;
    cout << "4. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    const int num = 5;
    long long mobile[num];
    long long home[num];
    cout << "Телефонный справочник" << endl;
    input(mobile, home, num);

    int choice;
    bool exit = false;

    while (!exit) {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            sort1(mobile, home, num);
            break;
        case 2:
            sort2(mobile, home, num);
            break;
        case 3:
            print(mobile, home, num);
            break;
        case 4:
            exit = true;
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
            break;
        }
    }

}

//      Задание 2: Усовершенствованный пузырь

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swaps = 0;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }

        if (swaps == 0) {
            break;
        }
    }
}

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int arr[n];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, n);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}