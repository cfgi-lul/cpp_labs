#include "iostream"
#include "string"

using namespace std;

template<class T>
// шаблон функции getMax для выстсления любых типов значений
T getMax(T t1, T t2) {
    return t1 > t2 ? t1 : t2;
}

char *getMax(char *s1, char *s2) {  // функция getMax для строк
    return (strcmp(s1, s2) > 0) ? s1 : s2;
}

template<class T>
// шаблон функции getMax для массивов любых значений
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
    char *s1 = "string1";
    char *s2 = "string2";
    cout << "max int " << getMax(i1, i2) << endl; // вызов функции getMax для целых чисел
    cout << "max string  " << getMax(s1, s2) << endl; // вызов функции getMax для строк

    return 0;
}