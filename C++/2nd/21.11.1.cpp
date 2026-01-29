#include <iostream>
using namespace std;


//1
// Функции для работы с матрицей
void intMatrix() {
    int matrix[3][3];
    int size = 3;

    cout << "\tМатрица int" << endl;
    cout << "Введите 9 чисел для матрицы 3x3:" << endl;

    // Ввод матрицы
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "Ваша матрица:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Min и max
    int min = matrix[0][0];
    int max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
    cout << "Минимальный на диагонали: " << min << endl;
    cout << "Максимальный на диагонали: " << max << endl;

    // Сортировка строк
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }

    cout << "После сортировки строк:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функции для работы с double матрицей
void doubleMatrix() {
    double matrix[3][3];
    int size = 3;

    cout << "\n\tМатрица double" << endl;
    cout << "Введите 9 чисел для матрицы 3x3:" << endl;

    // Ввод матрицы
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "Ваша матрица:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Min и max
    double min = matrix[0][0];
    double max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
    cout << "Минимальный на диагонали: " << min << endl;
    cout << "Максимальный на диагонали: " << max << endl;

    // Сортировка строк
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    double temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }

    cout << "После сортировки строк:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функции для работы с char матрицей
void charMatrix() {
    char matrix[3][3];
    int size = 3;

    cout << "\n\tМатрица char" << endl;
    cout << "Введите 9 символов для матрицы 3x3:" << endl;

    // Ввод матрицы
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Вывод матрицы
    cout << "Ваша матрица:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Min и max на главной диагонали
    char min = matrix[0][0];
    char max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
    cout << "Минимальный на диагонали: " << min << endl;
    cout << "Максимальный на диагонали: " << max << endl;

    // Сортировка строк
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    char temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }

    cout << "После сортировки строк:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixFunctions() {
    intMatrix();
    doubleMatrix();
    charMatrix();
}

//2
// Рекурсивная функция нахождения НОД
int nod(int a, int b) {
    if (b == 0) {
        return a;
    }
    return nod(b, a % b);
}

void nnod() {
    cout << "\n=== Нахождение НОД ===" << endl;
    int num1, num2;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    // Делаем числа положительными
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    int result = nod(num1, num2);
    cout << "Наибольший общий делитель: " << result << endl;
}

// Проверка на повторяющиеся цифры
bool checkDuplicate(int number) {
    int digits[10] = { 0 };

    while (number > 0) {
        int digit = number % 10;
        if (digits[digit] > 0) {
            return true;
        }
        digits[digit]++;
        number /= 10;
    }
    return false;
}

// Проверка, что число четырехзначное
bool validNumber(int number) {
    return (number >= 1000 && number <= 9999 && !checkDuplicate(number));
}

//3
// Подсчет быков и коров
void countBullsAndCows(int secret, int guess, int& bulls, int& cows) {
    bulls = 0;
    cows = 0;

    int secretDigits[4];
    int guessDigits[4];

    // Разбиваем числа на цифры
    int tempSecret = secret;
    int tempGuess = guess;
    for (int i = 3; i >= 0; i--) {
        secretDigits[i] = tempSecret % 10;
        guessDigits[i] = tempGuess % 10;
        tempSecret /= 10;
        tempGuess /= 10;
    }

    // Считаем быков (правильные цифры на правильных местах)
    for (int i = 0; i < 4; i++) {
        if (secretDigits[i] == guessDigits[i]) {
            bulls++;
        }
    }

    // Считаем коров (правильные цифры на неправильных местах)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && secretDigits[i] == guessDigits[j]) {
                cows++;
            }
        }
    }
}

// Рекурсивная функция игры
void playGame(int secret, int attempts) {
    int guess;
    cout << "Попытка " << attempts << ". Введите четырехзначное число без повторяющихся цифр: ";
    cin >> guess;

    // Проверка ввода
    if (!validNumber(guess)) {
        cout << "Ошибка! Число должно быть четырехзначным и без повторяющихся цифр." << endl;
        playGame(secret, attempts);
        return;
    }

    // Подсчет быков и коров
    int bulls, cows;
    countBullsAndCows(secret, guess, bulls, cows);

    cout << "Быки: " << bulls << ", Коровы: " << cows << endl;

    // Проверка победы
    if (bulls == 4) {
        cout << "Поздравляем! Вы угадали число " << secret << " за " << attempts << " попыток!" << endl;
        return;
    }

    // Следующая попытка
    playGame(secret, attempts + 1);
}

void demoBullsAndCows() {
    cout << "\n\tИгра 'Быки и коровы'" << endl;
    cout << "Загадано четырехзначное число с неповторяющимися цифрами." << endl;
    cout << "Быки - цифры на своих местах, Коровы - правильные цифры не на своих местах." << endl;

    int secret;
    cout << "Загадайте число (1000-9999 без повторяющихся цифр): ";
    cin >> secret;

    // Проверка загаданного числа
    if (!validNumber(secret)) {
        cout << "Ошибка! Загаданное число должно быть четырехзначным и без повторяющихся цифр." << endl;
        return;
    }

    cout << "Число загадано! Игрок, начинай угадывать." << endl;
    playGame(secret, 1);
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice;

    do {
        cout << "\n\tМеню" << endl;
        cout << "1. Работа с матрицами" << endl;
        cout << "2. Нахождение НОД" << endl;
        cout << "3. Игра 'Быки и коровы'" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание: ";
        cin >> choice;

        switch (choice) {
        case 1:
            matrixFunctions();
            break;
        case 2:
            nnod();
            break;
        case 3:
            demoBullsAndCows();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}