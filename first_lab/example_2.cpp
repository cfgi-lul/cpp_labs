#define PR(x) printf("x=%u, *x=%d, &x=%u\n",x, *x, &x); // определение для PR как вывод в консоль с определенным правилом

#include <cstdio>
#include "iostream"

using namespace std;

int main() {
    int arr[] = {100, 200, 300}; // объявление массива
    int *ptr1, *ptr2; // объявление указателей
    ptr1 = arr; // присваиваем указателю ссылку на первый элмемнт массива
    ptr2 = &arr[2]; // присваиваем указателю ссылку на второй элмемнт массива
    PR(ptr1) // выводим в консоль первый указатель
    ptr1++; // инкремент
    PR(ptr1) // выводим в консоль первый указатель

    PR(ptr2) // выводим в консоль второй указатель
    ptr2++; // инкремент
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1); // вывод в консоль
    printf("\n");

    //
    //
    //
    // DOUBLE
    //
    //
    //

    {
        double temp = 2.71;
        double *ptrTemp = &temp;

        cout << "temp value:\t\t\t" << temp << endl;
        cout << "temp address\t\t" << &temp << endl;
        cout << "pointer value\t\t" << ptrTemp << endl;
        cout << "pointed value\t\t" << *ptrTemp << endl;

        *ptrTemp = 3.14;
        cout << "modified temp value\t" << temp << endl;

        printf("\n");
    }

    //
    //
    //
    // CHAR
    //
    //
    //

    {
        char temp = 'A';
        char *ptrTemp = &temp;

        cout << "temp value:\t\t\t" << temp << endl;
        cout << "temp address\t\t" << &temp << endl;
        cout << "pointer value\t\t" << ptrTemp << endl;
        cout << "pointed value\t\t" << *ptrTemp << endl;

        *ptrTemp = 'B';
        cout << "modified temp value\t" << temp << endl;

        printf("\n");
    }

    //
    //
    //
    // BOOLEAN
    //
    //
    //

    {
        bool temp = true;
        bool *ptrTemp = &temp;

        cout << "temp value:\t\t\t" << temp << endl;
        cout << "temp address\t\t" << &temp << endl;
        cout << "pointer value\t\t" << ptrTemp << endl;
        cout << "pointed value\t\t" << *ptrTemp << endl;

        *ptrTemp = false;
        cout << "modified temp value\t" << temp << endl;

        printf("\n");
    }

    return 0;
}