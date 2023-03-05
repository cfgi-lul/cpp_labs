#include <iostream>
#include "example_2_1.cpp"

int main() {
    char *temp = "asdf";
    string temp1 = "qwer";
    NewString str(temp);
    NewString str2(temp1);
    NewString str3;
    str3 = str2;

    cout << str.getString() << endl;
    cout << str2.getString() << endl;
    cout << ((str + str2) == (str + str2)) << endl;
    cout << (str3 == str2) << endl;
    return 0;
}