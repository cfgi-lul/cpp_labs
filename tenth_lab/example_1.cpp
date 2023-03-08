#include <iostream>
#include <string>
#include "example1_bus.cpp"
#include "example1_list.cpp"


int main() {
    void goBusOnTheWay(Node<Bus>*, string);
    void goBusInPark(Node<Bus>*, string);
    void printAllBusses(Node<Bus> *);
    void printAllBussesOnWay(Node<Bus> *);
    void printAllBussesInPark(Node<Bus> *);
    int size = 20;
    Bus busses[size];
    for (int i = 0; i < size; i++) {
        busses[i].setFullName("FullName " + to_string(i));
        busses[i].setNumber("Number " + to_string(i));
        busses[i].setRouteNumber("RouteNumber " + to_string(i));
    }

    Node<Bus> *pbeg = first(busses[0]);
    Node<Bus> *pend = pbeg;
    for (int i = 1; i < size; i++) {
        add(&pend, busses[i]);
    }
    Node<Bus> *pv = pbeg;
    goBusOnTheWay(pv, "Number 4");
    goBusOnTheWay(pv, "Number 7");
    goBusOnTheWay(pv, "Number 9");
    goBusOnTheWay(pv, "Number 13");
//    printAllBussesOnWay(pv);
    goBusInPark(pv, "Number 7");
//    printAllBussesOnWay(pv);
    printAllBussesInPark(pv);
//    printAllBusses(pv);
    return 0;
}

void goBusOnTheWay(Node<Bus>* pv, string number) {
    while (pv) {
        if(number == (pv)->val.getBusNumber()) {
            (pv)->val.goOnTheWay();
            break;
        }
        pv = pv->next;
    }
}

void goBusInPark(Node<Bus>* pv, string number) {
    while (pv) {
        if(number == (pv)->val.getBusNumber()) {
            (pv)->val.goToPark();
        }
        pv = pv->next;
    }
}

void printAllBussesOnWay(Node<Bus> *pv) {
    Node<Bus> *temp = pv;
    while (pv) {
        if(pv->val.isOnTheWay()) {
            cout << pv->val.getInfo() << endl;
        }
        pv = pv->next;
    }

    pv = temp;
}

void printAllBussesInPark(Node<Bus> *pv) {
    Node<Bus> *temp = pv;
    while (pv) {
        if(!(pv->val.isOnTheWay())) {
            cout << pv->val.getInfo() << endl;

        }
        pv = pv->next;
    }
    pv = temp;
}

void printAllBusses(Node<Bus> *pv) {
    Node<Bus> *temp = pv;
    while (pv) {
        cout << pv->val.getInfo() << endl;
        pv = pv->next;
    }
    pv = temp;
}