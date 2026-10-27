#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
 
#include <string>
#include "arrayList.h"

class caesarCipher{

private:
    arrayList<char> plainAlphabet; 

    arrayList<char> cipherAlphabet; 

    static const int ALPHABET_SIZE = 26;

public: 
    caesarCipher();

    ~caesarCipher();

    void rotateCipher(int numSteps);

    std::string decrypt(const std::string& cipherText);

    void print() const;

};


#endif