#include <cstdio>

using namespace std;

int main() {
    char ch, name[50]; // Объявление переменных для хранения символа и имени файла
    FILE *input;
    printf("input file name\n");
    scanf("%s", name); // Читаем имя переменной
    if ((input = fopen(name, "r")) == 0) { // проверка на существование файла
        printf("file %s cannot be opened ", name);
    } else {
        while (!feof(input)) { // проверка на не конец файла
            ch = getc(input); // получение следующего символа
            putchar(ch); // вывод символа в консоль
        }
    }

    return 0;
}