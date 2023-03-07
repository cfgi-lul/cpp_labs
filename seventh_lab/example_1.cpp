#include <iostream>

using namespace std;

class A {
    int x;
public:
    A(int x) {
        this->x = x;
    }

    virtual void show() {
        cout << "Hello from A \n";
    }
};

class B : public A {
    int y;
    int x;
public:
    B(int x, int y):A(x) {
        this->y = y;
        this->x = x;
    }

    void show() {
        cout << "Hello from B \n";
    }
};



class D : public B {
    int x, y,z;
public:
    D(int x, int y, int z):B(x, y) {
        this->z = z;
        this->x = x;
        this->y = y;
    }
};

int main() {
    D object(2,3,5);
    object.show();
}