#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;


class NewString {
public:
    bool operator==(const NewString &s) {
        bool res = true;
        int i = 0;
        if (strlen(s._string) != strlen(_string)) {
            return false;
        }
        while ((s._string[i] != 0) && (_string[i] != 0)) {
            res &= s._string[i] == _string[i];
            i++;
        }
        return res;
    }

public:
    NewString &operator=(const NewString &rhs);

public:
    friend NewString operator+(const NewString &lhs, const NewString &rhs);

    char *str;

private:
    char *_string = (char *) calloc(100, 100 * sizeof(char));

public:
    void setString(char *s) {
        memCopy(s, _string, 256);
    }

public:
    char *getString() {
        return _string;
    }

private:
    void memCopy(char *src, char *dst, size_t size) {
        for (int i = 0; i < size; ++i) {
            dst[i] = src[i];
        }
    }


public:
    NewString() {
        memCopy("", _string, 256);
    }

public:
    NewString(string s) {
        for (int i = 0; i < s.length(); i++) {
            _string[i] = s[i];
        }
    }

public:
    NewString(char *s) {
        memCopy(s, _string, 256);
    }

    ~NewString() { delete _string; }

    friend ostream &operator<<(ostream &, NewString &);

    friend istream &operator>>(istream &, NewString &);
};


NewString operator+(const NewString &lhs, const NewString &rhs) {
    int length = strlen(lhs._string) + strlen(rhs._string);

    char *buff = new char[length + 1];

    strcpy(buff, lhs._string);
    strcat(buff, rhs._string);
    buff[length] = '\0';

    NewString temp(buff);

    delete[] buff;

    return temp;
}

NewString &NewString::operator=(const NewString &s) {
    if (this == &s) {
        return *this;
    }

    delete[] _string;
    _string = new char[256];
    strcpy(_string, s._string);
    return *this;
}

ostream &operator<<(ostream &os, NewString &str) {
    os << str.getString();
    return os;
}

istream &operator>>(istream &is, NewString &str) {
    string temp;
    is >> str._string;

    return is;
}

int main() {
    char *temp = "asdf";
    NewString str(temp);

    cout << str << endl;
    cin >> str;

    cout << str.getString() << endl;

    return 0;
}