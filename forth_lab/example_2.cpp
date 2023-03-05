#include <iostream>

using namespace std;

int main() {
    // 0 === '\0' так как в двоичное представление одинаковое
    // Создадим три массива символов
    char str1[] = "qwertyui";
    char str2[] = "12345678967896780";
    char str4[] = "123456789skdfsadfjh0";
    char str3[20];
    cout << &str1 << " "  << &str2 << endl;

    int stringLength(const char *);
    int stringLength2(char *);
    int stringLength3(char *);
    void stringCopy(char *, char *);
    bool stringCompare(char *, char *);
    char *stringConcat(char *, char *);

    cout << "String length: \"" << str1 << "'\" equals: " << stringLength(str1) << endl;

    cout << "String length: \"" << str1 << "'\" equals: " << stringLength2(str1) << endl;

    cout << "String length: \"" << str1 << "'\" equals: " << stringLength3(str1) << endl;

    stringCopy(str3, str1);
    cout << "String to \"" << str3 << "\" String from \"'" << str1 << "\" " << endl;

    cout << "String comparison " << (stringCompare(str2, str4) ? "equal" : "not equal") << endl;

    stringConcat(str1, str2);
    cout << "String concat " << " " << str1 << " " << str2 << " " << " " << endl;

    return 0;
}

// Пока не найдем до пустого символа считаем
int stringLength(const char *str) {
    int res = 0;
    for (int i = 0; str[i] != 0; i++, res++);
    return res;
}


// Используем указатель для перемещения
int stringLength2(char *str) {
    char *temp = str;
    for (; *temp != 0; temp++);
    // указатель на начало минус указатель на конец равно длина строки
    return temp - str;
}

// Используем указатель для перемещения
int stringLength3(char *str) {
    int i;
    for (i = 0; *str != 0; i++, str++);
    return i;
}

void stringCopy(char *to, char *from) {
    for (int i = 0; *from != 0; i++, to++, from++) {
        *to = *from;
    }
}

bool stringCompare(char *str1, char *str2) {
    if (stringLength(str1) != stringLength(str2)) {
        return false;
    }
    bool res = true;
    for (int i = 0; *str1 != 0; i++, str1++, str2++) {
        res &= *str1 == *str2;
    }
    return res;
}

char *stringConcat(char *str1, char *str2) {
    // передвигаем указатель до конца первой строки
    for (; *str1 != 0; str1++);
    for (; *str2 != 0; str1++, str2++)
        *str1 = *str2;
    *str1 = 0;
}