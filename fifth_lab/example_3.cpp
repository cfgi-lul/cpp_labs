#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

int main() {
    bool findStringInFile(char *);

    cout << findStringInFile("qwer");
    return 0;
}

bool findStringInFile(char *str) {
    size_t stringLength = strlen(str);
    cout << stringLength << endl;
    int stringSearchIndex = 0;
    char ch;
    char name[50] = "input.txt";

    FILE *input;

    if ((input = fopen(name, "r")) == 0) {
        printf("file %s cannot be opened ", name);
    } else {
        while (!feof(input)) {
            ch = getc(input);
            if (stringSearchIndex != stringLength) {
                if (ch == str[stringSearchIndex]) {
                    stringSearchIndex++;
                } else {
                    stringSearchIndex = 0;
                }
            } else {
                return true;
            }
        }
    }

    return false;
}