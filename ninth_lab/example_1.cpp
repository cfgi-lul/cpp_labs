#include "iostream"

using namespace std;

template<class T> // создаем шаблон функции с типом определяющимся на этапе компиляции
void Sort(T array[], size_t size) {
    int i, j;
    T tmp; // переменная для смены значений
    for (i = 0; i < (size - 1); i++) { // сортировка пузырьком
        for (j = (size - 1); i < j; j--) {
            if (array[i] > array[j]) {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
        }
    }
}

class Money {
    long dollars;
    int cents;

public: // публичный конструктор без аргументов
    Money() {};

    Money(long d, int c) { // конструктор с аргументами
        dollars = d;
        cents = c;
    }

    int operator>(const Money &) const; // переопределение оператора сравнения

    friend ostream &operator<<(ostream &, Money &); // дружественное переопределение оператора вывода
};


int Money::operator>(const Money &amt) const { // логика сравнения
    return (dollars > amt.dollars) || ((dollars == amt.dollars) && (cents > amt.cents));
}

ostream &operator<<(ostream &os, Money &amt) { // Логика оператора вывода
    os << "$" << amt.dollars << '.' << amt.cents;
    return os;
}

int main() {
    Money mas[] = {Money(19, 10),
                   Money(99, 99),
                   Money(99, 95),
                   Money(19, 95)};
    size_t masSize = sizeof(mas) / sizeof(mas[0]); // Вычисление размера массива
    Sort(mas, masSize); // сортировка пузырьком нашего массива
    for (int i = 0; i < masSize; i++) { // вывод на экран
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }
}