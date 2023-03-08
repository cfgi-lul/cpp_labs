#include <iostream>
#include <string>

using namespace std;

class Bus {
    string number;
    string fullName;
    string routeNumber;
    bool isOnWay;

public:
    void setRouteNumber(string val) {
        routeNumber = val;
    }

public:
    void setFullName(string val) {
        fullName = val;
    }

public:
    void setNumber(string val) {
        number = val;
    }

public:
    Bus() {
        isOnWay = false;
    }

public:
    Bus(string number, string fullName, string routeNumber) {
        number = number;
        fullName = fullName;
        routeNumber = routeNumber;
    }

public:
    void goOnTheWay() {
        isOnWay = true;
    }

public:
    void goToPark() {
        isOnWay = false;
    }

public:
    bool isOnTheWay() {
        return isOnWay;
    }

public:
    string getInfo() {
        return "Bus number: " + number + ";\t Driver full name: " + fullName + ";\t Route number: " + routeNumber +
               ";\t bus " + (isOnWay ? "is" : "isn't'") + " on the way";
    }

public:
    string getBusNumber() {
        return number;
    }

    friend ostream &operator<<(ostream &, Bus &);

    bool operator==(const Bus &s) {
        bool res = true;
        int i = 0;
        if (s.number.length() != number.length()) {
            return false;
        }
        while ((s.number[i] != 0) && (number[i] != 0)) {
            res &= s.number[i] == number[i];
            i++;
        }
        return res;
    }
};

ostream &operator<<(ostream &os, Bus &bus) {
    os << bus.getInfo();
    return os;
}
