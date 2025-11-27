#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    // 1
    cout << "Привет! Это проверка таблицы умножения." << endl;
  
    int score = 0;
    int answer;

    // Вопрос 1
    cout << "Сколько будет 3 * 4?" << endl;
    cin >> answer;
    if (answer == 12) {
        cout << "Правильно!" << endl;
        score = score + 1;
    }
    else {
        cout << "Неправильно! Должно быть 12" << endl;
    }

    // Вопрос 2
    cout << "Сколько будет 5 * 6?" << endl;
    cin >> answer;
    if (answer == 30) {
        cout << "Правильно!" << endl;
        score = score + 1;
    }
    else {
        cout << "Неправильно! Должно быть 30" << endl;
    }

    // Вопрос 3
    cout << "Сколько будет 7 * 8?" << endl;
    cin >> answer;
    if (answer == 56) {
        cout << "Правильно!" << endl;
        score = score + 1;
    }
    else {
        cout << "Неправильно! Должно быть 56" << endl;
    }

    // Вопрос 4
    cout << "Сколько будет 9 * 9?" << endl;
    cin >> answer;
    if (answer == 81) {
        cout << "Правильно!" << endl;
        score = score + 1;
    }
    else {
        cout << "Неправильно! Должно быть 81" << endl;
    }

    // Вопрос 5
    cout << "Сколько будет 2 * 7?" << endl;
    cin >> answer;
    if (answer == 14) {
        cout << "Правильно!" << endl;
        score = score + 1;
    }
    else {
        cout << "Неправильно! Должно быть 14" << endl;
    }

    cout << "Твой результат: " << score << " из 5" << endl;

    if (score == 5) {
        cout << "Отлично! Ты знаешь таблицу умножения!" << endl;
    }
    else if (score >= 3) {
        cout << "Хорошо, но нужно еще потренироваться" << endl;
    }
    else {
        cout << "Нужно выучить таблицу умножения получше" << endl;
    }

    // 2
    int size;
    cout << "Из скольки строк сделать ромб? (например, 5): ";
    cin >> size;

    // Верхняя часть ромба
    for (int i = 1; i <= size; i = i + 2) {
        // Пробелы в начале
        for (int j = 1; j <= (size - i) / 2; j++) {
            cout << " ";
        }
        // Звездочки
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Нижняя часть ромба
    for (int i = size - 2; i >= 1; i = i - 2) {
        // Пробелы в начале
        for (int j = 1; j <= (size - i) / 2; j++) {
            cout << " ";
        }
        // Звездочки
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}