#include <iostream>
using namespace std;
enum class ErrorCode {
    success,
    file_not_found,
    access_denied,
    out_of_memory
};

enum class ConsoleColor {
    reset,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white
};

enum class SortOrder {
    ascending,
    descending
};

enum class Day {
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

enum class TrafficLight {
    red,
    green,
    yellow
};

ErrorCode checkFileAccess(bool fileExists, bool hasAccess, bool memoryAvailable) {
    if (!fileExists) return ErrorCode::file_not_found;
    if (!hasAccess) return ErrorCode::access_denied;
    if (!memoryAvailable) return ErrorCode::out_of_memory;
    return ErrorCode::success;
}

void printColored(ConsoleColor color, const string& text) {
    switch (color) {
    case ConsoleColor::reset: cout << "\033[0m"; break;
    case ConsoleColor::red: cout << "\033[31m"; break;
    case ConsoleColor::green: cout << "\033[32m"; break;
    case ConsoleColor::yellow: cout << "\033[33m"; break;
    case ConsoleColor::blue: cout << "\033[34m"; break;
    case ConsoleColor::magenta: cout << "\033[35m"; break;
    case ConsoleColor::cyan: cout << "\033[36m"; break;
    case ConsoleColor::white: cout << "\033[37m"; break;
    }
    cout << text << "\033[0m";
}

void sortArray(int arr[], int size, SortOrder order) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool shouldSwap = false;
            if (order == SortOrder::ascending) {
                shouldSwap = arr[j] > arr[j + 1];
            }
            else {
                shouldSwap = arr[j] < arr[j + 1];
            }

