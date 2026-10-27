#include <iostream>
#include <fstream>
#include <string>
#include "caesarCipher.h"

using namespace std;

string readFile(const string& filename) {
    ifstream in(filename.c_str());
    if (!in) {
        cerr << "Could not open " << filename << endl;
        return "";
    }
    string content, line;
    bool first = true;
    while (getline(in, line)) {
        if (!first) content += " ";
        content += line;
        first = false;
    }
    return content;
}

int main() {
    ofstream out("decryptedMessages.txt");
    string filenames[4] = { "cipher1.txt", "cipher2.txt", "cipher3.txt", "cipher4.txt" };
 
    for (int f = 0; f < 4; f++) {
        string encoded = readFile(filenames[f]);
        if (encoded.empty()) {
            continue;
        }
 
        cout << "===== " << filenames[f] << " =====" << endl;
        cout << "Encrypted Text: " << encoded << endl;
 
        caesarCipher decoder;
        string candidates[26]; 

        for (int shift = 0; shift < 26; shift++) {
            decoder.rotateCipher(shift);
            candidates[shift] = decoder.decrypt(encoded);
            cout << "Shift " << shift << ": " << candidates[shift] << endl;
        }
 

        int chosenShift = -1;
        while (chosenShift < 0 || chosenShift > 25) {
            cout << "Which shift (0-25) is the correct plain text? ";
            cin >> chosenShift;
        }
 
        out << "Filename: " << filenames[f] << endl;
        out << "Encrypted Text: " << encoded << endl;
        out << "Plain Text: " << candidates[chosenShift] << endl;
        out << "Shifts: " << chosenShift << endl << endl;
 
        cout << endl;
    }
 
    out.close();
    return 0;
}