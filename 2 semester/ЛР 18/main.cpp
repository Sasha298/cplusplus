#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
    void simplify(); // додатковий метод для спрощення дробу
};

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    simplify();
}

void Fraction::simplify() {
    // Знаходимо найбільший спільний дільник
    int gcd = abs(numerator);
    int tempDen = abs(denominator);
    while (tempDen != 0) {
        int temp = tempDen;
        tempDen = gcd % tempDen;
        gcd = temp;
    }

    numerator /= gcd;
    denominator /= gcd;
    
    // Якщо знаменник від'ємний, переносимо знак до чисельника
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

string Fraction::toString() {
    int wholePart = numerator / denominator;
    int remainder = abs(numerator % denominator);
    stringstream ss;
    if (wholePart != 0) {
        ss << wholePart;
        if (remainder != 0) {
            ss << " " << remainder << "/" << abs(denominator);
        }
    } else {
        ss << numerator << "/" << denominator;
    }
    return ss.str();
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int num, den;
    string input;
    cout << "Enter a fraction (e.g., 3 / 4): ";
    getline(cin, input);

    stringstream ss(input);
    char slash;
    ss >> num >> slash >> den;

    if (den == 0) {
        cout << "Denominator cannot be zero." << endl;
        return 1;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}
