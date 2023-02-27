#include <iostream>

using namespace std;

int main() {
    void bubbleSort(int[], int);
    void quicksort(int[], int, int);
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << size << endl;

//    bubbleSort(arr, size);
    quicksort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}


int partition(int arr[], int low, int high) {
    // выбор опорного элемента (последний)
    int pivot = arr[high];
    // индекс самого левого элемента
    int i = low - 1;
    for (int j = low; j < high; j++) {
        // меняем элементы местами если текущий меньше опорного
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // так как элемент под индексом i самый ближайщий (по значению) элемент к самому опорному и меньше него
    // меняем i + 1 и опорный
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// быстрая сортировка
void quicksort(int arr[], int low, int high) {
    // условие рекурсии
    if (low < high) {
        // вычисление опорного элемента
        int p = partition(arr, low, high);
        // рекурсивный вызов функции для левой части массива
        quicksort(arr, low, p - 1);
        // рекурсивный вызов функции для правой части массива
        quicksort(arr, p + 1, high);
    }
}

