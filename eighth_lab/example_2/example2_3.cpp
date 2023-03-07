#include <iostream>
#include <fstream>

const char fileName[] = "NewFile.txt";

using namespace std;

int main() {

    ofstream ofs(fileName, ios::out | ios::app);
    if (!ofs) // check if stream exist
    {
        cout << "File " << fileName << " already exists" << endl;
        return 0;
    } else {
        ofs << "This line is written to a new file" << endl;
        ofs.close(); // close stream
        fstream fs; // open new stream
        fs.open(fileName, ios::out | ios::ate | ios::app);
        fs << "We added some things" << endl;
        fs.close(); // close file
        fstream ifs(fileName); // open stream as input
        if (ifs) {
            cout << "Old file contains" << "..." << endl;
            char Line[80];
            ifs.getline(Line, sizeof(Line));
            cout << Line;
        } else {
            cout << "reopening error with " << fileName << endl;
        }
    }
    return 0;
}