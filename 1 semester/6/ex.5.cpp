#include <iostream>

int main() {
    int N;
    std::cout << "Введіть натуральне число N: ";
    std::cin >> N;

    int sum = 0;

    while (N > 0) {
        int digit = N % 10;
        if (digit % 2 != 0)
            sum += digit;
        N /= 10;
    }

    std::cout << "Сума непарних цифр числа: " << sum << std::endl;

    return 0;
}
