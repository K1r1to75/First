#include <iostream>
using namespace std;

//1
void convertToBase(int number, int base) {
    if (base < 2 || base > 36) {
        cout << "Неверная система счисления!" << endl;
        return;
    }

    char result[32];
    int index = 0;
    int temp = number;

    if (number == 0) {
        cout << "0" << endl;
        return;
    }

    while (temp > 0) {
        int remainder = temp % base;
        if (remainder < 10) {
            result[index++] = '0' + remainder;
        }
        else {
            result[index++] = 'A' + (remainder - 10);
        }
        temp /= base;
    }

    cout << "Число " << number << " в системе счисления " << base << ": ";
    for (int i = index - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

//2
void diceGame() {
    srand(time(0));

    int humanScore = 0, computerScore = 0;
    int humanThrows[5], computerThrows[5];
    bool humanFirst;

    cout << "Кто бросает первым? (1 - человек, 0 - компьютер): ";
    cin >> humanFirst;

    cout << "\tИгра в кубики" << endl;

    for (int round = 0; round < 5; round++) {
        cout << "\n--- Раунд " << (round + 1) << " ---" << endl;

        if ((humanFirst && round % 2 == 0) || (!humanFirst && round % 2 == 1)) {
            // Ход человека
            cout << "Ваш бросок: ";
            int dice1 = rand() % 6 + 1;
            int dice2 = rand() % 6 + 1;
            humanThrows[round] = dice1 + dice2;
            humanScore += humanThrows[round];

            cout << "[" << dice1 << "][" << dice2 << "] = " << humanThrows[round] << endl;
        }
        else {
            cout << "Бросок компьютера: ";
            int dice1 = rand() % 6 + 1;
            int dice2 = rand() % 6 + 1;
            computerThrows[round] = dice1 + dice2;
            computerScore += computerThrows[round];

            cout << "[" << dice1 << "][" << dice2 << "] = " << computerThrows[round] << endl;
        }
    }

    cout << "\n\tРезультаты:" << endl;
    cout << "Ваш общий счет: " << humanScore << endl;
    cout << "Счет компьютера: " << computerScore << endl;
    cout << "Ваша средняя сумма: " << (double)humanScore / 5 << endl;
    cout << "Средняя сумма компьютера: " << (double)computerScore / 5 << endl;

    if (humanScore > computerScore) {
        cout << "ПОБЕДА! Вы выиграли!" << endl;
    }
    else if (humanScore < computerScore) {
        cout << "ПОРАЖЕНИЕ! Компьютер выиграл!" << endl;
    }
    else {
        cout << "Ничья!" << endl;
    }
}

// Задание 3 - Функция рисования прямоугольника
void drawRectangle(int n, int k) {
    cout << "Прямоугольник " << n << "x" << k << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Задание 4 - Функция вычисления факториала
void factorial(int n) {
    if (n < 0) {
        cout << "Факториал отрицательного числа не определен!" << endl;
        return;
    }

    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    cout << n << "! = " << result << endl;
}

// Задание 5 - Функция проверки простого числа
void isPrime(int number) {
    if (number <= 1) {
        cout << number << " - не простое число" << endl;
        return;
    }

    bool prime = true;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            prime = false;
            break;
        }
    }

    if (prime) {
        cout << number << " - простое число" << endl;
    }
    else {
        cout << number << " - составное число" << endl;
    }
}

// задание 6 - Функция поиска минимума и максимума в массиве
void findMinMax(int arr[], int size) {
    if (size <= 0) {
        cout << "Массив пуст!" << endl;
        return;
    }

    int minVal = arr[0], maxVal = arr[0];
    int minIndex = 0, maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }

    cout << "Минимум: значение = " << minVal << ", индекс = " << minIndex << endl;
    cout << "Максимум: значение = " << maxVal << ", индекс = " << maxIndex << endl;
}

// Задание 7 - Функция обращения массива
void reverseArray(int arr[], int size) {
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }

    cout << "Перевернутый массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "ru");
    int z1, z12, z3, z32, z4, z5, z6, z62, z7, z72;
    cout << "\tЗадание 1: Перевод в систему счисления" << endl;
    cout << "Введите числа: ";
    cin >> z1; cin >> z12;
    convertToBase(z1, z12);

    cout << "\n\tЗадание 2: Игра в кубики" << endl;
    diceGame();

    cout << "\n\tЗадиние 3: Рисование прямоугольника" << endl;
    cout << "Введите N:";
    cin >> z3;
    cout << "Введите K:";
    cin >> z32;
    drawRectangle(z3, z32);

    cout << "\n\tЗадание 4: Вычисление факториала" << endl;
    cout << "Введите число: ";
    cin >> z4;
    factorial(z4);

    cout << "\n\tЗадание 5: Проверка простого числа" << endl;
    cout << "Введите число: ";
    cin >> z5;
    isPrime(z5);

    cout << "\n\tЗадание 6: Поиск минимума и максимума" << endl;
    int arr1[] = { 3, 7, 2, 9, 1, 8, 4 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    findMinMax(arr1, size1);

    cout << "\n\tЗадание 7: Обращение массива" << endl;
    int arr2[] = { 1, 2, 3, 4, 5 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    reverseArray(arr2, size2);

    return 0;
}