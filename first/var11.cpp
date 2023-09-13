#include <iostream>
#include <cmath>
#include <string>

int main() {
    int a = 1;
    double b = 20.01;

    double result = 3 * sqrt((0.719) / b * pow((b - a) / (a + b), 2) + cos(log(b) * M_PI / 6));
    

    std::cout << result;
    return 0;
}