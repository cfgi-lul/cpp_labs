#include "iostream"
#include "fstream"
#include <cctype>

using namespace std;

int main() {
    char frame[15], c;
    cout << "input inputFile name" << endl;
    cin >> frame;
    ifstream ifs(frame); // создали стрим
    if (!ifs) { // проверка на созданные стрим
        cout << "inputFile error" << endl;
    }
    cout << "input outputFile name" << endl;
    cin >> frame;
    ofstream ofs(frame); // создали стрим
    if (!ofs) { // проверка на созданные стрим
        cout << "outputFile error" << endl;
    }
    while (ifs && ofs) {
        ifs.get(c); // читаем символ
        c = toupper(c); // переводим в верхний регистр
        ofs.put(c); // кладем в выходной стрим
    }

    return 0;
}
