#include <iostream>
#include <cmath>

int main() {
    int a = 3;
    double b = 0.501;

    double result = 3 * sqrt(pow(a - b, 2)) * pow(sin(1 - (a / b) * (M_PI / 3)), 2) * pow(cos(1 - (b / a) * (M_PI / 3)), 2) / (0.701 * log(0.708 * b));

    std::cout << result;
    return 0;
}