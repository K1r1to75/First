
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru"); 
    //1
    int number;
    cout << "Введите число больше нуля: ";
    cin >> number;
    if (number <= 0) {
        cout << "Число равно или меньше нуля, повторите запрос." << endl;
    }
    cout << "Ваше число наоборот: ";

    while (number > 0) {
        int digit = number % 10;
        cout << digit;
        number = number / 10;
    }

    cout << endl;

    //2
    int number1;
    cout << "Введите число";
    cin >> number1;
    int sum = 0;
    while (number1 > 0) {
        sum += number1 % 10;
        number1 /= 10;
    }
    cout << "Сумма цифр равна " << sum << endl;

    //3
    int n;
    cout << "Введите количество дней: ";
    cin >> n;

    int first_day = 15;
    int increase = 2;
    int total = 0;
    int current_distance = first_day;

    for (int day = 1; day <= n; day++) {
        total += current_distance;
        current_distance += increase;

    }
    cout << "За " << n << " дней, улитка проползёт " << total << "см." << endl;
    
    //4
    int heads = 0;

    cout << "Введите 9 результатов (1 - орел, 0 - решка):" << endl;

    for (int i = 1; i <= 9; i++) {
        int coin;
        cout << i << ": ";
        cin >> coin;

        // Проверка
        while (coin != 0 && coin != 1) {
            cout << "Только 1 или 0, повторите: ";
            cin >> coin;
        }

        heads += coin; //Счётчик
    }

    cout << "\nОрлов: " << heads << endl;
    cout << "Решение: " << (heads % 2 == 0 ? "Положительное" : "Отрицательное") << endl;    
    return 0;
}

