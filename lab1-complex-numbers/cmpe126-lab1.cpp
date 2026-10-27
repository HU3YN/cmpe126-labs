#include <iostream>
#include <fstream>
#include <string>
#include "complexNumber.h"
#include <fstream>

int main() {

    complexNumber c1;
    complexNumber c2(1, -5);
    complexNumber c3(2);
    int realNum = 3;
    std::cout << c1 << std::endl;
    std::cout << c2 << " " << c3 << std::endl;
    std::cout << c2 + c3 << std::endl;
    c1 = c1 + realNum;
    std::cout << c1 << std::endl;
    std::cin >> c2;
    std::cout << c2 * c3 << std::endl;
    c3 = c2 - c1;


    std::ifstream inFile("complexInput.txt");
    std::ofstream outFile("complexOutput.txt");

    std::string num1, sign, num2;
    int r1, i1, r2, i2;

    while (inFile >> num1 >> sign >> num2) {
        if (!complexNumber::tryParse(num1, r1, i1) || !complexNumber::tryParse(num2, r2, i2)) {
            outFile << "Error: invalid input, skipping" << std::endl;
            continue;
        }

        complexNumber num1(r1, i1), num2(r2, i2), result;
        char s = sign[0];

        if (s == '+') {
            result = num1 + num2;
        } else if (s == '-') {
            result = num1 - num2;
        } else if (s == '*') {
            result = num1 * num2;
        }

        outFile << result << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}