            if (shouldSwap) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

string getDayName(Day day) {
    switch (day) {
    case Day::monday: return "Понедельник";
    case Day::tuesday: return "Вторник";
    case Day::wednesday: return "Среда";
    case Day::thursday: return "Четверг";
    case Day::friday: return "Пятница";
    case Day::saturday: return "Суббота";
    case Day::sunday: return "Воскресенье";
    default: return "Неизвестный день";
    }
}

bool isWeekend(Day day) {
    return day == Day::saturday || day == Day::sunday;
}

TrafficLight nextLight(TrafficLight current) {
    switch (current) {
    case TrafficLight::red: return TrafficLight::green;
    case TrafficLight::green: return TrafficLight::yellow;
    case TrafficLight::yellow: return TrafficLight::red;
    default: return TrafficLight::red;
    }
}

string getLightName(TrafficLight light) {
    switch (light) {
    case TrafficLight::red: return "Красный";
    case TrafficLight::green: return "Зеленый";
    case TrafficLight::yellow: return "Желтый";
    default: return "Неизвестный";
    }
}

void displayMenu() {
    printColored(ConsoleColor::cyan, "\n\tМеню\n");
    printColored(ConsoleColor::yellow, "1. Проверить коды ошибок\n");
    printColored(ConsoleColor::yellow, "2. Вывести цветной текст\n");
    printColored(ConsoleColor::yellow, "3. Отсортировать массив\n");
    printColored(ConsoleColor::yellow, "4. Дни недели\n");
    printColored(ConsoleColor::yellow, "5. Светофор\n");
    printColored(ConsoleColor::yellow, "0. Выход\n");
    printColored(ConsoleColor::green, "Выберите опцию: ");
}

int main() {
    setlocale(LC_ALL, "ru");
    int numbers[] = { 5, 2, 8, 1, 9, 3 };
    int size = 6;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            printColored(ConsoleColor::blue, "\n\tПроверка ошибок\n");

            bool fileExists, hasAccess, memoryAvailable;

            printColored(ConsoleColor::white, "Файл существует? (1/0): ");
            cin >> fileExists;
            printColored(ConsoleColor::white, "Есть доступ? (1/0): ");
            cin >> hasAccess;
            printColored(ConsoleColor::white, "Память доступна? (1/0): ");
            cin >> memoryAvailable;

            ErrorCode result = checkFileAccess(fileExists, hasAccess, memoryAvailable);

            switch (result) {
            case ErrorCode::success:
                printColored(ConsoleColor::green, "Успешно!\n");
                break;
            case ErrorCode::file_not_found:
                printColored(ConsoleColor::red, "Ошибка: Файл не найден\n");
                break;
            case ErrorCode::access_denied:
                printColored(ConsoleColor::red, "Ошибка: Доступ запрещен\n");
                break;
            case ErrorCode::out_of_memory:
                printColored(ConsoleColor::red, "Ошибка: Нехватка памяти\n");
                break;
            }
        }
        else if (choice == 2) {
            printColored(ConsoleColor::blue, "\n\tЦветной текст\n");

            printColored(ConsoleColor::red, "Красный текст\n");
            printColored(ConsoleColor::green, "Зеленый текст\n");
            printColored(ConsoleColor::yellow, "Желтый текст\n");
            printColored(ConsoleColor::blue, "Синий текст\n");
            printColored(ConsoleColor::magenta, "Фиолетовый текст\n");
            printColored(ConsoleColor::cyan, "Бирюзовый текст\n");
            printColored(ConsoleColor::white, "Белый текст\n");
        }
        else if (choice == 3) {
            printColored(ConsoleColor::blue, "\n\tСортировка массива\n");

            int arr[6];
            for (int i = 0; i < size; i++) {
                arr[i] = numbers[i];
            }

            printColored(ConsoleColor::white, "Исходный массив: ");
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";

            int sortChoice;
            printColored(ConsoleColor::white, "1. По возрастанию\n");
            printColored(ConsoleColor::white, "2. По убыванию\n");
            printColored(ConsoleColor::green, "Выберите порядок: ");
            cin >> sortChoice;

            SortOrder order = (sortChoice == 1) ? SortOrder::ascending : SortOrder::descending;
            sortArray(arr, size, order);

            printColored(ConsoleColor::green, "Отсортированный массив: ");
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        else if (choice == 4) {
            printColored(ConsoleColor::blue, "\n\tДни недели\n");

            int dayChoice;
            printColored(ConsoleColor::white, "Выберите день:\n");
            printColored(ConsoleColor::white, "1. Понедельник\n");
            printColored(ConsoleColor::white, "2. Вторник\n");
            printColored(ConsoleColor::white, "3. Среда\n");
            printColored(ConsoleColor::white, "4. Четверг\n");
            printColored(ConsoleColor::white, "5. Пятница\n");
            printColored(ConsoleColor::white, "6. Суббота\n");
            printColored(ConsoleColor::white, "7. Воскресенье\n");
            printColored(ConsoleColor::green, "Ваш выбор: ");
            cin >> dayChoice;

            Day selectedDay;
            switch (dayChoice) {
            case 1: selectedDay = Day::monday; break;
            case 2: selectedDay = Day::tuesday; break;
            case 3: selectedDay = Day::wednesday; break;
            case 4: selectedDay = Day::thursday; break;
            case 5: selectedDay = Day::friday; break;
            case 6: selectedDay = Day::saturday; break;
            case 7: selectedDay = Day::sunday; break;
            default: selectedDay = Day::monday;
            }

            string dayName = getDayName(selectedDay);
            bool weekend = isWeekend(selectedDay);

            cout << "День: " << dayName << endl;
            if (weekend) {
                printColored(ConsoleColor::green, "Эт выходной день.\n");
            }
            else {
                printColored(ConsoleColor::yellow, "Эт рабочий день.\n");
            }
        }
        else if (choice == 5) {
            printColored(ConsoleColor::blue, "\n\tСветофор\n");

            TrafficLight current = TrafficLight::red;

            cout << "Текущий свет: " << getLightName(current) << endl;

            int steps;
            printColored(ConsoleColor::green, "Сколько шагов переключить?: ");
            cin >> steps;

            for (int i = 0; i < steps; i++) {
                current = nextLight(current);
                cout << "Шаг " << i + 1 << ": " << getLightName(current) << endl;
            }
        }
        else if (choice == 0) {
            printColored(ConsoleColor::green, "\nВииход\n");
            break;
        }
        else {
            printColored(ConsoleColor::red, "Нет такей!\n");
        }
    }
    return 0;
}