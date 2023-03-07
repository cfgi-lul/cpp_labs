#include "iostream"

using namespace std;

template<class T> // шаблон функции нахождения максимума среди двух чичел
T getMax(T t1, T t2) {
    return t1 > t2 ? t1 : t2;
}

template<class T> // шаблон функции нахождения максимума среди массива
T getMax(T t[], size_t size) {
    T retVal = t[0];
    for (int i = 0; i < size; i++) {
        if (t[i] > retVal) {
            retVal = t[i];
        }
    }
    return retVal;
}

int main() {
    int i1 = 3, i2 = 5;
    int arr[] = {3, 9, 5, 8};
    cout << "max int = " << getMax(i1, i2) << endl;// вызов для двух чисел
    cout << "max int = ";
    cout << getMax(arr, sizeof(arr) / sizeof(arr[0])) << endl; // вызов для массива
    return 0;
}