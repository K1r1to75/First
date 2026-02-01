#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <clocale>
#include <Windows.h> // Для SetConsoleCP и SetConsoleOutputCP
using namespace std;

// Структура
struct Task {
    string title; // название
    int priority; // приоритет
    string description; // описание
    string datetime; // дата и время 
};

// Хранилище 
vector<Task> tasks;

// Добавление задач
void addTask() {
    Task t;
    cin.ignore();

    cout << "Название: ";
    getline(cin, t.title);

    cout << "Приоритет (1-5): ";
    cin >> t.priority;
    cin.ignore();

    cout << "Описание: ";
    getline(cin, t.description);

    cout << "Дата и время (например 2000-01-01 12:00): ";
    getline(cin, t.datetime);

    tasks.push_back(t);
    cout << "Дело добавлено успешно!\n";
}

// Удаление задач
void deleteTask() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    int index;
    cout << "Номер дела для удаления: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Дело удалено успешно!\n";
    }
    else {
        cout << "Неверный номер дела!\n";
    }
}

// Редактирование задач
void editTask() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    int index;
    cout << "Номер дела для редактирования: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        cin.ignore();
        cout << "Новое название: ";
        getline(cin, tasks[index - 1].title);

        cout << "Новый приоритет (1-5): ";
        cin >> tasks[index - 1].priority;
        cin.ignore();

        cout << "Новое описание: ";
        getline(cin, tasks[index - 1].description);

        cout << "Новая дата и время: ";
        getline(cin, tasks[index - 1].datetime);

        cout << "Дело отредактировано успешно!\n";
    }
    else {
        cout << "Неверный номер дела!\n";
    }
}

// Просмотр конкретного дела
void viewTaskDetails() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    int index;
    cout << "Введите номер дела для просмотра: ";
    cin >> index;

    if (index > 0 && index <= tasks.size()) {
        Task& task = tasks[index - 1];

        cout << "\n========================================\n";
        cout << "        Информация о деле №" << index << "\n";
        cout << "========================================\n";
        cout << "Название:    " << task.title << "\n";
        cout << "Приоритет:   " << task.priority << "\n";
        cout << "Дата и время: " << task.datetime << "\n";
        cout << "Описание:\n";
        cout << "  " << task.description << "\n";
        cout << "========================================\n";
    }
    else {
        cout << "Неверный номер дела!\n";
    }
}

// Поиск задач
void searchByTitle() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    string key;
    cin.ignore();
    cout << "Введите название для поиска: ";
    getline(cin, key);

    bool found = false;
    cout << "\nРезультаты поиска:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].title.find(key) != string::npos) {
            cout << i + 1 << ". "
                << "Название: " << tasks[i].title << " | "
                << "Приоритет: " << tasks[i].priority << " | "
                << "Дата и время: " << tasks[i].datetime << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Дела с таким названием не найдены.\n";
    }
}

// Отображение всех задач
void showTasks() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    cout << "\nСписок всех дел:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
            << "Название: " << tasks[i].title << " | "
            << "Приоритет: " << tasks[i].priority << " | "
            << "Дата и время: " << tasks[i].datetime << endl;
    }
}

// Сортировка задач
// По приоритету
void sortByPriority() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    sort(tasks.begin(), tasks.end(),
        [](Task a, Task b) {
            return a.priority < b.priority;
        });
    cout << "Дела отсортированы по приоритету!\n";
}
//По дате
void sortByDate() {
    if (tasks.empty()) {
        cout << "Список дел пуст!\n";
        return;
    }

    sort(tasks.begin(), tasks.end(),
        [](Task a, Task b) {
            return a.datetime < b.datetime;
        });
    cout << "Дела отсортированы по дате!\n";
}

// Меню
int main() {
    SetConsoleCP(1251); // кодировка ввода
    SetConsoleOutputCP(1251); // кодировка вывода
    setlocale(LC_ALL, "ru");

    int choice;

    do {
        cout << "\n===== Меню списка дел =====\n";
        cout << "1. Добавить дело\n";
        cout << "2. Удалить дело\n";
        cout << "3. Редактировать дело\n";
        cout << "4. Показать все дела (кратко)\n";
        cout << "5. Просмотреть детали дела\n";
        cout << "6. Поиск по названию\n";
        cout << "7. Сортировать по приоритету\n";
        cout << "8. Сортировать по дате\n";
        cout << "0. Выход\n";
        cout << "==============================\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: addTask(); break;
        case 2: deleteTask(); break;
        case 3: editTask(); break;
        case 4: showTasks(); break;
        case 5: viewTaskDetails(); break;
        case 6: searchByTitle(); break;
        case 7: sortByPriority(); break;
        case 8: sortByDate(); break;
        case 0: cout << "Выход из программы...\n"; break;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}