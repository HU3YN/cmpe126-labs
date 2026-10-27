#include "caesarCipher.h"
#include <iostream>

const int caesarCipher::ALPHABET_SIZE;

caesarCipher::caesarCipher(){

    arrayList<char> plainTemp(ALPHABET_SIZE);
    arrayList<char> cipherTemp(ALPHABET_SIZE);

    plainAlphabet = plainTemp;
    cipherAlphabet = cipherTemp;
 
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char letter = 'A' + i;
        plainAlphabet.insertAt(i, letter);
        cipherAlphabet.insertAt(i, letter);
    }
}

caesarCipher::~caesarCipher(){}

void caesarCipher::rotateCipher(int numSteps){
    arrayList<char> rotated(ALPHABET_SIZE);
 
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        
        int sourceIndex = i - numSteps;
        while (sourceIndex < 0) {
            sourceIndex += ALPHABET_SIZE;
        }
        while (sourceIndex >= ALPHABET_SIZE) {
            sourceIndex -= ALPHABET_SIZE;
        }
        char letter = 'A' + sourceIndex;
        rotated.insertAt(i, letter);
    }
 
    cipherAlphabet = rotated;
}

std::string caesarCipher::decrypt(const std::string& cipherText) {
    std::string result = "";
 
    for (size_t i = 0; i < cipherText.size(); i++) {
        char c = cipherText[i];
 
        if (c == ' ') {
            result += ' ';
            continue;
        }
 

        int foundIndex = -1;
        for (int pos = 0; pos < ALPHABET_SIZE; pos++) {
            if (cipherAlphabet.isItemAtEqual(pos, c)) {
                foundIndex = pos;
                break;
            }
        }
 
        if (foundIndex == -1) {

            result += c;
        } else {
            result += plainAlphabet.retrieveAt(foundIndex);
        }
    }
 
    return result;
}

void caesarCipher::print() const {
    std::cout << "Plain:  ";
    plainAlphabet.print();
    std::cout << "Cipher: ";
    cipherAlphabet.print();
}