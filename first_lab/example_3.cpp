#include "iostream"

using namespace std;

int main() {
    int a = 2, b = 5;
    void swapNumbers(int, int);
    void swapNumbers2(int *, int *);
    void swapNumbers3(int &, int &);

    cout << "before swap: a = " << a << " b =" << b << ";" << endl;
    // вызов swapNumbers(int, int);
    swapNumbers(a, b);
    cout << "after swap 1: a = " << a << "; b = " << b << ";" << endl;
    // вызов swapNumbers2(int*, int*);
    swapNumbers2(&a, &b);
    cout << "after swap 2: a = " << a << " b = " << b << ";" << endl;
    // вызов swapNumbers3(int&, int&);
    swapNumbers3(a, b);
    cout << "после after swap 3: a = " << a << "; b = " << b << ";" << endl;
    return 0;
}

void swapNumbers(int a, int b) {
    int c = b;
    a = b;
    b = c;
}

void swapNumbers2(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void swapNumbers3(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}