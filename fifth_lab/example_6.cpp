#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    void encodeFileWithKey(char *, string, string);

    string key;
    string inputFileName;
    string outputFileName;
    cin >> key;
    cin >> inputFileName;
    cin >> outputFileName;
    char *keyCh = &key[0];
    encodeFileWithKey(keyCh, inputFileName, outputFileName);

    return 0;
}

void encodeFileWithKey(char *key, string inputFileName, string outputFileName) {
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