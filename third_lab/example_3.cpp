#include <iostream>
#include <algorithm>

using namespace std;

// компоратор для сортировки четных чисел по убыванию, а нечетных по возрастанию с сохранением позиций четных и нечетрых элементов
bool comparator(int i, int j) {
    if ((i % 2 == 0) && (j % 2 == 0)) {
        return i < j;
    } else if ((i % 2 != 0) && (j % 2 != 0)) {
        return i > j;
    }
    return false;
}

int main() {
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int size = sizeof(arr) / sizeof(int);
    void bubbleSort(int[], int);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// сортировка пузырьком
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (comparator(arr[i], arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}