#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    void encodeFileWithKey(string);

    string key = "SomeAwesomeKey";
    encodeFileWithKey(key);
    return 0;
}

void encodeFileWithKey(string key) {
    string inputFileName = "input5lab_ex5.txt";
    string outputFileName = "output5lab_ex5.txt";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    size_t keySize = key.length();
    size_t keyIndex = 0;
    cout << keySize;

    char ch;
    if (!inputFile.is_open() || !outputFile.is_open()) {
        printf("file %s cannot be opened ", inputFileName.c_str());
    } else {
        while (inputFile.get(ch)) {
            outputFile.put(ch ^ key[keyIndex]);
            keyIndex %= keySize;
        }
    }
    inputFile.close();
    outputFile.close();
}