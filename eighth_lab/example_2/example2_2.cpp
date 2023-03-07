#include "iostream"
#include "fstream"
#include "stdlib.h"

using namespace std;

int main() {
    char name[12];
    fstream fin;
    cout << "input file name" << endl;
    cin >> name;

    fin.open(name, ios::in);
    if (fin) { // check whether stream is open
        cout << "file has been opened " << name << endl;
        fin.close(); // close file
    } else { // error handling
        cout << "file cannot be opened" << endl;
    }


    return 0;
}