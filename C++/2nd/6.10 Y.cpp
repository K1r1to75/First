#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    // 1
    cout << "Определение типа символа\n";

    char symbol;
    cout << "Введите символ: ";
    cin >> symbol;

    if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
        cout << "Буква\n";
    }
    else if (symbol >= '0' && symbol <= '9') {
        cout << "Цифра\n";
    }
    else if (symbol == '.' ||  symbol == ',' || symbol == '!' || symbol == '?' || symbol == ':' || symbol == ';' || symbol == '-' || symbol == '"') {
        cout << "Знак препинания\n";
    }
    else {
        cout << "Другое\n";
    }

    cout << "\n";

    // 2
    cout << "Расчет стоимости разговора\n";

    int dur;
    int opF, opT;
    double cost;

    cout << "Введите длительность разговора (в минутах): ";
    cin >> dur;

    cout << "Выберите оператора ОТКУДА звоните:\n";
    cout << "1 - МТС\n";
    cout << "2 - Билайн\n";
    cout << "3 - Мегафон\n";
    cout << "4 - Теле2\n";
    cin >> opF;

    cout << "Выберите оператора КУДА звоните:\n";
    cout << "1 - МТС\n";
    cout << "2 - Билайн\n";
    cout << "3 - Мегафон\n";
    cout << "4 - Теле2\n";
    cin >> opT;

    
    if (opF == opT) {
        cost = dur * 1.0;  // 1 рубль за минуту внутри сети
    }
    else {
        cost = dur  * 2.0;  // 2 рубля за минуту к другим операторам
    }

    cout << "Стоимость разговора: " << cost << " руб.\n";

    cout << "\n";

    // ЗАДАНИЕ 3
    cout << "Зп Васи\n";

    int choice;
    cout << "Выберите вариант расчета:\n";
    cout << "1 - Расчет строк кода по желаемому доходу и опозданиям\n";
    cout << "2 - Расчет допустимых опозданий по написанному коду и желаемой зарплате\n";
    cout << "3 - Расчет итоговой зарплаты по написанному коду и опозданиям\n";
    cin >> choice;

    if (choice == 1) {
        //Расчет строк кода
        double dSal;
        int lateCount;

        cout << "Введите желаемый доход Васи ($): ";
        cin >> dSal;
        cout << "Введите количество опозданий: ";
        cin >> lateCount;

        // Штраф за каждое третье опоздание
        int penaltyCount = lateCount / 3;
        double totalPenalty = penaltyCount * 20;

        // Нужно заработать с учетом штрафов
        double neededEarn = dSal + totalPenalty;

        // Строки кода (50$ за 100 строк = 0.5$ за строку)
        int linesNeed = (neededEarn / 0.5);

        cout << "Васе нужно написать: " << linesNeed << " строк кода\n";
        cout << "Штраф за опоздания: " << totalPenalty << "$\n";

    }

    else if (choice == 2) {
        //Сколько раз Вася может опоздать
        int linesWritten;
        double desiredSalary;

        cout << "Введите количество написанных строк кода: ";
        cin >> linesWritten;
        cout << "Введите желаемую зарплату ($): ";
        cin >> desiredSalary;

        //Зп без штрафов
        double baseSalary = linesWritten * 0.5;

        if (baseSalary < desiredSalary) {
            cout << "Невозможно достичь желаемой зарплаты даже без опозданий!\n";
            cout << "Максимальная зарплата: " << baseSalary << "$\n";
        }
        else {
            double availablePenalty = baseSalary - desiredSalary;
            int maxPenalties = availablePenalty / 20;
            int maxLateDays = maxPenalties * 3;

            cout << "Вася может опоздать: " << maxLateDays << " раз\n";
            cout << "Это " << maxPenalties << " штрафов по 20$\n";
        }

    }
    else if (choice == 3) {
        //Расчет итоговой зарплаты
        int linesWritten;
        int lateCount;

        cout << "Введите количество написанных строк кода: ";
        cin >> linesWritten;
        cout << "Введите количество опозданий: ";
        cin >> lateCount;


        double baseSalary = linesWritten * 0.5;

        // Штрафы
        int penaltyCount = lateCount / 3;
        double totalPenalty = penaltyCount * 20;

        double finalSalary = baseSalary - totalPenalty;

        if (finalSalary < 0) {
            cout << "Вася должен компании: " << -finalSalary << "$\n";
            cout << "Деньги НЕ заплатят!\n";
        }
        else {
            cout << "Итоговая зарплата Васи: " << finalSalary << "$\n";
            cout << "Штраф за опоздания: " << totalPenalty << "$\n";
        }

    }
    return 0;
}