#include <iostream>
using namespace std;
// Функция для добавления строки в конец массива
int** addRowToEnd(int** arr, int rows, int cols, int* newRow) {
    int** newArr = new int* [rows + 1];

    for (int i = 0; i < rows; i++) {
        newArr[i] = arr[i];
    }

    newArr[rows] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[rows][j] = newRow[j];
    }

    delete[] arr;
    return newArr;
}

// Функция для добавления строки в начало массива
int** addRowToBeginning(int** arr, int rows, int cols, int* newRow) {
    int** newArr = new int* [rows + 1];

    newArr[0] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[0][j] = newRow[j];
    }

    for (int i = 0; i < rows; i++) {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    return newArr;
}

// Функция для добавления строки в указанную позицию
int** addRowAtPosition(int** arr, int rows, int cols, int* newRow, int pos) {
    if (pos < 0 || pos > rows) {
        cout << "Неверная позиция!\n";
        return arr;
    }

    int** newArr = new int* [rows + 1];

    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    newArr[pos] = new int[cols];
    for (int j = 0; j < cols; j++) {
        newArr[pos][j] = newRow[j];
    }

    for (int i = pos; i < rows; i++) {
        newArr[i + 1] = arr[i];
    }

    delete[] arr;
    return newArr;
}

// Функция для удаления строки по указанному номеру
int** deleteRow(int** arr, int rows, int cols, int pos) {
    if (pos < 0 || pos >= rows) {
        cout << "Неверная позиция!\n";
        return arr;
    }

    int** newArr = new int* [rows - 1];

    delete[] arr[pos];

    int newIndex = 0;
    for (int i = 0; i < rows; i++) {
        if (i != pos) {
            newArr[newIndex] = arr[i];
            newIndex++;
        }
    }

    delete[] arr;
    return newArr;
}

// Функция для вывода массива
void printArray(int** arr, int rows, int cols) {
    cout << "\nТекущий массив (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция для ввода строки с клавиатуры
int* inputRow(int cols) {
    int* row = new int[cols];
    cout << "Введите " << cols << " элементов строки через пробел: ";
    for (int i = 0; i < cols; i++) {
        cin >> row[i];
    }
    return row;
}

int main() {
    int rows, cols;

    cout << "Введите размеры массива (строки столбцы): ";
    cin >> rows >> cols;

    // Создание исходного массива
    int** arr = new int* [rows];
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
        cout << "Строка " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    int choice;
    do {
        cout << "\n\tМеню\n";
        cout << "1. Вывести массив\n";
        cout << "2. Добавить строку в конец\n";
        cout << "3. Добавить строку в начало\n";
        cout << "4. Добавить строку в указанную позицию\n";
        cout << "5. Удалить строку\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printArray(arr, rows, cols);
            break;

        case 2:
        {
            int* newRow = inputRow(cols);
            arr = addRowToEnd(arr, rows, cols, newRow);
            rows++;
            delete[] newRow;
            cout << "Строка добавлена в конец.\n";
        }
        break;

        case 3:
        {
            int* newRow = inputRow(cols);
            arr = addRowToBeginning(arr, rows, cols, newRow);
            rows++;
            delete[] newRow;
            cout << "Строка добавлена в начало.\n";
        }
        break;

        case 4:
        {
            int pos;
            cout << "Введите позицию для вставки (0-" << rows << "): ";
            cin >> pos;
            int* newRow = inputRow(cols);
            arr = addRowAtPosition(arr, rows, cols, newRow, pos);
            rows++;
            delete[] newRow;
            cout << "Строка добавлена в позицию " << pos << ".\n";
        }
        break;

        case 5:
        {
            int pos;
            cout << "Введите номер строки для удаления (0-" << rows - 1 << "): ";
            cin >> pos;
            arr = deleteRow(arr, rows, cols, pos);
            rows--;
            cout << "Строка " << pos << " удалена.\n";
        }
        break;

        case 0:
            cout << "Выход\n";
            break;

        default:
            cout << "Неправильно\n";
        }

    } while (choice != 0);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}