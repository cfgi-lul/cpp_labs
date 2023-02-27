#include <iostream>

using namespace std;

int main() {
    void bubbleSort(int[], int, int);
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << size << endl;

    bubbleSort(arr, 4, 10);

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

void bubbleSort(int arr[], int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j < end; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
