#include <iostream>

int main() {
    int N;
    input:
    std::cout << "Enter a three-digit positive number N: ";
    std::cin >> N;

    if (N < 100 || N > 999) {
        std::cout << "Entered number is not three digits long.\n";
        goto input;
    }
    
    int sum = 0;
    int digit;
    while (N > 0) {
        digit = N % 10;
        if (digit > 3) {
            sum += digit;
        }
        N /= 10;
    }
    
    std::cout << "Sum 3 number: " << sum << std::endl;

    return 0;
}