#include <iostream>
using namespace std;

// Пузырьковая сортировка
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Сортировка вставками
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Быстрая сортировка
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для копирования массива
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int original[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(original) / sizeof(original[0]);

    int arr1[n], arr2[n], arr3[n];

    copyArray(original, arr1, n);
    copyArray(original, arr2, n);
    copyArray(original, arr3, n);

    cout << "Исходный массив: ";
    printArray(original, n);
    cout << endl;

    bubbleSort(arr1, n);
    cout << "Пузырьковая сортировка: ";
    printArray(arr1, n);

    insertionSort(arr2, n);
    cout << "Сортировка вставками: ";
    printArray(arr2, n);

    quickSort(arr3, 0, n - 1);
    cout << "Быстрая сортировка: ";
    printArray(arr3, n);

    return 0;
}