#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char str1[] = "qwer";
    char str2[] = "asdf";
    char str3[] = "zxcv";

    // Возвращение длинны строки
    cout << "String length: " << strlen(str1) << endl;

    // Возвращение конкатенации двух строк
    cout << "String concatenation: " << strcat(str1, str3) << endl;

    // копирование 2 строк в одну
    cout << "String copying: " << strcpy(str1, str2) << " " << str1 << " " << str2 << endl;

    // сравнение 2 строк
    cout << "String comparison: " << (strcmp(str1, str2) == 0 ? "equal" : "not equal") << " " << str1 << " " << str2 << endl;
    return 0;
}