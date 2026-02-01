#include <iostream>
using namespace std;
// Задание 1: Реверс строки
void reverse() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    // Способ 1: с использованием алгоритма (без reverse из <algorithm>)
    string reversed1 = input;
    int len = reversed1.length();
    for (int i = 0; i < len / 2; i++) {
        char temp = reversed1[i];
        reversed1[i] = reversed1[len - 1 - i];
        reversed1[len - 1 - i] = temp;
    }
    cout << "С использованием обмена: " << reversed1 << endl;

    // Способ 2: с использованием цикла
    string reversed2;
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed2 += input[i];
    }
    cout << "С использованием цикла: " << reversed2 << endl;
}

// Задание 2: Подсчет символов
struct CountResult {
    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int other = 0;
};

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

CountResult countCharacters(const string& str) {
    CountResult res;
    for (char c : str) {
        if (isAlpha(c)) {
            res.letters++;
        }
        else if (isDigit(c)) {
            res.digits++;
        }
        else if (isSpace(c)) {
            res.spaces++;
        }
        else {
            res.other++;
        }
    }
    return res;
}

void count() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);
    CountResult res = countCharacters(input);
    cout << "Букв: " << res.letters
        << ", Цифр: " << res.digits
        << ", Пробелов: " << res.spaces
        << ", Других: " << res.other << endl;
}

// Задание 3: Удаление дубликатов
string removeDuplicates(const string& str) {
    string result;
    bool seen[256] = { false };
    for (char c : str) {
        unsigned char uc = c;
        if (!seen[uc]) {
            seen[uc] = true;
            result += c;
        }
    }
    return result;
}

void remove() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);
    string result = removeDuplicates(input);
    cout << "Результат: " << result << endl;
}

// Задание 4: Проверка префикса и суффикса
bool startsWith(const string& str, const string& prefix) {
    if (prefix.length() > str.length()) return false;
    for (size_t i = 0; i < prefix.length(); i++) {
        if (str[i] != prefix[i]) return false;
    }
    return true;
}

bool endsWith(const string& str, const string& suffix) {
    if (suffix.length() > str.length()) return false;
    size_t offset = str.length() - suffix.length();
    for (size_t i = 0; i < suffix.length(); i++) {
        if (str[offset + i] != suffix[i]) return false;
    }
    return true;
}

void starts() {
    string str, prefix, suffix;
    cout << "Введите строку: ";
    getline(cin, str);
    cout << "Введите префикс: ";
    getline(cin, prefix);
    cout << "Введите суффикс: ";
    getline(cin, suffix);

    cout << "Начинается с префикса? " << (startsWith(str, prefix) ? "Да" : "Нет") << endl;
    cout << "Заканчивается суффиксом? " << (endsWith(str, suffix) ? "Да" : "Нет") << endl;
}

// Задание 5: Форматирование имени
string formatName(const string& fullName) {
    string result;
    string part;
    bool firstPart = true;

    for (size_t i = 0; i <= fullName.length(); i++) {
        if (i == fullName.length() || fullName[i] == ' ') {
            if (!part.empty()) {
                if (firstPart) {
                    result = part; // фамилия
                    firstPart = false;
                }
                else {
                    result += " " + string(1, part[0]) + ".";
                }
                part.clear();
            }
        }
        else {
            part += fullName[i];
        }
    }

    return result;
}

void formatName() {
    string input;
    cout << "Введите полное имя: ";
    getline(cin, input);
    cout << "Форматированное имя: " << formatName(input) << endl;
}

// Задание 6: Форматирование телефонного номера
string formatPhoneNumber(const string& input) {
    string digits;
    for (char c : input) {
        if (isDigit(c)) {
            digits += c;
        }
    }

    if (digits.length() == 10) {
        return "+7 (" + digits.substr(0, 3) + ") " + digits.substr(3, 3) + "-" + digits.substr(6, 2) + "-" + digits.substr(8, 2);
    }
    else if (digits.length() == 11 && (digits[0] == '7' || digits[0] == '8')) {
        return "+7 (" + digits.substr(1, 3) + ") " + digits.substr(4, 3) + "-" + digits.substr(7, 2) + "-" + digits.substr(9, 2);
    }
    else if (digits.length() == 6) {
        return digits.substr(0, 3) + "-" + digits.substr(3, 3);
    }
    else if (digits.length() == 7) {
        return digits.substr(0, 3) + "-" + digits.substr(3, 2) + "-" + digits.substr(5, 2);
    }
    else {
        return "Ошибка: некорректная длина номера";
    }
}

