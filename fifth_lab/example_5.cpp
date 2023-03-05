#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    void encodeFileWithKey(char *);

    int size = 30;

    char *key = "SomeAwesomeKey";
    encodeFileWithKey(key);
    return 0;
}

void encodeFileWithKey(char *key) {
    string inputFileName = "input5lab_ex5.txt";
    string outputFileName = "output5lab_ex5.txt";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    int keySize = strlen(key);
    int keyIndex = 0;
    cout << keySize;

    char ch;
    if ((inputFile.is_open() == 0) || (outputFile.is_open() == 0)) {
        printf("file %s cannot be opened ", inputFileName.c_str());
    } else {
        while (inputFile.get(ch)) {
            outputFile.put(ch ^ key[keyIndex]);
            keyIndex %= keySize;
        }
    }
}