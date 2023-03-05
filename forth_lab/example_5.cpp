#include <iostream>

using namespace std;

int main() {
    // создаем массив strs из трех указателей на символы
    const int n = 3;
    char *strs[n];
    int stringLength3(char *);
    void memCopy(char *, char *, size_t);

    for (int i = 0; i < n; i++) {
        strs[i] = (char *) calloc(100, sizeof(char)); // выделяем память с помощью функции calloc()
    }

    memCopy("qwer", strs[0], sizeof("qwer"));
    memCopy("asdffg", strs[1], sizeof("asdffg"));
    memCopy("zxcvbnm", strs[2], sizeof("zxcvbnm"));

    cout << stringLength3(strs[0]) << endl;
    cout << stringLength3(strs[1]) << endl;
    cout << stringLength3(strs[2]) << endl;

    for (int i = 0; i < n; i++) { // вывод в консоль 
        cout << strs[i] << " ";
    }

    for (int i = 0; i < n; i++) {
        free(strs[i]); // освобождаем память, выделенную для каждой строки функцией free()
    }

    return 0;
}

// Используем указатель для перемещения
int stringLength3(char *str) {
    int i;
    for (i = 0; *str != 0; i++, str++);
    return i;
}

void memCopy(char *src, char *dst, size_t size) {
    for (int i = 0; i < size; ++i) {
        dst[i] = src[i];
    }
}