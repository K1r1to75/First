#include <iostream>
using namespace std;

// Элементы массива A, которые не включаются в массив B, без повторений.
void no_repetitions(int* a, int m, int* b, int n, int* result, int* res) {
    *res = 0;

    for (int* pa = a; pa < a + m; pa++) {
        bool inb = false;
        for (int* pb = b; pb < b + n; pb++) {
            if (*pa == *pb) {
                inb = true;
                break;
            }
        }

        bool already = false;
        for (int* pr = result; pr < result + *res; pr++) {
            if (*pa == *pr) {
                already = true;
                break;
            }
        }

        if (!inb && !already) {
            result[*res] = *pa;
            (*res)++;
        }
    }
}

// Элементы массивов A и B, которые не являются общими для них, без повторений.
void no_repetitions2(int* a, int m, int* b, int n, int* result, int* res) {
    *res = 0;

    for (int* pa = a; pa < a + m; pa++) {
        bool inb = false;
        for (int* pb = b; pb < b + n; pb++) {
            if (*pa == *pb) {
                inb = true;
                break;
            }
        }

        bool already = false;
        for (int* pr = result; pr < result + *res; pr++) {
            if (*pa == *pr) {
                already = true;
                break;
            }
        }

        if (!inb && !already) {
            result[*res] = *pa;
            (*res)++;
        }
    }

    for (int* pb = b; pb < b + n; pb++) {
        bool ina = false;
        for (int* pa = a; pa < a + m; pa++) {
            if (*pb == *pa) {
                ina = true;
                break;
            }
        }

        bool already = false;
        for (int* pr = result; pr < result + *res; pr++) {
            if (*pb == *pr) {
                already = true;
                break;
            }
        }

        if (!ina && !already) {
            result[*res] = *pb;
            (*res)++;
        }
    }
}

int main() {
    const int m = 5, n = 4;
    int a[m] = { 1, 2, 3, 4, 2 };
    int b[n] = { 2, 4, 6, 8 };

    int result1[m];
    int res1;
    no_repetitions(a, m, b, n, result1, &res1);

    cout << "Массив C: ";
    for (int* p = result1; p < result1 + res1; p++) {
        cout << *p << " ";
    }
    cout << endl;

    int result2[m + n];
    int resSize2;
    no_repetitions2(a, m, b, n, result2, &resSize2);

    cout << "Массив C: ";
    for (int* p = result2; p < result2 + resSize2; p++) {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}