#include <iostream>
#include <string>
using namespace std;

// Функция для вычисления простого выражения без скобок
double calculateSimple(string expr) {
    double result = 0;
    double num = 0;
    char op = '+';
    int i = 0;

    while (i < expr.length()) {
        // Считываем число
        if (expr[i] >= '0' && expr[i] <= '9') {
            num = 0;
            while (i < expr.length() && expr[i] >= '0' && expr[i] <= '9') {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            // Выполняем операцию
            if (op == '+') result += num;
            else if (op == '-') result -= num;
            else if (op == '*') result *= num;
            else if (op == '/') result /= num;
        }
        // Считываем оператор
        else if (expr[i] == '+' || expr[i] == '-' ||
            expr[i] == '*' || expr[i] == '/') {
            op = expr[i];
            i++;
        }
        else {
            i++; // Пропускаем пробелы и другие символы
        }
    }

    return result;
}

// Функция для обработки скобок
double calculate(string expr) {
    // Ищем самую внутреннюю пару скобок
    size_t openBracket = expr.find_last_of('(');

    // Если скобок нет - вычисляем простое выражение
    if (openBracket == string::npos) {
        return calculateSimple(expr);
    }

    // Находим соответствующую закрывающую скобку
    size_t closeBracket = expr.find(')', openBracket);
    if (closeBracket == string::npos) {
        cout << "Ошибка: нет закрывающей скобки!\n";
        return 0;
    }

    // Вычисляем выражение в скобках
    string insideBrackets = expr.substr(openBracket + 1, closeBracket - openBracket - 1);
    double bracketResult = calculate(insideBrackets);

    // Заменяем выражение в скобках на результат
    string before = expr.substr(0, openBracket);
    string after = expr.substr(closeBracket + 1);
    string newExpr = before + to_string((int)bracketResult) + after;

    // Продолжаем вычислять рекурсивно
    return calculate(newExpr);
}

int main() {
    string expr;

    cout << "Введите выражение (поддерживаются +, -, *, / и скобки):\n";
    cout << "Пример: 5 * 2 + 1 или 5 * (2 + 1)\n";
    cout << "Ваше выражение: ";
    getline(cin, expr);

    // Удаляем все пробелы
    string exprWithoutSpaces;
    for (char c : expr) {
        if (c != ' ') {
            exprWithoutSpaces += c;
        }
    }

    double result = calculate(exprWithoutSpaces);
    cout << "Результат: " << result << endl;

    return 0;
}