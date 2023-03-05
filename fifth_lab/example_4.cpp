#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string inputFileName = "input5lab.txt";
    string outputFileName = "output5lab.txt";

    ifstream inputFile(inputFileName);

    ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "cannot open files" << endl;
        return 1;
    }

    string line;
    int pageIndex = 1;
    int lineIndex = 0;
    bool isFPreviousChar = false;
    while (getline(inputFile, line)) {
        if (lineIndex == 0) {
            lineIndex++;
        } else {
            if (isFPreviousChar) {
                isFPreviousChar = false;
            } else {
                if (strcmp(line.c_str(), "\\f") == 0) {
                    outputFile << pageIndex << endl;
                    isFPreviousChar = true;
                    pageIndex++;
                } else {
                    outputFile << line << endl;
                }
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}