#include "iostream"


int main() {
    int power(int, int); // ссылка на функцию
    for (int i = 0; i < 10; i++) { // цикл для числа
        for (int j = 0; j < 10; j++) { // цикл для степени
            std::cout << j << " pow " << i << ": " << power(j, i) << std::endl; // вывод в консоль
        }
    }

    return 0;
}

int power(int number, int powerNumber) {
    int i, p = 1; // переменные
    for (i = 1; i < powerNumber; i++) { // цикл для вычисления степени
        p *= number; // возведение в степень
    }
    return p; // возвращение результата
}