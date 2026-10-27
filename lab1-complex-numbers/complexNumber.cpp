#include "complexNumber.h"
#include <string>
using namespace std;

complexNumber::complexNumber(int r, int i){
    real = r;
    imagine = i;
}

complexNumber complexNumber::operator+(const complexNumber& other) const {
    return complexNumber(real + other.real, imagine + other.imagine);
}

complexNumber complexNumber::operator-(const complexNumber& other) const {
    return complexNumber(real - other.real, imagine - other.imagine);
}

complexNumber complexNumber::operator*(const complexNumber& other) const {
    int r = real * other.real - imagine * other.imagine;
    int i = real * other.imagine + imagine * other.real;
    return complexNumber(r, i); 
}

ostream& operator<<(ostream& os, const complexNumber& c) {
    os << c.real;
    if (c.imagine >= 0) {
        os << "+" << c.imagine << "i";
    } else {
        os << c.imagine << "i";
    }
    return os;
}

istream& operator>>(istream& is, complexNumber& c) {
    string whole;
    is >> whole;

    if (whole.empty()) {
        return is; 
    }

    int splitPos = -1;
    for (size_t idx = 1; idx < whole.size(); idx++) {
        if (whole[idx] == '+' || whole[idx] == '-') {
            splitPos = idx;
            break;
        }
    }

    string realPart = whole.substr(0, splitPos);
    string imagPart = whole.substr(splitPos, whole.size() - splitPos - 1);

    c.real = stoi(realPart);
    c.imagine = stoi(imagPart);

    return is;
}

bool complexNumber::tryParse(const std::string& whole, int& outReal, int& outImag) {
    if (whole.empty() || whole.back() != 'i') {
        return false;
    }

    int splitPos = -1;
    for (size_t idx = 1; idx < whole.size(); idx++) {
        if (whole[idx] == '+' || whole[idx] == '-') {
            splitPos = idx;
            break;
        }
    }
    if (splitPos == -1) {
        return false;
    }

    string realPart = whole.substr(0, splitPos);
    string imagPart = whole.substr(splitPos, whole.size() - splitPos - 1);

    outReal = stoi(realPart);
    outImag = stoi(imagPart);
    return true;
}