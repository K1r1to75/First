#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    // Задание 1
    int n;
    cout << "\nВведите номер символа для удаления: ";
    cin >> n;
    // Удаление символа
    if (n >= 0 && n < s.length()) {
        s.erase(n, 1);
    }
    cout << "Результат: " << s << endl;

    // Задание 2
    char c;
    cout << "\nВведите символ для удаления: ";
    cin >> c;
    string s2 = "";
    // Удаление всех вхождений символа
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != c) s2 += s[i];
    }
    cout << "Результат: " << s2 << endl;

    // Задание 3
    cout << "\nВведите позицию: ";
    cin >> n;
    cout << "Введите символ: ";
    cin >> c;
    // Вставка символа
    string s3 = s;
    if (n >= 0 && n <= s3.length()) {
        s3.insert(n, 1, c);
    }
    cout << "Результат: " << s3 << endl;

    // Задание 4
    string s4 = s;
    // Замена всех точек на восклицательные знаки
    for (int i = 0; i < s4.length(); i++) {
        if (s4[i] == '.') s4[i] = '!';
    }
    cout << "\nРезультат: " << s4 << endl;

    // Задание 5
    cout << "\nВведите символ для поиска: ";
    cin >> c;
    int count = 0;
    // Подсчет количества вхождений символа
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) count++;
    }
    cout << "Количество: " << count << endl;

    // Задание 6
    int buk = 0, cif = 0, ost = 0;
    // Подсчет букв, цифр и остальных символов
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) buk++;
        else if (ch >= '0' && ch <= '9') cif++;
        else ost++;
    }
    cout << "\nБуквы: " << buk << ", Цифры: " << cif << ", Остальное: " << ost << endl;

    return 0;
}