void formatPhoneNumber() {
    string input;
    cout << "Введите номер телефона: ";
    getline(cin, input);
    string result = formatPhoneNumber(input);
    cout << "Отформатированный номер: " << result << endl;
}

// Задание 7: Текстовый анализатор
string toLower(const string& str) {
    string result;
    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            result += char(c + 32);
        }
        else {
            result += c;
        }
    }
    return result;
}

void analyzeText() {
    string text;
    cout << "Введите текст: ";
    getline(cin, text);

    // Очистка от знаков препинания и приведение к нижнему регистру
    string cleaned;
    for (char c : text) {
        if (isAlpha(c) || isSpace(c)) {
            cleaned += toLower(string(1, c))[0];
        }
        else if (c != '\'') {
            cleaned += ' ';
        }
    }

    // Разбиение на слова
    string words[1000];
    int wordCount = 0;
    string currentWord;

    for (size_t i = 0; i <= cleaned.length(); i++) {
        if (i == cleaned.length() || isSpace(cleaned[i])) {
            if (!currentWord.empty()) {
                words[wordCount++] = currentWord;
                currentWord.clear();
            }
        }
        else {
            currentWord += cleaned[i];
        }
    }

    if (wordCount == 0) {
        cout << "Нет слов для анализа." << endl;
        return;
    }

    // Статистика
    int totalWords = wordCount;
    string longest = words[0], shortest = words[0];

    // Подсчет частоты (упрощенный способ)
    int freq[1000] = { 0 };
    bool counted[1000] = { false };
    int uniqueCount = 0;

    for (int i = 0; i < wordCount; i++) {
        if (words[i].length() > longest.length()) longest = words[i];
        if (words[i].length() < shortest.length()) shortest = words[i];

        if (!counted[i]) {
            freq[i] = 1;
            for (int j = i + 1; j < wordCount; j++) {
                if (words[i] == words[j]) {
                    freq[i]++;
                    counted[j] = true;
                }
            }
            uniqueCount++;
            counted[i] = true;
        }
    }

    // Находим самое частое слово
    string mostFrequentWord = words[0];
    int maxFreq = 1;
    for (int i = 0; i < wordCount; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequentWord = words[i];
        }
    }

    // Вывод результатов
    cout << "Всего слов: " << totalWords << endl;
    cout << "Уникальных слов: " << uniqueCount << endl;
    cout << "Самое длинное слово: \"" << longest << "\" (" << longest.length() << " букв)" << endl;
    cout << "Самое короткое слово: \"" << shortest << "\" (" << shortest.length() << " букв)" << endl;
    cout << "Самое частое слово: \"" << mostFrequentWord << "\" (" << maxFreq << " раз)" << endl;

    // Собираем уникальные слова
    string uniqueWords[1000];
    int uniqueIndex = 0;
    bool added[1000] = { false };

    for (int i = 0; i < wordCount; i++) {
        if (!added[i]) {
            uniqueWords[uniqueIndex++] = words[i];
            added[i] = true;
            for (int j = i + 1; j < wordCount; j++) {
                if (words[i] == words[j]) {
                    added[j] = true;
                }
            }
        }
    }

    // Сортировка пузырьком
    for (int i = 0; i < uniqueIndex - 1; i++) {
        for (int j = 0; j < uniqueIndex - i - 1; j++) {
            if (uniqueWords[j] > uniqueWords[j + 1]) {
                string temp = uniqueWords[j];
                uniqueWords[j] = uniqueWords[j + 1];
                uniqueWords[j + 1] = temp;
            }
        }
    }

    cout << "Уникальные слова по алфавиту: ";
    for (int i = 0; i < uniqueIndex; i++) {
        cout << uniqueWords[i];
        if (i != uniqueIndex - 1) cout << ", ";
    }
    cout << endl;
}

// Главное меню
int main() {
    int choice;
    do {
        cout << "\n\tМеню заданий" << endl;
        cout << "1. Реверс строки" << endl;
        cout << "2. Подсчет символов" << endl;
        cout << "3. Удаление дубликатов" << endl;
        cout << "4. Проверка префикса/суффикса" << endl;
        cout << "5. Форматирование имени" << endl;
        cout << "6. Форматирование телефонного номера" << endl;
        cout << "7. Текстовый анализатор" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: reverse(); break;
        case 2: count(); break;
        case 3: remove(); break;
        case 4: starts(); break;
        case 5: formatName(); break;
        case 6: formatPhoneNumber(); break;
        case 7: analyzeText(); break;
        case 0: cout << "Выход." << endl; break;
        default: cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);

    return 0;
}