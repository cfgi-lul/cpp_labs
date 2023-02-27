#include <iostream>

using namespace std;

int main() {
    // инициализация массива
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    // вычисление размера массива
    int n = sizeof(mas) / sizeof(int);
    // начальные значение для imin и i
    int i = 0, imin = 0;
    // вывод в консоль значений
    for (i = 0; i < n; i++) {
        cout << mas[i] << ' ';
    }
    cout << endl;
    // Ищем минимальное и максимальное значение и устанавливаем их в соответствующие места в массиве
    for (i = 0; i < n - 1; i++) {
        imin = i;
        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[imin]) {
                imin = j;
            }
        }
        int t = mas[i];
        mas[i] = mas[imin];
        mas[imin] = t;
    }
    // вывод в консоль значений
    for (i = 0; i < n; i++) {
        cout << mas[i] << ' ';
    }
    cout << endl;

    return 0;
}