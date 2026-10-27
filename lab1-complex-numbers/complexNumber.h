#include <iostream>

class complexNumber{

    int real;
    int imagine;

    public:
    complexNumber(int r = 0, int i = 0);

    complexNumber operator+(const complexNumber& other) const;
    complexNumber operator-(const complexNumber& other) const;
    complexNumber operator*(const complexNumber& other) const;

    friend std::ostream& operator<<(std::ostream& os, const complexNumber& c);
    friend std::istream& operator>>(std::istream& is, complexNumber& c);

    static bool tryParse(const std::string& whole, int& outReal, int& outImag);
};