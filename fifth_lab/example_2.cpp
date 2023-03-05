#include <cstdio>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int printableCount = 0;
    int nonPrintableCount = 0;
    regex nonPrintableRegex(
            "[\\s\\u0000-\\u001F\\uFFF0-\\uFFF8\\u007F\\u115F\\u1160\\u3164\\uFFA0\\uFFFC]+"); // регулярка для вычисление неотображаемых символов
    char ch, name[50] = "input.txt"; // Объявление переменных для хранения символа и имени файла
    FILE *input;
    printf("input file name\n");
//    scanf("%s", name); // Читаем имя переменной
    if ((input = fopen(name, "r")) == 0) { // проверка на существование файла
        printf("file %s cannot be opened ", name);
    } else {
        while (!feof(input)) { // проверка на не конец файла
            ch = getc(input); // получение следующего символа
            string s(1, ch);
            if (!regex_match(s, nonPrintableRegex)) {
                printableCount++;
                cout << ch;
            } else {
                nonPrintableCount++;
            }
        }
    }

    cout << "printable characters count: " << printableCount << endl;
    cout << "non printable characters count: " << nonPrintableCount << endl;
    return 0;
}