#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-10;

// Вывод матрицы
void printMatrix(const vector<vector<double>>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < A[i].size(); j++) {
            cout << setw(10) << fixed << setprecision(6) << A[i][j];
        }
        cout << endl;
    }
}

// Вывод вектора
void printVector(const vector<double>& b) {
    for (double val : b) {
        cout << setw(10) << fixed << setprecision(6) << val;
    }
    cout << endl;
}

// Метод Гаусса для решения СЛАУ
vector<double> gauss(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    // Прямой ход
    for (int i = 0; i < n; i++) {
        // Поиск максимального элемента в столбце для устойчивости
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
                maxRow = k;
            }
        }

        // Перестановка строк
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        // Проверка на нулевой ведущий элемент
        if (fabs(A[i][i]) < EPS) {
            throw runtime_error("Матрица вырождена");
        }

        // Нормализация строки i
        double div = A[i][i];
        for (int j = i; j < n; j++) {
            A[i][j] /= div;
        }
        b[i] /= div;

        // Исключение переменной i из других строк
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = A[k][i];
                for (int j = i; j < n; j++) {
                    A[k][j] -= factor * A[i][j];
                }
                b[k] -= factor * b[i];
            }
        }
    }

    return b; // b теперь содержит решение
}

// Вычисление определителя методом Гаусса
double determinant(vector<vector<double>> A) {
    int n = A.size();
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        // Поиск максимального элемента в столбце
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
                maxRow = k;
            }
        }

        // Перестановка строк
        if (maxRow != i) {
            swap(A[i], A[maxRow]);
            det *= -1; // При перестановке строк знак определителя меняется
        }

        // Проверка на нулевой ведущий элемент
        if (fabs(A[i][i]) < EPS) {
            return 0.0;
        }

        det *= A[i][i];

        // Исключение переменной i из нижних строк
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i + 1; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    return det;
}

// Нахождение обратной матрицы методом Гаусса
vector<vector<double>> inverseMatrix(vector<vector<double>> A) {
    int n = A.size();

    // Создаем расширенную матрицу [A|I]
    vector<vector<double>> augmented(n, vector<double>(2 * n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augmented[i][j] = A[i][j];
        }
        augmented[i][n + i] = 1.0;
    }

    // Прямой ход 
    for (int i = 0; i < n; i++) {
        // Поиск максимального элемента
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(augmented[k][i]) > fabs(augmented[maxRow][i])) {
                maxRow = k;
            }
        }

        if (maxRow != i) {
            swap(augmented[i], augmented[maxRow]);
        }

        if (fabs(augmented[i][i]) < EPS) {
            throw runtime_error("Матрица вырождена, обратной не существует");
        }

        // Нормализация строки i
        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++) {
            augmented[i][j] /= pivot;
        }

        // Исключение переменной i из других строк
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = augmented[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Извлечение обратной матрицы из правой части
    vector<vector<double>> inv(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = augmented[i][n + j];
        }
    }

    return inv;
}

int main() {
    cout << fixed << setprecision(6);
    setlocale(LC_ALL, "ru");




    // Матрица коэффициентов 5x5
    vector<vector<double>> A5 = {
        {5.38, 7.33, -0.24, -0.49, -8.41},
        {2.81, -4.69, -6.13, -3.05, -5.19},
        {7.60, 4.78, 8.59, 0.98, 6.72},
        {-8.44, -8.53, 5.76, -8.34, 4.96},
        {0.61, 4.63, -4.04, 1.72, 3.61}
    };

    // Вектор правой части
    vector<double> b5 = { 4.27, 5.77, 3.70, 5.95, -6.77 };

    cout << "Матрица коэффициентов A:" << endl;
    printMatrix(A5);

    cout << "\nВектор правой части b:" << endl;
    printVector(b5);

    try {
        vector<double> solution = gauss(A5, b5);
        cout << "\nРешение системы (x1-x5):" << endl;
        printVector(solution);

        // Проверка решения
        cout << "\nПроверка (A*x - b):" << endl;
        for (int i = 0; i < 5; i++) {
            double sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += A5[i][j] * solution[j];
            }
            cout << "Уравнение " << i + 1 << ": " << setw(12) << sum - b5[i] << endl;
        }
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }


    
    
    

    vector<vector<double>> detMatrix = {
        {-6.32, 4.51, -3.84, -7.38, -6.56},
        {4.22, -4.13, -4.16, -1.93, 6.36},
        {1.90, -2.56, -3.94, -1.61, -8.84},
        {7.29, -1.49, 1.79, 6.11, 8.00},
        {-0.70, -2.39, -4.08, -6.90, 1.65}
    };

    cout << "Матрица для вычисления определителя:" << endl;
    printMatrix(detMatrix);

    double det = determinant(detMatrix);
    cout << "\nОпределитель матрицы: " << det << endl;







    vector<vector<double>> invMatrix = {
        {0.38, 1.83, 5.88, -5.62, 3.33},
        {6.65, -7.51, -5.84, 2.54, -5.38},
        {-1.37, -2.32, 6.00, 8.49, 3.03},
        {-8.46, 4.73, -1.71, 7.04, -2.11},
        {-7.34, -1.04, -6.43, -4.91, -7.14}
    };

    cout << "Исходная матрица:" << endl;
    printMatrix(invMatrix);

    try {
        vector<vector<double>> inverse = inverseMatrix(invMatrix);
        cout << "\nОбратная матрица:" << endl;
        printMatrix(inverse);

        // Проверка: A * A^(-1) = I
        cout << "\nПроверка (A * A^(-1)):" << endl;
        int n = invMatrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double sum = 0;
                for (int k = 0; k < n; k++) {
                    sum += invMatrix[i][k] * inverse[k][j];
                }
                cout << setw(10) << sum;
            }
            cout << endl;
        }
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}