#include "iostream"

using namespace std;

template<class T>
class Tstack {
public:
    int numItem;
    T *item;

public:
    Tstack(size_t size = 10) {
        numItem = 0;
        item = new T[size];

    }

public:
    bool isEmpty() {
        return numItem == 0;
    }

public:
    T top() {
        return item[numItem - 1];
    }

    void push(T t);

    T pop();
};

template<class T>
void Tstack<T>::push(T t) {
    item[numItem++] = t;
}

template<class T>
T Tstack<T>::pop() {
    return item[--numItem];
}

template<class T>
void stackSort(Tstack<T> stack) {
    Tstack<T> tmpStack; // временный стэк для сортировки
    while (!stack.isEmpty()) // Условие остановки, если стэк пустой
    {
        int tmp = stack.top(); // смотрим на верхний элемент
        stack.pop(); // убираем верхний элемент из исходного стэка
        while (!tmpStack.isEmpty() && tmpStack.top() <
                                      tmp) // условие оствновки внутреннего цикла, пока временный стэк не пуст и вершина временного стэка меньше  последнего элемента стэка
        {
            stack.push(tmpStack.pop()); // кладем в исходный стэк верхний элемент временного стэка
        }
        tmpStack.push(tmp);
    }

    while (!stack.isEmpty()) {
        stack.pop();
    }
    while (!tmpStack.isEmpty()) {
        stack.push(tmpStack.pop());
    }
}


int main() {
    srand(time(NULL));
    size_t size = 20;
    Tstack<int> arr(size);
    for (int i = 0; i < size; i++) {
        int temp = rand() % 20;
        cout << temp << "\t";
        arr.push(temp);
    }
    cout << endl;
    stackSort(arr);
    while (!arr.isEmpty()) {
        cout << arr.pop() << "\t";
    }

    return 0;
}
